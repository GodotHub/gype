
import type { Font } from '@godot/classes/font';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class TextParagraph extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public direction: number;    
    /**     * The raw type is 'String'     */
    public custom_punctuation: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public orientation: number;    
    /**     * The raw type is 'bool'     */
    public preserve_invalid: boolean;    
    /**     * The raw type is 'bool'     */
    public preserve_control: boolean;    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'int'     */
    public break_flags: number;    
    /**     * The raw type is 'int'     */
    public justification_flags: number;    
    /**     * The raw type is 'int'     */
    public text_overrun_behavior: number;    
    /**     * The raw type is 'String'     */
    public ellipsis_char: GDString | StringName | string;    
    /**     * The raw type is 'float'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public max_lines_visible: number;    
    /**     * The raw type is 'float'     */
    public line_spacing: number;
    public clear(): void;
    public set_direction(direction: number): void;
    public get_direction(): number;
    public get_inferred_direction(): number;
    public set_custom_punctuation(customPunctuation: GDString | StringName | string): void;
    public get_custom_punctuation(): GDString;
    public set_orientation(orientation: number): void;
    public get_orientation(): number;
    public set_preserve_invalid(enabled: boolean): void;
    public get_preserve_invalid(): boolean;
    public set_preserve_control(enabled: boolean): void;
    public get_preserve_control(): boolean;
    public set_bidi_override(override: GDArray | Array): void;
    public set_dropcap(text: GDString | StringName | string, font: Font, fontSize: number, dropcamargins: Rect2 = Rect2(0, 0, 0, 0), language: GDString | StringName | string = ""): boolean;
    public clear_dropcap(): void;
    public add_string(text: GDString | StringName | string, font: Font, fontSize: number, language: GDString | StringName | string = "", meta: any = null): boolean;
    public add_object(key: any, size: Vector2, inlineAlign: number = 5, length: number = 1, baseline: number = 0.0): boolean;
    public resize_object(key: any, size: Vector2, inlineAlign: number = 5, baseline: number = 0.0): boolean;
    public set_alignment(alignment: number): void;
    public get_alignment(): number;
    public tab_align(tabStops: PackedFloat32Array): void;
    public set_break_flags(flags: number): void;
    public get_break_flags(): number;
    public set_justification_flags(flags: number): void;
    public get_justification_flags(): number;
    public set_text_overrun_behavior(overrunBehavior: number): void;
    public get_text_overrun_behavior(): number;
    public set_ellipsis_char(char: GDString | StringName | string): void;
    public get_ellipsis_char(): GDString;
    public set_width(width: number): void;
    public get_width(): number;
    public get_non_wrapped_size(): Vector2;
    public get_size(): Vector2;
    public get_rid(): RID;
    public get_line_rid(line: number): RID;
    public get_dropcap_rid(): RID;
    public get_range(): Vector2i;
    public get_line_count(): number;
    public set_max_lines_visible(maxLinesVisible: number): void;
    public get_max_lines_visible(): number;
    public set_line_spacing(lineSpacing: number): void;
    public get_line_spacing(): number;
    public get_line_objects(line: number): GDArray;
    public get_line_object_rect(line: number, key: any): Rect2;
    public get_line_size(line: number): Vector2;
    public get_line_range(line: number): Vector2i;
    public get_line_ascent(line: number): number;
    public get_line_descent(line: number): number;
    public get_line_width(line: number): number;
    public get_line_underline_position(line: number): number;
    public get_line_underline_thickness(line: number): number;
    public get_dropcap_size(): Vector2;
    public get_dropcap_lines(): number;
    public draw(canvas: RID, pos: Vector2, color: Color = Color(1, 1, 1, 1), dcColor: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_outline(canvas: RID, pos: Vector2, outlineSize: number = 1, color: Color = Color(1, 1, 1, 1), dcColor: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_line(canvas: RID, pos: Vector2, line: number, color: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_line_outline(canvas: RID, pos: Vector2, line: number, outlineSize: number = 1, color: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_dropcap(canvas: RID, pos: Vector2, color: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_dropcap_outline(canvas: RID, pos: Vector2, outlineSize: number = 1, color: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public hit_test(coords: Vector2): number;


}

