
import type { Font } from '@godot/classes/font';
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class TextMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'String'     */
    public text: GDString;    
    /**     * The raw type is 'Font'     */
    public font: Font;    
    /**     * The raw type is 'int'     */
    public font_size: number;    
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
    public justification_flags: number;    
    /**     * The raw type is 'float'     */
    public pixel_size: number;    
    /**     * The raw type is 'float'     */
    public curve_step: number;    
    /**     * The raw type is 'float'     */
    public depth: number;    
    /**     * The raw type is 'float'     */
    public width: number;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString;    
    /**     * The raw type is 'int'     */
    public structured_text_bidi_override: number;    
    /**     * The raw type is 'Array'     */
    public structured_text_bidi_override_options: GDArray;
    public set_horizontal_alignment(alignment: number): void;
    public get_horizontal_alignment(): number;
    public set_vertical_alignment(alignment: number): void;
    public get_vertical_alignment(): number;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public set_font(font: Font): void;
    public get_font(): Font;
    public set_font_size(fontSize: number): void;
    public get_font_size(): number;
    public set_line_spacing(lineSpacing: number): void;
    public get_line_spacing(): number;
    public set_autowrap_mode(autowramode: number): void;
    public get_autowrap_mode(): number;
    public set_justification_flags(justificationFlags: number): void;
    public get_justification_flags(): number;
    public set_depth(depth: number): void;
    public get_depth(): number;
    public set_width(width: number): void;
    public get_width(): number;
    public set_pixel_size(pixelSize: number): void;
    public get_pixel_size(): number;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_curve_step(curveStep: number): void;
    public get_curve_step(): number;
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


}

