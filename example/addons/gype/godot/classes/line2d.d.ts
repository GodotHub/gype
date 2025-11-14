
import type { Color } from '@godot/builtins/color';
import type { Curve } from '@godot/classes/curve';
import type { Gradient } from '@godot/classes/gradient';
import type { Node2D } from '@godot/classes/node2d';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Line2D extends Node2D {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public points: PackedVector2Array;    
    /**     * The raw type is 'bool'     */
    public closed: boolean;    
    /**     * The raw type is 'float'     */
    public width: number;    
    /**     * The raw type is 'Curve'     */
    public width_curve: Curve;    
    /**     * The raw type is 'Color'     */
    public default_color: Color;    
    /**     * The raw type is 'Gradient'     */
    public gradient: Gradient;    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public texture_mode: number;    
    /**     * The raw type is 'int'     */
    public joint_mode: number;    
    /**     * The raw type is 'int'     */
    public begin_cap_mode: number;    
    /**     * The raw type is 'int'     */
    public end_cap_mode: number;    
    /**     * The raw type is 'float'     */
    public sharp_limit: number;    
    /**     * The raw type is 'int'     */
    public round_precision: number;    
    /**     * The raw type is 'bool'     */
    public antialiased: boolean;
    public set_points(points: PackedVector2Array): void;
    public get_points(): PackedVector2Array;
    public set_point_position(index: number, position: Vector2): void;
    public get_point_position(index: number): Vector2;
    public get_point_count(): number;
    public add_point(position: Vector2, index: number = -1): void;
    public remove_point(index: number): void;
    public clear_points(): void;
    public set_closed(closed: boolean): void;
    public is_closed(): boolean;
    public set_width(width: number): void;
    public get_width(): number;
    public set_curve(curve: Curve): void;
    public get_curve(): Curve;
    public set_default_color(color: Color): void;
    public get_default_color(): Color;
    public set_gradient(color: Gradient): void;
    public get_gradient(): Gradient;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_texture_mode(mode: number): void;
    public get_texture_mode(): number;
    public set_joint_mode(mode: number): void;
    public get_joint_mode(): number;
    public set_begin_cap_mode(mode: number): void;
    public get_begin_cap_mode(): number;
    public set_end_cap_mode(mode: number): void;
    public get_end_cap_mode(): number;
    public set_sharp_limit(limit: number): void;
    public get_sharp_limit(): number;
    public set_round_precision(precision: number): void;
    public get_round_precision(): number;
    public set_antialiased(antialiased: boolean): void;
    public get_antialiased(): boolean;


    public static readonly LineJointMode: {
        LINE_JOINT_SHARP: 0;
        LINE_JOINT_BEVEL: 1;
        LINE_JOINT_ROUND: 2;
    };
    public static readonly LineCapMode: {
        LINE_CAP_NONE: 0;
        LINE_CAP_BOX: 1;
        LINE_CAP_ROUND: 2;
    };
    public static readonly LineTextureMode: {
        LINE_TEXTURE_NONE: 0;
        LINE_TEXTURE_TILE: 1;
        LINE_TEXTURE_STRETCH: 2;
    };
}

