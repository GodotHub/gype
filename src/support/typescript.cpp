#include "support/typescript.hpp"

#include "godot_cpp/classes/expression.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
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
#include <format>

using namespace godot;

const char *TypeScript::class_symbol_mask = "GodotClass";
const char *TypeScript::signal_symbol_mask = "GodotSignal";
const char *TypeScript::export_symbol_mask = "GodotExport";
const char *TypeScript::tool_symbol_mask = "GodotTool";
const char *TypeScript::dist_path = "res://addons/gype/dist/";


bool TypeScript::_editor_can_reload_from_file() {
	return true;
}

void TypeScript::_placeholder_erased(void *p_placeholder) {
	if (p_placeholder) {
		script_placeholders.erase(p_placeholder);
	}
}

bool TypeScript::_can_instantiate() const {
	return godot_class_data;
}

Ref<Script> TypeScript::_get_base_script() const {
	this->analyze();
	// if (!godot_class_data->base_class_name.is_empty() && !ClassDB::class_exists(godot_class_data->base_class_name)) {
	// 	if (dependencies.has(godot_class_data->base_class_name)) {
	// 		StringName base_path = dependencies[godot_class_data->base_class_name];
	// 		return ResourceLoader::get_singleton()->load(base_path);
	// 	}
	// }
	// return nullptr; // 基类是内置类或未找到
	return base_script;
}

StringName TypeScript::_get_global_name() const {
	if (!godot_class_data) return "";
	return godot_class_data->class_name;
}

bool TypeScript::_inherits_script(const Ref<Script> &p_script) const {
	if (p_script.is_null()) {
		return false;
	}
	if (p_script.ptr() == this) {
		return true;
	}

	Ref<Script> current_base = _get_base_script();
	while (current_base.is_valid()) {
		if (current_base == p_script) {
			return true;
		}
		current_base = current_base->get_base_script();
	}

	return false;
}

StringName TypeScript::_get_instance_base_type() const {
	this->analyze();
	if (!godot_class_data) return "";
	return godot_class_data->base_class_name;
}

void *TypeScript::_instance_create(Object *p_for_object) const {
	TypeScriptInstance *instance = memnew(TypeScriptInstance(p_for_object, Ref<TypeScript>(this), false));
	this->script_instances.insert(instance);
	return internal::gdextension_interface_script_instance_create3(&InstanceInfo, instance);
}

void *TypeScript::_placeholder_instance_create(Object *p_for_object) const {
	// GDExtensionScriptInstancePtr instance = internal::gdextension_interface_placeholder_script_instance_create(TypeScriptLanguage::get_singleton()->_owner, this->_owner, p_for_object->_owner);
	// script_placeholders.insert(instance);
	// return instance;
	TypeScriptInstance *instance = memnew(TypeScriptInstance(p_for_object, Ref<TypeScript>(this), true));
	return internal::gdextension_interface_script_instance_create3(&InstanceInfo, instance);
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
	String path = get_path().replace("res://", dist_path).replace(".ts", ".js");
	if (FileAccess::file_exists(path)) {
		Ref<FileAccess> file = FileAccess::open(path, FileAccess::ModeFlags::READ);
		return file->get_as_text();
	}
	return "";
}

