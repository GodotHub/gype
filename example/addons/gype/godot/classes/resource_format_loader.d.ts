
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ResourceFormatLoader extends RefCounted {


    public _get_recognized_extensions(): PackedStringArray;
    public _recognize_path(path: GDString | StringName | string, _type: GDString | StringName | string): boolean;
    public _handles_type(_type: GDString | StringName | string): boolean;
    public _get_resource_type(path: GDString | StringName | string): GDString;
    public _get_resource_script_class(path: GDString | StringName | string): GDString;
    public _get_resource_uid(path: GDString | StringName | string): number;
    public _get_dependencies(path: GDString | StringName | string, addTypes: boolean): PackedStringArray;
    public _rename_dependencies(path: GDString | StringName | string, renames: Dictionary): number;
    public _exists(path: GDString | StringName | string): boolean;
    public _get_classes_used(path: GDString | StringName | string): PackedStringArray;
    public _load(path: GDString | StringName | string, originalPath: GDString | StringName | string, useSubThreads: boolean, cacheMode: number): any;


    public static readonly CacheMode: {
        CACHE_MODE_IGNORE: 0;
        CACHE_MODE_REUSE: 1;
        CACHE_MODE_REPLACE: 2;
        CACHE_MODE_IGNORE_DEEP: 3;
        CACHE_MODE_REPLACE_DEEP: 4;
    };
}

