#ifndef __GENERATED_BUILTIN_CALLABLE_VARARG_H__
#define __GENERATED_BUILTIN_CALLABLE_VARARG_H__

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <vector>

using namespace godot;

static Variant js_call_internal(void *p_instance, const Variant **p_args, GDExtensionInt p_arg_count) {
	static StringName method_name("call");
	static GDExtensionPtrBuiltInMethod method_ptr = internal::gdextension_interface_variant_get_ptr_builtin_method((GDExtensionVariantType)Variant::CALLABLE, method_name._native_ptr(), 3643564216);

	Variant return_value;
	method_ptr(p_instance, reinterpret_cast<GDExtensionConstTypePtr *>(p_args), &return_value, p_arg_count);
	return return_value;
}

Variant js_call(void *p_instance, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args;
	all_args.reserve(0 + p_args.size());
	if (!p_args.empty()) {
		all_args.insert(all_args.end(), p_args.begin(), p_args.end());
	}
	std::vector<const Variant *> arg_pointers;
	arg_pointers.reserve(all_args.size());
	for (const Variant &arg : all_args) {
		arg_pointers.push_back(&arg);
	}
	return js_call_internal(p_instance, arg_pointers.data(), arg_pointers.size());
}

static void js_call_deferred_internal(void *p_instance, const Variant **p_args, GDExtensionInt p_arg_count) {
	static StringName method_name("call_deferred");
	static GDExtensionPtrBuiltInMethod method_ptr = internal::gdextension_interface_variant_get_ptr_builtin_method((GDExtensionVariantType)Variant::CALLABLE, method_name._native_ptr(), 3286317445);

	method_ptr(p_instance, reinterpret_cast<GDExtensionConstTypePtr *>(p_args), nullptr, p_arg_count);
}

void js_call_deferred(void *p_instance, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args;
	all_args.reserve(0 + p_args.size());
	if (!p_args.empty()) {
		all_args.insert(all_args.end(), p_args.begin(), p_args.end());
	}
	std::vector<const Variant *> arg_pointers;
	arg_pointers.reserve(all_args.size());
	for (const Variant &arg : all_args) {
		arg_pointers.push_back(&arg);
	}
	js_call_deferred_internal(p_instance, arg_pointers.data(), arg_pointers.size());
}

static void js_rpc_internal(void *p_instance, const Variant **p_args, GDExtensionInt p_arg_count) {
	static StringName method_name("rpc");
	static GDExtensionPtrBuiltInMethod method_ptr = internal::gdextension_interface_variant_get_ptr_builtin_method((GDExtensionVariantType)Variant::CALLABLE, method_name._native_ptr(), 3286317445);

	method_ptr(p_instance, reinterpret_cast<GDExtensionConstTypePtr *>(p_args), nullptr, p_arg_count);
}

void js_rpc(void *p_instance, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args;
	all_args.reserve(0 + p_args.size());
	if (!p_args.empty()) {
		all_args.insert(all_args.end(), p_args.begin(), p_args.end());
	}
	std::vector<const Variant *> arg_pointers;
	arg_pointers.reserve(all_args.size());
	for (const Variant &arg : all_args) {
		arg_pointers.push_back(&arg);
	}
	js_rpc_internal(p_instance, arg_pointers.data(), arg_pointers.size());
}

static void js_rpc_id_internal(void *p_instance, const Variant **p_args, GDExtensionInt p_arg_count) {
	static StringName method_name("rpc_id");
	static GDExtensionPtrBuiltInMethod method_ptr = internal::gdextension_interface_variant_get_ptr_builtin_method((GDExtensionVariantType)Variant::CALLABLE, method_name._native_ptr(), 2270047679);

	method_ptr(p_instance, reinterpret_cast<GDExtensionConstTypePtr *>(p_args), nullptr, p_arg_count);
}

void js_rpc_id(void *p_instance, int p_peer_id, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args;
	all_args.reserve(1 + p_args.size());
	all_args.push_back(p_peer_id);
	if (!p_args.empty()) {
		all_args.insert(all_args.end(), p_args.begin(), p_args.end());
	}
	std::vector<const Variant *> arg_pointers;
	arg_pointers.reserve(all_args.size());
	for (const Variant &arg : all_args) {
		arg_pointers.push_back(&arg);
	}
	js_rpc_id_internal(p_instance, arg_pointers.data(), arg_pointers.size());
}

static Callable js_bind_internal(void *p_instance, const Variant **p_args, GDExtensionInt p_arg_count) {
	static StringName method_name("bind");
	static GDExtensionPtrBuiltInMethod method_ptr = internal::gdextension_interface_variant_get_ptr_builtin_method((GDExtensionVariantType)Variant::CALLABLE, method_name._native_ptr(), 3224143119);

	Callable return_value;
	method_ptr(p_instance, reinterpret_cast<GDExtensionConstTypePtr *>(p_args), &return_value, p_arg_count);
	return return_value;
}

Callable js_bind(void *p_instance, const std::vector<Variant>& p_args) {
	std::vector<Variant> all_args;
	all_args.reserve(0 + p_args.size());
	if (!p_args.empty()) {
		all_args.insert(all_args.end(), p_args.begin(), p_args.end());
	}
	std::vector<const Variant *> arg_pointers;
	arg_pointers.reserve(all_args.size());
	for (const Variant &arg : all_args) {
		arg_pointers.push_back(&arg);
	}
	return js_bind_internal(p_instance, arg_pointers.data(), arg_pointers.size());
}


#endif // __GENERATED_BUILTIN_CALLABLE_VARARG_H__