static Variant::Type type_by_name(const StringName &prop_type, const StringName &prop_value) {
	if (prop_type == StringName("number")) {
		if (prop_value.is_empty()) {
			return Variant::Type::INT;
		} else {
			if (prop_value.contains(".")) {
				return Variant::Type::FLOAT;
			} else {
				return Variant::Type::INT;
			}
		}
	} else if (prop_type == StringName("string") || prop_type == StringName("GDString")) {
		return Variant::Type::STRING;
	} else if (prop_type == StringName("StringName")) {
		return Variant::Type::STRING_NAME;
	} else if (prop_type == StringName("Array") ||
		(prop_type.contains(StringName("Array")) && prop_type.contains("<") && prop_type.contains(">")) ||
		prop_type == StringName("GDArray")) {
		return Variant::Type::ARRAY;
	} else if (prop_type == StringName("boolean")) {
		return Variant::Type::BOOL;
	} else if (prop_type == StringName("Vector2")) {
		return Variant::Type::VECTOR2;
	} else if (prop_type == StringName("Vector2i")) {
		return Variant::Type::VECTOR2I;
	} else if (prop_type == StringName("Vector3")) {
		return Variant::Type::VECTOR3;
	} else if (prop_type == StringName("Vector3i")) {
		return Variant::Type::VECTOR3I;
	} else if (prop_type == StringName("Vector4")) {
		return Variant::Type::VECTOR4;
	} else if (prop_type == StringName("Vector4i")) {
		return Variant::Type::VECTOR4I;
	} else if (prop_type == StringName("Rect2")) {
		return Variant::Type::RECT2;
	} else if (prop_type == StringName("Rect2i")) {
		return Variant::Type::RECT2I;
	} else if (prop_type == StringName("Color")) {
		return Variant::Type::COLOR;
	} else if (prop_type == StringName("Transform2D")) {
		return Variant::Type::TRANSFORM2D;
	} else if (prop_type == StringName("Transform3D")) {
		return Variant::Type::TRANSFORM3D;
	} else if (prop_type == StringName("Plane")) {
		return Variant::Type::PLANE;
	} else if (prop_type == StringName("Quaternion")) {
		return Variant::Type::QUATERNION;
	} else if (prop_type == StringName("AABB")) {
		return Variant::Type::AABB;
	} else if (prop_type == StringName("Basis")) {
		return Variant::Type::BASIS;
	} else if (prop_type == StringName("Projection")) {
		return Variant::Type::PROJECTION;
	} else if (prop_type == StringName("Dictionary")) {
		return Variant::Type::DICTIONARY;
	} else if (prop_type == StringName("NodePath")) {
		return Variant::Type::NODE_PATH;
	} else if (prop_type == StringName("RID")) {
		return Variant::Type::RID;
	} else if (prop_type == StringName("GodotObject")) {
		return Variant::Type::OBJECT;
	} else if (prop_type == StringName("Callable")) {
		return Variant::Type::CALLABLE;
	} else if (prop_type == StringName("Signal")) {
		return Variant::Type::SIGNAL;
	} else if (prop_type == StringName("PackedByteArray")) {
		return Variant::Type::PACKED_BYTE_ARRAY;
	} else if (prop_type == StringName("PackedInt32Array")) {
		return Variant::Type::PACKED_INT32_ARRAY;
	} else if (prop_type == StringName("PackedInt64Array")) {
		return Variant::Type::PACKED_INT64_ARRAY;
	} else if (prop_type == StringName("PackedFloat32Array")) {
		return Variant::Type::PACKED_FLOAT32_ARRAY;
	} else if (prop_type == StringName("PackedFloat64Array")) {
		return Variant::Type::PACKED_FLOAT64_ARRAY;
	} else if (prop_type == StringName("PackedStringArray")) {
		return Variant::Type::PACKED_STRING_ARRAY;
	} else if (prop_type == StringName("PackedVector2Array")) {
		return Variant::Type::PACKED_VECTOR2_ARRAY;
	} else if (prop_type == StringName("PackedVector3Array")) {
		return Variant::Type::PACKED_VECTOR3_ARRAY;
	} else if (prop_type == StringName("PackedColorArray")) {
		return Variant::Type::PACKED_COLOR_ARRAY;
	} else {
		return Variant::Type::NIL;
	}
}

static Variant execute_expression(String code) {
	Expression *expression = memnew(Expression());
	Error err = expression->parse(code);
	Variant ret;
	if (err == OK) {
		ret = expression->execute();
	}
	memdelete(expression);
	return ret;
}

