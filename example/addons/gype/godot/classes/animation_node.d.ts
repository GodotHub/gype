
import type { Resource } from '@godot/classes/resource';


export declare class AnimationNode extends Resource {

    
    /**     * The raw type is 'bool'     */
    public filter_enabled: boolean;    
    /**     * The raw type is 'Array'     */
    public filters: GDArray | Array;
    public _get_child_nodes(): Dictionary;
    public _get_parameter_list(): GDArray;
    public _get_child_by_name(name: GDString | StringName | string): AnimationNode;
    public _get_parameter_default_value(parameter: GDString | StringName | string): any;
    public _is_parameter_read_only(parameter: GDString | StringName | string): boolean;
    public _process(time: number, seek: boolean, isExternalSeeking: boolean, testOnly: boolean): number;
    public _get_caption(): GDString;
    public _has_filter(): boolean;
    public add_input(name: GDString | StringName | string): boolean;
    public remove_input(index: number): void;
    public set_input_name(input: number, name: GDString | StringName | string): boolean;
    public get_input_name(input: number): GDString;
    public get_input_count(): number;
    public find_input(name: GDString | StringName | string): number;
    public set_filter_path(path: NodePath | GDString | string, enable: boolean): void;
    public is_path_filtered(path: NodePath | GDString | string): boolean;
    public set_filter_enabled(enable: boolean): void;
    public is_filter_enabled(): boolean;
    public get_processing_animation_tree_instance_id(): number;
    public is_process_testing(): boolean;
    public blend_animation(animation: GDString | StringName | string, time: number, delta: number, seeked: boolean, isExternalSeeking: boolean, blend: number, loopedFlag: number = 0): void;
    public blend_node(name: GDString | StringName | string, node: AnimationNode, time: number, seek: boolean, isExternalSeeking: boolean, blend: number, filter: number = 0, sync: boolean = true, testOnly: boolean = false): number;
    public blend_input(inputIndex: number, time: number, seek: boolean, isExternalSeeking: boolean, blend: number, filter: number = 0, sync: boolean = true, testOnly: boolean = false): number;
    public set_parameter(name: GDString | StringName | string, value: any): void;
    public get_parameter(name: GDString | StringName | string): any;

    
    public readonly tree_changed: Signal;
    public readonly animation_node_renamed: Signal;
    public readonly animation_node_removed: Signal;

    public static readonly FilterAction: {
        FILTER_IGNORE: 0;
        FILTER_PASS: 1;
        FILTER_STOP: 2;
        FILTER_BLEND: 3;
    };
}

