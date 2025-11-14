
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';


export declare class ShaderIncludeDB extends GodotObject {


    public static list_built_in_include_files(): PackedStringArray;
    public static has_built_in_include_file(filename: GDString | StringName | string): boolean;
    public static get_built_in_include_file(filename: GDString | StringName | string): GDString;


}

