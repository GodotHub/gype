
import type { Resource } from '@godot/classes/resource';


export declare class EditorSettings extends Resource {


    public has_setting(name: GDString | StringName | string): boolean;
    public set_setting(name: GDString | StringName | string, value: any): void;
    public get_setting(name: GDString | StringName | string): any;
    public erase(property: GDString | StringName | string): void;
    public set_initial_value(name: GDString | StringName | string, value: any, updateCurrent: boolean): void;
    public add_property_info(info: Dictionary): void;
    public set_project_metadata(section: GDString | StringName | string, key: GDString | StringName | string, data: any): void;
    public get_project_metadata(section: GDString | StringName | string, key: GDString | StringName | string, _default: any = null): any;
    public set_favorites(dirs: PackedStringArray): void;
    public get_favorites(): PackedStringArray;
    public set_recent_dirs(dirs: PackedStringArray): void;
    public get_recent_dirs(): PackedStringArray;
    public set_builtin_action_override(name: GDString | StringName | string, actionsList: Array<any>): void;
    public check_changed_settings_in_group(settingPrefix: GDString | StringName | string): boolean;
    public get_changed_settings(): PackedStringArray;
    public mark_setting_changed(setting: GDString | StringName | string): void;

    
    public readonly settings_changed: Signal<() => void>;

}

