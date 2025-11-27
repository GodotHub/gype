
import type { Control } from '@godot/classes/control';
import type { Font } from '@godot/classes/font';
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { RichTextEffect } from '@godot/classes/rich_text_effect';
import type { Texture2D } from '@godot/classes/texture2d';
import type { VScrollBar } from '@godot/classes/v_scroll_bar';


export declare class RichTextLabel extends Control {

    
    /**     * The raw type is 'bool'     */
    public bbcode_enabled: boolean;    
    /**     * The raw type is 'String'     */
    public text: GDString;    
    /**     * The raw type is 'bool'     */
    public fit_content: boolean;    
    /**     * The raw type is 'bool'     */
    public scroll_active: boolean;    
    /**     * The raw type is 'bool'     */
    public scroll_following: boolean;    
    /**     * The raw type is 'bool'     */
    public scroll_following_visible_characters: boolean;    
    /**     * The raw type is 'int'     */
    public autowrap_mode: number;    
    /**     * The raw type is 'int'     */
    public autowrap_trim_flags: number;    
    /**     * The raw type is 'int'     */
    public tab_size: number;    
    /**     * The raw type is 'bool'     */
    public context_menu_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public shortcut_keys_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public horizontal_alignment: number;    
    /**     * The raw type is 'int'     */
    public vertical_alignment: number;    
    /**     * The raw type is 'int'     */
    public justification_flags: number;    
    /**     * The raw type is 'PackedFloat32Array'     */
    public tab_stops: PackedFloat32Array;    
    /**     * The raw type is 'typedarray::24/17:RichTextEffect'     */
    public custom_effects: GDArray;    
    /**     * The raw type is 'bool'     */
    public meta_underlined: boolean;    
    /**     * The raw type is 'bool'     */
    public hint_underlined: boolean;    
    /**     * The raw type is 'bool'     */
    public threaded: boolean;    
    /**     * The raw type is 'int'     */
    public progress_bar_delay: number;    
    /**     * The raw type is 'bool'     */
    public selection_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public deselect_on_focus_loss_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public drag_and_drop_selection_enabled: boolean;    
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
    public get_parsed_text(): GDString;
    public add_text(text: GDString | StringName | string): void;
    public set_text(text: GDString | StringName | string): void;
    public add_hr(width: number = 90, height: number = 2, color: Color = Color(1, 1, 1, 1), alignment: number = 1, widthInPercent: boolean = true, heightInPercent: boolean = false): void;
    public add_image(image: Texture2D, width: number = 0, height: number = 0, color: Color = Color(1, 1, 1, 1), inlineAlign: number = 5, region: Rect2 = Rect2(0, 0, 0, 0), key: any = null, pad: boolean = false, tooltip: GDString | StringName | string = "", widthInPercent: boolean = false, heightInPercent: boolean = false, altText: GDString | StringName | string = ""): void;
    public update_image(key: any, mask: number, image: Texture2D, width: number = 0, height: number = 0, color: Color = Color(1, 1, 1, 1), inlineAlign: number = 5, region: Rect2 = Rect2(0, 0, 0, 0), pad: boolean = false, tooltip: GDString | StringName | string = "", widthInPercent: boolean = false, heightInPercent: boolean = false): void;
    public newline(): void;
    public remove_paragraph(paragraph: number, noInvalidate: boolean = false): boolean;
    public invalidate_paragraph(paragraph: number): boolean;
    public push_font(font: Font, fontSize: number = 0): void;
    public push_font_size(fontSize: number): void;
    public push_normal(): void;
    public push_bold(): void;
    public push_bold_italics(): void;
    public push_italics(): void;
    public push_mono(): void;
    public push_color(color: Color): void;
    public push_outline_size(outlineSize: number): void;
    public push_outline_color(color: Color): void;
    public push_paragraph(alignment: number, baseDirection: number = 0, language: GDString | StringName | string = "", stParser: number = 0, justificationFlags: number = 163, tabStops: PackedFloat32Array = PackedFloat32Array()): void;
    public push_indent(level: number): void;
    public push_list(level: number, _type: number, capitalize: boolean, bullet: GDString | StringName | string = "•"): void;
    public push_meta(data: any, underlineMode: number = 1, tooltip: GDString | StringName | string = ""): void;
    public push_hint(description: GDString | StringName | string): void;
    public push_language(language: GDString | StringName | string): void;
    public push_underline(color: Color = Color(0, 0, 0, 0)): void;
    public push_strikethrough(color: Color = Color(0, 0, 0, 0)): void;
    public push_table(columns: number, inlineAlign: number = 0, alignToRow: number = -1, name: GDString | StringName | string = ""): void;
    public push_dropcap(_string: GDString | StringName | string, font: Font, size: number, dropcamargins: Rect2 = Rect2(0, 0, 0, 0), color: Color = Color(1, 1, 1, 1), outlineSize: number = 0, outlineColor: Color = Color(0, 0, 0, 0)): void;
    public set_table_column_expand(column: number, expand: boolean, ratio: number = 1, shrink: boolean = true): void;
    public set_table_column_name(column: number, name: GDString | StringName | string): void;
    public set_cell_row_background_color(oddRowBg: Color, evenRowBg: Color): void;
    public set_cell_border_color(color: Color): void;
    public set_cell_size_override(minSize: Vector2, maxSize: Vector2): void;
    public set_cell_padding(padding: Rect2): void;
    public push_cell(): void;
    public push_fgcolor(fgcolor: Color): void;
    public push_bgcolor(bgcolor: Color): void;
    public push_customfx(effect: RichTextEffect, env: Dictionary): void;
    public push_context(): void;
    public pop_context(): void;
    public pop(): void;
    public pop_all(): void;
    public clear(): void;
    public set_structured_text_bidi_override(parser: number): void;
    public get_structured_text_bidi_override(): number;
    public set_structured_text_bidi_override_options(args: GDArray | Array): void;
    public get_structured_text_bidi_override_options(): GDArray;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_horizontal_alignment(alignment: number): void;
    public get_horizontal_alignment(): number;
    public set_vertical_alignment(alignment: number): void;
    public get_vertical_alignment(): number;
    public set_justification_flags(justificationFlags: number): void;
    public get_justification_flags(): number;
    public set_tab_stops(tabStops: PackedFloat32Array): void;
    public get_tab_stops(): PackedFloat32Array;
    public set_autowrap_mode(autowramode: number): void;
    public get_autowrap_mode(): number;
    public set_autowrap_trim_flags(autowratrimFlags: number): void;
    public get_autowrap_trim_flags(): number;
    public set_meta_underline(enable: boolean): void;
    public is_meta_underlined(): boolean;
    public set_hint_underline(enable: boolean): void;
    public is_hint_underlined(): boolean;
    public set_scroll_active(active: boolean): void;
    public is_scroll_active(): boolean;
    public set_scroll_follow_visible_characters(follow: boolean): void;
    public is_scroll_following_visible_characters(): boolean;
    public set_scroll_follow(follow: boolean): void;
    public is_scroll_following(): boolean;
    public get_v_scroll_bar(): VScrollBar;
    public scroll_to_line(line: number): void;
    public scroll_to_paragraph(paragraph: number): void;
    public scroll_to_selection(): void;
    public set_tab_size(spaces: number): void;
    public get_tab_size(): number;
    public set_fit_content(enabled: boolean): void;
    public is_fit_content_enabled(): boolean;
    public set_selection_enabled(enabled: boolean): void;
    public is_selection_enabled(): boolean;
    public set_context_menu_enabled(enabled: boolean): void;
    public is_context_menu_enabled(): boolean;
    public set_shortcut_keys_enabled(enabled: boolean): void;
    public is_shortcut_keys_enabled(): boolean;
    public set_deselect_on_focus_loss_enabled(enable: boolean): void;
    public is_deselect_on_focus_loss_enabled(): boolean;
    public set_drag_and_drop_selection_enabled(enable: boolean): void;
    public is_drag_and_drop_selection_enabled(): boolean;
    public get_selection_from(): number;
    public get_selection_to(): number;
    public get_selection_line_offset(): number;
    public select_all(): void;
    public get_selected_text(): GDString;
    public deselect(): void;
    public parse_bbcode(bbcode: GDString | StringName | string): void;
    public append_text(bbcode: GDString | StringName | string): void;
    public get_text(): GDString;
    public is_ready(): boolean;
    public is_finished(): boolean;
    public set_threaded(threaded: boolean): void;
    public is_threaded(): boolean;
    public set_progress_bar_delay(delayMs: number): void;
    public get_progress_bar_delay(): number;
    public set_visible_characters(amount: number): void;
    public get_visible_characters(): number;
    public get_visible_characters_behavior(): number;
    public set_visible_characters_behavior(behavior: number): void;
    public set_visible_ratio(ratio: number): void;
    public get_visible_ratio(): number;
    public get_character_line(character: number): number;
    public get_character_paragraph(character: number): number;
    public get_total_character_count(): number;
    public set_use_bbcode(enable: boolean): void;
    public is_using_bbcode(): boolean;
    public get_line_count(): number;
    public get_line_range(line: number): Vector2i;
    public get_visible_line_count(): number;
    public get_paragraph_count(): number;
    public get_visible_paragraph_count(): number;
    public get_content_height(): number;
    public get_content_width(): number;
    public get_line_height(line: number): number;
    public get_line_width(line: number): number;
    public get_visible_content_rect(): Rect2i;
    public get_line_offset(line: number): number;
    public get_paragraph_offset(paragraph: number): number;
    public parse_expressions_for_values(expressions: PackedStringArray): Dictionary;
    public set_effects(effects: GDArray | Array): void;
    public get_effects(): GDArray;
    public install_effect(effect: any): void;
    public reload_effects(): void;
    public get_menu(): PopupMenu;
    public is_menu_visible(): boolean;
    public menu_option(option: number): void;

    
    public readonly meta_clicked: Signal;
    public readonly meta_hover_started: Signal;
    public readonly meta_hover_ended: Signal;
    public readonly finished: Signal;

    public static readonly ListType: {
        LIST_NUMBERS: 0;
        LIST_LETTERS: 1;
        LIST_ROMAN: 2;
        LIST_DOTS: 3;
    };
    public static readonly MenuItems: {
        MENU_COPY: 0;
        MENU_SELECT_ALL: 1;
        MENU_MAX: 2;
    };
    public static readonly MetaUnderline: {
        META_UNDERLINE_NEVER: 0;
        META_UNDERLINE_ALWAYS: 1;
        META_UNDERLINE_ON_HOVER: 2;
    };
    public static readonly ImageUpdateMask: {
        UPDATE_TEXTURE: 1;
        UPDATE_SIZE: 2;
        UPDATE_COLOR: 4;
        UPDATE_ALIGNMENT: 8;
        UPDATE_REGION: 16;
        UPDATE_PAD: 32;
        UPDATE_TOOLTIP: 64;
        UPDATE_WIDTH_IN_PERCENT: 128;
    };
}

