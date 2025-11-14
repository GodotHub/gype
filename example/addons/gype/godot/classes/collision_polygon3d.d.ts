
import type { Color } from '@godot/builtins/color';
import type { Node3D } from '@godot/classes/node3d';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';


export declare class CollisionPolygon3D extends Node3D {

    
    /**     * The raw type is 'float'     */
    public depth: number;    
    /**     * The raw type is 'bool'     */
    public disabled: boolean;    
    /**     * The raw type is 'PackedVector2Array'     */
    public polygon: PackedVector2Array;    
    /**     * The raw type is 'float'     */
    public margin: number;    
    /**     * The raw type is 'Color'     */
    public debug_color: Color;    
    /**     * The raw type is 'bool'     */
    public debug_fill: boolean;
    public set_depth(depth: number): void;
    public get_depth(): number;
    public set_polygon(polygon: PackedVector2Array): void;
    public get_polygon(): PackedVector2Array;
    public set_disabled(disabled: boolean): void;
    public is_disabled(): boolean;
    public set_debug_color(color: Color): void;
    public get_debug_color(): Color;
    public set_enable_debug_fill(enable: boolean): void;
    public get_enable_debug_fill(): boolean;
    public set_margin(margin: number): void;
    public get_margin(): number;


}

