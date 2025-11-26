
import type { GodotObject } from '@godot/classes/godot_object';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EditorSceneFormatImporter extends RefCounted {


    public _get_extensions(): PackedStringArray;
    public _import_scene(path: GDString | StringName | string, flags: number, options: Dictionary): GodotObject;
    public _get_import_options(path: GDString | StringName | string): void;
    public _get_option_visibility(path: GDString | StringName | string, forAnimation: boolean, option: GDString | StringName | string): any;
    public add_import_option(name: GDString | StringName | string, value: any): void;
    public add_import_option_advanced(_type: number, name: GDString | StringName | string, defaultValue: any, hint: number = 0, hintString: GDString | StringName | string = "", usageFlags: number = 6): void;


}

