
import type { Node } from '@godot/classes/node';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Resource extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public resource_local_to_scene: boolean;    
    /**     * The raw type is 'String'     */
    public resource_path: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public resource_name: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public resource_scene_unique_id: GDString | StringName | string;
    public _setup_local_to_scene(): void;
    public _get_rid(): RID;
    public _reset_state(): void;
    public _set_path_cache(path: GDString | StringName | string): void;
    public set_path(path: GDString | StringName | string): void;
    public take_over_path(path: GDString | StringName | string): void;
    public get_path(): GDString;
    public set_path_cache(path: GDString | StringName | string): void;
    public set_name(name: GDString | StringName | string): void;
    public get_name(): GDString;
    public get_rid(): RID;
    public set_local_to_scene(enable: boolean): void;
    public is_local_to_scene(): boolean;
    public get_local_scene(): Node;
    public setup_local_to_scene(): void;
    public reset_state(): void;
    public set_id_for_path(path: GDString | StringName | string, id: GDString | StringName | string): void;
    public get_id_for_path(path: GDString | StringName | string): GDString;
    public is_built_in(): boolean;
    public static generate_scene_unique_id(): GDString;
    public set_scene_unique_id(id: GDString | StringName | string): void;
    public get_scene_unique_id(): GDString;
    public emit_changed(): void;
    public duplicate(deep: boolean = false): Resource;
    public duplicate_deep(deesubresourcesMode: number = 1): Resource;

    
    public readonly changed: Signal;
    public readonly setup_local_to_scene_requested: Signal;

    public static readonly DeepDuplicateMode: {
        DEEP_DUPLICATE_NONE: 0;
        DEEP_DUPLICATE_INTERNAL: 1;
        DEEP_DUPLICATE_ALL: 2;
    };
}

