#ifndef __FUNC_UTILS_H__
#define __FUNC_UTILS_H__

#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <functional>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/builtin_types.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <utility>
#include <vector>

using namespace godot;

template <typename T>
struct is_const_ref : std::false_type {};

template <typename T>
struct is_const_ref<const Ref<T> &> : std::true_type {};

template <typename T>
constexpr bool is_const_ref_v = is_const_ref<T>::value;

template <typename T>
struct is_ref : std::false_type {};

template <typename T>
struct is_ref<Ref<T>> : std::true_type {};

template <typename T>
constexpr bool is_ref_v = is_ref<T>::value;

template <typename T>
struct ref_extract_type;

template <typename T>
struct ref_extract_type<Ref<T>> {
	using type = T;
};

template <typename T>
using ref_extract_type_t = typename ref_extract_type<T>::type;

template <typename T>
struct const_ref_extract_type;

template <typename T>
struct const_ref_extract_type<const Ref<T> &> {
	using type = T;
};

template <typename T>
using const_ref_extract_type_t = typename const_ref_extract_type<T>::type;

template <typename T>
struct is_bitfield : std::false_type {};

template <template <typename> class Template, typename T>
struct is_bitfield<Template<T>> : std::is_same<Template<T>, godot::BitField<T>> {};

template <typename T>
constexpr bool is_bitfield_v = is_bitfield<T>::value;

template <typename T>
struct FuncTraits;
template <typename R, typename T, typename... P>
struct FuncTraits<R (T::*)(P...)> {
	using ReturnType = R;
	using ArgTypes = std::tuple<P...>;
	using Type = T;
};
template <typename R, typename T, typename... P>
struct FuncTraits<R (T::*)(P...) const> {
	using ReturnType = R;
	using ArgTypes = std::tuple<P...>;
	using Type = T;
};
template <typename T, typename... P>
struct FuncTraits<void (T::*)(P...) const> {
	using ArgTypes = std::tuple<P...>;
	using Type = T;
};
template <typename R, typename... P>
struct FuncTraits<R (*)(P...)> {
	using ReturnType = R;
	using ArgTypes = std::tuple<P...>;
};

template <typename T>
std::enable_if_t<std::is_same_v<T, Variant>, T>
convert(JSContext *ctx, JSValue v) {
	return VariantAdapter(v);
}
template <typename T>
std::enable_if_t<std::is_same_v<T, Vector2> || std::is_same_v<T, Vector3>, T>
convert(JSContext *ctx, JSValue v) {
	return VariantAdapter(v).get();
}
template <typename T>
std::enable_if_t<std::is_fundamental_v<T> && !std::is_same_v<char32_t, T>, T>
convert(JSContext *ctx, JSValue v) {
	return VariantAdapter(v).get();
}

template <typename T>
std::enable_if_t<std::is_same_v<T, char32_t>, T>
convert(JSContext *ctx, JSValue v) {
	return *VariantAdapter(v).get().operator godot::String().ptrw();
}