void TypeScript::analyze() const {
	if (!dirty) {
		return;
	}

	class_data.clear();
	godot_class_data = nullptr;
	dependencies.clear();
	base_script = Ref<TypeScript>();
	interface_scripts.clear();

	String path = get_path();
	if (path.is_empty() || path.begins_with(dist_path)) {
		is_valid = false;
		return;
	}

	String code = _get_source_code();
	if (code.is_empty()) {
		is_valid = false;
		return;
	}

	std::string origin_string(code.utf8());
	const char *c_code = origin_string.c_str();

	TSTree *tree = ts_parser_parse_string(parser, NULL, c_code, origin_string.length());

	const std::string query_string = R"xxx(
	(import_statement
	  (import_clause
        (identifier)? @import.name
	    (named_imports
	      (import_specifier
	       name: (identifier) @import.name
	      )
	    )?
	  )
	  source: (string) @import.path
	)?
	(export_statement ("default") @export.default
	  declaration: (abstract_class_declaration
		name: (type_identifier) @class.name
	    (class_heritage 
	      (extends_clause
  			value: (identifier) @base.name
	      )
	      (implements_clause (type_identifier) @interface.name)?
	    ) @class.abstract
	    body: (class_body
	      (public_field_definition
  			decorator: (decorator (identifier) @decorator.member)?
	        name: (property_identifier) @prop.name
	        type: (type_annotation
	          (type_identifier)? @prop.type
	          (predefined_type)? @prop.type
	        )?
	        value: (_)? @prop.value
	      )?
	      (method_definition
	        name: (property_identifier) @method.name
	        parameters: (formal_parameters) @method.parameter
	      )?
	      (abstract_method_signature
	        name: (property_identifier) @method.name
	        parameters: (formal_parameters) @method.parameter
	      )?
	    )
	  )? @class.body
	)?
	(export_statement ("default") @export.default
	  (decorator (identifier) @decorator.other
		(#not-match? @decorator.other "^(GodotClass)$")
	  )?
	  
	  (class_declaration
		name: (type_identifier) @class.name
	    (class_heritage 
	      (extends_clause
  			value: (identifier) @base.name
	      )
	      (implements_clause (type_identifier) @interface.name)?
	    )
	    body: (class_body
	      (public_field_definition
  			decorator: (decorator (identifier) @decorator.member)?
	        name: (property_identifier) @prop.name
	        type: (type_annotation
	          (type_identifier)? @prop.type
	          (predefined_type)? @prop.type
	        )?
	        value: (_)? @prop.value
	      )?
	      (method_definition
	        name: (property_identifier) @method.name
	        parameters: (formal_parameters) @method.parameter
	      )?
	      (abstract_method_signature
	        name: (property_identifier) @method.name
	        parameters: (formal_parameters) @method.parameter
	      )?
	    )
	  )? @class.body
	)?
	(export_statement
	  declaration: (interface_declaration
	    name: (type_identifier) @class.name
	    (extends_type_clause
	      type: (type_identifier) @base.name
	    )
  		body: (interface_body
	      (property_signature 
      		name: (property_identifier) @prop.name
	        type: (type_annotation) @prop.type
	      )?
	      (method_signature
	        name: (property_identifier) @method.name
	        parameters: (formal_parameters) @method.parameter
	      )?
	    ) @class.body
	  )
	)?
	)xxx";

	uint32_t error_offset;
	TSQueryError error;
	TSQuery *query = ts_query_new(lang, query_string.c_str(), strlen(query_string.c_str()), &error_offset, &error);

	if (!query) {
		ERR_PRINT("Tree-sitter query failed to compile.");
		ts_tree_delete(tree);
		return;
	}

	TSQueryCursor *cursor = ts_query_cursor_new();
	ts_query_cursor_exec(cursor, query, ts_tree_root_node(tree));
	TSQueryMatch match;

	auto get_node_text = [&](TSNode node) -> String {
		uint32_t start = ts_node_start_byte(node);
		uint32_t end = ts_node_end_byte(node);
		return String::utf8(c_code + start, end - start);
	};

	// 循环处理每一个匹配 (一个匹配 = 一个成员，或者一个 @tool 注释)
	while (ts_query_cursor_next_match(cursor, &match)) {
		// 核心改动：为每一个 match 创建一个临时的 captures map
		// 这解决了捕获顺序问题，并让逻辑更清晰
		HashMap<String, String> captures;
		for (uint32_t i = 0; i < match.capture_count; i++) {
			TSQueryCapture capture = match.captures[i];
			uint32_t capture_id = capture.index;
			uint32_t capture_name_length;
			String capture_name = ts_query_capture_name_for_id(query, capture_id, &capture_name_length);
			String content = get_node_text(capture.node);
			captures[capture_name] = content;
		}

		if (captures.has("import.name")) {
			String import_path = captures["import.path"];
			String import_name = captures["import.name"];
			import_path = import_path.remove_char('"').remove_char('\'');
			if (import_path.begins_with("@res")) {
				import_path = import_path.replace("@res/", "res://") + ".ts";
				dependencies[import_name] = import_path;
			}
		}

		StringName class_name;
		if (captures.has("class.name")) {
			class_name = captures["class.name"];
		} else {
			continue;
		}

		if (!this->class_data.has(class_name)) {
			ClassData class_data;
			class_data.class_name = class_name;
			this->class_data[class_name] = class_data;
		}
		ClassData &current_class_data = this->class_data[class_name];

		if (captures.has("export.default")) {
			godot_class_data = &current_class_data;
		}

		if (captures.has("class.abstract")) {
			current_class_data.is_abstract = true;
		}
		if (captures.has("base.name")) {
			current_class_data.base_class_name = captures["base.name"];
		}
		if (captures.has("interface.name")) {
			current_class_data.interfaces.insert(captures["interface.name"]);
		}
		if (captures.has("decorator.other") && captures["decorator.other"].contains(tool_symbol_mask)) {
			current_class_data.is_tool = true;
		}
		if (captures.has("prop.name")) {
			// 这是一个属性成员的匹配
			String prop_name = captures["prop.name"];
			if (captures.has("decorator.member")) {
				String decorator_name = captures["decorator.member"];
				if (decorator_name == export_symbol_mask) {
					PropertyInfo pi;
					pi.name = prop_name;
					pi.class_name = class_name;
					pi.usage = PROPERTY_USAGE_DEFAULT;
					if (captures.has("prop.value")) {
						pi.type = type_by_name(captures["prop.type"], captures["prop.value"]);
						current_class_data.default_value[prop_name] = execute_expression(captures["prop.value"]);
					} else {
						pi.type = type_by_name(captures["prop.type"], "");
					}
					current_class_data.properties[prop_name] = pi;
				} else if (decorator_name == signal_symbol_mask) {
					MethodInfo mi;
					mi.name = prop_name;
					// TODO: 解析信号的参数
					current_class_data.signals[prop_name] = mi;
				}
			}
		}
		if (captures.has("method.name")) {
			// 这是一个方法成员的匹配
			StringName method_name = captures["method.name"];

			if (method_name != StringName("constructor")) {
				MethodInfo mi;
				mi.name = method_name;
				// TODO: 解析参数和返回值

				if (captures.has("method.static")) {
					// 存在 "method.static" 捕获，说明是静态方法
					current_class_data.static_methods[method_name] = mi;
				} else {
					current_class_data.methods[method_name] = mi;
				}
			}
		}
	}
	for (auto &kv : this->class_data) {
		ClassData &class_data = kv.value;
		for (auto &interface : class_data.interfaces) {
			String import_path = dependencies[interface];
			Ref<TypeScript> script = ResourceLoader::get_singleton()->load(import_path);
			interface_scripts.insert(script.ptr());
		}
		if (class_data.base_class_name != "" && dependencies.has(class_data.base_class_name)) {
			String import_path = dependencies[class_data.base_class_name];
			Ref<TypeScript> script = ResourceLoader::get_singleton()->load(import_path);
			base_script = script;
		}
	}
	ts_query_cursor_delete(cursor);
	ts_query_delete(query);
	ts_tree_delete(tree);

	is_valid = true;
	dirty = false;
}

