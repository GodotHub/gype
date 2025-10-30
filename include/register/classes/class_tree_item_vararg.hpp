#ifndef __GENERATED_CLASS_TREEITEM_VARARG_H__
#define __GENERATED_CLASS_TREEITEM_VARARG_H__

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <godot_cpp/variant/string_name.hpp>

using namespace godot;
// Internal wrapper for TreeItem::call_recursive
static void js_call_recursive_internal(GDExtensionObjectPtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count) {
	static GDExtensionMethodBindPtr gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(
        StringName("TreeItem")._native_ptr(),
        StringName("call_recursive")._native_ptr(),
        2866548813
    );
	CHECK_METHOD_BIND(gde_method_bind);
	GDExtensionCallError error;
	Variant ret;
	internal::gdextension_interface_object_method_bind_call(gde_method_bind, p_instance, p_args, p_arg_count, &ret, &error);
}

// Public-facing wrapper for JS binding
static void js_call_recursive(GodotObject *p_instance, const StringName& p_method, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args_variant;
	// Reserve space for both fixed and vararg arguments
	all_args_variant.reserve(1 + p_args.size());
	all_args_variant.push_back(p_method);
	// Append vararg arguments
	if (!p_args.empty()) {
		all_args_variant.insert(all_args_variant.end(), p_args.begin(), p_args.end());
	}
	// Prepare array of pointers for the GDExtension call
	std::vector<const Variant *> arg_pointers;
	arg_pointers.reserve(all_args_variant.size());
	for (const auto &arg : all_args_variant) {
		arg_pointers.push_back(&arg);
	}

	js_call_recursive_internal(p_instance, reinterpret_cast<GDExtensionConstVariantPtr *>(arg_pointers.data()), arg_pointers.size());
}

#endif // __GENERATED_CLASS_TREEITEM_VARARG_H__