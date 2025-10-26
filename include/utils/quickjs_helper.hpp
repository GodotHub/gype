#ifndef __QUICKutils_H__
#define __QUICKutils_H__

#include <quickjs.h>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <typeindex>
#include <unordered_map>

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof((array)[0]))
#endif // _countof

extern godot::HashMap<godot::StringName, JSClassID> classes;

bool is_exception(JSContext *ctx, JSValue exp);

template <typename T>
inline std::enable_if_t<std::is_base_of_v<godot::Wrapped, T>, void>
register_gd_class(JSClassID class_id) {
	classes[T::get_class_static()] = class_id;
}

#endif // __QUICKutils_H__
