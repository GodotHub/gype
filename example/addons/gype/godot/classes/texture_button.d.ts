
import type { BaseButton } from '@godot/classes/base_button';
import type { BitMap } from '@godot/classes/bit_map';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class TextureButton extends BaseButton {

    
    /**     * The raw type is 'Texture2D'     */
    public texture_normal: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_pressed: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_hover: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_disabled: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_focused: Texture2D;    
    /**     * The raw type is 'BitMap'     */
    public texture_click_mask: BitMap;    
    /**     * The raw type is 'bool'     */
    public ignore_texture_size: boolean;    
    /**     * The raw type is 'int'     */
    public stretch_mode: number;    
    /**     * The raw type is 'bool'     */
    public flip_h: boolean;    
    /**     * The raw type is 'bool'     */
    public flip_v: boolean;
    public set_texture_normal(texture: Texture2D): void;
    public set_texture_pressed(texture: Texture2D): void;
    public set_texture_hover(texture: Texture2D): void;
    public set_texture_disabled(texture: Texture2D): void;
    public set_texture_focused(texture: Texture2D): void;
    public set_click_mask(mask: BitMap): void;
    public set_ignore_texture_size(ignore: boolean): void;
    public set_stretch_mode(mode: number): void;
    public set_flip_h(enable: boolean): void;
    public is_flipped_h(): boolean;
    public set_flip_v(enable: boolean): void;
    public is_flipped_v(): boolean;
    public get_texture_normal(): Texture2D;
    public get_texture_pressed(): Texture2D;
    public get_texture_hover(): Texture2D;
    public get_texture_disabled(): Texture2D;
    public get_texture_focused(): Texture2D;
    public get_click_mask(): BitMap;
    public get_ignore_texture_size(): boolean;
    public get_stretch_mode(): number;


    public static readonly StretchMode: {
        STRETCH_SCALE: 0;
        STRETCH_TILE: 1;
        STRETCH_KEEP: 2;
        STRETCH_KEEP_CENTERED: 3;
        STRETCH_KEEP_ASPECT: 4;
        STRETCH_KEEP_ASPECT_CENTERED: 5;
        STRETCH_KEEP_ASPECT_COVERED: 6;
    };
}

