
import { Texture2D } from "@godot/classes/texture2d";
import { VScrollBar } from "@godot/classes/v_scroll_bar";
import { SyntaxHighlighter } from "@godot/classes/syntax_highlighter";
import { Control } from "@godot/classes/control";
import { PopupMenu } from "@godot/classes/popup_menu";
import { HScrollBar } from "@godot/classes/h_scroll_bar";

export declare class TextEdit extends Control{
  public _handle_unicode_input(_unicode_char: number, _caret_index: number): void;
  public _backspace(_caret_index: number): void;
  public _cut(_caret_index: number): void;
  public _copy(_caret_index: number): void;
  public _paste(_caret_index: number): void;
  public _paste_primary_clipboard(_caret_index: number): void;
  public has_ime_text(): boolean;
  public cancel_ime(): void;
  public apply_ime(): void;
  public set_editable(_enabled: boolean): void;
  public is_editable(): boolean;
  public set_text_direction(_direction: number): void;
  public get_text_direction(): number;
  public set_language(_language: String): void;
  public get_language(): String;
  public set_structured_text_bidi_override(_parser: number): void;
  public get_structured_text_bidi_override(): number;
  public set_structured_text_bidi_override_options(_args: GDArray): void;
  public get_structured_text_bidi_override_options(): GDArray;
  public set_tab_size(_size: number): void;
  public get_tab_size(): number;
  public set_indent_wrapped_lines(_enabled: boolean): void;
  public is_indent_wrapped_lines(): boolean;
  public set_overtype_mode_enabled(_enabled: boolean): void;
  public is_overtype_mode_enabled(): boolean;
  public set_context_menu_enabled(_enabled: boolean): void;
  public is_context_menu_enabled(): boolean;
  public set_shortcut_keys_enabled(_enabled: boolean): void;
  public is_shortcut_keys_enabled(): boolean;
  public set_virtual_keyboard_enabled(_enabled: boolean): void;
  public is_virtual_keyboard_enabled(): boolean;
  public set_middle_mouse_paste_enabled(_enabled: boolean): void;
  public is_middle_mouse_paste_enabled(): boolean;
  public clear(): void;
  public set_text(_text: String): void;
  public get_text(): String;
  public get_line_count(): number;
  public set_placeholder(_text: String): void;
  public get_placeholder(): String;
  public set_line(_line: number, _new_text: String): void;
  public get_line(_line: number): String;
  public get_line_width(_line: number, _wrap_index: number): number;
  public get_line_height(): number;
  public get_indent_level(_line: number): number;
  public get_first_non_whitespace_column(_line: number): number;
  public swap_lines(_from_line: number, _to_line: number): void;
  public insert_line_at(_line: number, _text: String): void;
  public remove_line_at(_line: number, _move_carets_down: boolean): void;
  public insert_text_at_caret(_text: String, _caret_index: number): void;
  public insert_text(_text: String, _line: number, _column: number, _before_selection_begin: boolean, _before_selection_end: boolean): void;
  public remove_text(_from_line: number, _from_column: number, _to_line: number, _to_column: number): void;
  public get_last_unhidden_line(): number;
  public get_next_visible_line_offset_from(_line: number, _visible_amount: number): number;
  public get_next_visible_line_index_offset_from(_line: number, _wrap_index: number, _visible_amount: number): Vector2i;
  public backspace(_caret_index: number): void;
  public cut(_caret_index: number): void;
  public copy(_caret_index: number): void;
  public paste(_caret_index: number): void;
  public paste_primary_clipboard(_caret_index: number): void;
  public start_action(_action: number): void;
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
  public set_search_text(_search_text: String): void;
  public set_search_flags(_flags: number): void;
  public search(_text: String, _flags: number, _from_line: number, _from_column: number): Vector2i;
  public set_tooltip_request_func(_callback: Callable): void;
  public get_local_mouse_pos(): Vector2;
  public get_word_at_pos(_position: Vector2): String;
  public get_line_column_at_pos(_position: Vector2i, _allow_out_of_bounds: boolean): Vector2i;
  public get_pos_at_line_column(_line: number, _column: number): Vector2i;
  public get_rect_at_line_column(_line: number, _column: number): Rect2i;
  public get_minimap_line_at_pos(_position: Vector2i): number;
  public is_dragging_cursor(): boolean;
  public is_mouse_over_selection(_edges: boolean, _caret_index: number): boolean;
  public set_caret_type(_type: number): void;
  public get_caret_type(): number;
  public set_caret_blink_enabled(_enable: boolean): void;
  public is_caret_blink_enabled(): boolean;
  public set_caret_blink_interval(_interval: number): void;
  public get_caret_blink_interval(): number;
  public set_draw_caret_when_editable_disabled(_enable: boolean): void;
  public is_drawing_caret_when_editable_disabled(): boolean;
  public set_move_caret_on_right_click_enabled(_enable: boolean): void;
  public is_move_caret_on_right_click_enabled(): boolean;
  public set_caret_mid_grapheme_enabled(_enabled: boolean): void;
  public is_caret_mid_grapheme_enabled(): boolean;
  public set_multiple_carets_enabled(_enabled: boolean): void;
  public is_multiple_carets_enabled(): boolean;
  public add_caret(_line: number, _column: number): number;
  public remove_caret(_caret: number): void;
  public remove_secondary_carets(): void;
  public get_caret_count(): number;
  public add_caret_at_carets(_below: boolean): void;
  public get_sorted_carets(_include_ignored_carets: boolean): PackedInt32Array;
  public collapse_carets(_from_line: number, _from_column: number, _to_line: number, _to_column: number, _inclusive: boolean): void;
  public merge_overlapping_carets(): void;
  public begin_multicaret_edit(): void;
  public end_multicaret_edit(): void;
  public is_in_mulitcaret_edit(): boolean;
  public multicaret_edit_ignore_caret(_caret_index: number): boolean;
  public is_caret_visible(_caret_index: number): boolean;
  public get_caret_draw_pos(_caret_index: number): Vector2;
  public set_caret_line(_line: number, _adjust_viewport: boolean, _can_be_hidden: boolean, _wrap_index: number, _caret_index: number): void;
  public get_caret_line(_caret_index: number): number;
  public set_caret_column(_column: number, _adjust_viewport: boolean, _caret_index: number): void;
  public get_caret_column(_caret_index: number): number;
  public get_caret_wrap_index(_caret_index: number): number;
  public get_word_under_caret(_caret_index: number): String;
  public set_use_default_word_separators(_enabled: boolean): void;
  public is_default_word_separators_enabled(): boolean;
  public set_use_custom_word_separators(_enabled: boolean): void;
  public is_custom_word_separators_enabled(): boolean;
  public set_custom_word_separators(_custom_word_separators: String): void;
  public get_custom_word_separators(): String;
  public set_selecting_enabled(_enable: boolean): void;
  public is_selecting_enabled(): boolean;
  public set_deselect_on_focus_loss_enabled(_enable: boolean): void;
  public is_deselect_on_focus_loss_enabled(): boolean;
  public set_drag_and_drop_selection_enabled(_enable: boolean): void;
  public is_drag_and_drop_selection_enabled(): boolean;
  public set_selection_mode(_mode: number): void;
  public get_selection_mode(): number;
  public select_all(): void;
  public select_word_under_caret(_caret_index: number): void;
  public add_selection_for_next_occurrence(): void;
  public skip_selection_for_next_occurrence(): void;
  public select(_origin_line: number, _origin_column: number, _caret_line: number, _caret_column: number, _caret_index: number): void;
  public has_selection(_caret_index: number): boolean;
  public get_selected_text(_caret_index: number): String;
  public get_selection_at_line_column(_line: number, _column: number, _include_edges: boolean, _only_selections: boolean): number;
  public get_line_ranges_from_carets(_only_selections: boolean, _merge_adjacent: boolean): GDArray;
  public get_selection_origin_line(_caret_index: number): number;
  public get_selection_origin_column(_caret_index: number): number;
  public set_selection_origin_line(_line: number, _can_be_hidden: boolean, _wrap_index: number, _caret_index: number): void;
  public set_selection_origin_column(_column: number, _caret_index: number): void;
  public get_selection_from_line(_caret_index: number): number;
  public get_selection_from_column(_caret_index: number): number;
  public get_selection_to_line(_caret_index: number): number;
  public get_selection_to_column(_caret_index: number): number;
  public is_caret_after_selection_origin(_caret_index: number): boolean;
  public deselect(_caret_index: number): void;
  public delete_selection(_caret_index: number): void;
  public set_line_wrapping_mode(_mode: number): void;
  public get_line_wrapping_mode(): number;
  public set_autowrap_mode(_autowrap_mode: number): void;
  public get_autowrap_mode(): number;
  public is_line_wrapped(_line: number): boolean;
  public get_line_wrap_count(_line: number): number;
  public get_line_wrap_index_at_column(_line: number, _column: number): number;
  public get_line_wrapped_text(_line: number): PackedStringArray;
  public set_smooth_scroll_enabled(_enable: boolean): void;
  public is_smooth_scroll_enabled(): boolean;
  public get_v_scroll_bar(): VScrollBar;
  public get_h_scroll_bar(): HScrollBar;
  public set_v_scroll(_value: number): void;
  public get_v_scroll(): number;
  public set_h_scroll(_value: number): void;
  public get_h_scroll(): number;
  public set_scroll_past_end_of_file_enabled(_enable: boolean): void;
  public is_scroll_past_end_of_file_enabled(): boolean;
  public set_v_scroll_speed(_speed: number): void;
  public get_v_scroll_speed(): number;
  public set_fit_content_height_enabled(_enabled: boolean): void;
  public is_fit_content_height_enabled(): boolean;
  public get_scroll_pos_for_line(_line: number, _wrap_index: number): number;
  public set_line_as_first_visible(_line: number, _wrap_index: number): void;
  public get_first_visible_line(): number;
  public set_line_as_center_visible(_line: number, _wrap_index: number): void;
  public set_line_as_last_visible(_line: number, _wrap_index: number): void;
  public get_last_full_visible_line(): number;
  public get_last_full_visible_line_wrap_index(): number;
  public get_visible_line_count(): number;
  public get_visible_line_count_in_range(_from_line: number, _to_line: number): number;
  public get_total_visible_line_count(): number;
  public adjust_viewport_to_caret(_caret_index: number): void;
  public center_viewport_to_caret(_caret_index: number): void;
  public set_draw_minimap(_enabled: boolean): void;
  public is_drawing_minimap(): boolean;
  public set_minimap_width(_width: number): void;
  public get_minimap_width(): number;
  public get_minimap_visible_lines(): number;
  public add_gutter(_at: number): void;
  public remove_gutter(_gutter: number): void;
  public get_gutter_count(): number;
  public set_gutter_name(_gutter: number, _name: String): void;
  public get_gutter_name(_gutter: number): String;
  public set_gutter_type(_gutter: number, _type: number): void;
  public get_gutter_type(_gutter: number): number;
  public set_gutter_width(_gutter: number, _width: number): void;
  public get_gutter_width(_gutter: number): number;
  public set_gutter_draw(_gutter: number, _draw: boolean): void;
  public is_gutter_drawn(_gutter: number): boolean;
  public set_gutter_clickable(_gutter: number, _clickable: boolean): void;
  public is_gutter_clickable(_gutter: number): boolean;
  public set_gutter_overwritable(_gutter: number, _overwritable: boolean): void;
  public is_gutter_overwritable(_gutter: number): boolean;
  public merge_gutters(_from_line: number, _to_line: number): void;
  public set_gutter_custom_draw(_column: number, _draw_callback: Callable): void;
  public get_total_gutter_width(): number;
  public set_line_gutter_metadata(_line: number, _gutter: number, _metadata: any): void;
  public get_line_gutter_metadata(_line: number, _gutter: number): any;
  public set_line_gutter_text(_line: number, _gutter: number, _text: String): void;
  public get_line_gutter_text(_line: number, _gutter: number): String;
  public set_line_gutter_icon(_line: number, _gutter: number, _icon: Texture2D): void;
  public get_line_gutter_icon(_line: number, _gutter: number): Texture2D;
  public set_line_gutter_item_color(_line: number, _gutter: number, _color: Color): void;
  public get_line_gutter_item_color(_line: number, _gutter: number): Color;
  public set_line_gutter_clickable(_line: number, _gutter: number, _clickable: boolean): void;
  public is_line_gutter_clickable(_line: number, _gutter: number): boolean;
  public set_line_background_color(_line: number, _color: Color): void;
  public get_line_background_color(_line: number): Color;
  public set_syntax_highlighter(_syntax_highlighter: SyntaxHighlighter): void;
  public get_syntax_highlighter(): SyntaxHighlighter;
  public set_highlight_current_line(_enabled: boolean): void;
  public is_highlight_current_line_enabled(): boolean;
  public set_highlight_all_occurrences(_enabled: boolean): void;
  public is_highlight_all_occurrences_enabled(): boolean;
  public get_draw_control_chars(): boolean;
  public set_draw_control_chars(_enabled: boolean): void;
  public set_draw_tabs(_enabled: boolean): void;
  public is_drawing_tabs(): boolean;
  public set_draw_spaces(_enabled: boolean): void;
  public is_drawing_spaces(): boolean;
  public get_menu(): PopupMenu;
  public is_menu_visible(): boolean;
  public menu_option(_option: number): void;
  public adjust_carets_after_edit(_caret: number, _from_line: number, _from_col: number, _to_line: number, _to_col: number): void;
  public get_caret_index_edit_order(): PackedInt32Array;
  public get_selection_line(_caret_index: number): number;
  public get_selection_column(_caret_index: number): number;
  public get text(): String {
    get_text();
  }
  public set text(value): void {
    set_text(value);
  }
  public get placeholder_text(): String {
    get_placeholder();
  }
  public set placeholder_text(value): void {
    set_placeholder(value);
  }
  public get editable(): boolean {
    is_editable();
  }
  public set editable(value): void {
    set_editable(value);
  }
  public get context_menu_enabled(): boolean {
    is_context_menu_enabled();
  }
  public set context_menu_enabled(value): void {
    set_context_menu_enabled(value);
  }
  public get shortcut_keys_enabled(): boolean {
    is_shortcut_keys_enabled();
  }
  public set shortcut_keys_enabled(value): void {
    set_shortcut_keys_enabled(value);
  }
  public get selecting_enabled(): boolean {
    is_selecting_enabled();
  }
  public set selecting_enabled(value): void {
    set_selecting_enabled(value);
  }
  public get deselect_on_focus_loss_enabled(): boolean {
    is_deselect_on_focus_loss_enabled();
  }
  public set deselect_on_focus_loss_enabled(value): void {
    set_deselect_on_focus_loss_enabled(value);
  }
  public get drag_and_drop_selection_enabled(): boolean {
    is_drag_and_drop_selection_enabled();
  }
  public set drag_and_drop_selection_enabled(value): void {
    set_drag_and_drop_selection_enabled(value);
  }
  public get virtual_keyboard_enabled(): boolean {
    is_virtual_keyboard_enabled();
  }
  public set virtual_keyboard_enabled(value): void {
    set_virtual_keyboard_enabled(value);
  }
  public get middle_mouse_paste_enabled(): boolean {
    is_middle_mouse_paste_enabled();
  }
  public set middle_mouse_paste_enabled(value): void {
    set_middle_mouse_paste_enabled(value);
  }
  public get wrap_mode(): number {
    get_line_wrapping_mode();
  }
  public set wrap_mode(value): void {
    set_line_wrapping_mode(value);
  }
  public get autowrap_mode(): number {
    get_autowrap_mode();
  }
  public set autowrap_mode(value): void {
    set_autowrap_mode(value);
  }
  public get indent_wrapped_lines(): boolean {
    is_indent_wrapped_lines();
  }
  public set indent_wrapped_lines(value): void {
    set_indent_wrapped_lines(value);
  }
  public get scroll_smooth(): boolean {
    is_smooth_scroll_enabled();
  }
  public set scroll_smooth(value): void {
    set_smooth_scroll_enabled(value);
  }
  public get scroll_v_scroll_speed(): number {
    get_v_scroll_speed();
  }
  public set scroll_v_scroll_speed(value): void {
    set_v_scroll_speed(value);
  }
  public get scroll_past_end_of_file(): boolean {
    is_scroll_past_end_of_file_enabled();
  }
  public set scroll_past_end_of_file(value): void {
    set_scroll_past_end_of_file_enabled(value);
  }
  public get scroll_vertical(): number {
    get_v_scroll();
  }
  public set scroll_vertical(value): void {
    set_v_scroll(value);
  }
  public get scroll_horizontal(): number {
    get_h_scroll();
  }
  public set scroll_horizontal(value): void {
    set_h_scroll(value);
  }
  public get scroll_fit_content_height(): boolean {
    is_fit_content_height_enabled();
  }
  public set scroll_fit_content_height(value): void {
    set_fit_content_height_enabled(value);
  }
  public get minimap_draw(): boolean {
    is_drawing_minimap();
  }
  public set minimap_draw(value): void {
    set_draw_minimap(value);
  }
  public get minimap_width(): number {
    get_minimap_width();
  }
  public set minimap_width(value): void {
    set_minimap_width(value);
  }
  public get caret_type(): number {
    get_caret_type();
  }
  public set caret_type(value): void {
    set_caret_type(value);
  }
  public get caret_blink(): boolean {
    is_caret_blink_enabled();
  }
  public set caret_blink(value): void {
    set_caret_blink_enabled(value);
  }
  public get caret_blink_interval(): number {
    get_caret_blink_interval();
  }
  public set caret_blink_interval(value): void {
    set_caret_blink_interval(value);
  }
  public get caret_draw_when_editable_disabled(): boolean {
    is_drawing_caret_when_editable_disabled();
  }
  public set caret_draw_when_editable_disabled(value): void {
    set_draw_caret_when_editable_disabled(value);
  }
  public get caret_move_on_right_click(): boolean {
    is_move_caret_on_right_click_enabled();
  }
  public set caret_move_on_right_click(value): void {
    set_move_caret_on_right_click_enabled(value);
  }
  public get caret_mid_grapheme(): boolean {
    is_caret_mid_grapheme_enabled();
  }
  public set caret_mid_grapheme(value): void {
    set_caret_mid_grapheme_enabled(value);
  }
  public get caret_multiple(): boolean {
    is_multiple_carets_enabled();
  }
  public set caret_multiple(value): void {
    set_multiple_carets_enabled(value);
  }
  public get use_default_word_separators(): boolean {
    is_default_word_separators_enabled();
  }
  public set use_default_word_separators(value): void {
    set_use_default_word_separators(value);
  }
  public get use_custom_word_separators(): boolean {
    is_custom_word_separators_enabled();
  }
  public set use_custom_word_separators(value): void {
    set_use_custom_word_separators(value);
  }
  public get custom_word_separators(): String {
    get_custom_word_separators();
  }
  public set custom_word_separators(value): void {
    set_custom_word_separators(value);
  }
  public get syntax_highlighter(): SyntaxHighlighter {
    get_syntax_highlighter();
  }
  public set syntax_highlighter(value): void {
    set_syntax_highlighter(value);
  }
  public get highlight_all_occurrences(): boolean {
    is_highlight_all_occurrences_enabled();
  }
  public set highlight_all_occurrences(value): void {
    set_highlight_all_occurrences(value);
  }
  public get highlight_current_line(): boolean {
    is_highlight_current_line_enabled();
  }
  public set highlight_current_line(value): void {
    set_highlight_current_line(value);
  }
  public get draw_control_chars(): boolean {
    get_draw_control_chars();
  }
  public set draw_control_chars(value): void {
    set_draw_control_chars(value);
  }
  public get draw_tabs(): boolean {
    is_drawing_tabs();
  }
  public set draw_tabs(value): void {
    set_draw_tabs(value);
  }
  public get draw_spaces(): boolean {
    is_drawing_spaces();
  }
  public set draw_spaces(value): void {
    set_draw_spaces(value);
  }
  public get text_direction(): number {
    get_text_direction();
  }
  public set text_direction(value): void {
    set_text_direction(value);
  }
  public get language(): String {
    get_language();
  }
  public set language(value): void {
    set_language(value);
  }
  public get structured_text_bidi_override(): number {
    get_structured_text_bidi_override();
  }
  public set structured_text_bidi_override(value): void {
    set_structured_text_bidi_override(value);
  }
  public get structured_text_bidi_override_options(): GDArray {
    get_structured_text_bidi_override_options();
  }
  public set structured_text_bidi_override_options(value): void {
    set_structured_text_bidi_override_options(value);
  }
  static MenuItems = {
    MENU_CUT = 0,
    MENU_COPY = 1,
    MENU_PASTE = 2,
    MENU_CLEAR = 3,
    MENU_SELECT_ALL = 4,
    MENU_UNDO = 5,
    MENU_REDO = 6,
    MENU_SUBMENU_TEXT_DIR = 7,
    MENU_DIR_INHERITED = 8,
    MENU_DIR_AUTO = 9,
    MENU_DIR_LTR = 10,
    MENU_DIR_RTL = 11,
    MENU_DISPLAY_UCC = 12,
    MENU_SUBMENU_INSERT_UCC = 13,
    MENU_INSERT_LRM = 14,
    MENU_INSERT_RLM = 15,
    MENU_INSERT_LRE = 16,
    MENU_INSERT_RLE = 17,
    MENU_INSERT_LRO = 18,
    MENU_INSERT_RLO = 19,
    MENU_INSERT_PDF = 20,
    MENU_INSERT_ALM = 21,
    MENU_INSERT_LRI = 22,
    MENU_INSERT_RLI = 23,
    MENU_INSERT_FSI = 24,
    MENU_INSERT_PDI = 25,
    MENU_INSERT_ZWJ = 26,
    MENU_INSERT_ZWNJ = 27,
    MENU_INSERT_WJ = 28,
    MENU_INSERT_SHY = 29,
    MENU_MAX = 30,
  }
  static EditAction = {
    ACTION_NONE = 0,
    ACTION_TYPING = 1,
    ACTION_BACKSPACE = 2,
    ACTION_DELETE = 3,
  }
  static SearchFlags = {
    SEARCH_MATCH_CASE = 1,
    SEARCH_WHOLE_WORDS = 2,
    SEARCH_BACKWARDS = 4,
  }
  static CaretType = {
    CARET_TYPE_LINE = 0,
    CARET_TYPE_BLOCK = 1,
  }
  static SelectionMode = {
    SELECTION_MODE_NONE = 0,
    SELECTION_MODE_SHIFT = 1,
    SELECTION_MODE_POINTER = 2,
    SELECTION_MODE_WORD = 3,
    SELECTION_MODE_LINE = 4,
  }
  static LineWrappingMode = {
    LINE_WRAPPING_NONE = 0,
    LINE_WRAPPING_BOUNDARY = 1,
  }
  static GutterType = {
    GUTTER_TYPE_STRING = 0,
    GUTTER_TYPE_ICON = 1,
    GUTTER_TYPE_CUSTOM = 2,
  }
}