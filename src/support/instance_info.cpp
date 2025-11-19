#include "support/instance_info.hpp"
#include "support/typescript_instance.hpp"
#include "utils/env.hpp"
#include <quickjs.h>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

GDExtensionBool set_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->set(p_name, p_value);
}

GDExtensionBool get_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get(p_name, r_ret);
}
const GDExtensionPropertyInfo *get_property_list_func(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get_property_list(r_count);
}

void free_property_list_func(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t p_count) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->free_property_list_func(p_list, p_count);
}
const GDExtensionMethodInfo *get_method_list_func(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get_method_list_func(r_count);
}
void free_method_list_func(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionMethodInfo *p_list, uint32_t p_count) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->free_method_list_func(p_list, p_count);
}
// GDExtensionBool property_can_revert_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name) {
// 	JavaScriptInstance *instance = reinterpret_cast<JavaScriptInstance *>(p_instance);
// 	return instance->property_can_revert(p_name);
// }

// GDExtensionBool property_get_revert_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret) {
// 	JavaScriptInstance *instance = reinterpret_cast<JavaScriptInstance *>(p_instance);
// 	return instance->property_get_revert(p_name, r_ret);
// }
GDExtensionBool has_method_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->has_method(p_name);
}

GDExtensionInt get_method_argument_count_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get_method_argument_count(p_name, r_is_valid);
}

void call_func(GDExtensionScriptInstanceDataPtr p_self, GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_self);
	instance->call(p_method, p_args, p_argument_count, r_return, r_error);
}

void notification_func(GDExtensionScriptInstanceDataPtr p_instance, int32_t p_what, GDExtensionBool p_reversed) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	instance->notification(p_what, p_reversed);
}

void to_string_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	instance->to_string(r_is_valid, r_out);
}

void refcount_incremented_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	instance->refcount_incremented();
}

GDExtensionBool refcount_decremented_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->refcount_decremented();
}

GDExtensionObjectPtr get_owner_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get_binding()->_owner;
}

GDExtensionObjectPtr get_script_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get_script();
}

GDExtensionBool is_placeholder_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->is_placeholder();
}

GDExtensionBool set_callback_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->set_callback(p_name, p_value);
}

GDExtensionScriptLanguagePtr get_language_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	return instance->get_language();
}

void free_func(GDExtensionScriptInstanceDataPtr p_instance) {
	TypeScriptInstance *instance = reinterpret_cast<TypeScriptInstance *>(p_instance);
	memdelete(instance);
}
