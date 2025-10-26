#include "support/typescript_language.hpp"
#include "utils/str_helper.hpp"
#include "support/typescript.hpp"
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/script_editor.hpp>
#include <godot_cpp/variant/callable_method_pointer.hpp>

using namespace godot;

TypeScriptLanguage *TypeScriptLanguage::singleton;

TypeScriptLanguage *TypeScriptLanguage::get_singleton() {
	if (singleton) {
		return singleton;
	}
	singleton = memnew(TypeScriptLanguage);
	if (likely(singleton)) {
		ClassDB::_register_engine_singleton(TypeScriptLanguage::get_class_static(), singleton);
	}
	return singleton;
}

String TypeScriptLanguage::_get_name() const {
	return "TypeScript";
}

void TypeScriptLanguage::_init() {
}

String TypeScriptLanguage::_get_type() const {
	return "TypeScript";
}

String TypeScriptLanguage::_get_extension() const {
	return "ts";
}

void TypeScriptLanguage::_finish() {
}

PackedStringArray TypeScriptLanguage::_get_reserved_words() const {
	return PackedStringArray();
}

bool TypeScriptLanguage::_is_control_flow_keyword(const String &p_keyword) const {
	return false;
}

PackedStringArray TypeScriptLanguage::_get_comment_delimiters() const {
	return PackedStringArray();
}

PackedStringArray TypeScriptLanguage::_get_doc_comment_delimiters() const {
	return PackedStringArray();
}

PackedStringArray TypeScriptLanguage::_get_string_delimiters() const {
	return PackedStringArray();
}

Ref<Script> TypeScriptLanguage::_make_template(const String &p_template, const String &p_class_name, const String &p_base_class_name) const {
	Ref<TypeScript> script;
	script.instantiate();
	const char *class_name = to_chars(p_class_name);
	const char *base_class_name = to_chars(p_base_class_name);
	char *code = new char[1024];
	sprintf(code, R"xxx(import { %s } from "@godot/classes/%s";
import { GodotClass } from "@godot/core/class_defined";

@GodotClass
export class %s extends %s {
	public _ready(): void {

	}

	public _process(delta: number): void {

	}
}
	)xxx",
			base_class_name, camelToSnake(base_class_name).c_str(), class_name, base_class_name);
	script->source_code = code;
	return script;
}

TypedArray<Dictionary> TypeScriptLanguage::_get_built_in_templates(const StringName &p_object) const {
	TypedArray<Dictionary> arr;
	return arr;
}

bool TypeScriptLanguage::_is_using_templates() {
	return false;
}

Dictionary TypeScriptLanguage::_validate(const String &p_script, const String &p_path, bool p_validate_functions, bool p_validate_errors, bool p_validate_warnings, bool p_validate_safe_lines) const {
	Dictionary validation;
	validation["valid"] = true;
	return validation;
}

String TypeScriptLanguage::_validate_path(const String &p_path) const {
	return "";
}

Object *TypeScriptLanguage::_create_script() const {
	TypeScript *script = memnew(TypeScript);
	return script;
}

bool TypeScriptLanguage::_has_named_classes() const {
	return true;
}

bool TypeScriptLanguage::_supports_builtin_mode() const {
	return false;
}

bool TypeScriptLanguage::_supports_documentation() const {
	return false;
}

bool TypeScriptLanguage::_can_inherit_from_file() const {
	return true;
}

int32_t TypeScriptLanguage::_find_function(const String &p_function, const String &p_code) const {
	return 0;
}

String TypeScriptLanguage::_make_function(const String &p_class_name, const String &p_function_name, const PackedStringArray &p_function_args) const {
	return String();
}

bool TypeScriptLanguage::_can_make_function() const {
	return false;
}

Error TypeScriptLanguage::_open_in_external_editor(const Ref<Script> &p_script, int32_t p_line, int32_t p_column) {
	return Error();
}

bool TypeScriptLanguage::_overrides_external_editor() {
	return false;
}

ScriptLanguage::ScriptNameCasing TypeScriptLanguage::_preferred_file_name_casing() const {
	return ScriptLanguage::SCRIPT_NAME_CASING_SNAKE_CASE;
}

Dictionary TypeScriptLanguage::_complete_code(const String &p_code, const String &p_path, Object *p_owner) const {
	return Dictionary();
}

