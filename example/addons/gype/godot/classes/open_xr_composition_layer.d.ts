
import type { GodotObject } from '@godot/classes/godot_object';
import type { JavaObject } from '@godot/classes/java_object';
import type { Node3D } from '@godot/classes/node3d';
import type { SubViewport } from '@godot/classes/sub_viewport';


export declare class OpenXRCompositionLayer extends Node3D {

    
    /**     * The raw type is 'Object'     */
    public layer_viewport: SubViewport;    
    /**     * The raw type is 'bool'     */
    public use_android_surface: boolean;    
    /**     * The raw type is 'Vector2i'     */
    public android_surface_size: Vector2i;    
    /**     * The raw type is 'int'     */
    public sort_order: number;    
    /**     * The raw type is 'bool'     */
    public alpha_blend: boolean;    
    /**     * The raw type is 'bool'     */
    public enable_hole_punch: boolean;    
    /**     * The raw type is 'int'     */
    public swapchain_state_min_filter: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_mag_filter: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_mipmap_mode: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_horizontal_wrap: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_vertical_wrap: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_red_swizzle: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_green_swizzle: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_blue_swizzle: number;    
    /**     * The raw type is 'int'     */
    public swapchain_state_alpha_swizzle: number;    
    /**     * The raw type is 'float'     */
    public swapchain_state_max_anisotropy: number;    
    /**     * The raw type is 'Color'     */
    public swapchain_state_border_color: Color;
    public set_layer_viewport(viewport: SubViewport): void;
    public get_layer_viewport(): SubViewport;
    public set_use_android_surface(enable: boolean): void;
    public get_use_android_surface(): boolean;
    public set_android_surface_size(size: Vector2i): void;
    public get_android_surface_size(): Vector2i;
    public set_enable_hole_punch(enable: boolean): void;
    public get_enable_hole_punch(): boolean;
    public set_sort_order(order: number): void;
    public get_sort_order(): number;
    public set_alpha_blend(enabled: boolean): void;
    public get_alpha_blend(): boolean;
    public get_android_surface(): JavaObject;
    public is_natively_supported(): boolean;
    public set_min_filter(mode: number): void;
    public get_min_filter(): number;
    public set_mag_filter(mode: number): void;
    public get_mag_filter(): number;
    public set_mipmap_mode(mode: number): void;
    public get_mipmap_mode(): number;
    public set_horizontal_wrap(mode: number): void;
    public get_horizontal_wrap(): number;
    public set_vertical_wrap(mode: number): void;
    public get_vertical_wrap(): number;
    public set_red_swizzle(mode: number): void;
    public get_red_swizzle(): number;
    public set_green_swizzle(mode: number): void;
    public get_green_swizzle(): number;
    public set_blue_swizzle(mode: number): void;
    public get_blue_swizzle(): number;
    public set_alpha_swizzle(mode: number): void;
    public get_alpha_swizzle(): number;
    public set_max_anisotropy(value: number): void;
    public get_max_anisotropy(): number;
    public set_border_color(color: Color): void;
    public get_border_color(): Color;
    public intersects_ray(origin: Vector3, direction: Vector3): Vector2;


    public static readonly Filter: {
        FILTER_NEAREST: 0;
        FILTER_LINEAR: 1;
        FILTER_CUBIC: 2;
    };
    public static readonly MipmapMode: {
        MIPMAP_MODE_DISABLED: 0;
        MIPMAP_MODE_NEAREST: 1;
        MIPMAP_MODE_LINEAR: 2;
    };
    public static readonly Wrap: {
        WRAP_CLAMP_TO_BORDER: 0;
        WRAP_CLAMP_TO_EDGE: 1;
        WRAP_REPEAT: 2;
        WRAP_MIRRORED_REPEAT: 3;
        WRAP_MIRROR_CLAMP_TO_EDGE: 4;
    };
    public static readonly Swizzle: {
        SWIZZLE_RED: 0;
        SWIZZLE_GREEN: 1;
        SWIZZLE_BLUE: 2;
        SWIZZLE_ALPHA: 3;
        SWIZZLE_ZERO: 4;
        SWIZZLE_ONE: 5;
    };
}

