#ifndef __TYPESCRIPT_H__
#define __TYPESCRIPT_H__

#include <unordered_set>

#include "support/typescript_instance.hpp"
#include "support/typescript_language.hpp"
#include "support/typescript_loader.hpp"
#include "support/typescript_saver.hpp"
#include "tree_sitter/api.h"
#include "typescript/tree_sitter/tree-sitter-typescript.h"
#include <godot_cpp/classes/script_extension.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/hash_set.hpp>
#include <godot_cpp/classes/os.hpp>
#include <unordered_set>
#include <variant>

namespace godot {

class TypeScriptInstance;
class TypeScript;
class Variant;
class Object;
class ScriptExtension;
struct ClassData;
struct CaptureData;
struct EnumParseResult;
struct TypeParseResult;
struct PropertyParseResult;
enum TSNodeType : int;

class TypeScript : public ScriptExtension {
	GDCLASS(TypeScript, ScriptExtension)

	friend class TypeScriptLanguage;
	friend class TypeScriptSaver;
	friend class TypeScriptLoader;
	friend class TypeScriptInstance;
	friend class PlaceholderJavaScriptInstance;

	TSParser *parser;
	const TSLanguage *lang;

	String source_code = "";
	String dist_source_code = "";
	mutable TypeScript *base_script = nullptr;
	mutable StringName base_script_path = "";
	mutable HashSet<Ref<TypeScript>> interface_scripts;
	mutable bool dirty = true;
    mutable bool is_valid = false;
	mutable ClassData *godot_class_data = nullptr;

	HashSet<uint64_t> instances;
	mutable HashSet<TypeScriptInstance *> script_instances;
	mutable HashSet<TypeScriptInstance *> script_placeholders;
	const char *query_type = R"xxx(
	(type_alias_declaration
	  name: (type_identifier) @type.name
	  value: (_) @type.body
	)
	)xxx";
	const char *query_type_body = R"xxx(
	(union_type
	  [
  		(literal_type (_) @type.value)
	    (type_identifier) @type.value
	  ]
	)
	)xxx";
	const char *query_property_type = R"xxx(
	[
	  (enum_declaration
		  name: (identifier) @enum.name
		  body: (enum_body) @enum.body
	  )
	  (type_alias_declaration
	    name: (type_identifier) @type.name
	    value: (_) @type.body
	  )
	]
	)xxx";
	const char *query_enum_body = R"xxx(
	(property_identifier) @enum.member

    (enum_assignment
      name: (property_identifier) @enum.member
      value: (_) @enum.value
    )
	)xxx";
	const char *query_import_type = R"xxx(
    (import_statement
 	  (import_clause
        [
 	      (identifier) @import.default
 	      (named_imports
 	      (import_specifier 
			name: (identifier) @import.name))
        ]
 	  )
 	  source: (string) @import.path
 	)
	)xxx";
	const char * query_default_class = R"xxx(
	[
	  (export_statement
	    ("default") @export.default
	    (decorator (identifier) @decorator.other)?
	    [
	      (class_declaration
	        name: (type_identifier) @class.name
	        (class_heritage
	          (extends_clause value: (identifier) @base.name)
	          (implements_clause (type_identifier) @interface.name)?
	        )?
	        body: (class_body
	          (public_field_definition
	            decorator: (decorator (identifier) @decorator.member)?
	            name: (property_identifier) @prop.name
	            type: (type_annotation
	              [
	                (type_identifier)
	                (predefined_type)
	                (generic_type
	                  name: (type_identifier)
	                  type_arguments: (type_arguments
	                    (function_type
	                      parameters: (formal_parameters)
	                      return_type: (predefined_type)
	                    )
	                  )
	                )
	              ] @prop.type
	            )
	            value: (_)? @prop.value
	          )? @prop.body

	          (method_definition
	            name: (property_identifier) @method.name
	            parameters: (formal_parameters) @method.parameter
	            return_type: (type_annotation
	              [
	                (type_identifier)
	                (predefined_type)
	              ] @method.return_type
	            )
	          )? @method.body

	          (abstract_method_signature
	            name: (property_identifier) @method.name
	            parameters: (formal_parameters) @method.parameter
	            return_type: (type_annotation
	              [
	                (type_identifier)
	                (predefined_type)
	              ] @method.return_type
	            )
	          )? @method.body @method.is_abstract
	        )
	      )
	      (abstract_class_declaration
	        ("abstract") @class.is_abstract
	        name: (type_identifier) @class.name
	        (class_heritage
	          (extends_clause value: (identifier) @base.name)
	          (implements_clause (type_identifier) @interface.name)?
	        )?
	        body: (class_body
	          (public_field_definition
	            decorator: (decorator (identifier) @decorator.member)?
	            name: (property_identifier) @prop.name
	            type: (type_annotation
	              [
	                (type_identifier)
	                (predefined_type)
	                (generic_type
	                  name: (type_identifier)
	                  type_arguments: (type_arguments
	                    (function_type
	                      parameters: (formal_parameters)
	                      return_type: (predefined_type)
	                    )
	                  )
	                )
	              ] @prop.type
	            )
	            value: (_)? @prop.value
	          )? @prop.body

	          (method_definition
	            name: (property_identifier) @method.name
	            parameters: (formal_parameters) @method.parameter
	            return_type: (type_annotation
	              [
	                (type_identifier)
	                (predefined_type)
	              ] @method.return_type
	            )
	          )? @method.body

	          (abstract_method_signature
	            name: (property_identifier) @method.name
	            parameters: (formal_parameters) @method.parameter
	            return_type: (type_annotation
	              [
	                (type_identifier)
	                (predefined_type)
	              ] @method.return_type
	            )
	          )? @method.body @method.is_abstract
	        )
	      )
	    ] @class.body
	  )
	]
	)xxx";