Dictionary TypeScriptLanguage::_lookup_code(const String &p_code, const String &p_symbol, const String &p_path, Object *p_owner) const {
	return Dictionary();
}

String TypeScriptLanguage::_auto_indent_code(const String &p_code, int32_t p_from_line, int32_t p_to_line) const {
	return String();
}

void TypeScriptLanguage::_add_global_constant(const StringName &p_name, const Variant &p_value) {
}

void TypeScriptLanguage::_add_named_global_constant(const StringName &p_name, const Variant &p_value) {
}

void TypeScriptLanguage::_remove_named_global_constant(const StringName &p_name) {
}

void TypeScriptLanguage::_thread_enter() {
}

void TypeScriptLanguage::_thread_exit() {
}

String TypeScriptLanguage::_debug_get_error() const {
	return "";
}

int32_t TypeScriptLanguage::_debug_get_stack_level_count() const {
	return 0;
}

int32_t TypeScriptLanguage::_debug_get_stack_level_line(int32_t p_level) const {
	return 0;
}

String TypeScriptLanguage::_debug_get_stack_level_function(int32_t p_level) const {
	return "";
}

String TypeScriptLanguage::_debug_get_stack_level_source(int32_t p_level) const {
	return "";
}

Dictionary TypeScriptLanguage::_debug_get_stack_level_locals(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth) {
	return {};
}

Dictionary TypeScriptLanguage::_debug_get_stack_level_members(int32_t p_level, int32_t p_max_subitems, int32_t p_max_depth) {
	return {};
}

void *TypeScriptLanguage::_debug_get_stack_level_instance(int32_t p_level) {
	return nullptr;
}

Dictionary TypeScriptLanguage::_debug_get_globals(int32_t p_max_subitems, int32_t p_max_depth) {
	return {};
}

String TypeScriptLanguage::_debug_parse_stack_level_expression(int32_t p_level, const String &p_expression, int32_t p_max_subitems, int32_t p_max_depth) {
	return "";
}

TypedArray<Dictionary> TypeScriptLanguage::_debug_get_current_stack_info() {
	return TypedArray<Dictionary>();
}

void TypeScriptLanguage::_reload_all_scripts() {
}

void TypeScriptLanguage::_reload_tool_script(const Ref<Script> &p_script, bool p_soft_reload) {
}

PackedStringArray TypeScriptLanguage::_get_recognized_extensions() const {
	PackedStringArray ret = PackedStringArray();
	ret.append("ts");
	ret.append("js");
	return ret;
}

TypedArray<Dictionary> TypeScriptLanguage::_get_public_functions() const {
	return TypedArray<Dictionary>();
}

Dictionary TypeScriptLanguage::_get_public_constants() const {
	return {};
}

TypedArray<Dictionary> TypeScriptLanguage::_get_public_annotations() const {
	return TypedArray<Dictionary>();
}

void TypeScriptLanguage::_profiling_start() {
}

void TypeScriptLanguage::_profiling_stop() {
}

void TypeScriptLanguage::_profiling_set_save_native_calls(bool p_enable) {
}

int32_t TypeScriptLanguage::_profiling_get_accumulated_data(ScriptLanguageExtensionProfilingInfo *p_info_array, int32_t p_info_max) {
	return 0;
}

int32_t TypeScriptLanguage::_profiling_get_frame_data(ScriptLanguageExtensionProfilingInfo *p_info_array, int32_t p_info_max) {
	return 0;
}

void TypeScriptLanguage::_frame() {
}

bool TypeScriptLanguage::_handles_global_class_type(const String &p_type) const {
	return p_type == "TypeScript";
}

Dictionary TypeScriptLanguage::_get_global_class_name(const String &p_path) const {
	Dictionary dict;
	return dict;
}

TypedArray<TypeScript> godot::TypeScriptLanguage::get_scripts() {
	TypedArray<TypeScript> r_arr;
	HashSet<Ref<TypeScript>>::Iterator it = TypeScriptLanguage::get_singleton()->scripts.begin();
	while (it) {
		r_arr.append(it->ptr());
		++it;
	}
	return r_arr;
}

TypeScriptLanguage::~TypeScriptLanguage() {
	if (singleton == this) {
		ClassDB::_unregister_engine_singleton(TypeScriptLanguage::get_class_static());
		singleton = nullptr;
	}
}
