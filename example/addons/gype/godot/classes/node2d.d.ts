
import type { CanvasItem } from '@godot/classes/canvas_item';
import type { Node } from '@godot/classes/node';


export declare class Node2D extends CanvasItem {

    
    /**     * The raw type is 'Vector2'     */
    public position: Vector2;    
    /**     * The raw type is 'float'     */
    public rotation: number;    
    /**     * The raw type is 'float'     */
    public rotation_degrees: number;    
    /**     * The raw type is 'Vector2'     */
    public scale: Vector2;    
    /**     * The raw type is 'float'     */
    public skew: number;    
    /**     * The raw type is 'Transform2D'     */
    public transform: Transform2D;    
    /**     * The raw type is 'Vector2'     */
    public global_position: Vector2;    
    /**     * The raw type is 'float'     */
    public global_rotation: number;    
    /**     * The raw type is 'float'     */
    public global_rotation_degrees: number;    
    /**     * The raw type is 'Vector2'     */
    public global_scale: Vector2;    
    /**     * The raw type is 'float'     */
    public global_skew: number;    
    /**     * The raw type is 'Transform2D'     */
    public global_transform: Transform2D;
    public set_position(position: Vector2): void;
    public set_rotation(radians: number): void;
    public set_rotation_degrees(degrees: number): void;
    public set_skew(radians: number): void;
    public set_scale(scale: Vector2): void;
    public get_position(): Vector2;
    public get_rotation(): number;
    public get_rotation_degrees(): number;
    public get_skew(): number;
    public get_scale(): Vector2;
    public rotate(radians: number): void;
    public move_local_x(delta: number, scaled: boolean = false): void;
    public move_local_y(delta: number, scaled: boolean = false): void;
    public translate(offset: Vector2): void;
    public global_translate(offset: Vector2): void;
    public apply_scale(ratio: Vector2): void;
    public set_global_position(position: Vector2): void;
    public get_global_position(): Vector2;
    public set_global_rotation(radians: number): void;
    public set_global_rotation_degrees(degrees: number): void;
    public get_global_rotation(): number;
    public get_global_rotation_degrees(): number;
    public set_global_skew(radians: number): void;
    public get_global_skew(): number;
    public set_global_scale(scale: Vector2): void;
    public get_global_scale(): Vector2;
    public set_transform(xform: Transform2D): void;
    public set_global_transform(xform: Transform2D): void;
    public look_at(point: Vector2): void;
    public get_angle_to(point: Vector2): number;
    public to_local(globalPoint: Vector2): Vector2;
    public to_global(localPoint: Vector2): Vector2;
    public get_relative_transform_to_parent(parent: Node): Transform2D;


}