void TypeScript::compile(bool force) {
	ERR_FAIL_COND_EDMSG(!FileAccess::file_exists("res://tsconfig.json"), "tsconfig.json file does not exist.");
	int exit_code = 0;
	if (force) {
		exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json", "--force" });
	} else {
		exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json" });
	}
	ERR_FAIL_COND_EDMSG(exit_code == -1, "error executing tsc.");
}

void TypeScript::compile_module() {
	this->reload();
	auto it = script_instances.begin();
	while (it != script_instances.end()) {
		(*it)->compile_module();
		++it;
	}
}

void TypeScript::_set_source_code(const String &p_code) {
	source_code = p_code;
	dirty = true;
	this->analyze();
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
	String content = FileAccess::get_file_as_string(get_path());
	_set_source_code(content);
	return OK;
}

TypedArray<Dictionary> TypeScript::_get_documentation() const {
	return {};
}

String TypeScript::_get_class_icon_path() const {
	return "";
}

bool TypeScript::_has_method(const StringName &p_method) const {
	this->analyze();
	if (!godot_class_data) return false;
	Ref<TypeScript> base = get_base_script();
	if (godot_class_data->methods.has(p_method) || ClassDB::class_has_method(godot_class_data->base_class_name, p_method, true)) {
		return true;
	} else if (base.is_valid()) {
		return base->_has_method(p_method);
	} else {
		return false;
	}
}

bool TypeScript::_has_static_method(const StringName &p_method) const {
	this->analyze();
	if (!godot_class_data) return false;
	Ref<TypeScript> base = get_base_script();
	if (godot_class_data->static_methods.has(p_method)) {
		return true;
	} else if (base.is_valid()) {
		return base->_has_static_method(p_method);
	} else {
		return false;
	}
}