template <typename T>
std::enable_if_t<std::is_enum_v<T> && !std::is_fundamental_v<T>, T>
convert(JSContext *ctx, JSValue v) {
	return T((VariantAdapter(v).get().operator int64_t()));
}
template <typename T>
std::enable_if_t<is_const_ref_v<T>, const_ref_extract_type_t<T> *>
convert(JSContext *ctx, JSValue v) {
	return static_cast<const_ref_extract_type_t<T> *>(VariantAdapter(v).get().operator godot::Object *());
}
template <typename T>
std::enable_if_t<is_ref_v<T>, ref_extract_type_t<T> *>
convert(JSContext *ctx, JSValue v) {
	return static_cast<ref_extract_type_t<T> *>(VariantAdapter(v).get());
}
template <typename T>
std::enable_if_t<std::is_same_v<const void*, T>, const void*>
convert(JSContext *ctx, JSValue v) {
	JSClassID class_id = 0;
	return JS_GetAnyOpaque(v, &class_id);
}
template <typename T>
std::enable_if_t<!is_const_ref_v<T> && !is_ref_v<T> && std::is_reference_v<T>, std::remove_const_t<std::remove_reference_t<T>>>
convert(JSContext *ctx, JSValue v) {
	return VariantAdapter(v).get();
}
template <typename T>
std::enable_if_t<std::is_pointer_v<T> && std::is_base_of_v<Object, std::remove_pointer_t<T>>, std::remove_pointer_t<T> *>
convert(JSContext *ctx, JSValue v) {
	JSClassID class_id = 0;
	VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(v, &class_id));
	return static_cast<std::remove_pointer_t<T> *>(adapter->get().operator Object *());
}
// template <typename T>
// std::enable_if_t<std::is_pointer_v<T> && !std::is_base_of_v<Object, std::remove_pointer_t<T>>, std::remove_pointer_t<T> *>
// convert(JSContext *ctx, JSValue v) {
// 	JSClassID class_id = 0;
// 	VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(v, &class_id));
// 	return static_cast<std::remove_pointer_t<T> *>(&adapter->variant);
// }

template <typename T>
std::enable_if_t<is_bitfield_v<T>, T>
convert(JSContext *ctx, JSValue v) {
	return VariantAdapter(v).get().operator int64_t();
}
template <typename T>
std::enable_if_t<std::is_base_of_v<Object, T>, T *>
convert(JSValue v) {
	JSClassID id = 0;
	VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(v, &id));
	const char *n = typeid(T).name();
	return static_cast<T *>(adapter->get().operator godot::Object *());
}
template <typename T>
std::enable_if_t<!std::is_base_of_v<Object, T> && std::is_constructible_v<Variant, T>, T>
convert(JSValue v) {
	JSClassID id = 0;
	VariantAdapter *adapter = static_cast<VariantAdapter *>(JS_GetAnyOpaque(v, &id));
	return adapter->get();
}
template <typename T>
void *native_ptr(T variant) {
	if constexpr (std::is_pointer_v<T> && std::is_base_of_v<Object, T>) {
		return variant->operator godot::Object *()->_native_ptr();
	} else if constexpr (std::is_pointer_v<T>) {
		return variant->_native_ptr();
	} else {
		return variant._native_ptr();
	}
}

template <typename T, typename... P, std::size_t... Is>
JSValue call_builtin_method_no_ret_impl(void (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	std::invoke(Func, callee, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])...);
	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_method_no_ret(void (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv) {
	return call_builtin_method_no_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P)>());
}

template <typename T, typename... P, std::size_t... Is>
JSValue call_builtin_const_method_no_ret_impl(void (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	std::invoke(Func, callee, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])...);
	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_const_method_no_ret(void (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv) {
	return call_builtin_const_method_no_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P)>());
}
template <typename R, typename T, typename... P, std::size_t... Is>
JSValue call_builtin_method_ret_impl(R (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	return VariantAdapter(std::invoke(Func, callee, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])...));
}

template <typename R, typename T, typename... P>
JSValue call_builtin_method_ret(R (T::*Func)(P...), JSContext *ctx, JSValue this_val, int argc, JSValue *argv) {
	return call_builtin_method_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P)>());
}

template <typename R, typename T, typename... P, std::size_t... Is>
JSValue call_builtin_const_method_ret_impl(R (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	return VariantAdapter(std::invoke(Func, callee, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])...));
}

template <typename R, typename T, typename... P>
JSValue call_builtin_const_method_ret(R (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv) {
	return call_builtin_const_method_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P)>());
}

template <typename R, typename... P, std::size_t... Is>
JSValue call_builtin_static_method_ret_impl(R (*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv, std::index_sequence<Is...>) {
	JSValue ret = VariantAdapter((*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])...));
	return ret;
}

template <typename R, typename... P>
JSValue call_builtin_static_method_ret(R (*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValue *argv) {
	return call_builtin_static_method_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P)>());
}

