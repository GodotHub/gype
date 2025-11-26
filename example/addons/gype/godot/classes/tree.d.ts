
import type { Control } from '@godot/classes/control';
import type { TreeItem } from '@godot/classes/tree_item';


export declare class Tree extends Control {

    
    /**     * The raw type is 'int'     */
    public columns: number;    
    /**     * The raw type is 'bool'     */
    public column_titles_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_reselect: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_rmb_select: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_search: boolean;    
    /**     * The raw type is 'bool'     */
    public hide_folding: boolean;    
    /**     * The raw type is 'bool'     */
    public enable_recursive_folding: boolean;    
    /**     * The raw type is 'bool'     */
    public hide_root: boolean;    
    /**     * The raw type is 'int'     */
    public drop_mode_flags: number;    
    /**     * The raw type is 'int'     */
    public select_mode: number;    
    /**     * The raw type is 'bool'     */
    public scroll_horizontal_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public scroll_vertical_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public auto_tooltip: boolean;
    public clear(): void;
    public create_item(parent: TreeItem = null, index: number = -1): TreeItem;
    public get_root(): TreeItem;
    public set_column_custom_minimum_width(column: number, minWidth: number): void;
    public set_column_expand(column: number, expand: boolean): void;
    public set_column_expand_ratio(column: number, ratio: number): void;
    public set_column_clip_content(column: number, enable: boolean): void;
    public is_column_expanding(column: number): boolean;
    public is_column_clipping_content(column: number): boolean;
    public get_column_expand_ratio(column: number): number;
    public get_column_width(column: number): number;
    public set_hide_root(enable: boolean): void;
    public is_root_hidden(): boolean;
    public get_next_selected(_from: TreeItem): TreeItem;
    public get_selected(): TreeItem;
    public set_selected(item: TreeItem, column: number): void;
    public get_selected_column(): number;
    public get_pressed_button(): number;
    public set_select_mode(mode: number): void;
    public get_select_mode(): number;
    public deselect_all(): void;
    public set_columns(amount: number): void;
    public get_columns(): number;
    public get_edited(): TreeItem;
    public get_edited_column(): number;
    public edit_selected(forceEdit: boolean = false): boolean;
    public get_custom_popup_rect(): Rect2;
    public get_item_area_rect(item: TreeItem, column: number = -1, buttonIndex: number = -1): Rect2;
    public get_item_at_position(position: Vector2): TreeItem;
    public get_column_at_position(position: Vector2): number;
    public get_drop_section_at_position(position: Vector2): number;
    public get_button_id_at_position(position: Vector2): number;
    public ensure_cursor_is_visible(): void;
    public set_column_titles_visible(visible: boolean): void;
    public are_column_titles_visible(): boolean;
    public set_column_title(column: number, title: GDString | StringName | string): void;
    public get_column_title(column: number): GDString;
    public set_column_title_alignment(column: number, titleAlignment: number): void;
    public get_column_title_alignment(column: number): number;
    public set_column_title_direction(column: number, direction: number): void;
    public get_column_title_direction(column: number): number;
    public set_column_title_language(column: number, language: GDString | StringName | string): void;
    public get_column_title_language(column: number): GDString;
    public get_scroll(): Vector2;
    public scroll_to_item(item: TreeItem, centerOnItem: boolean = false): void;
    public set_h_scroll_enabled(hScroll: boolean): void;
    public is_h_scroll_enabled(): boolean;
    public set_v_scroll_enabled(hScroll: boolean): void;
    public is_v_scroll_enabled(): boolean;
    public set_hide_folding(hide: boolean): void;
    public is_folding_hidden(): boolean;
    public set_enable_recursive_folding(enable: boolean): void;
    public is_recursive_folding_enabled(): boolean;
    public set_drop_mode_flags(flags: number): void;
    public get_drop_mode_flags(): number;
    public set_allow_rmb_select(allow: boolean): void;
    public get_allow_rmb_select(): boolean;
    public set_allow_reselect(allow: boolean): void;
    public get_allow_reselect(): boolean;
    public set_allow_search(allow: boolean): void;
    public get_allow_search(): boolean;
    public set_auto_tooltip(enable: boolean): void;
    public is_auto_tooltip_enabled(): boolean;

    
    public readonly item_selected: Signal;
    public readonly cell_selected: Signal;
    public readonly multi_selected: Signal;
    public readonly item_mouse_selected: Signal;
    public readonly empty_clicked: Signal;
    public readonly item_edited: Signal;
    public readonly custom_item_clicked: Signal;
    public readonly item_icon_double_clicked: Signal;
    public readonly item_collapsed: Signal;
    public readonly check_propagated_to_item: Signal;
    public readonly button_clicked: Signal;
    public readonly custom_popup_edited: Signal;
    public readonly item_activated: Signal;
    public readonly column_title_clicked: Signal;
    public readonly nothing_selected: Signal;

    public static readonly SelectMode: {
        SELECT_SINGLE: 0;
        SELECT_ROW: 1;
        SELECT_MULTI: 2;
    };
    public static readonly DropModeFlags: {
        DROP_MODE_DISABLED: 0;
        DROP_MODE_ON_ITEM: 1;
        DROP_MODE_INBETWEEN: 2;
    };
}

