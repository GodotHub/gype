
import type { Color } from '@godot/builtins/color';
import type { Rect2 } from '@godot/builtins/rect2';
import type { StyleBox } from '@godot/classes/style_box';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class StyleBoxTexture extends StyleBox {

    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'float'     */
    public texture_margin_left: number;    
    /**     * The raw type is 'float'     */
    public texture_margin_top: number;    
    /**     * The raw type is 'float'     */
    public texture_margin_right: number;    
    /**     * The raw type is 'float'     */
    public texture_margin_bottom: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_left: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_top: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_right: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_bottom: number;    
    /**     * The raw type is 'int'     */
    public axis_stretch_horizontal: number;    
    /**     * The raw type is 'int'     */
    public axis_stretch_vertical: number;    
    /**     * The raw type is 'Rect2'     */
    public region_rect: Rect2;    
    /**     * The raw type is 'Color'     */
    public modulate_color: Color;    
    /**     * The raw type is 'bool'     */
    public draw_center: boolean;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_texture_margin(margin: number, size: number): void;
    public set_texture_margin_all(size: number): void;
    public get_texture_margin(margin: number): number;
    public set_expand_margin(margin: number, size: number): void;
    public set_expand_margin_all(size: number): void;
    public get_expand_margin(margin: number): number;
    public set_region_rect(region: Rect2): void;
    public get_region_rect(): Rect2;
    public set_draw_center(enable: boolean): void;
    public is_draw_center_enabled(): boolean;
    public set_modulate(color: Color): void;
    public get_modulate(): Color;
    public set_h_axis_stretch_mode(mode: number): void;
    public get_h_axis_stretch_mode(): number;
    public set_v_axis_stretch_mode(mode: number): void;
    public get_v_axis_stretch_mode(): number;


    public static readonly AxisStretchMode: {
        AXIS_STRETCH_MODE_STRETCH: 0;
        AXIS_STRETCH_MODE_TILE: 1;
        AXIS_STRETCH_MODE_TILE_FIT: 2;
    };
}

