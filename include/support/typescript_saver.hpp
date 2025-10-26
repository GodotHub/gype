#ifndef __JAVASCRIPT_SAVER_H__
#define __JAVASCRIPT_SAVER_H__

#include "support/typescript.hpp"
#include <godot_cpp/classes/resource_format_saver.hpp>

namespace godot {

class Variant;

class TypeScriptSaver : public ResourceFormatSaver {
	GDCLASS(TypeScriptSaver, ResourceFormatSaver)

	friend class TypeScript;

	static TypeScriptSaver *singleton;

public:
	static TypeScriptSaver *get_singleton();
	Error _save(const Ref<Resource> &p_resource, const String &p_path, uint32_t p_flags);
	Error _set_uid(const String &p_path, int64_t p_uid);
	bool _recognize(const Ref<Resource> &p_resource) const;
	PackedStringArray _get_recognized_extensions(const Ref<Resource> &p_resource) const;
	bool _recognize_path(const Ref<Resource> &p_resource, const String &p_path) const;
	~TypeScriptSaver();

protected:
	static void _bind_methods() {}
};
} // namespace godot

#endif // __JAVASCRIPT_SAVER_H__