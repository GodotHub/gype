
import type { Dictionary } from '@godot/builtins/dictionary';
import type { Font } from '@godot/classes/font';
import type { GDString } from '@godot/builtins/gd_string';
import type { Image } from '@godot/classes/image';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class FontFile extends Font {

    
    /**     * The raw type is 'PackedByteArray'     */
    public data: PackedByteArray;    
    /**     * The raw type is 'bool'     */
    public generate_mipmaps: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_embedded_bitmaps: boolean;    
    /**     * The raw type is 'int'     */
    public antialiasing: number;    
    /**     * The raw type is 'String'     */
    public font_name: GDString;    
    /**     * The raw type is 'String'     */
    public style_name: GDString;    
    /**     * The raw type is 'int'     */
    public font_style: number;    
    /**     * The raw type is 'int'     */
    public font_weight: number;    
    /**     * The raw type is 'int'     */
    public font_stretch: number;    
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
    /**     * The raw type is 'bool'     */
    public allow_system_fallback: boolean;    
    /**     * The raw type is 'bool'     */
    public force_autohinter: boolean;    
    /**     * The raw type is 'bool'     */
    public modulate_color_glyphs: boolean;    
    /**     * The raw type is 'int'     */
    public hinting: number;    
    /**     * The raw type is 'int'     */
    public fixed_size: number;    
    /**     * The raw type is 'int'     */
    public fixed_size_scale_mode: number;    
    /**     * The raw type is 'Dictionary'     */
    public opentype_feature_overrides: Dictionary;    
    /**     * The raw type is 'float'     */
    public oversampling: number;
    public load_bitmap_font(path: GDString | StringName | string): number;
    public load_dynamic_font(path: GDString | StringName | string): number;
    public set_data(data: PackedByteArray): void;
    public get_data(): PackedByteArray;
    public set_font_name(name: GDString | StringName | string): void;
    public set_font_style_name(name: GDString | StringName | string): void;
    public set_font_style(style: number): void;
    public set_font_weight(weight: number): void;
    public set_font_stretch(stretch: number): void;
    public set_antialiasing(antialiasing: number): void;
    public get_antialiasing(): number;
    public set_disable_embedded_bitmaps(disableEmbeddedBitmaps: boolean): void;
    public get_disable_embedded_bitmaps(): boolean;
    public set_generate_mipmaps(generateMipmaps: boolean): void;
    public get_generate_mipmaps(): boolean;
    public set_multichannel_signed_distance_field(msdf: boolean): void;
    public is_multichannel_signed_distance_field(): boolean;
    public set_msdf_pixel_range(msdfPixelRange: number): void;
    public get_msdf_pixel_range(): number;
    public set_msdf_size(msdfSize: number): void;
    public get_msdf_size(): number;
    public set_fixed_size(fixedSize: number): void;
    public get_fixed_size(): number;
    public set_fixed_size_scale_mode(fixedSizeScaleMode: number): void;
    public get_fixed_size_scale_mode(): number;
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
    public set_oversampling(oversampling: number): void;
    public get_oversampling(): number;
    public get_cache_count(): number;
    public clear_cache(): void;
    public remove_cache(cacheIndex: number): void;
    public get_size_cache_list(cacheIndex: number): Array<any>;
    public clear_size_cache(cacheIndex: number): void;
    public remove_size_cache(cacheIndex: number, size: Vector2i): void;
    public set_variation_coordinates(cacheIndex: number, variationCoordinates: Dictionary): void;
    public get_variation_coordinates(cacheIndex: number): Dictionary;
    public set_embolden(cacheIndex: number, strength: number): void;
    public get_embolden(cacheIndex: number): number;
    public set_transform(cacheIndex: number, transform: Transform2D): void;
    public get_transform(cacheIndex: number): Transform2D;
    public set_extra_spacing(cacheIndex: number, spacing: number, value: number): void;
    public get_extra_spacing(cacheIndex: number, spacing: number): number;
    public set_extra_baseline_offset(cacheIndex: number, baselineOffset: number): void;
    public get_extra_baseline_offset(cacheIndex: number): number;
    public set_face_index(cacheIndex: number, faceIndex: number): void;
    public get_face_index(cacheIndex: number): number;
    public set_cache_ascent(cacheIndex: number, size: number, ascent: number): void;
    public get_cache_ascent(cacheIndex: number, size: number): number;
    public set_cache_descent(cacheIndex: number, size: number, descent: number): void;
    public get_cache_descent(cacheIndex: number, size: number): number;
    public set_cache_underline_position(cacheIndex: number, size: number, underlinePosition: number): void;
    public get_cache_underline_position(cacheIndex: number, size: number): number;
    public set_cache_underline_thickness(cacheIndex: number, size: number, underlineThickness: number): void;
    public get_cache_underline_thickness(cacheIndex: number, size: number): number;
    public set_cache_scale(cacheIndex: number, size: number, scale: number): void;
    public get_cache_scale(cacheIndex: number, size: number): number;
    public get_texture_count(cacheIndex: number, size: Vector2i): number;
    public clear_textures(cacheIndex: number, size: Vector2i): void;
    public remove_texture(cacheIndex: number, size: Vector2i, textureIndex: number): void;
    public set_texture_image(cacheIndex: number, size: Vector2i, textureIndex: number, image: Image): void;
    public get_texture_image(cacheIndex: number, size: Vector2i, textureIndex: number): Image;
    public set_texture_offsets(cacheIndex: number, size: Vector2i, textureIndex: number, offset: PackedInt32Array): void;
    public get_texture_offsets(cacheIndex: number, size: Vector2i, textureIndex: number): PackedInt32Array;
    public get_glyph_list(cacheIndex: number, size: Vector2i): PackedInt32Array;
    public clear_glyphs(cacheIndex: number, size: Vector2i): void;
    public remove_glyph(cacheIndex: number, size: Vector2i, glyph: number): void;
    public set_glyph_advance(cacheIndex: number, size: number, glyph: number, advance: Vector2): void;
    public get_glyph_advance(cacheIndex: number, size: number, glyph: number): Vector2;
    public set_glyph_offset(cacheIndex: number, size: Vector2i, glyph: number, offset: Vector2): void;
    public get_glyph_offset(cacheIndex: number, size: Vector2i, glyph: number): Vector2;
    public set_glyph_size(cacheIndex: number, size: Vector2i, glyph: number, glSize: Vector2): void;
    public get_glyph_size(cacheIndex: number, size: Vector2i, glyph: number): Vector2;
    public set_glyph_uv_rect(cacheIndex: number, size: Vector2i, glyph: number, uvRect: Rect2): void;
    public get_glyph_uv_rect(cacheIndex: number, size: Vector2i, glyph: number): Rect2;
    public set_glyph_texture_idx(cacheIndex: number, size: Vector2i, glyph: number, textureIdx: number): void;
    public get_glyph_texture_idx(cacheIndex: number, size: Vector2i, glyph: number): number;
    public get_kerning_list(cacheIndex: number, size: number): Array<any>;
    public clear_kerning_map(cacheIndex: number, size: number): void;
    public remove_kerning(cacheIndex: number, size: number, glyphPair: Vector2i): void;
    public set_kerning(cacheIndex: number, size: number, glyphPair: Vector2i, kerning: Vector2): void;
    public get_kerning(cacheIndex: number, size: number, glyphPair: Vector2i): Vector2;
    public render_range(cacheIndex: number, size: Vector2i, start: number, end: number): void;
    public render_glyph(cacheIndex: number, size: Vector2i, index: number): void;
    public set_language_support_override(language: GDString | StringName | string, supported: boolean): void;
    public get_language_support_override(language: GDString | StringName | string): boolean;
    public remove_language_support_override(language: GDString | StringName | string): void;
    public get_language_support_overrides(): PackedStringArray;
    public set_script_support_override(script: GDString | StringName | string, supported: boolean): void;
    public get_script_support_override(script: GDString | StringName | string): boolean;
    public remove_script_support_override(script: GDString | StringName | string): void;
    public get_script_support_overrides(): PackedStringArray;
    public set_opentype_feature_overrides(overrides: Dictionary): void;
    public get_opentype_feature_overrides(): Dictionary;
    public get_glyph_index(size: number, char: number, variationSelector: number): number;
    public get_char_from_glyph_index(size: number, glyphIndex: number): number;


}

