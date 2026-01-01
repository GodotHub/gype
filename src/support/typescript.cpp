#include "support/typescript.hpp"

#include "godot_cpp/classes/expression.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "support/instance_info.hpp"
#include "support/typescript_instance.hpp"
#include "support/typescript_language.hpp"
#include "utils/quickjs_helper.hpp"

#include <tree.h>

#include <format>
#include <functional>
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

const char *TypeScript::class_symbol_mask = "GodotClass";
const char *TypeScript::signal_symbol_mask = "GodotSignal";
const char *TypeScript::export_symbol_mask = "GodotExport";
const char *TypeScript::tool_symbol_mask = "GodotTool";
const char *TypeScript::dist_path = "res://addons/gype/dist/";

static String get_node_text(const char *p_source_code, TSNode node) {
	uint32_t start = ts_node_start_byte(node);
	uint32_t end = ts_node_end_byte(node);
	return String::utf8(p_source_code + start, end - start);
}

bool TypeScript::_editor_can_reload_from_file() {
	return true;
}

void TypeScript::_placeholder_erased(void *p_placeholder) {
	if (p_placeholder) {
		script_placeholders.erase(static_cast<TypeScriptInstance *>(p_placeholder));
	}
}

bool TypeScript::_can_instantiate() const {
	this->analyze();
	return is_valid && godot_class_data;
}

Ref<Script> TypeScript::_get_base_script() const {
	this->analyze();
	if (base_script_path.is_empty() || base_script_path.begins_with("@godot/classes")) {
		return nullptr;
	}
	return ResourceLoader::get_singleton()->load(base_script_path);
}

StringName TypeScript::_get_global_name() const {
	this->analyze();
	if (!godot_class_data) {
		return "";
	}
	return godot_class_data->class_name;
}

bool TypeScript::_inherits_script(const Ref<Script> &p_script) const {
	this->analyze();
	if (p_script.is_null()) {
		return false;
	}
	if (p_script.ptr() == this) {
		return true;
	}

	Ref<Script> current_base = get_base_script();
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
	if (!godot_class_data) {
		return "";
	}
	return godot_class_data->base_class_name;
}

void *TypeScript::_instance_create(Object *p_for_object) const {
	TypeScriptInstance *instance = memnew(TypeScriptInstance(p_for_object, const_cast<TypeScript *>(this), false));
	this->script_instances.insert(instance);
	return internal::gdextension_interface_script_instance_create3(&InstanceInfo, instance);
}

