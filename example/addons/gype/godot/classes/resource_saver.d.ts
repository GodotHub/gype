
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Resource } from '@godot/classes/resource';
import type { ResourceFormatSaver } from '@godot/classes/resource_format_saver';


export declare class ResourceSaver extends GodotObject {


    public save(resource: Resource, path: GDString | StringName | string = "", flags: number = 0): number;
    public set_uid(resource: GDString | StringName | string, uid: number): number;
    public get_recognized_extensions(_type: Resource): PackedStringArray;
    public add_resource_format_saver(formatSaver: ResourceFormatSaver, atFront: boolean = false): void;
    public remove_resource_format_saver(formatSaver: ResourceFormatSaver): void;
    public get_resource_id_for_path(path: GDString | StringName | string, generate: boolean = false): number;


    public static readonly SaverFlags: {
        FLAG_NONE: 0;
        FLAG_RELATIVE_PATHS: 1;
        FLAG_BUNDLE_RESOURCES: 2;
        FLAG_CHANGE_PATH: 4;
        FLAG_OMIT_EDITOR_PROPERTIES: 8;
        FLAG_SAVE_BIG_ENDIAN: 16;
        FLAG_COMPRESS: 32;
        FLAG_REPLACE_SUBRESOURCE_PATHS: 64;
    };
}


/**
 * A singleton instance of ResourceSaver.
 * This is a global variable, available from anywhere.
 */
export const ResourceSaver: ResourceSaver;
