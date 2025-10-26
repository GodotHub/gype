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
	const_cast<TypeScript *>(this)->analyze();
	if (!base_class_name.is_empty() && !ClassDB::class_exists(base_class_name)) {
		// 如果基类不是内置类，那么它应该是另一个脚本。
		// 我们需要从 TypeScriptLanguage 的全局类注册表中查找它。
		String base_path = TypeScriptLanguage::get_singleton()->get_path_for_global_class(base_class_name);
		if (!base_path.is_empty()) {
			return ResourceLoader::get_singleton()->load(base_path);
		}
	}
	return nullptr; // 基类是内置类或未找到
}

StringName TypeScript::_get_global_name() const {
	return global_class_name;
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
	const_cast<TypeScript *>(this)->analyze();
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

void TypeScript::analyze() {
	// 如果已经分析过且未变脏，则直接返回
	if (is_valid_cache && !dirty) {
		return;
	}

	// 清空旧的缓存数据
	methods.clear();
	static_methods.clear();
	properties.clear();
	signals.clear();
	base_class_name = "Object"; // 默认基类
	global_class_name = "";
	is_tool = false;

	String path = get_path();
	if (path.is_empty() || path.begins_with(dist_path)) {
		is_valid_cache = true;
		return; // 不分析编译后的JS文件
	}

	String code = _get_source_code();
	if (code.is_empty()) {
		is_valid_cache = true;
		return;
	}

	// --- Tree-sitter 解析 ---
	std::string origin_string(code.utf8()); // 使用utf8以支持非ASCII字符
	const char *c_code = origin_string.c_str();

	TSTree *tree = ts_parser_parse_string(parser, NULL, c_code, origin_string.length());

	// 更强大的查询，用于捕获类、基类、属性、信号和方法
	const char *query_string = R"xxx(
        (export_statement
            (decorator (call_expression (identifier) @decorator.class))
            (class_declaration
                name: (type_identifier) @class.name
                (class_heritage (extends_clause (identifier) @base.name))?
                body: (class_body
                    [
                        (
                            (decorator (call_expression (identifier) @decorator.prop))
                            (public_field_definition
                                name: (property_identifier) @prop.name
                                type: (type_annotation)? @prop.type
                            )
                        )
                        (
                            (decorator (call_expression (identifier) @decorator.signal))
                            (public_field_definition
                                name: (property_identifier) @signal.name
                            )
                        )
                        (
                            (method_definition
                                (modifier)* @method.modifier  ;
                                name: (property_identifier) @method.name
                            )
                        )
                    ]
                )
            )
            (#eq? @decorator.class "GodotClass")
        )
        (comment) @comment.tool ; 用于检查 @tool
	)xxx";

	uint32_t error_offset;
	TSQueryError error;
	TSQuery *query = ts_query_new(lang, query_string, strlen(query_string), &error_offset, &error);

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

	while (ts_query_cursor_next_match(cursor, &match)) {
		String current_prop_name, current_prop_decorator;
		String current_signal_name, current_signal_decorator;

		StringName method_name;
		bool is_static = false;
		uint32_t method_name_capture_index = -1;

		for (uint32_t i = 0; i < match.capture_count; i++) {
			TSQueryCapture capture = match.captures[i];
			TSNode node = capture.node;
			uint32_t capture_id = capture.index;
			String capture_name = ts_query_capture_name_for_id(query, capture_id, nullptr);
			String content = get_node_text(node);

			if (capture_name == "class.name") {
				global_class_name = content;
			} else if (capture_name == "base.name") {
				base_class_name = content;
			} else if (capture_name == "comment.tool" && content.contains("@tool")) {
				is_tool = true;
			} else if (capture_name == "prop.name") {
				current_prop_name = content;
			} else if (capture_name == "decorator.prop" && content == "export") {
				// 捕获到一个 @export 属性
				if (!current_prop_name.is_empty()) {
					PropertyInfo pi;
					pi.name = current_prop_name;
					pi.class_name = global_class_name;
					pi.type = Variant::NIL; // 简化的类型，实际需要解析 @prop.type
					pi.usage = PROPERTY_USAGE_DEFAULT;
					properties[current_prop_name] = pi;
					current_prop_name = "";
				}
			} else if (capture_name == "signal.name") {
				current_signal_name = content;
			} else if (capture_name == "decorator.signal" && content == "signal") {
				// 捕获到一个 @signal
				if (!current_signal_name.is_empty()) {
					MethodInfo mi;
					mi.name = current_signal_name;
					signals[current_signal_name] = mi;
					current_signal_name = "";
				}
			} else if (capture_name == "method.name") {
				// 捕获到一个方法
				// 忽略构造函数
				if (content != "constructor") {
					method_name = content;
					method_name_capture_index = i;
				}
			}
			if (method_name_capture_index != -1) {
				// 现在回头检查这个匹配中的所有修饰符
				for (uint32_t i = 0; i < match.capture_count; i++) {
					TSQueryCapture capture = match.captures[i];
					uint32_t capture_id = capture.index;
					String capture_name = ts_query_capture_name_for_id(query, capture_id, nullptr);

					if (capture_name == "method.modifier" && get_node_text(capture.node) == "static") {
						is_static = true;
						break; // 找到 static 就够了
					}
				}

				// 根据是否是 static，存入不同的 map
				if (!method_name.is_empty() && method_name != StringName("constructor")) {
					MethodInfo mi;
					mi.name = method_name;
					// 实际应用中需要解析参数和返回值

					if (is_static) {
						static_methods[method_name] = mi;
					} else {
						methods[method_name] = mi;
					}
				}
			}
		}
	}

	ts_query_cursor_delete(cursor);
	ts_query_delete(query);
	ts_tree_delete(tree);

	is_valid_cache = true;
	dirty = false;
}

void TypeScript::compile(bool force) {
	int exit_code = 0;
	if (dirty && Engine::get_singleton()->is_editor_hint()) {
		if (force) {
			exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json", "--force" });
		} else {
			exit_code = OS::get_singleton()->execute("cmd.exe", { "/c", "tsc", "--build", "tsconfig.json" });
		}
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
	const_cast<TypeScript *>(this)->analyze();
	return methods.has(p_method) || ClassDB::class_has_method(base_class_name, p_method, true);
}

bool TypeScript::_has_static_method(const StringName &p_method) const {
	const_cast<TypeScript *>(this)->analyze();
	return static_methods.has(p_method);
}

Variant TypeScript::_get_script_method_argument_count(const StringName &p_method) const {
	return Variant();
}

Dictionary TypeScript::_get_method_info(const StringName &p_method) const {
	const_cast<TypeScript *>(this)->analyze();
	if (methods.has(p_method)) {
		return methods[p_method];
	}
	return {};
}

bool TypeScript::_is_tool() const {
	const_cast<TypeScript *>(this)->analyze();
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
	const_cast<TypeScript *>(this)->analyze();
	return signals.has(p_signal);
}

TypedArray<Dictionary> TypeScript::_get_script_signal_list() const {
	const_cast<TypeScript *>(this)->analyze();
	TypedArray<Dictionary> list;
	for (const KeyValue<StringName, MethodInfo> &E : signals) {
		list.push_back(Dictionary(E.value));
	}
	return list;
}

bool TypeScript::_has_property_default_value(const StringName &p_property) const {
	return false;
}

Variant TypeScript::_get_property_default_value(const StringName &p_property) const {
	return Variant();
}

void TypeScript::_update_exports() {
	compile(false);
}

TypedArray<Dictionary> TypeScript::_get_script_method_list() const {
	const_cast<TypeScript *>(this)->analyze();
	TypedArray<Dictionary> list;
	for (const KeyValue<StringName, MethodInfo> &E : methods) {
		list.push_back(Dictionary(E.value));
	}
	return list;
}

TypedArray<Dictionary> TypeScript::_get_script_property_list() const {
	const_cast<TypeScript *>(this)->analyze();
	TypedArray<Dictionary> list;
	for (const KeyValue<StringName, PropertyInfo> &E : properties) {
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
    const_cast<TypeScript*>(this)->analyze();
    TypedArray<StringName> members;
    for (const KeyValue<StringName, PropertyInfo> &E : properties) {
        members.push_back(E.key);
    }
    for (const KeyValue<StringName, MethodInfo> &E : methods) {
        members.push_back(E.key);
    }
	return members;
}

bool TypeScript::_is_placeholder_fallback_enabled() const {
	return false;
}

Variant TypeScript::_get_rpc_config() const {
	return Variant();
}

godot::TypeScript::~TypeScript() {
}
