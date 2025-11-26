
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class DirAccess extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public include_navigational: boolean;    
    /**     * The raw type is 'bool'     */
    public include_hidden: boolean;
    public static open(path: GDString | StringName | string): DirAccess;
    public static get_open_error(): number;
    public static create_temp(prefix: GDString | StringName | string = "", keep: boolean = false): DirAccess;
    public list_dir_begin(): number;
    public get_next(): GDString;
    public current_is_dir(): boolean;
    public list_dir_end(): void;
    public get_files(): PackedStringArray;
    public static get_files_at(path: GDString | StringName | string): PackedStringArray;
    public get_directories(): PackedStringArray;
    public static get_directories_at(path: GDString | StringName | string): PackedStringArray;
    public static get_drive_count(): number;
    public static get_drive_name(idx: number): GDString;
    public get_current_drive(): number;
    public change_dir(toDir: GDString | StringName | string): number;
    public get_current_dir(includeDrive: boolean = true): GDString;
    public make_dir(path: GDString | StringName | string): number;
    public static make_dir_absolute(path: GDString | StringName | string): number;
    public make_dir_recursive(path: GDString | StringName | string): number;
    public static make_dir_recursive_absolute(path: GDString | StringName | string): number;
    public file_exists(path: GDString | StringName | string): boolean;
    public dir_exists(path: GDString | StringName | string): boolean;
    public static dir_exists_absolute(path: GDString | StringName | string): boolean;
    public get_space_left(): number;
    public copy(_from: GDString | StringName | string, to: GDString | StringName | string, chmodFlags: number = -1): number;
    public static copy_absolute(_from: GDString | StringName | string, to: GDString | StringName | string, chmodFlags: number = -1): number;
    public rename(_from: GDString | StringName | string, to: GDString | StringName | string): number;
    public static rename_absolute(_from: GDString | StringName | string, to: GDString | StringName | string): number;
    public remove(path: GDString | StringName | string): number;
    public static remove_absolute(path: GDString | StringName | string): number;
    public is_link(path: GDString | StringName | string): boolean;
    public read_link(path: GDString | StringName | string): GDString;
    public create_link(source: GDString | StringName | string, target: GDString | StringName | string): number;
    public is_bundle(path: GDString | StringName | string): boolean;
    public set_include_navigational(enable: boolean): void;
    public get_include_navigational(): boolean;
    public set_include_hidden(enable: boolean): void;
    public get_include_hidden(): boolean;
    public get_filesystem_type(): GDString;
    public is_case_sensitive(path: GDString | StringName | string): boolean;
    public is_equivalent(pathA: GDString | StringName | string, pathB: GDString | StringName | string): boolean;


}

