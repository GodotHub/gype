#include "support/typescript_saver.hpp"
#include "support/typescript.hpp"
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/resource_saver.hpp>
#include <godot_cpp/classes/resource_uid.hpp>


using namespace godot;

TypeScriptSaver *TypeScriptSaver::singleton;

TypeScriptSaver *TypeScriptSaver::get_singleton() {
	if (singleton) {
		return singleton;
	}
	singleton = memnew(TypeScriptSaver);
	if (likely(singleton)) {
		ClassDB::_register_engine_singleton(TypeScriptSaver::get_class_static(), singleton);
	}
	return singleton;
}

Error TypeScriptSaver::_save(const Ref<Resource> &p_resource, const String &p_path, uint32_t p_flags) {
	Ref<TypeScript> script = p_resource;
	Ref<FileAccess> file = FileAccess::open(p_path, FileAccess::ModeFlags::WRITE);
	String source_code = script->_get_source_code();
	if (source_code != "") {
		file->store_string(source_code);
	}
	file->close();
	script->complie(false);
	return Error::OK;
}

Error TypeScriptSaver::_set_uid(const String &p_path, int64_t p_uid) {
	ResourceUID::get_singleton()->set_id(p_uid, p_path);
	return OK;
}

bool TypeScriptSaver::_recognize(const Ref<Resource> &p_resource) const {
	return true;
}

PackedStringArray TypeScriptSaver::_get_recognized_extensions(const Ref<Resource> &p_resource) const {
	PackedStringArray ret = PackedStringArray();
	ret.append("ts");
	ret.append("js");
	return ret;
}

bool TypeScriptSaver::_recognize_path(const Ref<Resource> &p_resource, const String &p_path) const {
	return p_path.ends_with(".js") || p_path.ends_with(".ts");
}

godot::TypeScriptSaver::~TypeScriptSaver() {
	if (singleton == this) {
		ClassDB::_unregister_engine_singleton(TypeScriptSaver::get_class_static());
		singleton = nullptr;
	}
}
