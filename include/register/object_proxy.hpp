#ifndef __OBJECT_PROXY_H__
#define __OBJECT_PROXY_H__

#include <functional>
#include <godot_cpp/variant/variant.hpp>

namespace godot {
class Object;
class Variant;
template <typename T>
class Ref;
} //namespace godot

template <typename T, typename = void>
struct ObjectProxy;

template <typename T>
struct ObjectProxy<T, std::enable_if_t<!std::is_pointer_v<T> && std::is_base_of_v<godot::Object, T>>> {
	godot::Object *wrapped;
	std::function<godot::Ref<T>()> getter;
	std::function<void(const godot::Ref<T> &)> setter;
	operator godot::Variant() const { return getter(); }
};

template <typename T>
struct ObjectProxy<T, std::enable_if_t<std::is_pointer_v<T> && std::is_base_of_v<godot::Object, std::remove_pointer_t<T>>>> {
	godot::Object *wrapped;
	std::function<T()> getter;
	std::function<void(const T)> setter;
	operator godot::Variant() const { return getter(); }
};

template <typename T>
struct ObjectProxy<T, std::enable_if_t<!std::is_pointer_v<T> && !std::is_base_of_v<godot::Object, T> && std::is_constructible_v<godot::Variant, T>>> {
	godot::Object *wrapped;
	std::function<T()> getter;
	std::function<void(const T &)> setter;
	operator godot::Variant() const { return getter(); }
};
#endif // __OBJECT_PROXY_H__