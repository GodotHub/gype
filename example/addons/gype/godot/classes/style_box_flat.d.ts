
import type { Color } from '@godot/builtins/color';
import type { StyleBox } from '@godot/classes/style_box';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class StyleBoxFlat extends StyleBox {

    
    /**     * The raw type is 'Color'     */
    public bg_color: Color;    
    /**     * The raw type is 'bool'     */
    public draw_center: boolean;    
    /**     * The raw type is 'Vector2'     */
    public skew: Vector2;    
    /**     * The raw type is 'int'     */
    public border_width_left: number;    
    /**     * The raw type is 'int'     */
    public border_width_top: number;    
    /**     * The raw type is 'int'     */
    public border_width_right: number;    
    /**     * The raw type is 'int'     */
    public border_width_bottom: number;    
    /**     * The raw type is 'Color'     */
    public border_color: Color;    
    /**     * The raw type is 'bool'     */
    public border_blend: boolean;    
    /**     * The raw type is 'int'     */
    public corner_radius_top_left: number;    
    /**     * The raw type is 'int'     */
    public corner_radius_top_right: number;    
    /**     * The raw type is 'int'     */
    public corner_radius_bottom_right: number;    
    /**     * The raw type is 'int'     */
    public corner_radius_bottom_left: number;    
    /**     * The raw type is 'int'     */
    public corner_detail: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_left: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_top: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_right: number;    
    /**     * The raw type is 'float'     */
    public expand_margin_bottom: number;    
    /**     * The raw type is 'Color'     */
    public shadow_color: Color;    
    /**     * The raw type is 'int'     */
    public shadow_size: number;    
    /**     * The raw type is 'Vector2'     */
    public shadow_offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public anti_aliasing: boolean;    
    /**     * The raw type is 'float'     */
    public anti_aliasing_size: number;
    public set_bg_color(color: Color): void;
    public get_bg_color(): Color;
    public set_border_color(color: Color): void;
    public get_border_color(): Color;
    public set_border_width_all(width: number): void;
    public get_border_width_min(): number;
    public set_border_width(margin: number, width: number): void;
    public get_border_width(margin: number): number;
    public set_border_blend(blend: boolean): void;
    public get_border_blend(): boolean;
    public set_corner_radius_all(radius: number): void;
    public set_corner_radius(corner: number, radius: number): void;
    public get_corner_radius(corner: number): number;
    public set_expand_margin(margin: number, size: number): void;
    public set_expand_margin_all(size: number): void;
    public get_expand_margin(margin: number): number;
    public set_draw_center(drawCenter: boolean): void;
    public is_draw_center_enabled(): boolean;
    public set_skew(skew: Vector2): void;
    public get_skew(): Vector2;
    public set_shadow_color(color: Color): void;
    public get_shadow_color(): Color;
    public set_shadow_size(size: number): void;
    public get_shadow_size(): number;
    public set_shadow_offset(offset: Vector2): void;
    public get_shadow_offset(): Vector2;
    public set_anti_aliased(antiAliased: boolean): void;
    public is_anti_aliased(): boolean;
    public set_aa_size(size: number): void;
    public get_aa_size(): number;
    public set_corner_detail(detail: number): void;
    public get_corner_detail(): number;


}

