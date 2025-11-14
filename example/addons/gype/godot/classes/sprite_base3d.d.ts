
import type { Color } from '@godot/builtins/color';
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';
import type { Rect2 } from '@godot/builtins/rect2';
import type { TriangleMesh } from '@godot/classes/triangle_mesh';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class SpriteBase3D extends GeometryInstance3D {

    
    /**     * The raw type is 'bool'     */
    public centered: boolean;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public flip_h: boolean;    
    /**     * The raw type is 'bool'     */
    public flip_v: boolean;    
    /**     * The raw type is 'Color'     */
    public modulate: Color;    
    /**     * The raw type is 'float'     */
    public pixel_size: number;    
    /**     * The raw type is 'int'     */
    public axis: number;    
    /**     * The raw type is 'int'     */
    public billboard: number;    
    /**     * The raw type is 'bool'     */
    public transparent: boolean;    
    /**     * The raw type is 'bool'     */
    public shaded: boolean;    
    /**     * The raw type is 'bool'     */
    public double_sided: boolean;    
    /**     * The raw type is 'bool'     */
    public no_depth_test: boolean;    
    /**     * The raw type is 'bool'     */
    public fixed_size: boolean;    
    /**     * The raw type is 'int'     */
    public alpha_cut: number;    
    /**     * The raw type is 'float'     */
    public alpha_scissor_threshold: number;    
    /**     * The raw type is 'float'     */
    public alpha_hash_scale: number;    
    /**     * The raw type is 'int'     */
    public alpha_antialiasing_mode: number;    
    /**     * The raw type is 'float'     */
    public alpha_antialiasing_edge: number;    
    /**     * The raw type is 'int'     */
    public texture_filter: number;    
    /**     * The raw type is 'int'     */
    public render_priority: number;
    public set_centered(centered: boolean): void;
    public is_centered(): boolean;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_flip_h(flih: boolean): void;
    public is_flipped_h(): boolean;
    public set_flip_v(fliv: boolean): void;
    public is_flipped_v(): boolean;
    public set_modulate(modulate: Color): void;
    public get_modulate(): Color;
    public set_render_priority(priority: number): void;
    public get_render_priority(): number;
    public set_pixel_size(pixelSize: number): void;
    public get_pixel_size(): number;
    public set_axis(axis: number): void;
    public get_axis(): number;
    public set_draw_flag(flag: number, enabled: boolean): void;
    public get_draw_flag(flag: number): boolean;
    public set_alpha_cut_mode(mode: number): void;
    public get_alpha_cut_mode(): number;
    public set_alpha_scissor_threshold(threshold: number): void;
    public get_alpha_scissor_threshold(): number;
    public set_alpha_hash_scale(threshold: number): void;
    public get_alpha_hash_scale(): number;
    public set_alpha_antialiasing(alphaAa: number): void;
    public get_alpha_antialiasing(): number;
    public set_alpha_antialiasing_edge(edge: number): void;
    public get_alpha_antialiasing_edge(): number;
    public set_billboard_mode(mode: number): void;
    public get_billboard_mode(): number;
    public set_texture_filter(mode: number): void;
    public get_texture_filter(): number;
    public get_item_rect(): Rect2;
    public generate_triangle_mesh(): TriangleMesh;


    public static readonly DrawFlags: {
        FLAG_TRANSPARENT: 0;
        FLAG_SHADED: 1;
        FLAG_DOUBLE_SIDED: 2;
        FLAG_DISABLE_DEPTH_TEST: 3;
        FLAG_FIXED_SIZE: 4;
        FLAG_MAX: 5;
    };
    public static readonly AlphaCutMode: {
        ALPHA_CUT_DISABLED: 0;
        ALPHA_CUT_DISCARD: 1;
        ALPHA_CUT_OPAQUE_PREPASS: 2;
        ALPHA_CUT_HASH: 3;
    };
}

