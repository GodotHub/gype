
import type { Color } from '@godot/builtins/color';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { RID } from '@godot/builtins/rid';
import type { Resource } from '@godot/classes/resource';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Font extends Resource {

    
    /**     * The raw type is 'typedarray::24/17:Font'     */
    public fallbacks: Array<any>;
    public set_fallbacks(fallbacks: Array<any>): void;
    public get_fallbacks(): Array<any>;
    public find_variation(variationCoordinates: Dictionary, faceIndex: number = 0, strength: number = 0.0, transform: Transform2D = Transform2D(1, 0, 0, 1, 0, 0), spacingTop: number = 0, spacingBottom: number = 0, spacingSpace: number = 0, spacingGlyph: number = 0, baselineOffset: number = 0.0): RID;
    public get_rids(): Array<any>;
    public get_height(fontSize: number = 16): number;
    public get_ascent(fontSize: number = 16): number;
    public get_descent(fontSize: number = 16): number;
    public get_underline_position(fontSize: number = 16): number;
    public get_underline_thickness(fontSize: number = 16): number;
    public get_font_name(): GDString;
    public get_font_style_name(): GDString;
    public get_ot_name_strings(): Dictionary;
    public get_font_style(): number;
    public get_font_weight(): number;
    public get_font_stretch(): number;
    public get_spacing(spacing: number): number;
    public get_opentype_features(): Dictionary;
    public set_cache_capacity(singleLine: number, multiLine: number): void;
    public get_string_size(text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, justificationFlags: number = 3, direction: number = 0, orientation: number = 0): Vector2;
    public get_multiline_string_size(text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, maxLines: number = -1, brkFlags: number = 3, justificationFlags: number = 3, direction: number = 0, orientation: number = 0): Vector2;
    public draw_string(canvasItem: RID, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, modulate: Color = Color(1, 1, 1, 1), justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_multiline_string(canvasItem: RID, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, maxLines: number = -1, modulate: Color = Color(1, 1, 1, 1), brkFlags: number = 3, justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_string_outline(canvasItem: RID, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, size: number = 1, modulate: Color = Color(1, 1, 1, 1), justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public draw_multiline_string_outline(canvasItem: RID, pos: Vector2, text: GDString | StringName | string, alignment: number = 0, width: number = -1, fontSize: number = 16, maxLines: number = -1, size: number = 1, modulate: Color = Color(1, 1, 1, 1), brkFlags: number = 3, justificationFlags: number = 3, direction: number = 0, orientation: number = 0, oversampling: number = 0.0): void;
    public get_char_size(char: number, fontSize: number): Vector2;
    public draw_char(canvasItem: RID, pos: Vector2, char: number, fontSize: number, modulate: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): number;
    public draw_char_outline(canvasItem: RID, pos: Vector2, char: number, fontSize: number, size: number = -1, modulate: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): number;
    public has_char(char: number): boolean;
    public get_supported_chars(): GDString;
    public is_language_supported(language: GDString | StringName | string): boolean;
    public is_script_supported(script: GDString | StringName | string): boolean;
    public get_supported_feature_list(): Dictionary;
    public get_supported_variation_list(): Dictionary;
    public get_face_count(): number;


}

