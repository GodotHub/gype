#include "support/typescript.hpp"
#include "support/instance_info.hpp"
#include "support/typescript_instance.hpp"
#include "support/typescript_language.hpp"
#include <godot_cpp/classes/dir_access.hpp>
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/os.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/script_editor.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

const char *TypeScript::symbol_mask = "GodotClass";
const char *TypeScript::dist_path = "res://addons/gype/dist/";

bool TypeScript::_editor_can_reload_from_file() {
	return true;
}

void TypeScript::_placeholder_erased(void *p_placeholder) {
}

bool TypeScript::_can_instantiate() const {
	return true;
}

Ref<Script> TypeScript::_get_base_script() const {
	return nullptr;
}

StringName TypeScript::_get_global_name() const {
	return global_class_name;
}

bool TypeScript::_inherits_script(const Ref<Script> &p_script) const {
	String base1 = static_cast<Ref<TypeScript>>(p_script)->global_class_name;
	String base2 = this->base_class_name;
	return base1 == base2;
}

StringName TypeScript::_get_instance_base_type() const {
	complie(false);
	return base_class_name;
}

void *TypeScript::_instance_create(Object *p_for_object) const {
	String path = get_path().replace("res://", dist_path).replace(".ts", ".js");
	Ref<TypeScript> script = ResourceLoader::get_singleton()->load(path);
	return internal::gdextension_interface_script_instance_create3(&InstanceInfo, memnew(TypeScriptInstance(p_for_object, script.ptr(), false)));
}

void *TypeScript::_placeholder_instance_create(Object *p_for_object) const {
	return NULL;
}

bool TypeScript::_instance_has(Object *p_object) const {
	return instances.has(p_object->get_instance_id());
}

bool TypeScript::_has_source_code() const {
	return !source_code.is_empty();
}

String TypeScript::_get_source_code() const {
	return source_code;
}

String TypeScript::get_dist_source_code() const {
	return dist_source_code;
}

void TypeScript::analyze() const {
	is_tool = false;
	String path = get_path();
	if (path != "" && !path.begins_with(dist_path)) {
		String code = _get_source_code();
		std::string origin_string = code.ascii().get_data();
		const char *c_code = origin_string.c_str();
		TSTree *tree = ts_parser_parse_string(parser, NULL, c_code, strlen(c_code));
		uint32_t error_offset;
		TSQueryError error;
		const char *query_string = R"xxx(
			(export_statement 
				(decorator)* @decorator.name
				(class_declaration
					name: (type_identifier) @class.name
					(class_heritage (extends_clause (identifier) @base.name))?
				))
				(#eq? @decorator.name "GodotClass")
		)xxx";
		TSQuery *query = ts_query_new(lang, query_string, strlen(query_string), &error_offset, &error);
		if (!query)
			return;
		TSQueryCursor *cursor = ts_query_cursor_new();
		ts_query_cursor_exec(cursor, query, ts_tree_root_node(tree));
		TSQueryMatch match;
		while (ts_query_cursor_next_match(cursor, &match)) {
			uint32_t i = -1;
			while (ts_query_cursor_next_capture(cursor, &match, &i)) {
				TSQueryCapture capture = match.captures[i];
				TSNode node = capture.node;
				char content[64] = {};
				memcpy(content, c_code + ts_node_start_byte(node), ts_node_end_byte(node) - ts_node_start_byte(node));
				uint32_t name_len;
				const char *name = ts_query_capture_name_for_id(query, capture.index, &name_len);
				if (strcmp(name, "base.name") == 0) {
					base_class_name = content;
				} else if (strcmp(name, "class.name") == 0) {
					global_class_name = content;
				} else if (strcmp(name, "decorator.name") == 0 && strcmp(content, "Tool") == 0) {
					is_tool = true;
				}
			}
		}
	}
}

void TypeScript::complie(bool force) const {
	int exit_code = 0;
	if (dirty && Engine::get_singleton()->is_editor_hint()) {
		if (force)
			exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json", "--force" });
		else
			exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json" });
		ERR_FAIL_COND_EDMSG(exit_code == -1, "Error executing tsc.");
	}
	analyze();
	dirty = false;
}

void TypeScript::_set_source_code(const String &p_code) {
	source_code = p_code;
	dirty = true;
}

void TypeScript::remove_dist() {
	Ref<DirAccess> dir = DirAccess::open(dist_path);
	Error err = dir->get_open_error();
	ERR_FAIL_COND(err != OK);
	remove_dist_internal(dir->get_current_dir());
}

void TypeScript::remove_dist_internal(const String &path) {
	Ref<DirAccess> dir = DirAccess::open(path);
	Error err = dir->list_dir_begin();
	ERR_FAIL_COND(err != OK);
	String file_path;
	while ((file_path = dir->get_next()) != "") {
		if (dir->current_is_dir()) {
			remove_dist_internal(dir->get_current_dir() + "/" + file_path);
		}
		dir->remove(file_path);
	}
}

Error TypeScript::_reload(bool p_keep_state) {
	_set_source_code(source_code);
	return OK;
}

TypedArray<Dictionary> TypeScript::_get_documentation() const {
	return {};
}

String TypeScript::_get_class_icon_path() const {
	return "";
}

bool TypeScript::_has_method(const StringName &p_method) const {
	return false;
}

bool TypeScript::_has_static_method(const StringName &p_method) const {
	return false;
}

Variant TypeScript::_get_script_method_argument_count(const StringName &p_method) const {
	return Variant();
}

Dictionary TypeScript::_get_method_info(const StringName &p_method) const {
	return {};
}

bool TypeScript::_is_tool() const {
	return is_tool;
}

bool TypeScript::_is_valid() const {
	return true;
}

bool TypeScript::_is_abstract() const {
	return false;
}

ScriptLanguage *TypeScript::_get_language() const {
	return TypeScriptLanguage::get_singleton();
}

bool TypeScript::_has_script_signal(const StringName &p_signal) const {
	return false;
}

TypedArray<Dictionary> TypeScript::_get_script_signal_list() const {
	return {};
}

bool TypeScript::_has_property_default_value(const StringName &p_property) const {
	return false;
}

Variant TypeScript::_get_property_default_value(const StringName &p_property) const {
	return Variant();
}

void TypeScript::_update_exports() {
}

TypedArray<Dictionary> TypeScript::_get_script_method_list() const {
	return {};
}

TypedArray<Dictionary> TypeScript::_get_script_property_list() const {
	return {};
}

int32_t TypeScript::_get_member_line(const StringName &p_member) const {
	return 0;
}

Dictionary TypeScript::_get_constants() const {
	return {};
}

TypedArray<StringName> TypeScript::_get_members() const {
	return {};
}

bool TypeScript::_is_placeholder_fallback_enabled() const {
	return false;
}

Variant TypeScript::_get_rpc_config() const {
	return Variant();
}

godot::TypeScript::~TypeScript() {
}
