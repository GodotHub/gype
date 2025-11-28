
import type { Control } from '@godot/classes/control';
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class LineEdit extends Control {

    
    /**     * The raw type is 'String'     */
    public text: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public placeholder_text: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public alignment: number;    
    /**     * The raw type is 'int'     */
    public max_length: number;    
    /**     * The raw type is 'bool'     */
    public editable: boolean;    
    /**     * The raw type is 'bool'     */
    public keep_editing_on_text_submit: boolean;    
    /**     * The raw type is 'bool'     */
    public expand_to_text_length: boolean;    
    /**     * The raw type is 'bool'     */
    public context_menu_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public emoji_menu_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public backspace_deletes_composite_character_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public virtual_keyboard_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public virtual_keyboard_show_on_focus: boolean;    
    /**     * The raw type is 'int'     */
    public virtual_keyboard_type: number;    
    /**     * The raw type is 'bool'     */
    public clear_button_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public shortcut_keys_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public middle_mouse_paste_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public selecting_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public deselect_on_focus_loss_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public drag_and_drop_selection_enabled: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public right_icon: Texture2D;    
    /**     * The raw type is 'bool'     */
    public flat: boolean;    
    /**     * The raw type is 'bool'     */
    public draw_control_chars: boolean;    
    /**     * The raw type is 'bool'     */
    public select_all_on_focus: boolean;    
    /**     * The raw type is 'bool'     */
    public caret_blink: boolean;    
    /**     * The raw type is 'float'     */
    public caret_blink_interval: number;    
    /**     * The raw type is 'int'     */
    public caret_column: number;    
    /**     * The raw type is 'bool'     */
    public caret_force_displayed: boolean;    
    /**     * The raw type is 'bool'     */
    public caret_mid_grapheme: boolean;    
    /**     * The raw type is 'bool'     */
    public secret: boolean;    
    /**     * The raw type is 'String'     */
    public secret_character: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public structured_text_bidi_override: number;    
    /**     * The raw type is 'Array'     */
    public structured_text_bidi_override_options: GDArray | Array;
    public has_ime_text(): boolean;
    public cancel_ime(): void;
    public apply_ime(): void;
    public set_horizontal_alignment(alignment: number): void;
    public get_horizontal_alignment(): number;
    public edit(): void;
    public unedit(): void;
    public is_editing(): boolean;
    public set_keep_editing_on_text_submit(enable: boolean): void;
    public is_editing_kept_on_text_submit(): boolean;
    public clear(): void;
    public select(_from: number = 0, to: number = -1): void;
    public select_all(): void;
    public deselect(): void;
    public has_undo(): boolean;
    public has_redo(): boolean;
    public has_selection(): boolean;
    public get_selected_text(): GDString;
    public get_selection_from_column(): number;
    public get_selection_to_column(): number;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public get_draw_control_chars(): boolean;
    public set_draw_control_chars(enable: boolean): void;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_structured_text_bidi_override(parser: number): void;
    public get_structured_text_bidi_override(): number;
    public set_structured_text_bidi_override_options(args: GDArray | Array): void;
    public get_structured_text_bidi_override_options(): GDArray;
    public set_placeholder(text: GDString | StringName | string): void;
    public get_placeholder(): GDString;
    public set_caret_column(position: number): void;
    public get_caret_column(): number;
    public get_next_composite_character_column(column: number): number;
    public get_previous_composite_character_column(column: number): number;
    public get_scroll_offset(): number;
    public set_expand_to_text_length_enabled(enabled: boolean): void;
    public is_expand_to_text_length_enabled(): boolean;
    public set_caret_blink_enabled(enabled: boolean): void;
    public is_caret_blink_enabled(): boolean;
    public set_caret_mid_grapheme_enabled(enabled: boolean): void;
    public is_caret_mid_grapheme_enabled(): boolean;
    public set_caret_force_displayed(enabled: boolean): void;
    public is_caret_force_displayed(): boolean;
    public set_caret_blink_interval(interval: number): void;
    public get_caret_blink_interval(): number;
    public set_max_length(chars: number): void;
    public get_max_length(): number;
    public insert_text_at_caret(text: GDString | StringName | string): void;
    public delete_char_at_caret(): void;
    public delete_text(fromColumn: number, toColumn: number): void;
    public set_editable(enabled: boolean): void;
    public is_editable(): boolean;
    public set_secret(enabled: boolean): void;
    public is_secret(): boolean;
    public set_secret_character(character: GDString | StringName | string): void;
    public get_secret_character(): GDString;
    public menu_option(option: number): void;
    public get_menu(): PopupMenu;
    public is_menu_visible(): boolean;
    public set_context_menu_enabled(enable: boolean): void;
    public is_context_menu_enabled(): boolean;
    public set_emoji_menu_enabled(enable: boolean): void;
    public is_emoji_menu_enabled(): boolean;
    public set_backspace_deletes_composite_character_enabled(enable: boolean): void;
    public is_backspace_deletes_composite_character_enabled(): boolean;
    public set_virtual_keyboard_enabled(enable: boolean): void;
    public is_virtual_keyboard_enabled(): boolean;
    public set_virtual_keyboard_show_on_focus(showOnFocus: boolean): void;
    public get_virtual_keyboard_show_on_focus(): boolean;
    public set_virtual_keyboard_type(_type: number): void;
    public get_virtual_keyboard_type(): number;
    public set_clear_button_enabled(enable: boolean): void;
    public is_clear_button_enabled(): boolean;
    public set_shortcut_keys_enabled(enable: boolean): void;
    public is_shortcut_keys_enabled(): boolean;
    public set_middle_mouse_paste_enabled(enable: boolean): void;
    public is_middle_mouse_paste_enabled(): boolean;
    public set_selecting_enabled(enable: boolean): void;
    public is_selecting_enabled(): boolean;
    public set_deselect_on_focus_loss_enabled(enable: boolean): void;
    public is_deselect_on_focus_loss_enabled(): boolean;
    public set_drag_and_drop_selection_enabled(enable: boolean): void;
    public is_drag_and_drop_selection_enabled(): boolean;
    public set_right_icon(icon: Texture2D): void;
    public get_right_icon(): Texture2D;
    public set_flat(enabled: boolean): void;
    public is_flat(): boolean;
    public set_select_all_on_focus(enabled: boolean): void;
    public is_select_all_on_focus(): boolean;

    
    public readonly text_changed: Signal;
    public readonly text_change_rejected: Signal;
    public readonly text_submitted: Signal;
    public readonly editing_toggled: Signal;

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
    public static readonly VirtualKeyboardType: {
        KEYBOARD_TYPE_DEFAULT: 0;
        KEYBOARD_TYPE_MULTILINE: 1;
        KEYBOARD_TYPE_NUMBER: 2;
        KEYBOARD_TYPE_NUMBER_DECIMAL: 3;
        KEYBOARD_TYPE_PHONE: 4;
        KEYBOARD_TYPE_EMAIL_ADDRESS: 5;
        KEYBOARD_TYPE_PASSWORD: 6;
        KEYBOARD_TYPE_URL: 7;
    };
}