Variant TypeScript::_get_script_method_argument_count(const StringName &p_method) const {
	this->analyze();
	if (!godot_class_data) return -1;
	Ref<TypeScript> base = get_base_script();
	if (godot_class_data->methods.has(p_method)) {
		return godot_class_data->methods[p_method].arguments.size();
	} else if (base.is_valid()) {
		return base->_get_method_info(p_method);
	} else {
		return Variant();
	}
}

Dictionary TypeScript::_get_method_info(const StringName &p_method) const {
	this->analyze();
	if (!godot_class_data) return Dictionary();
	Ref<TypeScript> base = get_base_script();
	if (godot_class_data->methods.has(p_method)) {
		return godot_class_data->methods[p_method];
	} else if (base.is_valid()) {
		return base->_get_method_info(p_method);
	} else {
		return Dictionary();
	}
}

bool TypeScript::_is_tool() const {
	this->analyze();
	if (!godot_class_data) return false;
	return godot_class_data->is_tool;
}

bool TypeScript::_is_valid() const {
	return this->is_valid;
}

bool TypeScript::_is_abstract() const {
	if (!godot_class_data) return false;
	return godot_class_data->is_abstract;
}

ScriptLanguage *TypeScript::_get_language() const {
	return TypeScriptLanguage::get_singleton();
}

bool TypeScript::_has_script_signal(const StringName &p_signal) const {
	this->analyze();
	if (godot_class_data == nullptr) return false;
	Ref<TypeScript> base = get_base_script();
	if (godot_class_data->signals.has(p_signal)) {
		return true;
	} else if (base.is_valid()) {
		return base->_has_script_signal(p_signal);
	} else {
		return false;
	}
}

TypedArray<Dictionary> TypeScript::_get_script_signal_list() const {
	this->analyze();
	if (godot_class_data == nullptr) return Array();
	TypedArray<Dictionary> list;
	Ref<TypeScript> base = get_base_script();
	if (base.is_valid()) {
		list.append_array(base->get_script_signal_list());
	}
	for (const KeyValue<StringName, MethodInfo> &E : godot_class_data->signals) {
		list.push_back(Dictionary(E.value));
	}
	return list;
}

bool TypeScript::_has_property_default_value(const StringName &p_property) const {
	if (godot_class_data == nullptr) return false;
	return godot_class_data->default_value.has(p_property);
}

Variant TypeScript::_get_property_default_value(const StringName &p_property) const {
	if (godot_class_data == nullptr) return Variant();
	return godot_class_data->default_value[p_property];
}

void TypeScript::_update_exports() {
	this->analyze();
}

TypedArray<Dictionary> TypeScript::_get_script_method_list() const {
	this->analyze();
	if (godot_class_data == nullptr) return Array();
	TypedArray<Dictionary> list;
	Ref<TypeScript> base = get_base_script();
	if (base.is_valid()) {
		list.append_array(base->_get_script_method_list());
	}
	for (const KeyValue<StringName, MethodInfo> &E : godot_class_data->methods) {
		list.push_back(Dictionary(E.value));
	}
	return list;
}

TypedArray<Dictionary> TypeScript::_get_script_property_list() const {
	this->analyze();
	if (godot_class_data == nullptr) return Array();
	TypedArray<Dictionary> list;
	Ref<TypeScript> base = get_base_script();
	if (base.is_valid()) {
		list.append_array(base->_get_script_property_list());
	}
	for (const KeyValue<StringName, PropertyInfo> &E : godot_class_data->properties) {
		list.push_back(Dictionary(E.value));
	}
	return list;
}

int32_t TypeScript::_get_member_line(const StringName &p_member) const {
	return 0;
}

Dictionary TypeScript::_get_constants() const {
	return {};
}

TypedArray<StringName> TypeScript::_get_members() const {
	this->analyze();
	if (godot_class_data == nullptr) return Array();
	TypedArray<StringName> members;
	Ref<TypeScript> base = get_base_script();
	if (base.is_valid()) {
		members.append_array(base->_get_members());
	}
	for (const KeyValue<StringName, PropertyInfo> &E : godot_class_data->properties) {
		members.push_back(E.key);
	}
	for (const KeyValue<StringName, MethodInfo> &E : godot_class_data->methods) {
		members.push_back(E.key);
	}
	return members;
}

bool TypeScript::_is_placeholder_fallback_enabled() const {
	return true;
}

Variant TypeScript::_get_rpc_config() const {
	return Variant();
}

godot::TypeScript::~TypeScript() {
}