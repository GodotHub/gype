
import type { Control } from '@godot/classes/control';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class NinePatchRect extends Control {

    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public draw_center: boolean;    
    /**     * The raw type is 'Rect2'     */
    public region_rect: Rect2;    
    /**     * The raw type is 'int'     */
    public patch_margin_left: number;    
    /**     * The raw type is 'int'     */
    public patch_margin_top: number;    
    /**     * The raw type is 'int'     */
    public patch_margin_right: number;    
    /**     * The raw type is 'int'     */
    public patch_margin_bottom: number;    
    /**     * The raw type is 'int'     */
    public axis_stretch_horizontal: number;    
    /**     * The raw type is 'int'     */
    public axis_stretch_vertical: number;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_patch_margin(margin: number, value: number): void;
    public get_patch_margin(margin: number): number;
    public set_region_rect(rect: Rect2): void;
    public get_region_rect(): Rect2;
    public set_draw_center(drawCenter: boolean): void;
    public is_draw_center_enabled(): boolean;
    public set_h_axis_stretch_mode(mode: number): void;
    public get_h_axis_stretch_mode(): number;
    public set_v_axis_stretch_mode(mode: number): void;
    public get_v_axis_stretch_mode(): number;

    
    public readonly texture_changed: Signal<() => void>;

    public static readonly AxisStretchMode: {
        AXIS_STRETCH_MODE_STRETCH: 0;
        AXIS_STRETCH_MODE_TILE: 1;
        AXIS_STRETCH_MODE_TILE_FIT: 2;
    };
}

