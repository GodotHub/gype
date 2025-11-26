
import type { Resource } from '@godot/classes/resource';
import type { TextEdit } from '@godot/classes/text_edit';


export declare class CodeEdit extends TextEdit {

    
    /**     * The raw type is 'bool'     */
    public symbol_lookup_on_click: boolean;    
    /**     * The raw type is 'bool'     */
    public symbol_tooltip_on_hover: boolean;    
    /**     * The raw type is 'bool'     */
    public line_folding: boolean;    
    /**     * The raw type is 'PackedInt32Array'     */
    public line_length_guidelines: Array<any>;    
    /**     * The raw type is 'bool'     */
    public gutters_draw_breakpoints_gutter: boolean;    
    /**     * The raw type is 'bool'     */
    public gutters_draw_bookmarks: boolean;    
    /**     * The raw type is 'bool'     */
    public gutters_draw_executing_lines: boolean;    
    /**     * The raw type is 'bool'     */
    public gutters_draw_line_numbers: boolean;    
    /**     * The raw type is 'bool'     */
    public gutters_zero_pad_line_numbers: boolean;    
    /**     * The raw type is 'bool'     */
    public gutters_draw_fold_gutter: boolean;    
    /**     * The raw type is 'PackedStringArray'     */
    public delimiter_strings: Array<any>;    
    /**     * The raw type is 'PackedStringArray'     */
    public delimiter_comments: Array<any>;    
    /**     * The raw type is 'bool'     */
    public code_completion_enabled: boolean;    
    /**     * The raw type is 'PackedStringArray'     */
    public code_completion_prefixes: Array<any>;    
    /**     * The raw type is 'int'     */
    public indent_size: number;    
    /**     * The raw type is 'bool'     */
    public indent_use_spaces: boolean;    
    /**     * The raw type is 'bool'     */
    public indent_automatic: boolean;    
    /**     * The raw type is 'PackedStringArray'     */
    public indent_automatic_prefixes: Array<any>;    
    /**     * The raw type is 'bool'     */
    public auto_brace_completion_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public auto_brace_completion_highlight_matching: boolean;    
    /**     * The raw type is 'Dictionary'     */
    public auto_brace_completion_pairs: Dictionary;
    public _confirm_code_completion(replace: boolean): void;
    public _request_code_completion(force: boolean): void;
    public _filter_code_completion_candidates(candidates: Array<any>): Array<any>;
    public set_indent_size(size: number): void;
    public get_indent_size(): number;
    public set_indent_using_spaces(useSpaces: boolean): void;
    public is_indent_using_spaces(): boolean;
    public set_auto_indent_enabled(enable: boolean): void;
    public is_auto_indent_enabled(): boolean;
    public set_auto_indent_prefixes(prefixes: Array<any>): void;
    public get_auto_indent_prefixes(): Array<any>;
    public do_indent(): void;
    public indent_lines(): void;
    public unindent_lines(): void;
    public convert_indent(fromLine: number = -1, toLine: number = -1): void;
    public set_auto_brace_completion_enabled(enable: boolean): void;
    public is_auto_brace_completion_enabled(): boolean;
    public set_highlight_matching_braces_enabled(enable: boolean): void;
    public is_highlight_matching_braces_enabled(): boolean;
    public add_auto_brace_completion_pair(startKey: GDString | StringName | string, endKey: GDString | StringName | string): void;
    public set_auto_brace_completion_pairs(pairs: Dictionary): void;
    public get_auto_brace_completion_pairs(): Dictionary;
    public has_auto_brace_completion_open_key(openKey: GDString | StringName | string): boolean;
    public has_auto_brace_completion_close_key(closeKey: GDString | StringName | string): boolean;
    public get_auto_brace_completion_close_key(openKey: GDString | StringName | string): GDString;
    public set_draw_breakpoints_gutter(enable: boolean): void;
    public is_drawing_breakpoints_gutter(): boolean;
    public set_draw_bookmarks_gutter(enable: boolean): void;
    public is_drawing_bookmarks_gutter(): boolean;
    public set_draw_executing_lines_gutter(enable: boolean): void;
    public is_drawing_executing_lines_gutter(): boolean;
    public set_line_as_breakpoint(line: number, breakpointed: boolean): void;
    public is_line_breakpointed(line: number): boolean;
    public clear_breakpointed_lines(): void;
    public get_breakpointed_lines(): PackedInt32Array;
    public set_line_as_bookmarked(line: number, bookmarked: boolean): void;
    public is_line_bookmarked(line: number): boolean;
    public clear_bookmarked_lines(): void;
    public get_bookmarked_lines(): PackedInt32Array;
    public set_line_as_executing(line: number, executing: boolean): void;
    public is_line_executing(line: number): boolean;
    public clear_executing_lines(): void;
    public get_executing_lines(): PackedInt32Array;
    public set_draw_line_numbers(enable: boolean): void;
    public is_draw_line_numbers_enabled(): boolean;
    public set_line_numbers_zero_padded(enable: boolean): void;
    public is_line_numbers_zero_padded(): boolean;
    public set_draw_fold_gutter(enable: boolean): void;
    public is_drawing_fold_gutter(): boolean;
    public set_line_folding_enabled(enabled: boolean): void;
    public is_line_folding_enabled(): boolean;
    public can_fold_line(line: number): boolean;
    public fold_line(line: number): void;
    public unfold_line(line: number): void;
    public fold_all_lines(): void;
    public unfold_all_lines(): void;
    public toggle_foldable_line(line: number): void;
    public toggle_foldable_lines_at_carets(): void;
    public is_line_folded(line: number): boolean;
    public get_folded_lines(): Array<any>;
    public create_code_region(): void;
    public get_code_region_start_tag(): GDString;
    public get_code_region_end_tag(): GDString;
    public set_code_region_tags(start: GDString | StringName | string = "region", end: GDString | StringName | string = "endregion"): void;
    public is_line_code_region_start(line: number): boolean;
    public is_line_code_region_end(line: number): boolean;
    public add_string_delimiter(startKey: GDString | StringName | string, endKey: GDString | StringName | string, lineOnly: boolean = false): void;
    public remove_string_delimiter(startKey: GDString | StringName | string): void;
    public has_string_delimiter(startKey: GDString | StringName | string): boolean;
    public set_string_delimiters(stringDelimiters: Array<any>): void;
    public clear_string_delimiters(): void;
    public get_string_delimiters(): Array<any>;
    public is_in_string(line: number, column: number = -1): number;
    public add_comment_delimiter(startKey: GDString | StringName | string, endKey: GDString | StringName | string, lineOnly: boolean = false): void;
    public remove_comment_delimiter(startKey: GDString | StringName | string): void;
    public has_comment_delimiter(startKey: GDString | StringName | string): boolean;
    public set_comment_delimiters(commentDelimiters: Array<any>): void;
    public clear_comment_delimiters(): void;
    public get_comment_delimiters(): Array<any>;
    public is_in_comment(line: number, column: number = -1): number;
    public get_delimiter_start_key(delimiterIndex: number): GDString;
    public get_delimiter_end_key(delimiterIndex: number): GDString;
    public get_delimiter_start_position(line: number, column: number): Vector2;
    public get_delimiter_end_position(line: number, column: number): Vector2;
    public set_code_hint(codeHint: GDString | StringName | string): void;
    public set_code_hint_draw_below(drawBelow: boolean): void;
    public get_text_for_code_completion(): GDString;
    public request_code_completion(force: boolean = false): void;
    public add_code_completion_option(_type: number, displayText: GDString | StringName | string, insertText: GDString | StringName | string, textColor: Color = Color(1, 1, 1, 1), icon: Resource = null, value: any = null, location: number = 1024): void;
    public update_code_completion_options(force: boolean): void;
    public get_code_completion_options(): Array<any>;
    public get_code_completion_option(index: number): Dictionary;
    public get_code_completion_selected_index(): number;
    public set_code_completion_selected_index(index: number): void;
    public confirm_code_completion(replace: boolean = false): void;
    public cancel_code_completion(): void;
    public set_code_completion_enabled(enable: boolean): void;
    public is_code_completion_enabled(): boolean;
    public set_code_completion_prefixes(prefixes: Array<any>): void;
    public get_code_completion_prefixes(): Array<any>;
    public set_line_length_guidelines(guidelineColumns: Array<any>): void;
    public get_line_length_guidelines(): Array<any>;
    public set_symbol_lookup_on_click_enabled(enable: boolean): void;
    public is_symbol_lookup_on_click_enabled(): boolean;
    public get_text_for_symbol_lookup(): GDString;
    public get_text_with_cursor_char(line: number, column: number): GDString;
    public set_symbol_lookup_word_as_valid(valid: boolean): void;
    public set_symbol_tooltip_on_hover_enabled(enable: boolean): void;
    public is_symbol_tooltip_on_hover_enabled(): boolean;
    public move_lines_up(): void;
    public move_lines_down(): void;
    public delete_lines(): void;
    public duplicate_selection(): void;
    public duplicate_lines(): void;

    
    public readonly breakpoint_toggled: Signal;
    public readonly code_completion_requested: Signal;
    public readonly symbol_lookup: Signal;
    public readonly symbol_validate: Signal;
    public readonly symbol_hovered: Signal;

    public static readonly CodeCompletionKind: {
        KIND_CLASS: 0;
        KIND_FUNCTION: 1;
        KIND_SIGNAL: 2;
        KIND_VARIABLE: 3;
        KIND_MEMBER: 4;
        KIND_ENUM: 5;
        KIND_CONSTANT: 6;
        KIND_NODE_PATH: 7;
        KIND_FILE_PATH: 8;
        KIND_PLAIN_TEXT: 9;
    };
    public static readonly CodeCompletionLocation: {
        LOCATION_LOCAL: 0;
        LOCATION_PARENT_MASK: 256;
        LOCATION_OTHER_USER_CODE: 512;
        LOCATION_OTHER: 1024;
    };
}

