
import type { Range } from '@godot/classes/range';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class TextureProgressBar extends Range {

    
    /**     * The raw type is 'int'     */
    public fill_mode: number;    
    /**     * The raw type is 'float'     */
    public radial_initial_angle: number;    
    /**     * The raw type is 'float'     */
    public radial_fill_degrees: number;    
    /**     * The raw type is 'Vector2'     */
    public radial_center_offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public nine_patch_stretch: boolean;    
    /**     * The raw type is 'int'     */
    public stretch_margin_left: number;    
    /**     * The raw type is 'int'     */
    public stretch_margin_top: number;    
    /**     * The raw type is 'int'     */
    public stretch_margin_right: number;    
    /**     * The raw type is 'int'     */
    public stretch_margin_bottom: number;    
    /**     * The raw type is 'Texture2D'     */
    public texture_under: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_over: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_progress: Texture2D;    
    /**     * The raw type is 'Vector2'     */
    public texture_progress_offset: Vector2;    
    /**     * The raw type is 'Color'     */
    public tint_under: Color;    
    /**     * The raw type is 'Color'     */
    public tint_over: Color;    
    /**     * The raw type is 'Color'     */
    public tint_progress: Color;
    public set_under_texture(tex: Texture2D): void;
    public get_under_texture(): Texture2D;
    public set_progress_texture(tex: Texture2D): void;
    public get_progress_texture(): Texture2D;
    public set_over_texture(tex: Texture2D): void;
    public get_over_texture(): Texture2D;
    public set_fill_mode(mode: number): void;
    public get_fill_mode(): number;
    public set_tint_under(tint: Color): void;
    public get_tint_under(): Color;
    public set_tint_progress(tint: Color): void;
    public get_tint_progress(): Color;
    public set_tint_over(tint: Color): void;
    public get_tint_over(): Color;
    public set_texture_progress_offset(offset: Vector2): void;
    public get_texture_progress_offset(): Vector2;
    public set_radial_initial_angle(mode: number): void;
    public get_radial_initial_angle(): number;
    public set_radial_center_offset(mode: Vector2): void;
    public get_radial_center_offset(): Vector2;
    public set_fill_degrees(mode: number): void;
    public get_fill_degrees(): number;
    public set_stretch_margin(margin: number, value: number): void;
    public get_stretch_margin(margin: number): number;
    public set_nine_patch_stretch(stretch: boolean): void;
    public get_nine_patch_stretch(): boolean;


    public static readonly FillMode: {
        FILL_LEFT_TO_RIGHT: 0;
        FILL_RIGHT_TO_LEFT: 1;
        FILL_TOP_TO_BOTTOM: 2;
        FILL_BOTTOM_TO_TOP: 3;
        FILL_CLOCKWISE: 4;
        FILL_COUNTER_CLOCKWISE: 5;
        FILL_BILINEAR_LEFT_AND_RIGHT: 6;
        FILL_BILINEAR_TOP_AND_BOTTOM: 7;
        FILL_CLOCKWISE_AND_COUNTER_CLOCKWISE: 8;
    };
}

