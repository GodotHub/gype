
import type { Resource } from '@godot/classes/resource';


export declare class Gradient extends Resource {

    
    /**     * The raw type is 'int'     */
    public interpolation_mode: number;    
    /**     * The raw type is 'int'     */
    public interpolation_color_space: number;    
    /**     * The raw type is 'PackedFloat32Array'     */
    public offsets: PackedFloat32Array;    
    /**     * The raw type is 'PackedColorArray'     */
    public colors: PackedColorArray;
    public add_point(offset: number, color: Color): void;
    public remove_point(point: number): void;
    public set_offset(point: number, offset: number): void;
    public get_offset(point: number): number;
    public reverse(): void;
    public set_color(point: number, color: Color): void;
    public get_color(point: number): Color;
    public sample(offset: number): Color;
    public get_point_count(): number;
    public set_offsets(offsets: PackedFloat32Array): void;
    public get_offsets(): PackedFloat32Array;
    public set_colors(colors: PackedColorArray): void;
    public get_colors(): PackedColorArray;
    public set_interpolation_mode(interpolationMode: number): void;
    public get_interpolation_mode(): number;
    public set_interpolation_color_space(interpolationColorSpace: number): void;
    public get_interpolation_color_space(): number;


    public static readonly InterpolationMode: {
        GRADIENT_INTERPOLATE_LINEAR: 0;
        GRADIENT_INTERPOLATE_CONSTANT: 1;
        GRADIENT_INTERPOLATE_CUBIC: 2;
    };
    public static readonly ColorSpace: {
        GRADIENT_COLOR_SPACE_SRGB: 0;
        GRADIENT_COLOR_SPACE_LINEAR_SRGB: 1;
        GRADIENT_COLOR_SPACE_OKLAB: 2;
    };
}

