
import type { Font } from '@godot/classes/font';
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';
import type { TriangleMesh } from '@godot/classes/triangle_mesh';


export declare class Label3D extends GeometryInstance3D {

    
    /**     * The raw type is 'float'     */
    public pixel_size: number;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'int'     */
    public billboard: number;    
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
    /**     * The raw type is 'int'     */
    public outline_render_priority: number;    
    /**     * The raw type is 'Color'     */
    public modulate: Color;    
    /**     * The raw type is 'Color'     */
    public outline_modulate: Color;    
    /**     * The raw type is 'String'     */
    public text: GDString | StringName | string;    
    /**     * The raw type is 'Font'     */
    public font: Font;    
    /**     * The raw type is 'int'     */
    public font_size: number;    
    /**     * The raw type is 'int'     */
    public outline_size: number;    
    /**     * The raw type is 'int'     */
    public horizontal_alignment: number;    
    /**     * The raw type is 'int'     */
    public vertical_alignment: number;    
    /**     * The raw type is 'bool'     */
    public uppercase: boolean;    
    /**     * The raw type is 'float'     */
    public line_spacing: number;    
    /**     * The raw type is 'int'     */
    public autowrap_mode: number;    
    /**     * The raw type is 'int'     */
    public autowrap_trim_flags: number;    
    /**     * The raw type is 'int'     */
    public justification_flags: number;    
    /**     * The raw type is 'float'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public structured_text_bidi_override: number;    
    /**     * The raw type is 'Array'     */
    public structured_text_bidi_override_options: GDArray | Array;
    public set_horizontal_alignment(alignment: number): void;
    public get_horizontal_alignment(): number;
    public set_vertical_alignment(alignment: number): void;
    public get_vertical_alignment(): number;
    public set_modulate(modulate: Color): void;
    public get_modulate(): Color;
    public set_outline_modulate(modulate: Color): void;
    public get_outline_modulate(): Color;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_structured_text_bidi_override(parser: number): void;
    public get_structured_text_bidi_override(): number;
    public set_structured_text_bidi_override_options(args: GDArray | Array): void;
    public get_structured_text_bidi_override_options(): GDArray;
    public set_uppercase(enable: boolean): void;
    public is_uppercase(): boolean;
    public set_render_priority(priority: number): void;
    public get_render_priority(): number;
    public set_outline_render_priority(priority: number): void;
    public get_outline_render_priority(): number;
    public set_font(font: Font): void;
    public get_font(): Font;
    public set_font_size(size: number): void;
    public get_font_size(): number;
    public set_outline_size(outlineSize: number): void;
    public get_outline_size(): number;
    public set_line_spacing(lineSpacing: number): void;
    public get_line_spacing(): number;
    public set_autowrap_mode(autowramode: number): void;
    public get_autowrap_mode(): number;
    public set_autowrap_trim_flags(autowratrimFlags: number): void;
    public get_autowrap_trim_flags(): number;
    public set_justification_flags(justificationFlags: number): void;
    public get_justification_flags(): number;
    public set_width(width: number): void;
    public get_width(): number;
    public set_pixel_size(pixelSize: number): void;
    public get_pixel_size(): number;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_draw_flag(flag: number, enabled: boolean): void;
    public get_draw_flag(flag: number): boolean;
    public set_billboard_mode(mode: number): void;
    public get_billboard_mode(): number;
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
    public set_texture_filter(mode: number): void;
    public get_texture_filter(): number;
    public generate_triangle_mesh(): TriangleMesh;


    public static readonly DrawFlags: {
        FLAG_SHADED: 0;
        FLAG_DOUBLE_SIDED: 1;
        FLAG_DISABLE_DEPTH_TEST: 2;
        FLAG_FIXED_SIZE: 3;
        FLAG_MAX: 4;
    };
    public static readonly AlphaCutMode: {
        ALPHA_CUT_DISABLED: 0;
        ALPHA_CUT_DISCARD: 1;
        ALPHA_CUT_OPAQUE_PREPASS: 2;
        ALPHA_CUT_HASH: 3;
    };
}

