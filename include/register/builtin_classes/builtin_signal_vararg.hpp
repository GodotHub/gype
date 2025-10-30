#ifndef __GENERATED_BUILTIN_SIGNAL_VARARG_H__
#define __GENERATED_BUILTIN_SIGNAL_VARARG_H__

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include <vector>

using namespace godot;

static void js_emit_internal(void *p_instance, const Variant **p_args, GDExtensionInt p_arg_count) {
	static StringName method_name("emit");
	static GDExtensionPtrBuiltInMethod method_ptr = internal::gdextension_interface_variant_get_ptr_builtin_method((GDExtensionVariantType)Variant::SIGNAL, method_name._native_ptr(), 3286317445);
	CHECK_METHOD_BIND(method_ptr);
	method_ptr(p_instance, reinterpret_cast<GDExtensionConstTypePtr *>(p_args), nullptr, p_arg_count);
}

void js_emit(void *p_instance, const std::vector<Variant>& p_args) {
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
	js_emit_internal(p_instance, arg_pointers.data(), arg_pointers.size());
}


#endif // __GENERATED_BUILTIN_SIGNAL_VARARG_H__