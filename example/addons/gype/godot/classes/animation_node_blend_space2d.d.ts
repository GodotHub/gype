
import type { AnimationRootNode } from '@godot/classes/animation_root_node';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { Signal } from '@godot/builtins/signal';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class AnimationNodeBlendSpace2D extends AnimationRootNode {

    
    /**     * The raw type is 'bool'     */
    public auto_triangles: boolean;    
    /**     * The raw type is 'PackedInt32Array'     */
    public triangles: PackedInt32Array;    
    /**     * The raw type is 'Vector2'     */
    public min_space: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public max_space: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public snap: Vector2;    
    /**     * The raw type is 'String'     */
    public x_label: GDString;    
    /**     * The raw type is 'String'     */
    public y_label: GDString;    
    /**     * The raw type is 'int'     */
    public blend_mode: number;    
    /**     * The raw type is 'bool'     */
    public sync: boolean;
    public add_blend_point(node: AnimationRootNode, pos: Vector2, atIndex: number = -1): void;
    public set_blend_point_position(point: number, pos: Vector2): void;
    public get_blend_point_position(point: number): Vector2;
    public set_blend_point_node(point: number, node: AnimationRootNode): void;
    public get_blend_point_node(point: number): AnimationRootNode;
    public remove_blend_point(point: number): void;
    public get_blend_point_count(): number;
    public add_triangle(x: number, y: number, z: number, atIndex: number = -1): void;
    public get_triangle_point(triangle: number, point: number): number;
    public remove_triangle(triangle: number): void;
    public get_triangle_count(): number;
    public set_min_space(minSpace: Vector2): void;
    public get_min_space(): Vector2;
    public set_max_space(maxSpace: Vector2): void;
    public get_max_space(): Vector2;
    public set_snap(snap: Vector2): void;
    public get_snap(): Vector2;
    public set_x_label(text: GDString | StringName | string): void;
    public get_x_label(): GDString;
    public set_y_label(text: GDString | StringName | string): void;
    public get_y_label(): GDString;
    public set_auto_triangles(enable: boolean): void;
    public get_auto_triangles(): boolean;
    public set_blend_mode(mode: number): void;
    public get_blend_mode(): number;
    public set_use_sync(enable: boolean): void;
    public is_using_sync(): boolean;

    
    public readonly triangles_updated: Signal<() => void>;

    public static readonly BlendMode: {
        BLEND_MODE_INTERPOLATED: 0;
        BLEND_MODE_DISCRETE: 1;
        BLEND_MODE_DISCRETE_CARRY: 2;
    };
}

