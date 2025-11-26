
import type { GodotObject } from '@godot/classes/godot_object';
import type { Resource } from '@godot/classes/resource';


export declare class Script extends Resource {

    
    /**     * The raw type is 'String'     */
    public source_code: GDString;
    public can_instantiate(): boolean;
    public instance_has(baseObject: GodotObject): boolean;
    public has_source_code(): boolean;
    public get_source_code(): GDString;
    public set_source_code(source: GDString | StringName | string): void;
    public reload(keestate: boolean = false): number;
    public get_base_script(): Script;
    public get_instance_base_type(): StringName;
    public get_global_name(): StringName;
    public has_script_signal(signalName: GDString | StringName | string): boolean;
    public get_script_property_list(): Array<any>;
    public get_script_method_list(): Array<any>;
    public get_script_signal_list(): Array<any>;
    public get_script_constant_map(): Dictionary;
    public get_property_default_value(property: GDString | StringName | string): any;
    public is_tool(): boolean;
    public is_abstract(): boolean;
    public get_rpc_config(): any;


}

