
import type { Control } from '@godot/classes/control';
import type { HScrollBar } from '@godot/classes/h_scroll_bar';
import type { Texture2D } from '@godot/classes/texture2d';
import type { VScrollBar } from '@godot/classes/v_scroll_bar';


export declare class ItemList extends Control {

    
    /**     * The raw type is 'int'     */
    public select_mode: number;    
    /**     * The raw type is 'bool'     */
    public allow_reselect: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_rmb_select: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_search: boolean;    
    /**     * The raw type is 'int'     */
    public max_text_lines: number;    
    /**     * The raw type is 'bool'     */
    public auto_width: boolean;    
    /**     * The raw type is 'bool'     */
    public auto_height: boolean;    
    /**     * The raw type is 'int'     */
    public text_overrun_behavior: number;    
    /**     * The raw type is 'bool'     */
    public wraparound_items: boolean;    
    /**     * The raw type is 'int'     */
    public item_count: number;    
    /**     * The raw type is 'int'     */
    public max_columns: number;    
    /**     * The raw type is 'bool'     */
    public same_column_width: boolean;    
    /**     * The raw type is 'int'     */
    public fixed_column_width: number;    
    /**     * The raw type is 'int'     */
    public icon_mode: number;    
    /**     * The raw type is 'float'     */
    public icon_scale: number;    
    /**     * The raw type is 'Vector2i'     */
    public fixed_icon_size: Vector2i;
    public add_item(text: GDString | StringName | string, icon: Texture2D = null, selectable: boolean = true): number;
    public add_icon_item(icon: Texture2D, selectable: boolean = true): number;
    public set_item_text(idx: number, text: GDString | StringName | string): void;
    public get_item_text(idx: number): GDString;
    public set_item_icon(idx: number, icon: Texture2D): void;
    public get_item_icon(idx: number): Texture2D;
    public set_item_text_direction(idx: number, direction: number): void;
    public get_item_text_direction(idx: number): number;
    public set_item_language(idx: number, language: GDString | StringName | string): void;
    public get_item_language(idx: number): GDString;
    public set_item_auto_translate_mode(idx: number, mode: number): void;
    public get_item_auto_translate_mode(idx: number): number;
    public set_item_icon_transposed(idx: number, transposed: boolean): void;
    public is_item_icon_transposed(idx: number): boolean;
    public set_item_icon_region(idx: number, rect: Rect2): void;
    public get_item_icon_region(idx: number): Rect2;
    public set_item_icon_modulate(idx: number, modulate: Color): void;
    public get_item_icon_modulate(idx: number): Color;
    public set_item_selectable(idx: number, selectable: boolean): void;
    public is_item_selectable(idx: number): boolean;
    public set_item_disabled(idx: number, disabled: boolean): void;
    public is_item_disabled(idx: number): boolean;
    public set_item_metadata(idx: number, metadata: any): void;
    public get_item_metadata(idx: number): any;
    public set_item_custom_bg_color(idx: number, customBgColor: Color): void;
    public get_item_custom_bg_color(idx: number): Color;
    public set_item_custom_fg_color(idx: number, customFgColor: Color): void;
    public get_item_custom_fg_color(idx: number): Color;
    public get_item_rect(idx: number, expand: boolean = true): Rect2;
    public set_item_tooltip_enabled(idx: number, enable: boolean): void;
    public is_item_tooltip_enabled(idx: number): boolean;
    public set_item_tooltip(idx: number, tooltip: GDString | StringName | string): void;
    public get_item_tooltip(idx: number): GDString;
    public select(idx: number, single: boolean = true): void;
    public deselect(idx: number): void;
    public deselect_all(): void;
    public is_selected(idx: number): boolean;
    public get_selected_items(): PackedInt32Array;
    public move_item(fromIdx: number, toIdx: number): void;
    public set_item_count(count: number): void;
    public get_item_count(): number;
    public remove_item(idx: number): void;
    public clear(): void;
    public sort_items_by_text(): void;
    public set_fixed_column_width(width: number): void;
    public get_fixed_column_width(): number;
    public set_same_column_width(enable: boolean): void;
    public is_same_column_width(): boolean;
    public set_max_text_lines(lines: number): void;
    public get_max_text_lines(): number;
    public set_max_columns(amount: number): void;
    public get_max_columns(): number;
    public set_select_mode(mode: number): void;
    public get_select_mode(): number;
    public set_icon_mode(mode: number): void;
    public get_icon_mode(): number;
    public set_fixed_icon_size(size: Vector2i): void;
    public get_fixed_icon_size(): Vector2i;
    public set_icon_scale(scale: number): void;
    public get_icon_scale(): number;
    public set_allow_rmb_select(allow: boolean): void;
    public get_allow_rmb_select(): boolean;
    public set_allow_reselect(allow: boolean): void;
    public get_allow_reselect(): boolean;
    public set_allow_search(allow: boolean): void;
    public get_allow_search(): boolean;
    public set_auto_width(enable: boolean): void;
    public has_auto_width(): boolean;
    public set_auto_height(enable: boolean): void;
    public has_auto_height(): boolean;
    public is_anything_selected(): boolean;
    public get_item_at_position(position: Vector2, exact: boolean = false): number;
    public ensure_current_is_visible(): void;
    public get_v_scroll_bar(): VScrollBar;
    public get_h_scroll_bar(): HScrollBar;
    public set_text_overrun_behavior(overrunBehavior: number): void;
    public get_text_overrun_behavior(): number;
    public set_wraparound_items(enable: boolean): void;
    public has_wraparound_items(): boolean;
    public force_update_list_size(): void;

    
    public readonly item_selected: Signal<(index: number) => void>;
    public readonly empty_clicked: Signal<(atPosition: Vector2, mouseButtonIndex: number) => void>;
    public readonly item_clicked: Signal<(index: number, atPosition: Vector2, mouseButtonIndex: number) => void>;
    public readonly multi_selected: Signal<(index: number, selected: boolean) => void>;
    public readonly item_activated: Signal<(index: number) => void>;

    public static readonly IconMode: {
        ICON_MODE_TOP: 0;
        ICON_MODE_LEFT: 1;
    };
    public static readonly SelectMode: {
        SELECT_SINGLE: 0;
        SELECT_MULTI: 1;
        SELECT_TOGGLE: 2;
    };
}

