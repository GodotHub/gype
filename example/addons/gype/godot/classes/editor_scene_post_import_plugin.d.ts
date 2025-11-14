
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';


export declare class EditorScenePostImportPlugin extends RefCounted {


    public _get_internal_import_options(category: number): void;
    public _get_internal_option_visibility(category: number, forAnimation: boolean, option: GDString | StringName | string): any;
    public _get_internal_option_update_view_required(category: number, option: GDString | StringName | string): any;
    public _internal_process(category: number, baseNode: Node, node: Node, resource: Resource): void;
    public _get_import_options(path: GDString | StringName | string): void;
    public _get_option_visibility(path: GDString | StringName | string, forAnimation: boolean, option: GDString | StringName | string): any;
    public _pre_process(scene: Node): void;
    public _post_process(scene: Node): void;
    public get_option_value(name: GDString | StringName | string): any;
    public add_import_option(name: GDString | StringName | string, value: any): void;
    public add_import_option_advanced(_type: number, name: GDString | StringName | string, defaultValue: any, hint: number = 0, hintString: GDString | StringName | string = "", usageFlags: number = 6): void;


    public static readonly InternalImportCategory: {
        INTERNAL_IMPORT_CATEGORY_NODE: 0;
        INTERNAL_IMPORT_CATEGORY_MESH_3D_NODE: 1;
        INTERNAL_IMPORT_CATEGORY_MESH: 2;
        INTERNAL_IMPORT_CATEGORY_MATERIAL: 3;
        INTERNAL_IMPORT_CATEGORY_ANIMATION: 4;
        INTERNAL_IMPORT_CATEGORY_ANIMATION_NODE: 5;
        INTERNAL_IMPORT_CATEGORY_SKELETON_3D_NODE: 6;
        INTERNAL_IMPORT_CATEGORY_MAX: 7;
    };
}

