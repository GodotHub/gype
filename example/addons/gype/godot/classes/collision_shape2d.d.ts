
import type { Color } from '@godot/builtins/color';
import type { Node2D } from '@godot/classes/node2d';
import type { Shape2D } from '@godot/classes/shape2d';


export declare class CollisionShape2D extends Node2D {

    
    /**     * The raw type is 'Shape2D'     */
    public shape: Shape2D;    
    /**     * The raw type is 'bool'     */
    public disabled: boolean;    
    /**     * The raw type is 'bool'     */
    public one_way_collision: boolean;    
    /**     * The raw type is 'float'     */
    public one_way_collision_margin: number;    
    /**     * The raw type is 'Color'     */
    public debug_color: Color;
    public set_shape(shape: Shape2D): void;
    public get_shape(): Shape2D;
    public set_disabled(disabled: boolean): void;
    public is_disabled(): boolean;
    public set_one_way_collision(enabled: boolean): void;
    public is_one_way_collision_enabled(): boolean;
    public set_one_way_collision_margin(margin: number): void;
    public get_one_way_collision_margin(): number;
    public set_debug_color(color: Color): void;
    public get_debug_color(): Color;


}

