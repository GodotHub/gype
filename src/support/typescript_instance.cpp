#include "support/typescript_instance.hpp"
#include "support/typescript.hpp"
#include "utils/event_loop.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <godot_cpp/classes/class_db_singleton.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/list.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant_size.hpp>
#include <memory>
#include <vector>

using namespace godot;

static void notification_bind(JSValue instance, JSValue prototype, int32_t p_what, GDExtensionBool p_reversed);

const char *TypeScriptInstance::class_symbol_mask = "_GodotClass";

#define BINDING_VALID_V(binding, ret) \
	gd_binding = get_binding();       \
	ERR_FAIL_NULL_V(binding, ret);    \
	ERR_FAIL_COND_V(JS_IsUndefined(js_binding), ret);
#define BINDING_VALID(binding)  \
	gd_binding = get_binding(); \
	ERR_FAIL_NULL(binding);     \
	ERR_FAIL_COND(JS_IsUndefined(js_binding));

TypeScriptInstance::TypeScriptInstance(Object *p_godot_object, Ref<TypeScript> script, bool is_placeholder) {
	this->script = script;
	this->p_godot_object = p_godot_object;
	this->compile_module();
}

godot::TypeScriptInstance::~TypeScriptInstance() {
	JS_FreeValue(js_context(), js_binding);
}

