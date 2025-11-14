
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Script } from '@godot/classes/script';
import type { ScriptLanguage } from '@godot/classes/script_language';
import type { StringName } from '@godot/builtins/string_name';


export declare class ScriptLanguageExtension extends ScriptLanguage {


    public _get_name(): GDString;
    public _init(): void;
    public _get_type(): GDString;
    public _get_extension(): GDString;
    public _finish(): void;
    public _get_reserved_words(): PackedStringArray;
    public _is_control_flow_keyword(keyword: GDString | StringName | string): boolean;
    public _get_comment_delimiters(): PackedStringArray;
    public _get_doc_comment_delimiters(): PackedStringArray;
    public _get_string_delimiters(): PackedStringArray;
    public _make_template(template: GDString | StringName | string, className: GDString | StringName | string, baseClassName: GDString | StringName | string): Script;
    public _get_built_in_templates(object: GDString | StringName | string): Array<any>;
    public _is_using_templates(): boolean;
    public _validate(script: GDString | StringName | string, path: GDString | StringName | string, validateFunctions: boolean, validateErrors: boolean, validateWarnings: boolean, validateSafeLines: boolean): Dictionary;
    public _validate_path(path: GDString | StringName | string): GDString;
    public _create_script(): GodotObject;
    public _has_named_classes(): boolean;
    public _supports_builtin_mode(): boolean;
    public _supports_documentation(): boolean;
    public _can_inherit_from_file(): boolean;
    public _find_function(_function: GDString | StringName | string, code: GDString | StringName | string): number;
    public _make_function(className: GDString | StringName | string, functionName: GDString | StringName | string, functionArgs: PackedStringArray): GDString;
    public _can_make_function(): boolean;
    public _open_in_external_editor(script: Script, line: number, column: number): number;
    public _overrides_external_editor(): boolean;
    public _preferred_file_name_casing(): number;
    public _complete_code(code: GDString | StringName | string, path: GDString | StringName | string, owner: GodotObject): Dictionary;
    public _lookup_code(code: GDString | StringName | string, _symbol: GDString | StringName | string, path: GDString | StringName | string, owner: GodotObject): Dictionary;
    public _auto_indent_code(code: GDString | StringName | string, fromLine: number, toLine: number): GDString;
    public _add_global_constant(name: GDString | StringName | string, value: any): void;
    public _add_named_global_constant(name: GDString | StringName | string, value: any): void;
    public _remove_named_global_constant(name: GDString | StringName | string): void;
    public _thread_enter(): void;
    public _thread_exit(): void;
    public _debug_get_error(): GDString;
    public _debug_get_stack_level_count(): number;
    public _debug_get_stack_level_line(level: number): number;
    public _debug_get_stack_level_function(level: number): GDString;
    public _debug_get_stack_level_source(level: number): GDString;
    public _debug_get_stack_level_locals(level: number, maxSubitems: number, maxDepth: number): Dictionary;
    public _debug_get_stack_level_members(level: number, maxSubitems: number, maxDepth: number): Dictionary;
    public _debug_get_stack_level_instance(level: number): any;
    public _debug_get_globals(maxSubitems: number, maxDepth: number): Dictionary;
    public _debug_parse_stack_level_expression(level: number, expression: GDString | StringName | string, maxSubitems: number, maxDepth: number): GDString;
    public _debug_get_current_stack_info(): Array<any>;
    public _reload_all_scripts(): void;
    public _reload_scripts(scripts: GDArray, softReload: boolean): void;
    public _reload_tool_script(script: Script, softReload: boolean): void;
    public _get_recognized_extensions(): PackedStringArray;
    public _get_public_functions(): Array<any>;
    public _get_public_constants(): Dictionary;
    public _get_public_annotations(): Array<any>;
    public _profiling_start(): void;
    public _profiling_stop(): void;
    public _profiling_set_save_native_calls(enable: boolean): void;
    public _profiling_get_accumulated_data(infoArray: any, infoMax: number): number;
    public _profiling_get_frame_data(infoArray: any, infoMax: number): number;
    public _frame(): void;
    public _handles_global_class_type(_type: GDString | StringName | string): boolean;
    public _get_global_class_name(path: GDString | StringName | string): Dictionary;


    public static readonly LookupResultType: {
        LOOKUP_RESULT_SCRIPT_LOCATION: 0;
        LOOKUP_RESULT_CLASS: 1;
        LOOKUP_RESULT_CLASS_CONSTANT: 2;
        LOOKUP_RESULT_CLASS_PROPERTY: 3;
        LOOKUP_RESULT_CLASS_METHOD: 4;
        LOOKUP_RESULT_CLASS_SIGNAL: 5;
        LOOKUP_RESULT_CLASS_ENUM: 6;
        LOOKUP_RESULT_CLASS_TBD_GLOBALSCOPE: 7;
        LOOKUP_RESULT_CLASS_ANNOTATION: 8;
        LOOKUP_RESULT_LOCAL_CONSTANT: 9;
        LOOKUP_RESULT_LOCAL_VARIABLE: 10;
        LOOKUP_RESULT_MAX: 11;
    };
    public static readonly CodeCompletionLocation: {
        LOCATION_LOCAL: 0;
        LOCATION_PARENT_MASK: 256;
        LOCATION_OTHER_USER_CODE: 512;
        LOCATION_OTHER: 1024;
    };
    public static readonly CodeCompletionKind: {
        CODE_COMPLETION_KIND_CLASS: 0;
        CODE_COMPLETION_KIND_FUNCTION: 1;
        CODE_COMPLETION_KIND_SIGNAL: 2;
        CODE_COMPLETION_KIND_VARIABLE: 3;
        CODE_COMPLETION_KIND_MEMBER: 4;
        CODE_COMPLETION_KIND_ENUM: 5;
        CODE_COMPLETION_KIND_CONSTANT: 6;
        CODE_COMPLETION_KIND_NODE_PATH: 7;
        CODE_COMPLETION_KIND_FILE_PATH: 8;
        CODE_COMPLETION_KIND_PLAIN_TEXT: 9;
        CODE_COMPLETION_KIND_MAX: 10;
    };
}