void *TypeScript::_placeholder_instance_create(Object *p_for_object) const {
	return internal::gdextension_interface_placeholder_script_instance_create(TypeScriptLanguage::get_singleton(), const_cast<TypeScript *>(this), p_for_object->_owner);
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

static Variant::Type type_by_name(const StringName &prop_type, const StringName &prop_value = "") {
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
	} else if (JS_IsRegisteredClass(js_runtime(), classes[prop_type])) {
		return Variant::Type::OBJECT;
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

TypeParseResult TypeScript::parse_type_members(TSNode p_type_declaration_node, const char *p_source_code) const {
	uint32_t error_offset;
	TSQueryError error;
	static const TSQuery *p_body_query = ts_query_new(lang, query_type_body, strlen(query_type_body), &error_offset, &error);

	TypeParseResult result; // constants 默认为空 Array

	if (ts_node_is_null(p_type_declaration_node) || !p_body_query) {
		return result;
	}

	TSNode body_node = ts_node_child_by_field_name(
			p_type_declaration_node,
			"value",
			5);

	if (ts_node_is_null(body_node)) {
		return result;
	}

	TSQueryCursor *cursor = ts_query_cursor_new();
	ts_query_cursor_exec(cursor, p_body_query, body_node);

	TSQueryMatch match;

	HashSet<String> seen_values;

	Vector<String> ordered_hints;

	while (ts_query_cursor_next_match(cursor, &match)) {
		for (uint32_t i = 0; i < match.capture_count; i++) {
			const TSQueryCapture &capture = match.captures[i];
			String value_str = get_node_text(p_source_code, capture.node);

			String clean_value = value_str;
			if ((clean_value.begins_with("\"") && clean_value.ends_with("\"")) ||
					(clean_value.begins_with("'") && clean_value.ends_with("'"))) {
				clean_value = clean_value.substr(1, clean_value.length() - 2);
			}

			// 【关键步骤 1】 去重 (基于清理后的值)
			if (seen_values.has(clean_value)) {
				continue;
			}

			// 【关键步骤 2】 同步写入
			seen_values.insert(clean_value);
			ordered_hints.push_back(clean_value); // UI 显示用的名字
			result.constants.push_back(clean_value); // 实际存储的数据值
		}
	}
	ts_query_cursor_delete(cursor);

	// 【关键步骤 3】 手动拼接逗号分隔字符串
	String final_hint;
	for (int i = 0; i < ordered_hints.size(); i++) {
		if (i > 0) {
			final_hint += ",";
		}
		final_hint += ordered_hints[i];
	}

	result.hint_string = final_hint;
	return result;
}

EnumParseResult TypeScript::parse_enum_members(TSNode p_enum_declaration_node, const char *p_source_code) const {
	uint32_t error_offset;
	TSQueryError error;
	static const TSQuery *p_member_query = ts_query_new(lang, query_enum_body, strlen(query_enum_body), &error_offset, &error);

	EnumParseResult result; // result.constants 已经是 Array 类型

	if (ts_node_is_null(p_enum_declaration_node) || !p_member_query) {
		return result;
	}

	TSNode body_node = ts_node_child_by_field_name(p_enum_declaration_node, "body", 4);
	if (ts_node_is_null(body_node)) {
		return result;
	}

	TSQueryCursor *cursor = ts_query_cursor_new();
	ts_query_cursor_exec(cursor, p_member_query, body_node);

	TSQueryMatch match;
	int next_enum_value = 0;

	// 1. 用于去重的查找表 (只存名字)
	HashSet<String> seen_names;
	// 或者用 Dictionary seen_names; if (!seen_names.has(...))

	// 2. 用于保持顺序的临时容器
	Vector<String> ordered_names;

	while (ts_query_cursor_next_match(cursor, &match)) {
		String member_name;
		String value_str;
		bool has_value = false;

		for (uint32_t i = 0; i < match.capture_count; i++) {
			uint32_t length = 0;
			const TSQueryCapture &capture = match.captures[i];
			String capture_name = ts_query_capture_name_for_id(p_member_query, capture.index, &length);

			if (capture_name == "enum.member") {
				member_name = get_node_text(p_source_code, capture.node);
			} else if (capture_name == "enum.value") {
				value_str = get_node_text(p_source_code, capture.node);
				has_value = true;
			}
		}

		if (member_name.is_empty()) {
			continue;
		}

		// 【关键步骤 1】 去重：检查名字是否已处理过
		if (seen_names.has(member_name)) {
			continue;
		}

		// 计算数值
		int current_value;
		if (has_value && value_str.is_valid_int()) {
			current_value = value_str.to_int();
		} else {
			current_value = next_enum_value;
		}

		// 【关键步骤 2】 同步写入数据
		seen_names.insert(member_name); // 标记名字已存在
		ordered_names.push_back(member_name); // 记录名字 (用于 hint_string)
		result.constants.push_back(current_value); // 记录数值 (存入 Array)

		next_enum_value = current_value + 1;
	}
	ts_query_cursor_delete(cursor);

	// 【关键步骤 3】 构建逗号分隔字符串
	String final_hint;
	for (int i = 0; i < ordered_names.size(); i++) {
		if (i > 0) {
			final_hint += ",";
		}
		final_hint += ordered_names[i];
	}

	result.hint_string = final_hint;
	return result;
}

PropertyParseResult TypeScript::analyze_recursive(const StringName &type_name, String path) const {
	path = path == "" ? get_path() : path;

	Ref<TypeScript> script = ResourceLoader::get_singleton()->load(path);
	String code = script->_get_source_code();
	std::string std_code = to_chars(code);
	const char *p_code = std_code.c_str();

	TSTree *tree = ts_parser_parse_string(parser, NULL, p_code, strlen(p_code));

	HashMap<StringName, StringName> dependencies;
	{
		uint32_t error_offset;
		TSQueryError error;
		static const TSQuery *query = ts_query_new(lang, query_import_type, strlen(query_import_type), &error_offset, &error);
		if (!query) {
			ERR_PRINT("Tree-sitter query failed to compile.");
			ts_tree_delete(tree);
		} else {
			TSQueryCursor *cursor = ts_query_cursor_new();
			ts_query_cursor_exec(cursor, query, ts_tree_root_node(tree));
			TSQueryMatch match;
			while (ts_query_cursor_next_match(cursor, &match)) {
				HashMap<String, CaptureData> captures;
				for (uint32_t i = 0; i < match.capture_count; i++) {
					TSQueryCapture capture = match.captures[i];
					uint32_t capture_id = capture.index;
					uint32_t capture_name_length;
					String capture_name = ts_query_capture_name_for_id(query, capture_id, &capture_name_length);
					captures[capture_name] = { get_node_text(p_code, capture.node), "", capture.node };
				}
				if (captures.has("import.name") || captures.has("import.default")) {
					String import_name;
					if (captures.has("import.name")) {
						import_name = captures["import.name"].text;
					} else {
						import_name = captures["import.default"].text;
					}
					String import_path = captures["import.path"].text;
					import_path = import_path.remove_char('"').remove_char('\'');
					if (import_path.begins_with("@res")) {
						import_path = import_path.replace("@res/", "res://") + ".ts";
						dependencies[import_name] = import_path;
					}
				}
			}
		}
	}

	if (dependencies.has(type_name)) {
		return analyze_recursive(type_name, dependencies[type_name]);
	} else {
		uint32_t error_offset;
		TSQueryError error;
		static const TSQuery *query = ts_query_new(lang, query_property_type, strlen(query_property_type), &error_offset, &error);
		if (!query) {
			ERR_PRINT("Tree-sitter query failed to compile.");
			ts_tree_delete(tree);
			return { NONE };
		}
		TSQueryCursor *cursor = ts_query_cursor_new();
		ts_query_cursor_exec(cursor, query, ts_tree_root_node(tree));
		TSQueryMatch match;

		while (ts_query_cursor_next_match(cursor, &match)) {
			HashMap<String, Vector<TSNode>> captures;
			for (uint32_t i = 0; i < match.capture_count; i++) {
				TSQueryCapture capture = match.captures[i];
				uint32_t capture_name_length;
				String capture_name = ts_query_capture_name_for_id(query, capture.index, &capture_name_length);

				if (!captures.has(capture_name)) {
					captures[capture_name] = Vector<TSNode>();
				}
				captures[capture_name].push_back(capture.node);
			}

			if (captures.has("enum.name")) {
				TSNode name_node = captures["enum.name"][0];
				String enum_name_text = get_node_text(p_code, name_node);

				if (type_name == enum_name_text) {
					TSNode enum_declaration_node = ts_node_parent(name_node);
					return { ENUM, parse_enum_members(enum_declaration_node, p_code) };
				}
			} else if (captures.has("type.name")) {
				TSNode name_node = captures["type.name"][0];
				String type_name_text = get_node_text(p_code, name_node);

				if (type_name == type_name_text) {
					TSNode type_declaration_node = ts_node_parent(name_node);
					return { TYPE, parse_type_members(type_declaration_node, p_code) };
				}
			}
		}
		return { NONE };
	}
}

bool TypeScript::analyze_internal(const String &path) const {
	bool matched = false;

	Ref<TypeScript> script = ResourceLoader::get_singleton()->load(path);
	String code = script->_get_source_code();
	std::string std_code = to_chars(code);
	const char *p_code = std_code.c_str();

	TSTree *tree = ts_parser_parse_string(parser, NULL, p_code, strlen(p_code));

	if (ts_node_has_error(ts_tree_root_node(tree))) {
		return false;
	}

	HashMap<StringName, String> dependencies;
	{
		uint32_t error_offset;
		TSQueryError error;
		static const TSQuery *query = ts_query_new(lang, query_import_type, strlen(query_import_type), &error_offset, &error);
		if (!query) {
			ERR_PRINT("Tree-sitter query failed to compile.");
			ts_tree_delete(tree);
			return false;
		}
		TSQueryCursor *cursor = ts_query_cursor_new();
		ts_query_cursor_exec(cursor, query, ts_tree_root_node(tree));
		TSQueryMatch match;
		while (ts_query_cursor_next_match(cursor, &match)) {
			HashMap<String, CaptureData> captures;
			for (uint32_t i = 0; i < match.capture_count; i++) {
				TSQueryCapture capture = match.captures[i];
				uint32_t capture_id = capture.index;
				uint32_t capture_name_length;
				String capture_name = ts_query_capture_name_for_id(query, capture_id, &capture_name_length);
				captures[capture_name] = { get_node_text(p_code, capture.node), "", capture.node };
			}
			if (captures.has("import.name") || captures.has("import.default")) {
				String import_name;
				if (captures.has("import.name")) {
					import_name = captures["import.name"].text;
				} else {
					import_name = captures["import.default"].text;
				}
				String import_path = captures["import.path"].text;
				import_path = import_path.remove_char('"').remove_char('\'');
				if (import_path.begins_with("@res")) {
					import_path = import_path.replace("@res/", "res://") + ".ts";
					dependencies[import_name] = import_path;
				}
			}
		}
	}
	{
		uint32_t error_offset = 0;
		TSQueryError error = TSQueryErrorNone;
		static const TSQuery *query = ts_query_new(lang, query_default_class, strlen(query_default_class), &error_offset, &error);
		if (!query) {
			ERR_PRINT("Tree-sitter query failed to compile.");
			ts_tree_delete(tree);
			return false;
		}

		TSQueryCursor *cursor = ts_query_cursor_new();
		ts_query_cursor_exec(cursor, query, ts_tree_root_node(tree));
		TSQueryMatch match;

		while (ts_query_cursor_next_match(cursor, &match)) {
			HashMap<String, CaptureData> captures;
			for (uint32_t i = 0; i < match.capture_count; i++) {
				TSQueryCapture capture = match.captures[i];
				uint32_t capture_id = capture.index;
				uint32_t capture_name_length;
				String capture_name = ts_query_capture_name_for_id(query, capture_id, &capture_name_length);
				captures[capture_name] = { get_node_text(p_code, capture.node), "", capture.node };
			}

			StringName class_name;
			if (captures.has("class.name")) {
				class_name = captures["class.name"].text;
				matched = true;
				if (!godot_class_data) {
					godot_class_data = new ClassData();
					godot_class_data->class_name = class_name;
				}
			} else {
				continue;
			}

			if (captures.has("base.name")) {
				godot_class_data->base_class_name = captures["base.name"].text;
				base_script_path = dependencies[godot_class_data->base_class_name];
			}
			if (captures.has("class.is_abstract")) {
				godot_class_data->is_abstract = true;
			}

			if (captures.has("prop.name")) {
				// 这是一个属性成员的匹配
				String prop_name = captures["prop.name"].text;
				if (captures.has("decorator.member")) {
					String decorator_name = captures["decorator.member"].text;
					if (decorator_name == export_symbol_mask) {
						PropertyInfo pi;
						pi.name = prop_name;
						pi.class_name = class_name;
						pi.hint = PROPERTY_HINT_NONE;
						pi.usage = PROPERTY_USAGE_DEFAULT;
						pi.type = captures.has("prop.value") ? type_by_name(captures["prop.type"].text, captures["prop.value"].text) : type_by_name(captures["prop.type"].text);
						if (pi.type == Variant::Type::NIL) {
							PropertyParseResult property_parse_result = analyze_recursive(captures["prop.type"].text);
							switch (property_parse_result.type) {
								case ENUM: {
									pi.type = Variant::Type::INT;
									pi.hint = PROPERTY_HINT_ENUM;
									EnumParseResult parse_ret = std::get<EnumParseResult>(property_parse_result.parse_ret);
									pi.hint_string = parse_ret.hint_string;
									godot_class_data->enum_properties[prop_name] = parse_ret;
								} break;
								case TYPE: {
									pi.type = Variant::Type::INT;
									pi.hint = PROPERTY_HINT_ENUM;
									TypeParseResult parse_ret = std::get<TypeParseResult>(property_parse_result.parse_ret);
									pi.hint_string = parse_ret.hint_string;
									godot_class_data->type_properties[prop_name] = parse_ret;
								} break;
								case NONE:
								default: {
								} break;
							}
						} else {
							if (captures.has("prop.value")) {
								godot_class_data->default_value[prop_name] = execute_expression(captures["prop.value"].text);
							}
						}
						godot_class_data->properties[prop_name] = pi;
					} else if (decorator_name == signal_symbol_mask) {
						TSNode prop_type_node = captures["prop.type"].node;
						if (String("generic_type") == ts_node_grammar_type(prop_type_node)) {
							TSNode name_node = ts_node_child_by_field_name(prop_type_node, "name", 4);
							if (get_node_text(p_code, name_node) == "Signal") {
								MethodInfo mi;
								PropertyInfo return_value;
								LocalVector<PropertyInfo> arguments;
								return_value.type = Variant::Type::NIL;
								mi.name = prop_name;
								mi.return_val = return_value;

								TSNode type_arguments_node = ts_node_child_by_field_name(prop_type_node, "type_arguments", 14);
								TSNode function_type_node = ts_node_named_child(type_arguments_node, 0);
								TSNode parameters_node = ts_node_child_by_field_name(function_type_node, "parameters", 10);
								if (ts_node_named_child_count(parameters_node) > 0) {
									for (uint32_t i = 0; i < ts_node_named_child_count(parameters_node); ++i) {
										TSNode param_node = ts_node_named_child(parameters_node, i);
										TSNode param_name_node = ts_node_child_by_field_name(param_node, "pattern", 7);
										TSNode param_type_annotation_node = ts_node_child_by_field_name(param_node, "type", 4);
										TSNode param_type_node = ts_node_named_child(param_type_annotation_node, 0);
										TSNode param_value_node = ts_node_child_by_field_name(param_node, "value", 5);
										PropertyInfo pi;
										pi.name = get_node_text(p_code, param_name_node);
										if (ts_node_is_null(param_value_node)) {
											pi.type = type_by_name(get_node_text(p_code, param_type_node));
										} else {
											pi.type = type_by_name(get_node_text(p_code, param_type_node), get_node_text(p_code, param_value_node));
										}
										arguments.push_back(pi);
									}
									mi.arguments = arguments;
								}
								godot_class_data->signals[prop_name] = mi;
							}
						}
					}
				}
			}

			if (captures.has("method.body")) { // 使用新的 @method.body 捕获来识别方法
				MethodInfo mi;
				mi.name = captures["method.name"].text;
				mi.flags = METHOD_FLAG_NORMAL; // 默认为普通方法

				// 检查是否是抽象方法
				if (captures.has("method.is_abstract")) {
					mi.flags |= METHOD_FLAG_VIRTUAL;
				}

				// 1. 解析返回值
				if (captures.has("method.return_type")) {
					String return_type_str = captures["method.return_type"].text;
					// 假设 type_by_name 能处理 "void" 并返回 Variant::NIL
					mi.return_val.type = type_by_name(return_type_str);
					mi.return_val.name = ""; // 返回值没有名字
				} else {
					// 如果没有指定返回类型，默认为 void
					mi.return_val.type = Variant::NIL;
				}

				// 2. 解析参数
				if (captures.has("method.parameter")) {
					TSNode params_node = captures["method.parameter"].node;
					// 遍历 (formal_parameters) 的命名子节点，跳过 '(' ')' ',' 等符号
					uint32_t param_count = ts_node_named_child_count(params_node);

					for (uint32_t i = 0; i < param_count; i++) {
						TSNode param_node = ts_node_named_child(params_node, i);
						const char *param_node_type = ts_node_type(param_node);

						// 我们只关心 required_parameter 和 optional_parameter
						if (strcmp(param_node_type, "required_parameter") == 0 || strcmp(param_node_type, "optional_parameter") == 0) {
							PropertyInfo arg_pi;
							arg_pi.class_name = godot_class_data->class_name;

							TSNode name_node = ts_node_child_by_field_name(param_node, "pattern", 7); // "pattern"
							if (!ts_node_is_null(name_node)) {
								arg_pi.name = get_node_text(p_code, name_node);
							}

							// 获取参数类型 (type -> type_annotation -> [predefined_type | type_identifier])
							TSNode type_annotation_node = ts_node_child_by_field_name(param_node, "type", 4); // "type"
							if (!ts_node_is_null(type_annotation_node)) {
								TSNode type_node = ts_node_named_child(type_annotation_node, 0);
								if (!ts_node_is_null(type_node)) {
									String type_str = get_node_text(p_code, type_node);
									arg_pi.type = type_by_name(type_str);
								}
							} else {
								arg_pi.type = Variant::NIL;
							}

							mi.arguments.push_back(arg_pi);
						}
					}
				}
				godot_class_data->methods[mi.name] = mi;
			}
		}
	}
	return matched;
}

void TypeScript::analyze() const {
	if (!dirty) {
		return;
	}
	if (godot_class_data) {
		delete godot_class_data;
		godot_class_data = nullptr;
	}

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
	if (analyze_internal(path)) {
		is_valid = true;
		dirty = false;
	}
}

void TypeScript::compile() {
	ERR_FAIL_COND_EDMSG(!FileAccess::file_exists("res://tsconfig.json"), "tsconfig.json file does not exist.");
	int exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json" });
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
	if (!godot_class_data) {
		return false;
	}
	Ref<TypeScript> base = _get_base_script();
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
	if (!godot_class_data) {
		return false;
	}
	Ref<TypeScript> base = _get_base_script();
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
	if (!godot_class_data) {
		return -1;
	}
	Ref<TypeScript> base = _get_base_script();
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
	if (!godot_class_data) {
		return Dictionary();
	}
	Ref<TypeScript> base = _get_base_script();
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
	if (!godot_class_data) {
		return false;
	}
	return godot_class_data->is_tool;
}

bool TypeScript::_is_valid() const {
	this->analyze();
	return this->is_valid;
}

bool TypeScript::_is_abstract() const {
	this->analyze();
	if (!godot_class_data) {
		return false;
	}
	return godot_class_data->is_abstract;
}

ScriptLanguage *TypeScript::_get_language() const {
	return TypeScriptLanguage::get_singleton();
}

bool TypeScript::_has_script_signal(const StringName &p_signal) const {
	this->analyze();
	if (godot_class_data == nullptr) {
		return false;
	}
	Ref<TypeScript> base = _get_base_script();
	if (godot_class_data->signals.has(p_signal)) {
		return true;
	} else {
		return base.is_valid() && base->_has_script_signal(p_signal);
	}
}

TypedArray<Dictionary> TypeScript::_get_script_signal_list() const {
	this->analyze();
	if (godot_class_data == nullptr) {
		return {};
	}
	TypedArray<Dictionary> list;
	Ref<TypeScript> base = _get_base_script();
	if (base.is_valid()) {
		list.append_array(base->get_script_signal_list());
	}
	for (const KeyValue<StringName, MethodInfo> &E : godot_class_data->signals) {
		list.push_back(Dictionary(E.value));
	}
	return list;
}

bool TypeScript::_has_property_default_value(const StringName &p_property) const {
	this->analyze();
	if (godot_class_data->default_value.has(p_property)) {
		return true;
	} else {
		Ref<TypeScript> base = _get_base_script();
		return base.is_valid() && base->_has_property_default_value(p_property);
	}
}

Variant TypeScript::_get_property_default_value(const StringName &p_property) const {
	this->analyze();
	if (godot_class_data->default_value.has(p_property)) {
		return godot_class_data->default_value[p_property];
	} else {
		Ref<TypeScript> base = _get_base_script();
		if (base.is_valid()) {
			return base->_get_property_default_value(p_property);
		} else {
			return {};
		}
	}
}

void TypeScript::_update_exports() {
	this->analyze();
}

TypedArray<Dictionary> TypeScript::_get_script_method_list() const {
	this->analyze();
	if (godot_class_data == nullptr) {
		return {};
	}
	TypedArray<Dictionary> list;
	Ref<TypeScript> base = _get_base_script();
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
	if (godot_class_data == nullptr) {
		return {};
	}
	TypedArray<Dictionary> list;
	Ref<TypeScript> base = _get_base_script();
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
	if (godot_class_data == nullptr) {
		return {};
	}
	TypedArray<StringName> members;
	Ref<TypeScript> base = _get_base_script();
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

StringName TypeScript::_get_doc_class_name() const {
	this->analyze();
	if (!godot_class_data) {
		return "";
	}
	return godot_class_data->class_name;
}

PropertyParseResult TypeScript::get_property_parse_result(StringName prop_name) const {
	if (godot_class_data) {
		if (godot_class_data->enum_properties.has(prop_name)) {
			return { ENUM, godot_class_data->enum_properties[prop_name] };
		} else if (godot_class_data->type_properties.has(prop_name)) {
			return { TYPE, godot_class_data->type_properties[prop_name] };
		} else {
			Ref<TypeScript> base_script = _get_base_script();
			if (base_script.is_valid()) {
				return base_script->get_property_parse_result(prop_name);
			}
		}
	}
	return { NONE };
}

TypeScript::~TypeScript() {
	TypeScriptLanguage::scripts.erase(this);
}