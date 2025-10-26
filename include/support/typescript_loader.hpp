#ifndef __JAVASCRIPT_LOADER_H__
#define __JAVASCRIPT_LOADER_H__

#include "support/typescript.hpp"
#include <godot_cpp/classes/resource_format_loader.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/variant/variant.hpp>

namespace godot {

class Variant;
class Object;

class TypeScriptLoader : public ResourceFormatLoader {
	GDCLASS(TypeScriptLoader, ResourceFormatLoader)
	static TypeScriptLoader *singleton;
	HashMap<const String, TypeScript *> scripts;

public:
	static TypeScriptLoader *get_singleton();
	PackedStringArray _get_recognized_extensions() const;
	bool _recognize_path(const String &p_path, const StringName &p_type) const;
	bool _handles_type(const StringName &p_type) const;
	String _get_resource_type(const String &p_path) const;
	String _get_resource_script_class(const String &p_path) const;
	int64_t _get_resource_uid(const String &p_path) const;
	PackedStringArray _get_dependencies(const String &p_path, bool p_add_types) const;
	Error _rename_dependencies(const String &p_path, const Dictionary &p_renames) const;
	bool _exists(const String &p_path) const;
	PackedStringArray _get_classes_used(const String &p_path) const;
	Variant _load(const String &p_path, const String &p_original_path, bool p_use_sub_threads, int32_t p_cache_mode) const;
	~TypeScriptLoader();

protected:
	static void _bind_methods() {}
};
} // namespace godot

#endif // __JAVASCRIPT_LOADER_H__