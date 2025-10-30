#ifndef __GENERATED_CLASS_NODE_VARARG_H__
#define __GENERATED_CLASS_NODE_VARARG_H__

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>
#include <godot_cpp/variant/string_name.hpp>

using namespace godot;
// Internal wrapper for Node::rpc
static Error js_rpc_internal(GDExtensionObjectPtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count) {
	static GDExtensionMethodBindPtr gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(
        StringName("Node")._native_ptr(),
        StringName("rpc")._native_ptr(),
        4047867050
    );
	CHECK_METHOD_BIND_RET(gde_method_bind, Error());
	GDExtensionCallError error;
	Variant ret;
	internal::gdextension_interface_object_method_bind_call(gde_method_bind, p_instance, p_args, p_arg_count, &ret, &error);
	return VariantCaster<enum::Error>::cast(ret);
}

// Public-facing wrapper for JS binding
static Error js_rpc(GodotObject *p_instance, const StringName& p_method, const std::vector<Variant>& p_args) {
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

	return js_rpc_internal(p_instance, reinterpret_cast<GDExtensionConstVariantPtr *>(arg_pointers.data()), arg_pointers.size());
}
// Internal wrapper for Node::rpc_id
static Error js_rpc_id_internal(GDExtensionObjectPtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count) {
	static GDExtensionMethodBindPtr gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(
        StringName("Node")._native_ptr(),
        StringName("rpc_id")._native_ptr(),
        361499283
    );
	CHECK_METHOD_BIND_RET(gde_method_bind, Error());
	GDExtensionCallError error;
	Variant ret;
	internal::gdextension_interface_object_method_bind_call(gde_method_bind, p_instance, p_args, p_arg_count, &ret, &error);
	return VariantCaster<enum::Error>::cast(ret);
}

// Public-facing wrapper for JS binding
static Error js_rpc_id(GodotObject *p_instance, int p_peer_id, const StringName& p_method, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args_variant;
	// Reserve space for both fixed and vararg arguments
	all_args_variant.reserve(2 + p_args.size());
	all_args_variant.push_back(p_peer_id);
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

	return js_rpc_id_internal(p_instance, reinterpret_cast<GDExtensionConstVariantPtr *>(arg_pointers.data()), arg_pointers.size());
}
// Internal wrapper for Node::call_deferred_thread_group
static Variant js_call_deferred_thread_group_internal(GDExtensionObjectPtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count) {
	static GDExtensionMethodBindPtr gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(
        StringName("Node")._native_ptr(),
        StringName("call_deferred_thread_group")._native_ptr(),
        3400424181
    );
	CHECK_METHOD_BIND_RET(gde_method_bind, Variant());
	GDExtensionCallError error;
	Variant ret;
	internal::gdextension_interface_object_method_bind_call(gde_method_bind, p_instance, p_args, p_arg_count, &ret, &error);
	return VariantCaster<Variant>::cast(ret);
}

// Public-facing wrapper for JS binding
static Variant js_call_deferred_thread_group(GodotObject *p_instance, const StringName& p_method, const std::vector<Variant>& p_args) {
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

	return js_call_deferred_thread_group_internal(p_instance, reinterpret_cast<GDExtensionConstVariantPtr *>(arg_pointers.data()), arg_pointers.size());
}
// Internal wrapper for Node::call_thread_safe
static Variant js_call_thread_safe_internal(GDExtensionObjectPtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_arg_count) {
	static GDExtensionMethodBindPtr gde_method_bind = internal::gdextension_interface_classdb_get_method_bind(
        StringName("Node")._native_ptr(),
        StringName("call_thread_safe")._native_ptr(),
        3400424181
    );
	CHECK_METHOD_BIND_RET(gde_method_bind, Variant());
	GDExtensionCallError error;
	Variant ret;
	internal::gdextension_interface_object_method_bind_call(gde_method_bind, p_instance, p_args, p_arg_count, &ret, &error);
	return VariantCaster<Variant>::cast(ret);
}

// Public-facing wrapper for JS binding
static Variant js_call_thread_safe(GodotObject *p_instance, const StringName& p_method, const std::vector<Variant>& p_args) {
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

	return js_call_thread_safe_internal(p_instance, reinterpret_cast<GDExtensionConstVariantPtr *>(arg_pointers.data()), arg_pointers.size());
}

#endif // __GENERATED_CLASS_NODE_VARARG_H__