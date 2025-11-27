
import type { GodotObject } from '@godot/classes/godot_object';
import type { Resource } from '@godot/classes/resource';
import type { ResourceFormatLoader } from '@godot/classes/resource_format_loader';


export declare class ResourceLoader extends GodotObject {


    public load_threaded_request(path: GDString | StringName | string, typeHint: GDString | StringName | string = "", useSubThreads: boolean = false, cacheMode: number = 1): number;
    public load_threaded_get_status(path: GDString | StringName | string, progress: GDArray | Array = []): number;
    public load_threaded_get(path: GDString | StringName | string): Resource;
    public load(path: GDString | StringName | string, typeHint: GDString | StringName | string = "", cacheMode: number = 1): Resource;
    public get_recognized_extensions_for_type(_type: GDString | StringName | string): PackedStringArray;
    public add_resource_format_loader(formatLoader: ResourceFormatLoader, atFront: boolean = false): void;
    public remove_resource_format_loader(formatLoader: ResourceFormatLoader): void;
    public set_abort_on_missing_resources(abort: boolean): void;
    public get_dependencies(path: GDString | StringName | string): PackedStringArray;
    public has_cached(path: GDString | StringName | string): boolean;
    public get_cached_ref(path: GDString | StringName | string): Resource;
    public exists(path: GDString | StringName | string, typeHint: GDString | StringName | string = ""): boolean;
    public get_resource_uid(path: GDString | StringName | string): number;
    public list_directory(directoryPath: GDString | StringName | string): PackedStringArray;


    public static readonly ThreadLoadStatus: {
        THREAD_LOAD_INVALID_RESOURCE: 0;
        THREAD_LOAD_IN_PROGRESS: 1;
        THREAD_LOAD_FAILED: 2;
        THREAD_LOAD_LOADED: 3;
    };
    public static readonly CacheMode: {
        CACHE_MODE_IGNORE: 0;
        CACHE_MODE_REUSE: 1;
        CACHE_MODE_REPLACE: 2;
        CACHE_MODE_IGNORE_DEEP: 3;
        CACHE_MODE_REPLACE_DEEP: 4;
    };
}


/**
 * A singleton instance of ResourceLoader.
 * This is a global variable, available from anywhere.
 */
export const ResourceLoader: ResourceLoader;
