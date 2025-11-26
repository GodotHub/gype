
import type { Control } from '@godot/classes/control';
import type { LabelSettings } from '@godot/classes/label_settings';


export declare class Label extends Control {

    
    /**     * The raw type is 'String'     */
    public text: GDString;    
    /**     * The raw type is 'LabelSettings'     */
    public label_settings: LabelSettings;    
    /**     * The raw type is 'int'     */
    public horizontal_alignment: number;    
    /**     * The raw type is 'int'     */
    public vertical_alignment: number;    
    /**     * The raw type is 'int'     */
    public autowrap_mode: number;    
    /**     * The raw type is 'int'     */
    public autowrap_trim_flags: number;    
    /**     * The raw type is 'int'     */
    public justification_flags: number;    
    /**     * The raw type is 'String'     */
    public paragraph_separator: GDString;    
    /**     * The raw type is 'bool'     */
    public clip_text: boolean;    
    /**     * The raw type is 'int'     */
    public text_overrun_behavior: number;    
    /**     * The raw type is 'String'     */
    public ellipsis_char: GDString;    
    /**     * The raw type is 'bool'     */
    public uppercase: boolean;    
    /**     * The raw type is 'PackedFloat32Array'     */
    public tab_stops: PackedFloat32Array;    
    /**     * The raw type is 'int'     */
    public lines_skipped: number;    
    /**     * The raw type is 'int'     */
    public max_lines_visible: number;    
    /**     * The raw type is 'int'     */
    public visible_characters: number;    
    /**     * The raw type is 'int'     */
    public visible_characters_behavior: number;    
    /**     * The raw type is 'float'     */
    public visible_ratio: number;    
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
    public set_label_settings(settings: LabelSettings): void;
    public get_label_settings(): LabelSettings;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_paragraph_separator(paragraphSeparator: GDString | StringName | string): void;
    public get_paragraph_separator(): GDString;
    public set_autowrap_mode(autowramode: number): void;
    public get_autowrap_mode(): number;
    public set_autowrap_trim_flags(autowratrimFlags: number): void;
    public get_autowrap_trim_flags(): number;
    public set_justification_flags(justificationFlags: number): void;
    public get_justification_flags(): number;
    public set_clip_text(enable: boolean): void;
    public is_clipping_text(): boolean;
    public set_tab_stops(tabStops: PackedFloat32Array): void;
    public get_tab_stops(): PackedFloat32Array;
    public set_text_overrun_behavior(overrunBehavior: number): void;
    public get_text_overrun_behavior(): number;
    public set_ellipsis_char(char: GDString | StringName | string): void;
    public get_ellipsis_char(): GDString;
    public set_uppercase(enable: boolean): void;
    public is_uppercase(): boolean;
    public get_line_height(line: number = -1): number;
    public get_line_count(): number;
    public get_visible_line_count(): number;
    public get_total_character_count(): number;
    public set_visible_characters(amount: number): void;
    public get_visible_characters(): number;
    public get_visible_characters_behavior(): number;
    public set_visible_characters_behavior(behavior: number): void;
    public set_visible_ratio(ratio: number): void;
    public get_visible_ratio(): number;
    public set_lines_skipped(linesSkipped: number): void;
    public get_lines_skipped(): number;
    public set_max_lines_visible(linesVisible: number): void;
    public get_max_lines_visible(): number;
    public set_structured_text_bidi_override(parser: number): void;
    public get_structured_text_bidi_override(): number;
    public set_structured_text_bidi_override_options(args: GDArray): void;
    public get_structured_text_bidi_override_options(): GDArray;
    public get_character_bounds(pos: number): Rect2;


}

