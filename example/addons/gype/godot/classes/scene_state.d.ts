
import type { PackedScene } from '@godot/classes/packed_scene';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class SceneState extends RefCounted {


    public get_path(): GDString;
    public get_base_scene_state(): SceneState;
    public get_node_count(): number;
    public get_node_type(idx: number): StringName;
    public get_node_name(idx: number): StringName;
    public get_node_path(idx: number, forParent: boolean = false): NodePath;
    public get_node_owner_path(idx: number): NodePath;
    public is_node_instance_placeholder(idx: number): boolean;
    public get_node_instance_placeholder(idx: number): GDString;
    public get_node_instance(idx: number): PackedScene;
    public get_node_groups(idx: number): PackedStringArray;
    public get_node_index(idx: number): number;
    public get_node_property_count(idx: number): number;
    public get_node_property_name(idx: number, proidx: number): StringName;
    public get_node_property_value(idx: number, proidx: number): any;
    public get_connection_count(): number;
    public get_connection_source(idx: number): NodePath;
    public get_connection_signal(idx: number): StringName;
    public get_connection_target(idx: number): NodePath;
    public get_connection_method(idx: number): StringName;
    public get_connection_flags(idx: number): number;
    public get_connection_binds(idx: number): GDArray;
    public get_connection_unbinds(idx: number): number;


    public static readonly GenEditState: {
        GEN_EDIT_STATE_DISABLED: 0;
        GEN_EDIT_STATE_INSTANCE: 1;
        GEN_EDIT_STATE_MAIN: 2;
        GEN_EDIT_STATE_MAIN_INHERITED: 3;
    };
}

