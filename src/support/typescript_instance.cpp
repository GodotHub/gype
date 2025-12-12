#include "support/typescript_instance.hpp"
#include "support/typescript.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/list.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <memory>
#include <vector>

using namespace godot;

static void notification_bind(JSValue instance, JSValue prototype, int32_t p_what, GDExtensionBool p_reversed);

const char *TypeScriptInstance::class_symbol_mask = "_GodotClass";

#define BINDING_VALID_V(ret)             \
	ERR_FAIL_NULL_V(get_binding(), ret); \
	ERR_FAIL_COND_V(JS_IsUndefined(js_binding), ret);
#define BINDING_VALID             \
	ERR_FAIL_NULL(get_binding()); \
	ERR_FAIL_COND(JS_IsUndefined(js_binding));

TypeScriptInstance::TypeScriptInstance(Object *p_godot_object, TypeScript *script, bool is_placeholder) {
	this->is_placeholder_mode = is_placeholder;
	this->script = script;
	this->p_godot_object = p_godot_object;
	this->script->analyze();
	if (!is_placeholder_mode) {
		this->script->compile();
		this->compile_module();
	}
}

godot::TypeScriptInstance::~TypeScriptInstance() {
	JS_FreeValue(js_context(), js_binding);
}

HashMap<StringName, Variant> TypeScriptInstance::get_exported_values(JSValue this_obj) {
	HashMap<StringName, Variant> values;
	if (!JS_IsUndefined(this_obj)) {
		TypedArray<Dictionary> props = script->get_script_property_list();
		for (Dictionary prop : props) {
			PropertyInfo info = PropertyInfo::from_dict(prop);
			String prop_name = info.name;
			JSValue jsvalue = JS_GetPropertyStr(js_context(), this_obj, prop_name.utf8());
			Variant prop_value = jsvalue_to_variant(jsvalue);
			values[prop_name] = prop_value;
			JS_FreeValue(js_context(), jsvalue);
		}
	}
	return values;
}

void TypeScriptInstance::replace_exported_values(JSValue this_obj, HashMap<StringName, Variant> exported_values) {
	for (KeyValue<StringName, Variant> prop : exported_values) {
		JS_SetPropertyStr(js_context(), this_obj, String(prop.key).utf8(), variant_to_jsvalue(prop.value));
	}
}

void TypeScriptInstance::compile_module() {
	if (!p_godot_object || !p_godot_object->_owner) {
		return;
	}
	HashMap<StringName, Variant> exported_values = get_exported_values(js_binding);
	if (!JS_IsUndefined(js_binding)) {
		JS_FreeValue(js_context(), js_binding);
	}
	gd_binding = internal::get_object_instance_binding(p_godot_object->_owner);
	String code = script->get_dist_source_code();
	code = add_cache_buster_to_code_gd(code, UtilityFunctions::str(UtilityFunctions::randi()));
	JSValue module = JS_Eval(js_context(), code.utf8(), code.length(), "<eval>", JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);

	if (is_exception(js_context(), module)) {
		ERR_FAIL_MSG("Failed to compile JS module.");
	}

	JSModuleDef *md = (JSModuleDef *)JS_VALUE_GET_PTR(module);
	JSValue module_eval = JS_EvalFunction(js_context(), module);
	if (is_exception(js_context(), module_eval)) {
		JS_FreeValue(js_context(), module_eval);
		// JS_FreeValue(js_context(), module); // 别忘了释放 module
		ERR_FAIL_MSG("Failed to evaluate JS module.");
	}

	JSValue ns = JS_GetModuleNamespace(js_context(), md);
	if (is_exception(js_context(), ns)) {
		JS_FreeValue(js_context(), ns);
		JS_FreeValue(js_context(), module_eval);
		// JS_FreeValue(js_context(), module);
		ERR_FAIL_MSG("Failed to get module namespace.");
	}

	JSPropertyEnum *props = nullptr; // 初始化为 nullptr
	uint32_t len;
	if (JS_GetOwnPropertyNames(js_context(), &props, &len, ns, JS_GPN_STRING_MASK) < 0) {
		// 错误处理：释放已分配的资源
		JS_FreeValue(js_context(), ns);
		JS_FreeValue(js_context(), module_eval);
		// JS_FreeValue(js_context(), module);
		ERR_FAIL_MSG("Error getting module property names.");
		return;
	}

	bool instance_created = false; // 标志位，用于跳出外层循环
	for (uint32_t i = 0; i < len; i++) {
		JSAtom class_atom = props[i].atom;
		const char *prop_name = JS_AtomToCString(js_context(), class_atom);
		JSValue js_prop = JS_GetPropertyStr(js_context(), ns, prop_name);

		if (strcmp(prop_name, "default") == 0) {
			VariantAdapter *adapter = memnew(VariantAdapter(gd_binding));
			JSValue constroctor_arg = *adapter;
			js_binding = JS_CallConstructor(js_context(), js_prop, 1, &constroctor_arg);
			memdelete(adapter); // adapter 仅用于传参，之后立即删除

			if (!is_exception(js_context(), js_binding)) {
				instance_created = true; // 成功创建
				break;
			}
		}
	}

	// 修复点 2：释放 JS_GetOwnPropertyNames 分配的 props 数组
	js_free(js_context(), props);

	// 修复点 1：取消注释，释放 module 对象
	// JS_FreeValue(js_context(), module);
	JS_FreeValue(js_context(), module_eval);
	JS_FreeValue(js_context(), ns);

	// 检查最终是否成功创建实例
	if (!instance_created) {
		ERR_FAIL_MSG("Could not find a matching class to instantiate in the module.");
	} else {
		replace_exported_values(js_binding, exported_values);
		script->instances.insert(gd_binding->get_instance_id());
	}
}

