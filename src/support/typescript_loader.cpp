#include "support/typescript_loader.hpp"
#include "support/typescript.hpp"
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/resource_uid.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

TypeScriptLoader *TypeScriptLoader::singleton;

TypeScriptLoader *TypeScriptLoader::get_singleton() {
	if (singleton) {
		return singleton;
	}
	singleton = memnew(TypeScriptLoader);
	if (likely(singleton)) {
		ClassDB::_register_engine_singleton(TypeScriptLoader::get_class_static(), singleton);
	}
	return singleton;
}

PackedStringArray TypeScriptLoader::_get_recognized_extensions() const {
	PackedStringArray ret = PackedStringArray();
	ret.append("ts");
	ret.append("js");
	return ret;
}

bool TypeScriptLoader::_recognize_path(const String &p_path, const StringName &p_type) const {
	return p_path.ends_with(".js") || p_path.ends_with(".ts");
}

bool TypeScriptLoader::_handles_type(const StringName &p_type) const {
	return p_type == StringName("Script");
}

String TypeScriptLoader::_get_resource_type(const String &p_path) const {
	if (p_path.ends_with(".js") || p_path.ends_with(".ts")) {
		return "Script";
	} else {
		return "";
	}
}

String TypeScriptLoader::_get_resource_script_class(const String &p_path) const {
	return p_path.get_extension();
}

int64_t TypeScriptLoader::_get_resource_uid(const String &p_path) const {
	return ResourceUID::get_singleton()->text_to_id(p_path);
}

PackedStringArray TypeScriptLoader::_get_dependencies(const String &p_path, bool p_add_types) const {
	return PackedStringArray();
}

Error TypeScriptLoader::_rename_dependencies(const String &p_path, const Dictionary &p_renames) const {
	return OK;
}

bool TypeScriptLoader::_exists(const String &p_path) const {
	return FileAccess::file_exists(p_path);
}

PackedStringArray TypeScriptLoader::_get_classes_used(const String &p_path) const {
	return PackedStringArray();
}

Variant TypeScriptLoader::_load(const String &p_path, const String &p_original_path, bool p_use_sub_threads, int32_t p_cache_mode) const {
	String source_code = FileAccess::get_file_as_string(p_original_path);
	Ref<TypeScript> script = memnew(TypeScript);
	script->source_code = source_code;
	TypeScriptLanguage::get_singleton()->scripts.insert(script);
	return script;
}

TypeScriptLoader::~TypeScriptLoader() {
	if (singleton == this) {
		ClassDB::_unregister_engine_singleton(TypeScriptLoader::get_class_static());
		singleton = nullptr;
	}
}
