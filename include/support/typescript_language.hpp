#ifndef __JAVASCRIPT_LANGUAGE_H__
#define __JAVASCRIPT_LANGUAGE_H__

#include "support/typescript.hpp"
#include "support/typescript_loader.hpp"
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/script_language_extension.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/hash_set.hpp>
#include <godot_cpp/templates/list.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/variant.hpp>

namespace godot {

class Variant;
class Object;

class TypeScriptLanguage : public ScriptLanguageExtension {
	GDCLASS(TypeScriptLanguage, ScriptLanguageExtension)

	static TypeScriptLanguage *singleton;

	HashSet<Ref<TypeScript>> scripts;
	TypedArray<Dictionary> templates;

	friend class TypeScriptLoader;

public:
	static TypeScriptLanguage *get_singleton();
	String _get_name() const;
	void _init();
	String _get_type() const;
	String _get_extension() const;
	void _finish();
	PackedStringArray _get_reserved_words() const;
	bool _is_control_flow_keyword(const String &p_keyword) const;
	PackedStringArray _get_comment_delimiters() const;
	PackedStringArray _get_doc_comment_delimiters() const;
	PackedStringArray _get_string_delimiters() const;
	Ref<Script> _make_template(const String &p_template, const String &p_class_name, const String &p_base_class_name) const;
	TypedArray<Dictionary> _get_built_in_templates(const StringName &p_object) const;
	bool _is_using_templates();
	Dictionary _validate(const String &p_script, const String &p_path, bool p_validate_functions, bool p_validate_errors, bool p_validate_warnings, bool p_validate_safe_lines) const;
	String _validate_path(const String &p_path) const;
	Object *_create_script() const;
	bool _has_named_classes() const;
	bool _supports_builtin_mode() const;
	bool _supports_documentation() const;
	bool _can_inherit_from_file() const;
	int32_t _find_function(const String &p_function, const String &p_code) const;
	String _make_function(const String &p_class_name, const String &p_function_name, const PackedStringArray &p_function_args) const;
	bool _can_make_function() const;
	Error _open_in_external_editor(const Ref<Script> &p_script, int32_t p_line, int32_t p_column);
	bool _overrides_external_editor();
	ScriptLanguage::ScriptNameCasing _preferred_file_name_casing() const;
	Dictionary _complete_code(const String &p_code, const String &p_path, Object *p_owner) const;
	Dictionary _lookup_code(const String &p_code, const String &p_symbol, const String &p_path, Object *p_owner) const;
	String _auto_indent_code(const String &p_code, int32_t p_from_line, int32_t p_to_line) const;
	void _add_global_constant(const StringName &p_name, const Variant &p_value);
	void _add_named_global_constant(const StringName &p_name, const Variant &p_value);
	void _remove_named_global_constant(const StringName &p_name);
	void _thread_enter();
	void _thread_exit();
	String _debug_get_error() const;
	int32_t _debug_get_stack_level_count() const;
	int32_t _debug_get_stack_level_line(int32_t p_level) const;
	String _debug_get_stack_level_function(int32_t p_level) const;
	String _debug_get_stack_level_source(int32_t p_level) const;
	Dictionary _debug_get_stack_level_locals(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth);
	Dictionary _debug_get_stack_level_members(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth);
	void *_debug_get_stack_level_instance(int32_t p_level);
	Dictionary _debug_get_globals(int32_t p_max_subitems, int32_t p_max_depth);
	String _debug_parse_stack_level_expression(int32_t p_level, const String &p_expression, int32_t p_max_subitems, int32_t p_max_depth);
	TypedArray<Dictionary> _debug_get_current_stack_info();
	void _reload_all_scripts();
	void _reload_tool_script(const Ref<Script> &p_script, bool p_soft_reload);
	PackedStringArray _get_recognized_extensions() const;
	TypedArray<Dictionary> _get_public_functions() const;
	Dictionary _get_public_constants() const;
	TypedArray<Dictionary> _get_public_annotations() const;
	void _profiling_start();
	void _profiling_stop();
	void _profiling_set_save_native_calls(bool p_enable);
	int32_t _profiling_get_accumulated_data(ScriptLanguageExtensionProfilingInfo *p_info_array, int32_t p_info_max);
	int32_t _profiling_get_frame_data(ScriptLanguageExtensionProfilingInfo *p_info_array, int32_t p_info_max);
	void _frame();
	bool _handles_global_class_type(const String &p_type) const;
	Dictionary _get_global_class_name(const String &p_path) const;
	static TypedArray<TypeScript> get_scripts();

	~TypeScriptLanguage();

protected:
	static void _bind_methods() {
		ClassDB::bind_static_method("TypeScriptLanguage", D_METHOD("get_scripts"), &TypeScriptLanguage::get_scripts);
	}
};
} // namespace godot

#endif // __JAVASCRIPT_LANGUAGE_H__