GDExtensionBool TypeScriptInstance::set(GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_variant) {
	if (is_placeholder_mode) {
		StringName name = *reinterpret_cast<const StringName *>(p_name);
		const Variant *val = reinterpret_cast<const Variant *>(p_variant);
		if (script->godot_class_data) {
			for (const auto &prop_info : script->godot_class_data->properties) {
				if (name == prop_info.key) {
					placeholder_storage[name] = *val;
					return true;
				}
			}
		}
		return false;
	} else {
		BINDING_VALID_V(false);
		const String name = *reinterpret_cast<const StringName *>(p_name);
		const String _name = name.substr(1);
		const char *char_name;
		if (name.begins_with("_")) {
			char_name = _name.utf8();
		} else {
			char_name = name.utf8();
		}
		Variant variant = *reinterpret_cast<const Variant *>(p_variant);
		if (Engine::get_singleton()->is_editor_hint()) {
			if (script->godot_class_data->enum_properties.has(name)) {
				EnumParseResult parse_result = script->godot_class_data->enum_properties[name];
				variant = parse_result.constants[variant.operator int()];
			} else if (script->godot_class_data->type_properties.has(name)) {
				TypeParseResult parse_result = script->godot_class_data->type_properties[name];
				variant = parse_result.constants[variant.operator int()];
			}
		}
		JSAtom name_atom = JS_NewAtom(js_context(), char_name);
		if (JS_HasProperty(js_context(), js_binding, name_atom)) {
			JS_FreeAtom(js_context(), name_atom);
			return JS_SetPropertyStr(js_context(), js_binding, char_name, VariantAdapter(variant)) > 0;
		} else {
			JS_FreeAtom(js_context(), name_atom);
			return false;
		}
	}
}

GDExtensionBool TypeScriptInstance::get(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	if (is_placeholder_mode) {
		StringName name = *reinterpret_cast<const StringName *>(p_name);
		Variant *ret = reinterpret_cast<Variant *>(r_ret);
		if (placeholder_storage.has(name)) {
			*ret = placeholder_storage[name];
			return true;
		}
		// 如果字典里没有，尝试获取脚本默认值
		Variant def_val = script->get_property_default_value(name);
		if (def_val.get_type() != Variant::NIL) {
			*ret = def_val;
			return true;
		}
		return false;
	} else {
		BINDING_VALID_V(false);
		const StringName *gdname = reinterpret_cast<const StringName *>(p_name);
		const String _name = gdname->substr(1);
		const String name = *gdname;
		const char *char_name;
		if (gdname->begins_with("_")) {
			char_name = _name.utf8();
		} else {
			char_name = name.utf8();
		}
		JSAtom name_atom = JS_NewAtom(js_context(), char_name);
		if (JS_HasProperty(js_context(), js_binding, name_atom) > 0) {
			JS_FreeAtom(js_context(), name_atom);
			JSValue js_ret = JS_GetPropertyStr(js_context(), js_binding, char_name);
			if (JS_IsUndefined(js_ret)) {
				return false;
			}
			Variant ret = VariantAdapter(js_ret).get();
			internal::gdextension_interface_variant_new_copy(r_ret, ret._native_ptr());
			return true;
		} else {
			JS_FreeAtom(js_context(), name_atom);
			return false;
		}
	}
}

