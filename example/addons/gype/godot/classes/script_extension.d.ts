
import type { GodotObject } from '@godot/classes/godot_object';
import type { Script } from '@godot/classes/script';
import type { ScriptLanguage } from '@godot/classes/script_language';


export declare class ScriptExtension extends Script {


    public _editor_can_reload_from_file(): boolean;
    public _placeholder_erased(placeholder: any): void;
    public _can_instantiate(): boolean;
    public _get_base_script(): Script;
    public _get_global_name(): StringName;
    public _inherits_script(script: Script): boolean;
    public _get_instance_base_type(): StringName;
    public _instance_create(forObject: GodotObject): any;
    public _placeholder_instance_create(forObject: GodotObject): any;
    public _instance_has(object: GodotObject): boolean;
    public _has_source_code(): boolean;
    public _get_source_code(): GDString;
    public _set_source_code(code: GDString | StringName | string): void;
    public _reload(keestate: boolean): number;
    public _get_doc_class_name(): StringName;
    public _get_documentation(): Array<any>;
    public _get_class_icon_path(): GDString;
    public _has_method(method: GDString | StringName | string): boolean;
    public _has_static_method(method: GDString | StringName | string): boolean;
    public _get_script_method_argument_count(method: GDString | StringName | string): any;
    public _get_method_info(method: GDString | StringName | string): Dictionary;
    public _is_tool(): boolean;
    public _is_valid(): boolean;
    public _is_abstract(): boolean;
    public _get_language(): ScriptLanguage;
    public _has_script_signal(signal: GDString | StringName | string): boolean;
    public _get_script_signal_list(): Array<any>;
    public _has_property_default_value(property: GDString | StringName | string): boolean;
    public _get_property_default_value(property: GDString | StringName | string): any;
    public _update_exports(): void;
    public _get_script_method_list(): Array<any>;
    public _get_script_property_list(): Array<any>;
    public _get_member_line(member: GDString | StringName | string): number;
    public _get_constants(): Dictionary;
    public _get_members(): Array<any>;
    public _is_placeholder_fallback_enabled(): boolean;
    public _get_rpc_config(): any;


}

