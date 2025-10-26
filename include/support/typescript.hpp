#ifndef __TYPESCRIPT_H__
#define __TYPESCRIPT_H__

#include "support/typescript_instance.hpp"
#include "support/typescript_language.hpp"
#include "support/typescript_loader.hpp"
#include "support/typescript_saver.hpp"
#include "tree_sitter/api.h"
#include "typescript/tree_sitter/tree-sitter-typescript.h"
#include <godot_cpp/classes/script_extension.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/hash_set.hpp>

namespace godot {

class TypeScriptInstance;
class TypeScript;
class Variant;
class Object;
class ScriptExtension;

class TypeScript : public ScriptExtension {
	GDCLASS(TypeScript, ScriptExtension)

	friend class TypeScriptLanguage;
	friend class TypeScriptSaver;
	friend class TypeScriptLoader;
	friend class TypeScriptInstance;
	friend class PlaceholderJavaScriptInstance;

	TSParser *parser;
	const TSLanguage *lang;

	String source_code;
	String dist_source_code;
	TypeScript *baseScript;
	mutable String global_class_name;
	mutable String base_class_name;
	mutable bool is_tool = false;
	mutable bool dirty = true;

	HashSet<int64_t> instances;

public:
	static const char *dist_path;
	static const char *symbol_mask;

	bool _editor_can_reload_from_file();
	void _placeholder_erased(void *p_placeholder);
	bool _can_instantiate() const;
	Ref<Script> _get_base_script() const;
	StringName _get_global_name() const;
	bool _inherits_script(const Ref<Script> &p_script) const;
	StringName _get_instance_base_type() const;
	void *_instance_create(Object *p_for_object) const;
	void *_placeholder_instance_create(Object *p_for_object) const;
	bool _instance_has(Object *p_object) const;
	bool _has_source_code() const;
	String _get_source_code() const;
	void _set_source_code(const String &p_code);
	Error _reload(bool p_keep_state);
	void update_cur_class();
	TypedArray<Dictionary> _get_documentation() const;
	String _get_class_icon_path() const;
	bool _has_method(const StringName &p_method) const;
	bool _has_static_method(const StringName &p_method) const;
	Variant _get_script_method_argument_count(const StringName &p_method) const;
	Dictionary _get_method_info(const StringName &p_method) const;
	bool _is_tool() const;
	bool _is_valid() const;
	bool _is_abstract() const;
	ScriptLanguage *_get_language() const;
	bool _has_script_signal(const StringName &p_signal) const;
	TypedArray<Dictionary> _get_script_signal_list() const;
	bool _has_property_default_value(const StringName &p_property) const;
	Variant _get_property_default_value(const StringName &p_property) const;
	void _update_exports();
	TypedArray<Dictionary> _get_script_method_list() const;
	TypedArray<Dictionary> _get_script_property_list() const;
	int32_t _get_member_line(const StringName &p_member) const;
	Dictionary _get_constants() const;
	TypedArray<StringName> _get_members() const;
	bool _is_placeholder_fallback_enabled() const;
	Variant _get_rpc_config() const;

	TypeScript() {
		parser = ts_parser_new();
		lang = tree_sitter_typescript();
		ts_parser_set_language(parser, lang);
	}
	~TypeScript();

protected:
	static void _bind_methods() {}

private:
	void remove_dist();
	void remove_dist_internal(const String &path);
	String get_dist_source_code() const;
	void complie(bool force = false) const;
	void analyze() const;
};

} // namespace godot

#endif // __TYPESCRIPT_H__