
import type { Color } from '@godot/builtins/color';
import type { Font } from '@godot/classes/font';
import type { Resource } from '@godot/classes/resource';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class LabelSettings extends Resource {

    
    /**     * The raw type is 'float'     */
    public line_spacing: number;    
    /**     * The raw type is 'float'     */
    public paragraph_spacing: number;    
    /**     * The raw type is 'Font'     */
    public font: Font;    
    /**     * The raw type is 'int'     */
    public font_size: number;    
    /**     * The raw type is 'Color'     */
    public font_color: Color;    
    /**     * The raw type is 'int'     */
    public outline_size: number;    
    /**     * The raw type is 'Color'     */
    public outline_color: Color;    
    /**     * The raw type is 'int'     */
    public shadow_size: number;    
    /**     * The raw type is 'Color'     */
    public shadow_color: Color;    
    /**     * The raw type is 'Vector2'     */
    public shadow_offset: Vector2;    
    /**     * The raw type is 'int'     */
    public stacked_outline_count: number;    
    /**     * The raw type is 'int'     */
    public stacked_shadow_count: number;
    public set_line_spacing(spacing: number): void;
    public get_line_spacing(): number;
    public set_paragraph_spacing(spacing: number): void;
    public get_paragraph_spacing(): number;
    public set_font(font: Font): void;
    public get_font(): Font;
    public set_font_size(size: number): void;
    public get_font_size(): number;
    public set_font_color(color: Color): void;
    public get_font_color(): Color;
    public set_outline_size(size: number): void;
    public get_outline_size(): number;
    public set_outline_color(color: Color): void;
    public get_outline_color(): Color;
    public set_shadow_size(size: number): void;
    public get_shadow_size(): number;
    public set_shadow_color(color: Color): void;
    public get_shadow_color(): Color;
    public set_shadow_offset(offset: Vector2): void;
    public get_shadow_offset(): Vector2;
    public get_stacked_outline_count(): number;
    public set_stacked_outline_count(count: number): void;
    public add_stacked_outline(index: number = -1): void;
    public move_stacked_outline(fromIndex: number, toPosition: number): void;
    public remove_stacked_outline(index: number): void;
    public set_stacked_outline_size(index: number, size: number): void;
    public get_stacked_outline_size(index: number): number;
    public set_stacked_outline_color(index: number, color: Color): void;
    public get_stacked_outline_color(index: number): Color;
    public get_stacked_shadow_count(): number;
    public set_stacked_shadow_count(count: number): void;
    public add_stacked_shadow(index: number = -1): void;
    public move_stacked_shadow(fromIndex: number, toPosition: number): void;
    public remove_stacked_shadow(index: number): void;
    public set_stacked_shadow_offset(index: number, offset: Vector2): void;
    public get_stacked_shadow_offset(index: number): Vector2;
    public set_stacked_shadow_color(index: number, color: Color): void;
    public get_stacked_shadow_color(index: number): Color;
    public set_stacked_shadow_outline_size(index: number, size: number): void;
    public get_stacked_shadow_outline_size(index: number): number;


}

