#ifndef __QUICKutils_H__
#define __QUICKutils_H__

#include "register/object_proxy.hpp"
#include "utils/str_helper.hpp"
#include "utils/variant_helper.hpp"
#include <quickjs.h>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <string>
#include <typeindex>
#include <unordered_map>

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof((array)[0]))
#endif // _countof

#define PROXY_GET_INSTANCE(js_proxy, wrapped_type, member_type) \
	wrapped_type *instance = reinterpret_cast<ObjectProxy<wrapped_type, member_type> *>(JS_GetOpaque(js_proxy, proxies[typeid(ObjectProxy<wrapped_type, member_type>)]))->get_object();

// extern std::unordered_map<std::type_index, JSClassID> classes;
// extern std::unordered_map<std::type_index, JSClassID> proxies;
// extern std::unordered_map<JSClassID, std::type_index> classes_by_id;

extern godot::HashMap<godot::StringName, JSClassID> classes;
extern godot::HashMap<godot::StringName, JSClassID> proxies;

extern bool is_exception(JSContext *ctx, JSValue exp);
extern void print_exception(JSContext *ctx);
extern godot::Variant jsvalue_to_variant(JSValue val);

#endif // __QUICKutils_H__
