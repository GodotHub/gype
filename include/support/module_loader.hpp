#ifndef __MODULE_LOADER_H__
#define __MODULE_LOADER_H__

#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/hash_set.hpp>
#include <godot_cpp/variant/string.hpp>

typedef struct JSModuleDef JSModuleDef;
typedef struct JSContext JSContext;
typedef void (*REGISTER_FUNC)();

extern inline godot::HashMap<godot::String, REGISTER_FUNC> *register_func_map() {
	static godot::HashMap<godot::String, REGISTER_FUNC> _register_func_map;
	return &_register_func_map;
}
extern inline godot::HashSet<godot::String> *registered_classes() {
	static godot::HashSet<godot::String> _registered_classes;
	return &_registered_classes;
}

JSModuleDef *module_loader(JSContext *ctx, const char *module_name, void *opaque);
#endif // __MODULE_LOADER_H__