const GDExtensionPropertyInfo *TypeScriptInstance::get_property_list(uint32_t *r_count) {
	TypedArray<Dictionary> script_properties = script->get_script_property_list();
	auto it = script_properties.begin();
	while (it != script_properties.end()) {
		PropertyInfo *p_prop = memnew(PropertyInfo(PropertyInfo::from_dict(*it)));
		p_properties.push_back(p_prop);
		properties.push_back(p_prop->_to_gdextension());
		++it;
	}
	*r_count = properties.size();
	return properties.data();
}

void TypeScriptInstance::free_property_list_func(const GDExtensionPropertyInfo *p_list, uint32_t p_count) {
	for (uint32_t i = 0; i < p_properties.size(); ++i) {
		memdelete(p_properties.get(i));
	}
	p_properties.clear();
	properties.clear();
}

// GDExtensionBool JavaScriptInstance::property_can_revert(GDExtensionConstStringNamePtr p_name) {
// 	return false;
// }

// GDExtensionBool JavaScriptInstance::property_get_revert(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
// StringName *name = (StringName *)p_name;
// *(Variant *)r_ret = p_godot_object->property_get_revert(*name);
// return true;
// }

const GDExtensionMethodInfo *TypeScriptInstance::get_method_list_func(uint32_t *r_count) {
	TypedArray<Dictionary> script_methods = script->get_script_method_list();
	auto it = script_methods.begin();
	while (it != script_methods.end()) {
		MethodInfo mi = MethodInfo(*it);
		MethodInfo *method_info = memnew(MethodInfo(mi));
		p_methods.push_back(method_info);
		std::vector<GDExtensionPropertyInfo> arguments;
		LocalVector<PropertyInfo>::Iterator arguments_it = method_info->arguments.begin();
		while (arguments_it != method_info->arguments.end()) {
			arguments.push_back(arguments_it->_to_gdextension());
			++arguments_it;
		}
		std::vector<GDExtensionVariantPtr> default_arguments;
		auto default_it = method_info->default_arguments.begin();
		while (default_it != method_info->default_arguments.end()) {
			default_arguments.push_back(default_it->_native_ptr());
			++default_it;
		}
		methods.push_back({
				.name = method_info->name._native_ptr(),
				.return_value = method_info->return_val._to_gdextension(),
				.flags = method_info->flags,
				.id = method_info->id,
				.argument_count = method_info->arguments.size(),
				.arguments = arguments.data(),
				.default_argument_count = method_info->default_arguments.size(),
				.default_arguments = default_arguments.data(),
		});
		++it;
	}
	*r_count = script_methods.size();
	return methods.data();
}

void TypeScriptInstance::free_method_list_func(const GDExtensionMethodInfo *p_list, uint32_t p_count) {
	for (uint32_t i = 0; i < p_methods.size(); ++i) {
		memdelete(p_methods.get(i));
	}
	p_methods.clear();
	methods.clear();
}

GDExtensionBool TypeScriptInstance::has_method(GDExtensionConstStringNamePtr p_name) {
	StringName method = *reinterpret_cast<const StringName *>(p_name);
	return script->_has_method(method);
}

GDExtensionInt TypeScriptInstance::get_method_argument_count(GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	const char *name = to_chars(*reinterpret_cast<const StringName *>(p_name));
	*r_is_valid = script->_has_method(name);
	return script->_get_script_method_argument_count(name);
}

