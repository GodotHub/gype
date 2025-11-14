
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class ProjectSettings extends GodotObject {


    public has_setting(name: GDString | StringName | string): boolean;
    public set_setting(name: GDString | StringName | string, value: any): void;
    public get_setting(name: GDString | StringName | string, defaultValue: any = null): any;
    public get_setting_with_override(name: GDString | StringName | string): any;
    public get_global_class_list(): Array<any>;
    public get_setting_with_override_and_custom_features(name: GDString | StringName | string, features: PackedStringArray): any;
    public set_order(name: GDString | StringName | string, position: number): void;
    public get_order(name: GDString | StringName | string): number;
    public set_initial_value(name: GDString | StringName | string, value: any): void;
    public set_as_basic(name: GDString | StringName | string, basic: boolean): void;
    public set_as_internal(name: GDString | StringName | string, internal: boolean): void;
    public add_property_info(hint: Dictionary): void;
    public set_restart_if_changed(name: GDString | StringName | string, restart: boolean): void;
    public clear(name: GDString | StringName | string): void;
    public localize_path(path: GDString | StringName | string): GDString;
    public globalize_path(path: GDString | StringName | string): GDString;
    public save(): number;
    public load_resource_pack(pack: GDString | StringName | string, replaceFiles: boolean = true, offset: number = 0): boolean;
    public save_custom(file: GDString | StringName | string): number;

    
    public readonly settings_changed: Signal<() => void>;

}


/**
 * A singleton instance of ProjectSettings.
 * This is a global variable, available from anywhere.
 */
export const ProjectSettings: ProjectSettings;
