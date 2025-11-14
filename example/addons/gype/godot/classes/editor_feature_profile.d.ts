
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { StringName } from '@godot/builtins/string_name';


export declare class EditorFeatureProfile extends RefCounted {


    public set_disable_class(className: GDString | StringName | string, disable: boolean): void;
    public is_class_disabled(className: GDString | StringName | string): boolean;
    public set_disable_class_editor(className: GDString | StringName | string, disable: boolean): void;
    public is_class_editor_disabled(className: GDString | StringName | string): boolean;
    public set_disable_class_property(className: GDString | StringName | string, property: GDString | StringName | string, disable: boolean): void;
    public is_class_property_disabled(className: GDString | StringName | string, property: GDString | StringName | string): boolean;
    public set_disable_feature(feature: number, disable: boolean): void;
    public is_feature_disabled(feature: number): boolean;
    public get_feature_name(feature: number): GDString;
    public save_to_file(path: GDString | StringName | string): number;
    public load_from_file(path: GDString | StringName | string): number;


    public static readonly Feature: {
        FEATURE_3D: 0;
        FEATURE_SCRIPT: 1;
        FEATURE_ASSET_LIB: 2;
        FEATURE_SCENE_TREE: 3;
        FEATURE_NODE_DOCK: 4;
        FEATURE_FILESYSTEM_DOCK: 5;
        FEATURE_IMPORT_DOCK: 6;
        FEATURE_HISTORY_DOCK: 7;
        FEATURE_GAME: 8;
        FEATURE_MAX: 9;
    };
}