void TypeScriptInstance::call(GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	if (is_placeholder_mode) {
		return;
	}
	BINDING_VALID(gd_binding);
	JSValue js_instance = js_binding;
	JSValue prototype = JS_GetPrototype(js_context(), js_instance);
	const char *method = to_chars(*reinterpret_cast<const StringName *>(p_method));
	JSAtom atom = JS_NewAtom(js_context(), method);

	if (!script->is_tool() && Engine::get_singleton()->is_editor_hint()) {
		r_error->error = GDExtensionCallErrorType::GDEXTENSION_CALL_ERROR_INVALID_METHOD;
		return;
	}
	int it = 0;
	while (!JS_IsNull(prototype)) {
		JSPropertyDescriptor prop;
		if (JS_GetOwnProperty(js_context(), &prop, prototype, atom) > 0) {
			JSValue js_method = prop.value;
			if (!JS_IsFunction(js_context(), js_method)) {
				r_error->error = GDExtensionCallErrorType::GDEXTENSION_CALL_ERROR_INVALID_METHOD;
				return;
			}
			const Variant *variant_args = p_args ? *reinterpret_cast<const Variant *const *>(p_args) : nullptr;
			std::vector<JSValue> js_args(p_argument_count);
			for (int i = 0; i < p_argument_count; i++) {
				js_args[i] = VariantAdapter(variant_args[i]);
			}
			Variant ret = VariantAdapter(JS_Call(js_context(), js_method, js_instance, p_argument_count, js_args.data())).get();
			internal::gdextension_interface_variant_new_copy(r_return, ret._native_ptr());
			r_error->error = GDExtensionCallErrorType::GDEXTENSION_CALL_OK;
			return;
		}
		prototype = JS_GetPrototype(js_context(), prototype);
		++it;
	}
	r_error->error = GDExtensionCallErrorType::GDEXTENSION_CALL_ERROR_INVALID_METHOD;
}

void TypeScriptInstance::notification(int32_t p_what, GDExtensionBool p_reversed) {
	if (is_placeholder_mode) {
		return;
	}
	BINDING_VALID
	JSAtom atom = JS_NewAtom(js_context(), "_notification");
	if (script->is_tool() || !Engine::get_singleton()->is_editor_hint()) {
		JSValue js_instance = js_binding;
		if (JS_HasProperty(js_context(), js_instance, atom)) {
			notification_bind(js_instance, JS_GetPrototype(js_context(), js_instance), p_what, p_reversed);
		}
	}
}

void TypeScriptInstance::to_string(GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {
	if (is_placeholder_mode) {
		return;
	}
	BINDING_VALID(gd_binding);
	JSValue js_instance = js_binding;
	static JSAtom to_string_atom = JS_NewAtom(js_context(), "toString");
	JSValue ret = JS_Invoke(js_context(), js_instance, to_string_atom, 0, NULL);
	const char *cstr = JS_ToCString(js_context(), ret);
	internal::gdextension_interface_variant_new_copy(r_out, String(cstr)._native_ptr());
	*r_is_valid = true;
}

void TypeScriptInstance::refcount_incremented() {
	BINDING_VALID;
	JS_DupValue(js_context(), js_binding);
}

GDExtensionBool TypeScriptInstance::refcount_decremented() {
	BINDING_VALID_V(false);
	JS_FreeValue(js_context(), js_binding);
	return !JS_IsLiveObject(js_runtime(), js_binding);
}

GDExtensionObjectPtr TypeScriptInstance::get_owner() {
	return p_godot_object->_owner;
}

void TypeScriptInstance::get_property_state(GDExtensionScriptInstancePropertyStateAdd p_add_func, void *p_userdata) {
	for (StringName prop_name : placeholder_storage.keys()) {
		Variant variant = placeholder_storage[prop_name];
		p_add_func(prop_name._native_ptr(), variant._native_ptr(), p_userdata);
	}
}

GDExtensionObjectPtr TypeScriptInstance::get_script() {
	return script->_owner;
}

GDExtensionBool TypeScriptInstance::is_placeholder() {
	return is_placeholder_mode;
}

GDExtensionBool TypeScriptInstance::set_callback(GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	return true;
}

GDExtensionScriptLanguagePtr TypeScriptInstance::get_language() {
	return TypeScriptLanguage::get_singleton();
}

Object *TypeScriptInstance::get_binding() {
	return internal::get_object_instance_binding(p_godot_object->_owner);
}

static void notification_bind(JSValue instance, JSValue prototype, int32_t p_what, GDExtensionBool p_reversed) {
	if (JS_IsNull(prototype)) {
		return;
	}
	JSAtom method_atom = JS_NewAtom(js_context(), "_notification");
	JSValue what = JS_NewInt32(js_context(), p_what);
	JSPropertyDescriptor prop;
	JS_GetOwnProperty(js_context(), &prop, prototype, method_atom);
	JSValue js_method = prop.value;
	if (p_reversed && JS_IsFunction(js_context(), js_method)) {
		JS_Call(js_context(), js_method, instance, 1, &what);
	}
	prototype = JS_GetPrototype(js_context(), prototype);
	notification_bind(instance, prototype, p_what, p_reversed);
	if (!p_reversed && JS_IsFunction(js_context(), js_method)) {
		JS_Call(js_context(), js_method, instance, 1, &what);
	}
	JS_FreeAtom(js_context(), method_atom);
}