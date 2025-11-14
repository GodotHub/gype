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

const char *TypeScriptInstance::symbol_mask = "_GodotClass";

#define BINDING_VALID_V(binding, ret) \
	gd_binding = get_binding();       \
	ERR_FAIL_NULL_V(binding, ret);    \
	ERR_FAIL_COND_V(JS_IsUndefined(js_binding), ret);
#define BINDING_VALID(binding)  \
	gd_binding = get_binding(); \
	ERR_FAIL_NULL(binding);     \
	ERR_FAIL_COND(JS_IsUndefined(js_binding));

TypeScriptInstance::TypeScriptInstance(Object *p_godot_object, TypeScript *script, bool is_placeholder) {
	if (script->dirty) {
		script->compile();
	}

	this->script = script;
	this->p_godot_object = p_godot_object;
	gd_binding = internal::get_object_instance_binding(p_godot_object->_owner);
	String code = script->get_dist_source_code();
	std::string code_str = std::string(code.utf8().get_data());
	JSValue ret = JS_Eval(js_context(), code_str.c_str(), code_str.size(), "<eval>", JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);
	ERR_FAIL_COND(is_exception(js_context(), ret));
	JSModuleDef *md = (JSModuleDef *)JS_VALUE_GET_PTR(ret);
	ret = JS_EvalFunction(js_context(), ret);
	ERR_FAIL_COND(is_exception(js_context(), ret));
	JSValue ns = JS_GetModuleNamespace(js_context(), md);
	ERR_FAIL_COND(is_exception(js_context(), ns));
	JSPropertyEnum *props;
	uint32_t len;
	ERR_FAIL_COND_MSG(JS_GetOwnPropertyNames(js_context(), &props, &len, ns, JS_GPN_STRING_MASK) < 0, "Error getting module property\n");
	for (uint32_t i = 0; i < len; i++) {
		JSAtom class_atom = props[i].atom;
		const char *prop_name = JS_AtomToCString(js_context(), class_atom);
		ret = JS_GetPropertyStr(js_context(), ns, prop_name);
		if (!is_exception(js_context(), ret) && JS_IsObject(ret)) {
			JSValue clazz = ret;
			JSPropertyEnum *class_props;
			uint32_t class_len;
			ERR_FAIL_COND_MSG(JS_GetOwnPropertyNames(js_context(), &class_props, &class_len, clazz, JS_GPN_SYMBOL_MASK) < 0, "Error getting class property\n");
			for (uint32_t j = 0; j < class_len; j++) {
				JSAtom symbol = class_props[j].atom;
				const char *symbol_name = JS_AtomToCString(js_context(), symbol);
				ret = JS_GetProperty(js_context(), ret, symbol);
				if (strcmp(symbol_mask, symbol_name) == 0) {
					VariantAdapter *adapter = memnew(VariantAdapter(gd_binding));
					JSValue constroctor_arg = *adapter;
					js_binding = JS_CallConstructor(js_context(), clazz, 1, &constroctor_arg);
					ERR_FAIL_COND(is_exception(js_context(), js_binding));
					script->instances.insert(gd_binding->get_instance_id());
				}
			}
		}
	}
}

godot::TypeScriptInstance::~TypeScriptInstance() {
	internal::gdextension_interface_object_free_instance_binding(gd_binding->_owner, internal::token);
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
	// BINDING_VALID_V(gd_binding, false);
	const char *name = to_chars(*reinterpret_cast<const StringName *>(p_name));
	if (script->is_tool || !Engine::get_singleton()->is_editor_hint()) {
		Variant varg;
		internal::gdextension_interface_variant_new_copy(varg._native_ptr(), p_variant);
		return JS_SetPropertyStr(js_context(), js_binding, name, VariantAdapter(varg)) > 0;
	}
	return false;
}

GDExtensionBool TypeScriptInstance::get(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	// BINDING_VALID_V(gd_binding, false);
	const char *name = to_chars(*reinterpret_cast<const StringName *>(p_name));
	if (script->is_tool || !Engine::get_singleton()->is_editor_hint()) {
		JSValue js_ret = JS_GetPropertyStr(js_context(), js_binding, name);
		if (JS_IsUndefined(js_ret)) {
			return false;
		}
		Variant ret = VariantAdapter(js_ret).get();
		internal::gdextension_interface_variant_new_copy(r_ret, ret._native_ptr());
		return true;
	}
	return false;
}

const GDExtensionPropertyInfo *TypeScriptInstance::get_property_list(uint32_t *r_count) {
	properties.clear();
	HashMap<StringName, PropertyInfo>::Iterator it = script->properties.begin();
	while (it != script->properties.end()) {
		const PropertyInfo &prop_info = it->value;
		properties.push_back(prop_info._to_gdextension());
		++it;
	}
	*r_count = script->properties.size();
	return properties.data();
}

// GDExtensionBool JavaScriptInstance::property_can_revert(GDExtensionConstStringNamePtr p_name) {
// 	return false;
// }

// GDExtensionBool JavaScriptInstance::property_get_revert(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
// StringName *name = (StringName *)p_name;
// *(Variant *)r_ret = p_godot_object->property_get_revert(*name);
// return true;
// }

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
	// BINDING_VALID(gd_binding);
	Object *o = internal::get_object_instance_binding(p_godot_object->_owner);
	UtilityFunctions::print(o);
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
	// BINDING_VALID(gd_binding);
	JSAtom atom = JS_NewAtom(js_context(), "_notification");
	if (script->is_tool || !Engine::get_singleton()->is_editor_hint()) {
		JSValue js_instance = js_binding;
		if (JS_HasProperty(js_context(), js_instance, atom)) {
			notification_bind(js_instance, JS_GetPrototype(js_context(), js_instance), p_what, p_reversed);
		}
	}
}

void TypeScriptInstance::to_string(GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {
	// BINDING_VALID(gd_binding);
	JSValue js_instance = js_binding;
	static JSAtom to_string_atom = JS_NewAtom(js_context(), "toString");
	JSValue ret = JS_Invoke(js_context(), js_instance, to_string_atom, 0, NULL);
	const char *cstr = JS_ToCString(js_context(), ret);
	internal::gdextension_interface_variant_new_copy(r_out, String(cstr)._native_ptr());
	*r_is_valid = true;
}

void TypeScriptInstance::refcount_incremented() {
	// BINDING_VALID(gd_binding);
	JS_DupValue(js_context(), js_binding);
}

GDExtensionBool TypeScriptInstance::refcount_decremented() {
	// BINDING_VALID_V(gd_binding, false);
	JS_FreeValue(js_context(), js_binding);
	return !JS_IsLiveObject(js_runtime(), js_binding);
}

GDExtensionObjectPtr TypeScriptInstance::get_owner() {
	return p_godot_object->_owner;
}

GDExtensionObjectPtr TypeScriptInstance::get_script() {
	return script;
}

GDExtensionBool godot::TypeScriptInstance::is_placeholder() {
	return false;
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