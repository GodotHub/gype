
import type { Callable } from '@godot/builtins/callable';
import type { Color } from '@godot/builtins/color';
import type { Control } from '@godot/classes/control';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { HScrollBar } from '@godot/classes/h_scroll_bar';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { Rect2i } from '@godot/builtins/rect2i';
import type { Signal } from '@godot/builtins/signal';
import type { SyntaxHighlighter } from '@godot/classes/syntax_highlighter';
import type { Texture2D } from '@godot/classes/texture2d';
import type { VScrollBar } from '@godot/classes/v_scroll_bar';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class TextEdit extends Control {

    
    /**     * The raw type is 'String'     */
    public text: GDString;    
    /**     * The raw type is 'String'     */
    public placeholder_text: GDString;    
    /**     * The raw type is 'bool'     */
    public editable: boolean;    
    /**     * The raw type is 'bool'     */
    public context_menu_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public emoji_menu_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public backspace_deletes_composite_character_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public shortcut_keys_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public selecting_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public deselect_on_focus_loss_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public drag_and_drop_selection_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public virtual_keyboard_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public virtual_keyboard_show_on_focus: boolean;    
    /**     * The raw type is 'bool'     */
    public middle_mouse_paste_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public empty_selection_clipboard_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public wrap_mode: number;    
    /**     * The raw type is 'int'     */
    public autowrap_mode: number;    
    /**     * The raw type is 'bool'     */
    public indent_wrapped_lines: boolean;    
    /**     * The raw type is 'bool'     */
    public tab_input_mode: boolean;    
    /**     * The raw type is 'bool'     */
    public scroll_smooth: boolean;    
    /**     * The raw type is 'float'     */
    public scroll_v_scroll_speed: number;    
    /**     * The raw type is 'bool'     */
    public scroll_past_end_of_file: boolean;    
    /**     * The raw type is 'float'     */
    public scroll_vertical: number;    
    /**     * The raw type is 'int'     */
    public scroll_horizontal: number;    
    /**     * The raw type is 'bool'     */
    public scroll_fit_content_height: boolean;    
    /**     * The raw type is 'bool'     */
    public scroll_fit_content_width: boolean;    
    /**     * The raw type is 'bool'     */
    public minimap_draw: boolean;    
    /**     * The raw type is 'int'     */
    public minimap_width: number;    
    /**     * The raw type is 'int'     */
    public caret_type: number;    
    /**     * The raw type is 'bool'     */
    public caret_blink: boolean;    
    /**     * The raw type is 'float'     */
    public caret_blink_interval: number;    
    /**     * The raw type is 'bool'     */
    public caret_draw_when_editable_disabled: boolean;    
    /**     * The raw type is 'bool'     */
    public caret_move_on_right_click: boolean;    
    /**     * The raw type is 'bool'     */
    public caret_mid_grapheme: boolean;    
    /**     * The raw type is 'bool'     */
    public caret_multiple: boolean;    
    /**     * The raw type is 'bool'     */
    public use_default_word_separators: boolean;    
    /**     * The raw type is 'bool'     */
    public use_custom_word_separators: boolean;    
    /**     * The raw type is 'String'     */
    public custom_word_separators: GDString;    
    /**     * The raw type is 'SyntaxHighlighter'     */
    public syntax_highlighter: SyntaxHighlighter;    
    /**     * The raw type is 'bool'     */
    public highlight_all_occurrences: boolean;    
    /**     * The raw type is 'bool'     */
    public highlight_current_line: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_control_chars: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_tabs: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_spaces: boolean;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString;    
    /**     * The raw type is 'int'     */
    public structured_text_bidi_override: number;    
    /**     * The raw type is 'Array'     */
    public structured_text_bidi_override_options: GDArray;
    public _handle_unicode_input(unicodeChar: number, caretIndex: number): void;
    public _backspace(caretIndex: number): void;
    public _cut(caretIndex: number): void;
    public _copy(caretIndex: number): void;
    public _paste(caretIndex: number): void;
    public _paste_primary_clipboard(caretIndex: number): void;
    public has_ime_text(): boolean;
    public cancel_ime(): void;
    public apply_ime(): void;
    public set_editable(enabled: boolean): void;
    public is_editable(): boolean;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_structured_text_bidi_override(parser: number): void;
    public get_structured_text_bidi_override(): number;
    public set_structured_text_bidi_override_options(args: GDArray): void;
    public get_structured_text_bidi_override_options(): GDArray;
    public set_tab_size(size: number): void;
    public get_tab_size(): number;
    public set_indent_wrapped_lines(enabled: boolean): void;
    public is_indent_wrapped_lines(): boolean;
    public set_tab_input_mode(enabled: boolean): void;
    public get_tab_input_mode(): boolean;
    public set_overtype_mode_enabled(enabled: boolean): void;
    public is_overtype_mode_enabled(): boolean;
    public set_context_menu_enabled(enabled: boolean): void;
    public is_context_menu_enabled(): boolean;
    public set_emoji_menu_enabled(enable: boolean): void;
    public is_emoji_menu_enabled(): boolean;
    public set_backspace_deletes_composite_character_enabled(enable: boolean): void;
    public is_backspace_deletes_composite_character_enabled(): boolean;
    public set_shortcut_keys_enabled(enabled: boolean): void;
    public is_shortcut_keys_enabled(): boolean;
    public set_virtual_keyboard_enabled(enabled: boolean): void;
    public is_virtual_keyboard_enabled(): boolean;
    public set_virtual_keyboard_show_on_focus(showOnFocus: boolean): void;
    public get_virtual_keyboard_show_on_focus(): boolean;
    public set_middle_mouse_paste_enabled(enabled: boolean): void;
    public is_middle_mouse_paste_enabled(): boolean;
    public set_empty_selection_clipboard_enabled(enabled: boolean): void;
    public is_empty_selection_clipboard_enabled(): boolean;
    public clear(): void;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public get_line_count(): number;
    public set_placeholder(text: GDString | StringName | string): void;
    public get_placeholder(): GDString;
    public set_line(line: number, newText: GDString | StringName | string): void;
    public get_line(line: number): GDString;
    public get_line_with_ime(line: number): GDString;
    public get_line_width(line: number, wraindex: number = -1): number;
    public get_line_height(): number;
    public get_indent_level(line: number): number;
    public get_first_non_whitespace_column(line: number): number;
    public swap_lines(fromLine: number, toLine: number): void;
    public insert_line_at(line: number, text: GDString | StringName | string): void;
    public remove_line_at(line: number, moveCaretsDown: boolean = true): void;
    public insert_text_at_caret(text: GDString | StringName | string, caretIndex: number = -1): void;
    public insert_text(text: GDString | StringName | string, line: number, column: number, beforeSelectionBegin: boolean = true, beforeSelectionEnd: boolean = false): void;
    public remove_text(fromLine: number, fromColumn: number, toLine: number, toColumn: number): void;
    public get_last_unhidden_line(): number;
    public get_next_visible_line_offset_from(line: number, visibleAmount: number): number;
    public get_next_visible_line_index_offset_from(line: number, wraindex: number, visibleAmount: number): Vector2i;
    public backspace(caretIndex: number = -1): void;
    public cut(caretIndex: number = -1): void;
    public copy(caretIndex: number = -1): void;
    public paste(caretIndex: number = -1): void;
    public paste_primary_clipboard(caretIndex: number = -1): void;
    public start_action(action: number): void;
    public end_action(): void;
    public begin_complex_operation(): void;
    public end_complex_operation(): void;
    public has_undo(): boolean;
    public has_redo(): boolean;
    public undo(): void;
    public redo(): void;
    public clear_undo_history(): void;
    public tag_saved_version(): void;
    public get_version(): number;
    public get_saved_version(): number;
    public set_search_text(searchText: GDString | StringName | string): void;
    public set_search_flags(flags: number): void;
    public search(text: GDString | StringName | string, flags: number, fromLine: number, fromColumn: number): Vector2i;
    public set_tooltip_request_func(callback: Callable): void;
    public get_local_mouse_pos(): Vector2;
    public get_word_at_pos(position: Vector2): GDString;
    public get_line_column_at_pos(position: Vector2i, clamline: boolean = true, clamcolumn: boolean = true): Vector2i;
    public get_pos_at_line_column(line: number, column: number): Vector2i;
    public get_rect_at_line_column(line: number, column: number): Rect2i;
    public get_minimap_line_at_pos(position: Vector2i): number;
    public is_dragging_cursor(): boolean;
    public is_mouse_over_selection(edges: boolean, caretIndex: number = -1): boolean;
    public set_caret_type(_type: number): void;
    public get_caret_type(): number;
    public set_caret_blink_enabled(enable: boolean): void;
    public is_caret_blink_enabled(): boolean;
    public set_caret_blink_interval(interval: number): void;
    public get_caret_blink_interval(): number;
    public set_draw_caret_when_editable_disabled(enable: boolean): void;
    public is_drawing_caret_when_editable_disabled(): boolean;
    public set_move_caret_on_right_click_enabled(enable: boolean): void;
    public is_move_caret_on_right_click_enabled(): boolean;
    public set_caret_mid_grapheme_enabled(enabled: boolean): void;
    public is_caret_mid_grapheme_enabled(): boolean;
    public set_multiple_carets_enabled(enabled: boolean): void;
    public is_multiple_carets_enabled(): boolean;
    public add_caret(line: number, column: number): number;
    public remove_caret(caret: number): void;
    public remove_secondary_carets(): void;
    public get_caret_count(): number;
    public add_caret_at_carets(below: boolean): void;
    public get_sorted_carets(includeIgnoredCarets: boolean = false): PackedInt32Array;
    public collapse_carets(fromLine: number, fromColumn: number, toLine: number, toColumn: number, inclusive: boolean = false): void;
    public merge_overlapping_carets(): void;
    public begin_multicaret_edit(): void;
    public end_multicaret_edit(): void;
    public is_in_mulitcaret_edit(): boolean;
    public multicaret_edit_ignore_caret(caretIndex: number): boolean;
    public is_caret_visible(caretIndex: number = 0): boolean;
    public get_caret_draw_pos(caretIndex: number = 0): Vector2;
    public set_caret_line(line: number, adjustViewport: boolean = true, canBeHidden: boolean = true, wraindex: number = 0, caretIndex: number = 0): void;
    public get_caret_line(caretIndex: number = 0): number;
    public set_caret_column(column: number, adjustViewport: boolean = true, caretIndex: number = 0): void;
    public get_caret_column(caretIndex: number = 0): number;
    public get_next_composite_character_column(line: number, column: number): number;
    public get_previous_composite_character_column(line: number, column: number): number;
    public get_caret_wrap_index(caretIndex: number = 0): number;
    public get_word_under_caret(caretIndex: number = -1): GDString;
    public set_use_default_word_separators(enabled: boolean): void;
    public is_default_word_separators_enabled(): boolean;
    public set_use_custom_word_separators(enabled: boolean): void;
    public is_custom_word_separators_enabled(): boolean;
    public set_custom_word_separators(customWordSeparators: GDString | StringName | string): void;
    public get_custom_word_separators(): GDString;
    public set_selecting_enabled(enable: boolean): void;
    public is_selecting_enabled(): boolean;
    public set_deselect_on_focus_loss_enabled(enable: boolean): void;
    public is_deselect_on_focus_loss_enabled(): boolean;
    public set_drag_and_drop_selection_enabled(enable: boolean): void;
    public is_drag_and_drop_selection_enabled(): boolean;
    public set_selection_mode(mode: number): void;
    public get_selection_mode(): number;
    public select_all(): void;
    public select_word_under_caret(caretIndex: number = -1): void;
    public add_selection_for_next_occurrence(): void;
    public skip_selection_for_next_occurrence(): void;
    public select(originLine: number, originColumn: number, caretLine: number, caretColumn: number, caretIndex: number = 0): void;
    public has_selection(caretIndex: number = -1): boolean;
    public get_selected_text(caretIndex: number = -1): GDString;
    public get_selection_at_line_column(line: number, column: number, includeEdges: boolean = true, onlySelections: boolean = true): number;
    public get_line_ranges_from_carets(onlySelections: boolean = false, mergeAdjacent: boolean = true): Array<any>;
    public get_selection_origin_line(caretIndex: number = 0): number;
    public get_selection_origin_column(caretIndex: number = 0): number;
    public set_selection_origin_line(line: number, canBeHidden: boolean = true, wraindex: number = -1, caretIndex: number = 0): void;
    public set_selection_origin_column(column: number, caretIndex: number = 0): void;
    public get_selection_from_line(caretIndex: number = 0): number;
    public get_selection_from_column(caretIndex: number = 0): number;
    public get_selection_to_line(caretIndex: number = 0): number;
    public get_selection_to_column(caretIndex: number = 0): number;
    public is_caret_after_selection_origin(caretIndex: number = 0): boolean;
    public deselect(caretIndex: number = -1): void;
    public delete_selection(caretIndex: number = -1): void;
    public set_line_wrapping_mode(mode: number): void;
    public get_line_wrapping_mode(): number;
    public set_autowrap_mode(autowramode: number): void;
    public get_autowrap_mode(): number;
    public is_line_wrapped(line: number): boolean;
    public get_line_wrap_count(line: number): number;
    public get_line_wrap_index_at_column(line: number, column: number): number;
    public get_line_wrapped_text(line: number): PackedStringArray;
    public set_smooth_scroll_enabled(enable: boolean): void;
    public is_smooth_scroll_enabled(): boolean;
    public get_v_scroll_bar(): VScrollBar;
    public get_h_scroll_bar(): HScrollBar;
    public set_v_scroll(value: number): void;
    public get_v_scroll(): number;
    public set_h_scroll(value: number): void;
    public get_h_scroll(): number;
    public set_scroll_past_end_of_file_enabled(enable: boolean): void;
    public is_scroll_past_end_of_file_enabled(): boolean;
    public set_v_scroll_speed(speed: number): void;
    public get_v_scroll_speed(): number;
    public set_fit_content_height_enabled(enabled: boolean): void;
    public is_fit_content_height_enabled(): boolean;
    public set_fit_content_width_enabled(enabled: boolean): void;
    public is_fit_content_width_enabled(): boolean;
    public get_scroll_pos_for_line(line: number, wraindex: number = 0): number;
    public set_line_as_first_visible(line: number, wraindex: number = 0): void;
    public get_first_visible_line(): number;
    public set_line_as_center_visible(line: number, wraindex: number = 0): void;
    public set_line_as_last_visible(line: number, wraindex: number = 0): void;
    public get_last_full_visible_line(): number;
    public get_last_full_visible_line_wrap_index(): number;
    public get_visible_line_count(): number;
    public get_visible_line_count_in_range(fromLine: number, toLine: number): number;
    public get_total_visible_line_count(): number;
    public adjust_viewport_to_caret(caretIndex: number = 0): void;
    public center_viewport_to_caret(caretIndex: number = 0): void;
    public set_draw_minimap(enabled: boolean): void;
    public is_drawing_minimap(): boolean;
    public set_minimap_width(width: number): void;
    public get_minimap_width(): number;
    public get_minimap_visible_lines(): number;
    public add_gutter(at: number = -1): void;
    public remove_gutter(gutter: number): void;
    public get_gutter_count(): number;
    public set_gutter_name(gutter: number, name: GDString | StringName | string): void;
    public get_gutter_name(gutter: number): GDString;
    public set_gutter_type(gutter: number, _type: number): void;
    public get_gutter_type(gutter: number): number;
    public set_gutter_width(gutter: number, width: number): void;
    public get_gutter_width(gutter: number): number;
    public set_gutter_draw(gutter: number, draw: boolean): void;
    public is_gutter_drawn(gutter: number): boolean;
    public set_gutter_clickable(gutter: number, clickable: boolean): void;
    public is_gutter_clickable(gutter: number): boolean;
    public set_gutter_overwritable(gutter: number, overwritable: boolean): void;
    public is_gutter_overwritable(gutter: number): boolean;
    public merge_gutters(fromLine: number, toLine: number): void;
    public set_gutter_custom_draw(column: number, drawCallback: Callable): void;
    public get_total_gutter_width(): number;
    public set_line_gutter_metadata(line: number, gutter: number, metadata: any): void;
    public get_line_gutter_metadata(line: number, gutter: number): any;
    public set_line_gutter_text(line: number, gutter: number, text: GDString | StringName | string): void;
    public get_line_gutter_text(line: number, gutter: number): GDString;
    public set_line_gutter_icon(line: number, gutter: number, icon: Texture2D): void;
    public get_line_gutter_icon(line: number, gutter: number): Texture2D;
    public set_line_gutter_item_color(line: number, gutter: number, color: Color): void;
    public get_line_gutter_item_color(line: number, gutter: number): Color;
    public set_line_gutter_clickable(line: number, gutter: number, clickable: boolean): void;
    public is_line_gutter_clickable(line: number, gutter: number): boolean;
    public set_line_background_color(line: number, color: Color): void;
    public get_line_background_color(line: number): Color;
    public set_syntax_highlighter(syntaxHighlighter: SyntaxHighlighter): void;
    public get_syntax_highlighter(): SyntaxHighlighter;
    public set_highlight_current_line(enabled: boolean): void;
    public is_highlight_current_line_enabled(): boolean;
    public set_highlight_all_occurrences(enabled: boolean): void;
    public is_highlight_all_occurrences_enabled(): boolean;
    public get_draw_control_chars(): boolean;
    public set_draw_control_chars(enabled: boolean): void;
    public set_draw_tabs(enabled: boolean): void;
    public is_drawing_tabs(): boolean;
    public set_draw_spaces(enabled: boolean): void;
    public is_drawing_spaces(): boolean;
    public get_menu(): PopupMenu;
    public is_menu_visible(): boolean;
    public menu_option(option: number): void;
    public adjust_carets_after_edit(caret: number, fromLine: number, fromCol: number, toLine: number, toCol: number): void;
    public get_caret_index_edit_order(): PackedInt32Array;
    public get_selection_line(caretIndex: number = 0): number;
    public get_selection_column(caretIndex: number = 0): number;

    
    public readonly text_set: Signal<() => void>;
    public readonly text_changed: Signal<() => void>;
    public readonly lines_edited_from: Signal<(fromLine: number, toLine: number) => void>;
    public readonly caret_changed: Signal<() => void>;
    public readonly gutter_clicked: Signal<(line: number, gutter: number) => void>;
    public readonly gutter_added: Signal<() => void>;
    public readonly gutter_removed: Signal<() => void>;

    public static readonly MenuItems: {
        MENU_CUT: 0;
        MENU_COPY: 1;
        MENU_PASTE: 2;
        MENU_CLEAR: 3;
        MENU_SELECT_ALL: 4;
        MENU_UNDO: 5;
        MENU_REDO: 6;
        MENU_SUBMENU_TEXT_DIR: 7;
        MENU_DIR_INHERITED: 8;
        MENU_DIR_AUTO: 9;
        MENU_DIR_LTR: 10;
        MENU_DIR_RTL: 11;
        MENU_DISPLAY_UCC: 12;
        MENU_SUBMENU_INSERT_UCC: 13;
        MENU_INSERT_LRM: 14;
        MENU_INSERT_RLM: 15;
        MENU_INSERT_LRE: 16;
        MENU_INSERT_RLE: 17;
        MENU_INSERT_LRO: 18;
        MENU_INSERT_RLO: 19;
        MENU_INSERT_PDF: 20;
        MENU_INSERT_ALM: 21;
        MENU_INSERT_LRI: 22;
        MENU_INSERT_RLI: 23;
        MENU_INSERT_FSI: 24;
        MENU_INSERT_PDI: 25;
        MENU_INSERT_ZWJ: 26;
        MENU_INSERT_ZWNJ: 27;
        MENU_INSERT_WJ: 28;
        MENU_INSERT_SHY: 29;
        MENU_EMOJI_AND_SYMBOL: 30;
        MENU_MAX: 31;
    };
    public static readonly EditAction: {
        ACTION_NONE: 0;
        ACTION_TYPING: 1;
        ACTION_BACKSPACE: 2;
        ACTION_DELETE: 3;
    };
    public static readonly SearchFlags: {
        SEARCH_MATCH_CASE: 1;
        SEARCH_WHOLE_WORDS: 2;
        SEARCH_BACKWARDS: 4;
    };
    public static readonly CaretType: {
        CARET_TYPE_LINE: 0;
        CARET_TYPE_BLOCK: 1;
    };
    public static readonly SelectionMode: {
        SELECTION_MODE_NONE: 0;
        SELECTION_MODE_SHIFT: 1;
        SELECTION_MODE_POINTER: 2;
        SELECTION_MODE_WORD: 3;
        SELECTION_MODE_LINE: 4;
    };
    public static readonly LineWrappingMode: {
        LINE_WRAPPING_NONE: 0;
        LINE_WRAPPING_BOUNDARY: 1;
    };
    public static readonly GutterType: {
        GUTTER_TYPE_STRING: 0;
        GUTTER_TYPE_ICON: 1;
        GUTTER_TYPE_CUSTOM: 2;
    };
}

