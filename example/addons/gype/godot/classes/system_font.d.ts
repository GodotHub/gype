
import type { Font } from '@godot/classes/font';


export declare class SystemFont extends Font {

    
    /**     * The raw type is 'PackedStringArray'     */
    public font_names: PackedStringArray;    
    /**     * The raw type is 'bool'     */
    public font_italic: boolean;    
    /**     * The raw type is 'int'     */
    public font_weight: number;    
    /**     * The raw type is 'int'     */
    public font_stretch: number;    
    /**     * The raw type is 'int'     */
    public antialiasing: number;    
    /**     * The raw type is 'bool'     */
    public generate_mipmaps: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_embedded_bitmaps: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_system_fallback: boolean;    
    /**     * The raw type is 'bool'     */
    public force_autohinter: boolean;    
    /**     * The raw type is 'bool'     */
    public modulate_color_glyphs: boolean;    
    /**     * The raw type is 'int'     */
    public hinting: number;    
    /**     * The raw type is 'int'     */
    public subpixel_positioning: number;    
    /**     * The raw type is 'bool'     */
    public keep_rounding_remainders: boolean;    
    /**     * The raw type is 'bool'     */
    public multichannel_signed_distance_field: boolean;    
    /**     * The raw type is 'int'     */
    public msdf_pixel_range: number;    
    /**     * The raw type is 'int'     */
    public msdf_size: number;    
    /**     * The raw type is 'float'     */
    public oversampling: number;
    public set_antialiasing(antialiasing: number): void;
    public get_antialiasing(): number;
    public set_disable_embedded_bitmaps(disableEmbeddedBitmaps: boolean): void;
    public get_disable_embedded_bitmaps(): boolean;
    public set_generate_mipmaps(generateMipmaps: boolean): void;
    public get_generate_mipmaps(): boolean;
    public set_allow_system_fallback(allowSystemFallback: boolean): void;
    public is_allow_system_fallback(): boolean;
    public set_force_autohinter(forceAutohinter: boolean): void;
    public is_force_autohinter(): boolean;
    public set_modulate_color_glyphs(modulate: boolean): void;
    public is_modulate_color_glyphs(): boolean;
    public set_hinting(hinting: number): void;
    public get_hinting(): number;
    public set_subpixel_positioning(subpixelPositioning: number): void;
    public get_subpixel_positioning(): number;
    public set_keep_rounding_remainders(keeroundingRemainders: boolean): void;
    public get_keep_rounding_remainders(): boolean;
    public set_multichannel_signed_distance_field(msdf: boolean): void;
    public is_multichannel_signed_distance_field(): boolean;
    public set_msdf_pixel_range(msdfPixelRange: number): void;
    public get_msdf_pixel_range(): number;
    public set_msdf_size(msdfSize: number): void;
    public get_msdf_size(): number;
    public set_oversampling(oversampling: number): void;
    public get_oversampling(): number;
    public get_font_names(): PackedStringArray;
    public set_font_names(names: PackedStringArray): void;
    public get_font_italic(): boolean;
    public set_font_italic(italic: boolean): void;
    public set_font_weight(weight: number): void;
    public set_font_stretch(stretch: number): void;


}

