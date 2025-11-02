#ifndef __QUICKutils_H__
#define __QUICKutils_H__

#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <typeindex>
#include <unordered_map>

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof((array)[0]))
#endif // _countof

extern std::unordered_map<std::type_index, JSClassID> classes;

bool is_exception(JSContext *ctx, JSValue exp);

extern godot::Variant jsvalue_to_variant(JSValue val);
#endif // __QUICKutils_H__
