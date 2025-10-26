#ifndef __UTILITY_FUNCTIONS_VARARG_METHOD_H__
#define __UTILITY_FUNCTIONS_VARARG_METHOD_H__

#include "register/utility_functions/register_utility_functions.hpp"
#include "register/utility_functions/utility_functions_vararg_method.hpp"
#include "utils/env.hpp"
#include "utils/func_utils.hpp"
#include "utils/quickjs_helper.hpp"
#include "utils/str_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;
Variant js_max_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("max")._native_ptr(), 3896050336);
	CHECK_METHOD_BIND_RET(_gde_function, Variant());
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
	return ret;
}
Variant js_min_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("min")._native_ptr(), 3896050336);
	CHECK_METHOD_BIND_RET(_gde_function, Variant());
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
	return ret;
}
String js_str_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("str")._native_ptr(), 32569176);
	CHECK_METHOD_BIND_RET(_gde_function, String());
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
	return ret;
}
void js_print_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("print")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_print_rich_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("print_rich")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_printerr_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("printerr")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_printt_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("printt")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_prints_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("prints")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_printraw_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("printraw")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_print_verbose_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("print_verbose")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_push_error_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("push_error")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
void js_push_warning_internal(const Variant **p_args, GDExtensionInt p_arg_count) {
	static GDExtensionPtrUtilityFunction _gde_function = internal::gdextension_interface_variant_get_ptr_utility_function(StringName("push_warning")._native_ptr(), 2648703342);
	CHECK_METHOD_BIND(_gde_function);
	Variant ret;
	_gde_function(&ret, reinterpret_cast<GDExtensionConstVariantPtr *>(p_args), p_arg_count);
}
Variant js_max(const Variant &p_arg1, const Variant &p_arg2, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	variant_args.push_back(p_arg2);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	return js_max_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
Variant js_min(const Variant &p_arg1, const Variant &p_arg2, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	variant_args.push_back(p_arg2);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	return js_min_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
String js_str(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	return js_str_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_print(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_print_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_print_rich(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_print_rich_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_printerr(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_printerr_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_printt(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_printt_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_prints(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_prints_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_printraw(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_printraw_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_print_verbose(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_print_verbose_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_push_error(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_push_error_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
void js_push_warning(const Variant &p_arg1, std::vector<Variant> p_args) {
	std::vector<Variant> variant_args;
	std::vector<Variant *> variant_args_ptr;
	variant_args.push_back(p_arg1);
	for (int i = 0; i < p_args.size(); i++) {
		variant_args.push_back(p_args[i]);
	}
	for (int i = 0; i < variant_args.size(); i++) {
		variant_args_ptr.push_back(&variant_args[i]);
	}
	js_push_warning_internal(const_cast<const Variant **>(variant_args_ptr.data()), variant_args_ptr.size());
}
#endif // __UTILITY_FUNCTIONS_VARARG_METHOD_H__