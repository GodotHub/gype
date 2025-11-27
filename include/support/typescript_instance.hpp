#ifndef __JAVASCRIPT_INSTANCE_H__
#define __JAVASCRIPT_INSTANCE_H__

#include "utils/env.hpp"
#include <gdextension_interface.h>
#include <quickjs.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <godot_cpp/core/object.hpp>

namespace godot {

class Variant;
class TypeScript;
class TypeScriptInstance;

class TypeScriptInstance {
	Object *gd_binding = nullptr;
	JSValue js_binding;
	Object *p_godot_object = nullptr;
	TypeScript *script = nullptr;
	JSValue module;
	List<PropertyInfo *> p_properties;
	std::vector<GDExtensionPropertyInfo> properties;
	List<MethodInfo *> p_methods;
	std::vector<GDExtensionMethodInfo> methods;

private:
	JSModuleDef *get_module(const char *path);
	JSValue find_ns_property(JSModuleDef *md, const char *name);

public:
	static const char *class_symbol_mask;

	GDExtensionBool set(GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_variant);
	GDExtensionBool get(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
	const GDExtensionPropertyInfo *get_property_list(uint32_t *r_count);
	void free_property_list_func(const GDExtensionPropertyInfo *p_list, uint32_t p_count);
	// GDExtensionBool property_can_revert(GDExtensionConstStringNamePtr p_name);
	// GDExtensionBool property_get_revert(GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
	void call(GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error);
	void notification(int32_t p_what, GDExtensionBool p_reversed);
	void to_string(GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out);
	void refcount_incremented();
	GDExtensionBool refcount_decremented();
	const GDExtensionMethodInfo *get_method_list_func(uint32_t *r_count);
	void free_method_list_func(const GDExtensionMethodInfo *p_list, uint32_t p_count);
	GDExtensionBool has_method(GDExtensionConstStringNamePtr p_name);
	GDExtensionInt get_method_argument_count(GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid);
	GDExtensionObjectPtr get_owner();
	GDExtensionObjectPtr get_script();
	GDExtensionBool is_placeholder();
	GDExtensionBool set_callback(GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value);
	GDExtensionScriptLanguagePtr get_language();

	Object *get_binding();

	TypeScriptInstance(Object *p_godot_object, TypeScript *script, bool is_placeholder);
	~TypeScriptInstance();
};
} // namespace godot

#endif // __JAVASCRIPT_INSTANCE_H__