template <typename... P, std::size_t... Is>
JSValue call_builtin_static_method_no_ret_impl(void (*Func)(P...), JSContext *ctx, JSValue this_val, int argc, JSValue *argv, std::index_sequence<Is...>) {
	(*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])...);
	return JS_UNDEFINED;
}

template <typename... P>
JSValue call_builtin_static_method_no_ret(void (*Func)(P...), JSContext *ctx, JSValue this_val, int argc, JSValue *argv) {
	return call_builtin_static_method_no_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P)>());
}

template <typename T, typename... P, std::size_t... Is>
JSValue call_builtin_vararg_method_no_ret_impl(void (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	T callee = convert<T>(this_val);

	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]));
	}

	JSValue ret = JS_UNDEFINED;
	if constexpr (std::is_base_of_v<Object, T>) {
		ret = VariantAdapter((callee->*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args));
	} else {
		ret = VariantAdapter((callee.*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args));
	}

	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_vararg_method_no_ret(void (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_vararg_method_no_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename T, typename... P, std::size_t... Is>
JSValue call_builtin_const_vararg_method_no_ret_impl(void (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	T callee = convert<T>(this_val);

	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]));
	}
	if (std::is_pointer_v<T>) {
		(callee->*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args);
	} else {
		(callee.*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args);
	}
	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_const_vararg_method_no_ret(void (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_vararg_method_no_ret_impl(Func, ctx, this_val, argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename T, typename... P>
JSValue call_builtin_const_no_fixed_vararg_method_no_ret_impl(void (T::*Func)(std::vector<Variant>) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	auto callee = convert<T>(this_val);
	std::vector<Variant> variant_args;
	for (int i = 0; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]));
	}
	std::invoke(Func, callee, variant_args);
	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_const_no_fixed_vararg_method_no_ret(void (T::*Func)(void *opaque, std::vector<Variant>) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_no_fixed_vararg_method_no_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, argv);
}

template <typename T, typename R>
JSValue call_builtin_free_opaque_no_fixed_vararg_method_ret_impl(R (*Func)(void *, const std::vector<Variant> &), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	T callee = convert<T>(this_val);
	GDExtensionTypePtr vopaque = native_ptr(callee);
	std::vector<Variant> variant_args;
	for (int i = 0; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	return VariantAdapter((*Func)(vopaque, variant_args));
}

template <typename T, typename R>
JSValue call_builtin_free_opaque_no_fixed_vararg_method_ret(R (*Func)(void *, const std::vector<Variant> &), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_ret_impl<T>(Func, ctx, std::forward<JSValue>(this_val), argc, argv);
}

template <typename T>
JSValue call_builtin_free_opaque_no_fixed_vararg_method_no_ret_impl(void (*Func)(void *, const std::vector<Variant> &), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	auto callee = convert<T>(this_val);
	GDExtensionTypePtr vopaque = native_ptr(callee);
	std::vector<Variant> variant_args;
	for (int i = 0; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	(*Func)(vopaque, variant_args);
	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_free_opaque_no_fixed_vararg_method_no_ret(void (*Func)(void *, const std::vector<Variant> &), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_no_fixed_vararg_method_no_ret_impl<T>(Func, ctx, std::forward<JSValue>(this_val), argc, argv);
}

template <typename T, typename R, typename... P, std::size_t... Is>
JSValue call_builtin_free_opaque_vararg_method_ret_impl(R (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	GDExtensionTypePtr vopaque = native_ptr(callee);
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]));
	}
	JSValue ret = VariantAdapter((*Func)(vopaque, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args));
	return ret;
}

