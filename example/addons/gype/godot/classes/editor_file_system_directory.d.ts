
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { StringName } from '@godot/builtins/string_name';


export declare class EditorFileSystemDirectory extends GodotObject {


    public get_subdir_count(): number;
    public get_subdir(idx: number): EditorFileSystemDirectory;
    public get_file_count(): number;
    public get_file(idx: number): GDString;
    public get_file_path(idx: number): GDString;
    public get_file_type(idx: number): StringName;
    public get_file_script_class_name(idx: number): GDString;
    public get_file_script_class_extends(idx: number): GDString;
    public get_file_import_is_valid(idx: number): boolean;
    public get_name(): GDString;
    public get_path(): GDString;
    public get_parent(): EditorFileSystemDirectory;
    public find_file_index(name: GDString | StringName | string): number;
    public find_dir_index(name: GDString | StringName | string): number;


}

