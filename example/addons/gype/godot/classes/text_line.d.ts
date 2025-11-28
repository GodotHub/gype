
import type { Font } from '@godot/classes/font';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class TextLine extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public direction: number;    
    /**     * The raw type is 'int'     */
    public orientation: number;    
    /**     * The raw type is 'bool'     */
    public preserve_invalid: boolean;    
    /**     * The raw type is 'bool'     */
    public preserve_control: boolean;    
    /**     * The raw type is 'float'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'int'     */
    public flags: number;    
    /**     * The raw type is 'int'     */
    public text_overrun_behavior: number;    
    /**     * The raw type is 'String'     */
    public ellipsis_char: GDString | StringName | string;
    public clear(): void;
    public set_direction(direction: number): void;
    public get_direction(): number;
    public get_inferred_direction(): number;
    public set_orientation(orientation: number): void;
    public get_orientation(): number;
    public set_preserve_invalid(enabled: boolean): void;
    public get_preserve_invalid(): boolean;
    public set_preserve_control(enabled: boolean): void;
    public get_preserve_control(): boolean;
    public set_bidi_override(override: GDArray | Array): void;
    public add_string(text: GDString | StringName | string, font: Font, fontSize: number, language: GDString | StringName | string = "", meta: any = null): boolean;
    public add_object(key: any, size: Vector2, inlineAlign: number = 5, length: number = 1, baseline: number = 0.0): boolean;
    public resize_object(key: any, size: Vector2, inlineAlign: number = 5, baseline: number = 0.0): boolean;
    public set_width(width: number): void;
    public get_width(): number;
    public set_horizontal_alignment(alignment: number): void;
    public get_horizontal_alignment(): number;
    public tab_align(tabStops: PackedFloat32Array): void;
    public set_flags(flags: number): void;
    public get_flags(): number;
    public set_text_overrun_behavior(overrunBehavior: number): void;
    public get_text_overrun_behavior(): number;
    public set_ellipsis_char(char: GDString | StringName | string): void;
    public get_ellipsis_char(): GDString;
    public get_objects(): GDArray;
    public get_object_rect(key: any): Rect2;
    public get_size(): Vector2;
    public get_rid(): RID;
    public get_line_ascent(): number;
    public get_line_descent(): number;
    public get_line_width(): number;
    public get_line_underline_position(): number;
    public get_line_underline_thickness(): number;
    public draw(canvas: RID, pos: Vector2, color: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public draw_outline(canvas: RID, pos: Vector2, outlineSize: number = 1, color: Color = Color(1, 1, 1, 1), oversampling: number = 0.0): void;
    public hit_test(coords: number): number;


}