template <typename T, typename R, typename... P>
JSValue call_builtin_free_opaque_vararg_method_ret(R (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_vararg_method_ret_impl<T>(Func, ctx, std::forward<JSValue>(this_val), argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename T, typename... P, std::size_t... Is>
JSValue call_builtin_free_opaque_vararg_method_no_ret_impl(void (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	T callee = convert<T>(this_val);
	GDExtensionTypePtr vopaque = native_ptr(callee);
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	(*Func)(vopaque, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args);
	return JS_UNDEFINED;
}

template <typename T, typename... P>
JSValue call_builtin_free_opaque_vararg_method_no_ret(void (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_opaque_vararg_method_no_ret_impl<T>(Func, ctx, std::forward<JSValue>(this_val), argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename T, typename R, typename... P, std::size_t... Is>
JSValue call_builtin_vararg_method_ret_impl(R (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	return VariantAdapter(std::invoke(Func, callee, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args));
}

template <typename T, typename R, typename... P>
JSValue call_builtin_vararg_method_ret(R (T::*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_vararg_method_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, std::forward<JSValue *>(argv), std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename... P, std::size_t... Is>
JSValue call_builtin_static_vararg_method_no_ret_impl(void (*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	(*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args);
	return JS_UNDEFINED;
}

template <typename... P>
JSValue call_builtin_static_vararg_method_no_ret(void (*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_vararg_method_no_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename... P, std::size_t... Is>
JSValue call_builtin_free_owner_vararg_method_no_ret_impl(void (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	JSClassID class_id = 0;
	GodotObject *owner = static_cast<VariantAdapter *>(JS_GetAnyOpaque(this_val, &class_id))->get().operator Object *()->_owner;
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	(*Func)(owner, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args);
	return JS_UNDEFINED;
}

template <typename... P>
JSValue call_builtin_free_owner_vararg_method_no_ret(void (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_owner_vararg_method_no_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename T, typename R, typename... P, std::size_t... Is>
JSValue call_builtin_const_vararg_method_ret_impl(R (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	auto callee = convert<T>(this_val);
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	return std::invoke(Func, callee, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args);
}

template <typename T, typename R, typename... P>
JSValue call_builtin_const_vararg_method_ret(R (T::*Func)(P...) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_vararg_method_ret_impl(Func, std::forward<JSContext *>(ctx), std::forward<JSValue>(this_val), argc, std::forward<JSValue *>(argv), std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename T, typename R>
JSValue call_builtin_const_no_fixed_vararg_method_ret_impl(R (T::*Func)(std::vector<Variant>) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	auto callee = convert<T>(this_val);
	std::vector<Variant> variant_args;
	for (int i = 0; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	return std::invoke(Func, callee, variant_args);
}

template <typename T, typename R>
JSValue call_builtin_const_no_fixed_vararg_method_ret(R (T::*Func)(std::vector<Variant>) const, JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_const_no_fixed_vararg_method_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, argv);
}

template <typename R, typename... P, std::size_t... Is>
JSValue call_builtin_static_vararg_method_ret_impl(R (*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	return VariantAdapter((*Func)(convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args));
}

template <typename R, typename... P>
JSValue call_builtin_static_vararg_method_ret(R (*Func)(P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_static_vararg_method_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

template <typename R, typename... P, std::size_t... Is>
JSValue call_builtin_free_owner_vararg_method_ret_impl(R (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv, std::index_sequence<Is...>) {
	JSClassID class_id = 0;
	GodotObject *owner = static_cast<VariantAdapter *>(JS_GetAnyOpaque(this_val, &class_id))->get().operator Object *()->_owner;
	constexpr int fixed_argc = sizeof...(P) - 1;
	std::vector<Variant> variant_args;
	for (int i = fixed_argc; i < argc; ++i) {
		variant_args.push_back(VariantAdapter(argv[i]).get());
	}
	return VariantAdapter((*Func)(owner, convert<std::tuple_element_t<Is, std::tuple<P...>>>(ctx, argv[Is])..., variant_args));
}

template <typename R, typename... P>
JSValue call_builtin_free_owner_vararg_method_ret(R (*Func)(void *, P...), JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
	return call_builtin_free_owner_vararg_method_ret_impl(Func, ctx, std::forward<JSValue>(this_val), argc, argv, std::make_index_sequence<sizeof...(P) - 1>());
}

#endif // __FUNC_UTILS_H__