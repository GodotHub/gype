#ifndef __INSTANCE_INFO_H__
#define __INSTANCE_INFO_H__

#include <gdextension_interface.h>
#include <string>

GDExtensionBool set_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionConstVariantPtr p_value);
GDExtensionBool get_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
// const GDExtensionPropertyInfo *get_property_list_func(GDExtensionScriptInstanceDataPtr p_instance, uint32_t *r_count);
// void free_property_list_func(GDExtensionScriptInstanceDataPtr p_instance, const GDExtensionPropertyInfo *p_list, uint32_t p_count);
// GDExtensionBool property_can_revert_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name);
// GDExtensionBool property_get_revert_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionVariantPtr r_ret);
GDExtensionBool has_method_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name);
GDExtensionInt get_method_argument_count_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionConstStringNamePtr p_name, GDExtensionBool *r_is_valid);
void call_func(GDExtensionScriptInstanceDataPtr p_self, GDExtensionConstStringNamePtr p_method, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error);
void notification_func(GDExtensionScriptInstanceDataPtr p_instance, int32_t p_what, GDExtensionBool p_reversed);
void to_string_func(GDExtensionScriptInstanceDataPtr p_instance, GDExtensionBool *r_is_valid, GDExtensionStringPtr r_out);
void refcount_incremented_func(GDExtensionScriptInstanceDataPtr p_instance);
GDExtensionBool refcount_decremented_func(GDExtensionScriptInstanceDataPtr p_instance);
GDExtensionObjectPtr get_owner_func(GDExtensionScriptInstanceDataPtr p_instance);
GDExtensionObjectPtr get_script_func(GDExtensionScriptInstanceDataPtr p_instance);
GDExtensionBool is_placeholder_func(GDExtensionScriptInstanceDataPtr p_instance);
GDExtensionScriptLanguagePtr get_language_func(GDExtensionScriptInstanceDataPtr p_instance);
void free_func(GDExtensionScriptInstanceDataPtr p_instance);

static const GDExtensionScriptInstanceInfo3 InstanceInfo{
	set_func,
	get_func,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	get_owner_func,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	has_method_func,
	get_method_argument_count_func,
	call_func,
	notification_func,
	to_string_func,
	refcount_incremented_func,
	refcount_decremented_func,
	get_script_func,
	nullptr,
	nullptr,
	nullptr,
	get_language_func,
	free_func
};
#endif // __INSTANCE_INFO_H__