private:
	void remove_dist_internal(const String &path);
	PropertyParseResult analyze_recursive(const StringName &type_name, String path = "") const;
	bool analyze_internal(const String &path) const;
	EnumParseResult parse_enum_members(TSNode p_enum_declaration_node, const char *p_source_code) const;
	TypeParseResult parse_type_members(TSNode p_type_declaration_node, const char *p_source_code) const;
public:
	
	static const char *dist_path;
	static const char *class_symbol_mask;
	static const char *signal_symbol_mask;
	static const char *export_symbol_mask;
	static const char *tool_symbol_mask;

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
	StringName _get_doc_class_name() const;
	PropertyParseResult get_property_parse_result(StringName prop_name) const;
	
	static void compile();

	TypeScript() :
		parser(ts_parser_new()),
		lang(tree_sitter_typescript())
	{
		ts_parser_set_language(parser, lang);
	}
	~TypeScript() {};

protected:
	static void _bind_methods() {}

private:
	void remove_dist();
	String get_dist_source_code() const;
	void analyze() const;
	void compile_module();
};

struct ClassData {
	bool is_tool = false;
	bool is_abstract = false;
	String class_name = "";
	String base_class_name = "";
	Dictionary constants;
	HashSet<StringName> interfaces;
	HashMap<StringName, MethodInfo> methods;
	HashMap<StringName, MethodInfo> static_methods;
	HashMap<StringName, PropertyInfo> properties;
	HashMap<StringName, EnumParseResult> enum_properties;
	HashMap<StringName, TypeParseResult> type_properties;
	HashMap<StringName, Variant> default_value;
	HashMap<StringName, MethodInfo> signals;
};

struct CaptureData {
	String text;
	String code;
	TSNode node;
};

enum TSNodeType : int{
	NONE,
	ENUM,
	TYPE,
	INTERFACE
};

struct EnumParseResult {
	String hint_string;
	Array constants;
};

struct TypeParseResult : EnumParseResult {
	
};

struct InterfaceParseResult {
	
};

struct PropertyParseResult {
	TSNodeType type;
	std::variant<EnumParseResult, TypeParseResult> parse_ret;
};

} // namespace godot

#endif // __TYPESCRIPT_H__