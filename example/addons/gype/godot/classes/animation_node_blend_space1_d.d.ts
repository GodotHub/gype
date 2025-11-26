
import type { AnimationRootNode } from '@godot/classes/animation_root_node';


export declare class AnimationNodeBlendSpace1D extends AnimationRootNode {

    
    /**     * The raw type is 'float'     */
    public min_space: number;    
    /**     * The raw type is 'float'     */
    public max_space: number;    
    /**     * The raw type is 'float'     */
    public snap: number;    
    /**     * The raw type is 'String'     */
    public value_label: GDString;    
    /**     * The raw type is 'int'     */
    public blend_mode: number;    
    /**     * The raw type is 'bool'     */
    public sync: boolean;
    public add_blend_point(node: AnimationRootNode, pos: number, atIndex: number = -1): void;
    public set_blend_point_position(point: number, pos: number): void;
    public get_blend_point_position(point: number): number;
    public set_blend_point_node(point: number, node: AnimationRootNode): void;
    public get_blend_point_node(point: number): AnimationRootNode;
    public remove_blend_point(point: number): void;
    public get_blend_point_count(): number;
    public set_min_space(minSpace: number): void;
    public get_min_space(): number;
    public set_max_space(maxSpace: number): void;
    public get_max_space(): number;
    public set_snap(snap: number): void;
    public get_snap(): number;
    public set_value_label(text: GDString | StringName | string): void;
    public get_value_label(): GDString;
    public set_blend_mode(mode: number): void;
    public get_blend_mode(): number;
    public set_use_sync(enable: boolean): void;
    public is_using_sync(): boolean;


    public static readonly BlendMode: {
        BLEND_MODE_INTERPOLATED: 0;
        BLEND_MODE_DISCRETE: 1;
        BLEND_MODE_DISCRETE_CARRY: 2;
    };
}