void TypeScriptInstance::compile_module() {
	gd_binding = internal::get_object_instance_binding(p_godot_object->_owner);
	String code = script->get_dist_source_code();
	std::string code_str = std::string(code.utf8().get_data());
	JSValue module = JS_Eval(js_context(), code_str.c_str(), code_str.size(), "<eval>", JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);

	// 检查 module 是否异常，如果是，则提前返回，避免后续操作
	if (is_exception(js_context(), module)) {
		// 在返回前，需要释放 module（即使它是异常值也需要释放）
		JS_FreeValue(js_context(), module);
		ERR_FAIL_MSG("Failed to compile JS module.");
		return;
	}

	JSModuleDef *md = (JSModuleDef *)JS_VALUE_GET_PTR(module);
	JSValue module_eval = JS_EvalFunction(js_context(), module);
	if (is_exception(js_context(), module_eval)) {
		JS_FreeValue(js_context(), module_eval);
		// JS_FreeValue(js_context(), module); // 别忘了释放 module
		ERR_FAIL_MSG("Failed to evaluate JS module.");
		return;
	}

	JSValue ns = JS_GetModuleNamespace(js_context(), md);
	if (is_exception(js_context(), ns)) {
		JS_FreeValue(js_context(), ns);
		JS_FreeValue(js_context(), module_eval);
		// JS_FreeValue(js_context(), module);
		ERR_FAIL_MSG("Failed to get module namespace.");
		return;
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

		if (!is_exception(js_context(), js_prop) && JS_IsObject(js_prop)) {
			// 注意：clazz 只是 js_prop 的别名，不需要单独管理它的生命周期
			JSValue clazz = js_prop;
			JSPropertyEnum *class_props = nullptr; // 初始化为 nullptr
			uint32_t class_len;
			if (JS_GetOwnPropertyNames(js_context(), &class_props, &class_len, clazz, JS_GPN_SYMBOL_MASK) < 0) {
				// 错误处理：释放当前循环中获取的资源
				JS_FreeValue(js_context(), js_prop);
				JS_FreeAtom(js_context(), class_atom);
				// 继续下一个循环，或者决定是否要终止整个过程
				continue;
			}

			for (uint32_t j = 0; j < class_len; j++) {
				JSAtom symbol = class_props[j].atom;
				const char *symbol_name = JS_AtomToCString(js_context(), symbol);
				if (strcmp(class_symbol_mask, symbol_name) == 0) {
					VariantAdapter *adapter = memnew(VariantAdapter(gd_binding));
					JSValue constroctor_arg = *adapter;
					js_binding = JS_CallConstructor(js_context(), clazz, 1, &constroctor_arg);
					memdelete(adapter); // adapter 仅用于传参，之后立即删除

					if (!is_exception(js_context(), js_binding)) {
						instance_created = true; // 成功创建
					}
				}
				JS_FreeAtom(js_context(), symbol);
				// 如果已经创建，可以跳出内层循环
				if (instance_created) {
					break;
				}
			}
			// 修复点 2：释放 JS_GetOwnPropertyNames 分配的 class_props 数组
			js_free(js_context(), class_props);
		}

		// 修复点 3：确保 js_prop 和 class_atom 在每次循环结束时都被释放
		JS_FreeAtom(js_context(), class_atom);
		JS_FreeValue(js_context(), js_prop);

		// 修复点 4：如果实例已创建，跳出外层循环
		if (instance_created) {
			break;
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
		script->instances.insert(gd_binding->get_instance_id());
	}
}

JSModuleDef *godot::TypeScriptInstance::get_module(const char *path) {
	char *code = new char[512];
	sprintf(code, "import * as md from \"%s\";", path);
	JSValue js_module = JS_Eval(js_context(), code, strlen(code), "<input>", JS_EVAL_FLAG_COMPILE_ONLY | JS_EVAL_TYPE_MODULE);
	JSModuleDef *md = (JSModuleDef *)JS_VALUE_GET_PTR(js_module);
	js_module = JS_EvalFunction(js_context(), js_module);
	return is_exception(js_context(), js_module) ? nullptr : md;
}

JSValue TypeScriptInstance::find_ns_property(JSModuleDef *md, const char *name) {
	JSValue ns = JS_GetModuleNamespace(js_context(), md);
	return JS_GetPropertyStr(js_context(), ns, name);
}

#define SET_JS_PROPERTY_WITH_MSG(prop_name, var)                        \
	if (JS_SetPropertyStr(ctx, js_instance, prop_name, var) <= 0) {     \
		qjs::print_exception(ctx);                                      \
		ERR_FAIL_V_EDMSG(false, "Error setting js_instance property."); \
	}                                                                   \
	return true;

#define SETTER_JS_PROPERTY_WITH_MSG(js_setter, var)                                                                                      \
	JSValue _var = var;                                                                                                                  \
	ERR_FAIL_COND_V_EDMSG(JS_IsException(JS_Call(ctx, js_setter, js_instance, 1, &_var)), false, "Error setting js_instance property."); \
	return true;

#define SETTER_GD_PROPERTY_WITH_MSG(gd_setter, var)                                                                                      \
	JSValue _var = var;                                                                                                                  \
	ERR_FAIL_COND_V_EDMSG(JS_IsException(JS_Call(ctx, gd_setter, js_instance, 1, &_var)), false, "Error setting js_instance property."); \
	return true;

GDExtensionBool TypeScriptInstance::set(GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_variant) {
	BINDING_VALID_V(gd_binding, false);
	const char *name = to_chars(*reinterpret_cast<const StringName *>(p_name));
	const Variant *varg = reinterpret_cast<const Variant *>(p_variant);
	return JS_SetPropertyStr(js_context(), js_binding, name, VariantAdapter(*varg)) > 0;
}

GDExtensionBool TypeScriptInstance::get(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	BINDING_VALID_V(gd_binding, false);
	const char *name = to_chars(*reinterpret_cast<const StringName *>(p_name));
	JSAtom name_atom = JS_NewAtom(js_context(), name);
	if (JS_HasProperty(js_context(), js_binding, name_atom) > 0) {
		JSValue js_ret = JS_GetPropertyStr(js_context(), js_binding, name);
		if (JS_IsUndefined(js_ret)) {
			return false;
		}
		Variant ret = VariantAdapter(js_ret).get();
		internal::gdextension_interface_variant_new_copy(r_ret, ret._native_ptr());
		JS_FreeAtom(js_context(), name_atom);
		return true;
	}
	JS_FreeAtom(js_context(), name_atom);
	return false;
}

const GDExtensionPropertyInfo *TypeScriptInstance::get_property_list(uint32_t *r_count) {
	BINDING_VALID_V(gd_binding, nullptr);
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
	BINDING_VALID_V(gd_binding, nullptr);
	TypedArray<Dictionary> script_methods = script->get_script_method_list();
	auto it = script_methods.begin();
	while (it != script_methods.end()) {
		MethodInfo *method_info = memnew(MethodInfo(MethodInfo::from_dict(*it)));
		p_methods.push_back(method_info);
		std::vector<GDExtensionPropertyInfo> arguments;
		LocalVector<PropertyInfo>::Iterator arguments_it = method_info->arguments.begin();
		while (arguments_it != method_info->arguments.end()) {
			arguments.push_back(arguments_it->_to_gdextension());
		}
		std::vector<GDExtensionVariantPtr> default_arguments;
		auto default_it = method_info->default_arguments.begin();
		while (default_it != method_info->default_arguments.end()) {
			default_arguments.push_back(default_it->_native_ptr());
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
	*r_count = script->methods.size();
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
	BINDING_VALID_V(gd_binding, false);
	StringName method = *reinterpret_cast<const StringName *>(p_name);
	return script->_has_method(method);
}

GDExtensionInt TypeScriptInstance::get_method_argument_count(GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	BINDING_VALID_V(gd_binding, 0);
	const char *name = to_chars(*reinterpret_cast<const StringName *>(p_name));
	*r_is_valid = script->_has_method(name);
	return script->_get_script_method_argument_count(name);
}

void TypeScriptInstance::call(GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	BINDING_VALID(gd_binding);
	JSValue js_instance = js_binding;
	JSValue prototype = JS_GetPrototype(js_context(), js_instance);
	const char *method = to_chars(*reinterpret_cast<const StringName *>(p_method));
	JSAtom atom = JS_NewAtom(js_context(), method);

	if (!script->is_tool && Engine::get_singleton()->is_editor_hint()) {
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
	BINDING_VALID(gd_binding);
	JSAtom atom = JS_NewAtom(js_context(), "_notification");
	if (script->is_tool || !Engine::get_singleton()->is_editor_hint()) {
		JSValue js_instance = js_binding;
		if (JS_HasProperty(js_context(), js_instance, atom)) {
			notification_bind(js_instance, JS_GetPrototype(js_context(), js_instance), p_what, p_reversed);
		}
	}
}

void TypeScriptInstance::to_string(GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {
	BINDING_VALID(gd_binding);
	JSValue js_instance = js_binding;
	static JSAtom to_string_atom = JS_NewAtom(js_context(), "toString");
	JSValue ret = JS_Invoke(js_context(), js_instance, to_string_atom, 0, NULL);
	const char *cstr = JS_ToCString(js_context(), ret);
	internal::gdextension_interface_variant_new_copy(r_out, String(cstr)._native_ptr());
	*r_is_valid = true;
}

void TypeScriptInstance::refcount_incremented() {
	BINDING_VALID(gd_binding);
	JS_DupValue(js_context(), js_binding);
}

GDExtensionBool TypeScriptInstance::refcount_decremented() {
	BINDING_VALID_V(gd_binding, false);
	JS_FreeValue(js_context(), js_binding);
	return !JS_IsLiveObject(js_runtime(), js_binding);
}

GDExtensionObjectPtr TypeScriptInstance::get_owner() {
	return p_godot_object->_owner;
}

GDExtensionObjectPtr TypeScriptInstance::get_script() {
	return script->_owner;
}

GDExtensionBool TypeScriptInstance::is_placeholder() {
	return false;
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