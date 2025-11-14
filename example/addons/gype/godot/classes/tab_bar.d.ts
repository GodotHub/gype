
import type { Control } from '@godot/classes/control';
import type { GDString } from '@godot/builtins/gd_string';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class TabBar extends Control {

    
    /**     * The raw type is 'int'     */
    public current_tab: number;    
    /**     * The raw type is 'int'     */
    public tab_alignment: number;    
    /**     * The raw type is 'bool'     */
    public clip_tabs: boolean;    
    /**     * The raw type is 'bool'     */
    public close_with_middle_mouse: boolean;    
    /**     * The raw type is 'int'     */
    public tab_close_display_policy: number;    
    /**     * The raw type is 'int'     */
    public max_tab_width: number;    
    /**     * The raw type is 'bool'     */
    public scrolling_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public drag_to_rearrange_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public tabs_rearrange_group: number;    
    /**     * The raw type is 'bool'     */
    public scroll_to_selected: boolean;    
    /**     * The raw type is 'bool'     */
    public select_with_rmb: boolean;    
    /**     * The raw type is 'bool'     */
    public deselect_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public tab_count: number;
    public set_tab_count(count: number): void;
    public get_tab_count(): number;
    public set_current_tab(tabIdx: number): void;
    public get_current_tab(): number;
    public get_previous_tab(): number;
    public select_previous_available(): boolean;
    public select_next_available(): boolean;
    public set_tab_title(tabIdx: number, title: GDString | StringName | string): void;
    public get_tab_title(tabIdx: number): GDString;
    public set_tab_tooltip(tabIdx: number, tooltip: GDString | StringName | string): void;
    public get_tab_tooltip(tabIdx: number): GDString;
    public set_tab_text_direction(tabIdx: number, direction: number): void;
    public get_tab_text_direction(tabIdx: number): number;
    public set_tab_language(tabIdx: number, language: GDString | StringName | string): void;
    public get_tab_language(tabIdx: number): GDString;
    public set_tab_icon(tabIdx: number, icon: Texture2D): void;
    public get_tab_icon(tabIdx: number): Texture2D;
    public set_tab_icon_max_width(tabIdx: number, width: number): void;
    public get_tab_icon_max_width(tabIdx: number): number;
    public set_tab_button_icon(tabIdx: number, icon: Texture2D): void;
    public get_tab_button_icon(tabIdx: number): Texture2D;
    public set_tab_disabled(tabIdx: number, disabled: boolean): void;
    public is_tab_disabled(tabIdx: number): boolean;
    public set_tab_hidden(tabIdx: number, hidden: boolean): void;
    public is_tab_hidden(tabIdx: number): boolean;
    public set_tab_metadata(tabIdx: number, metadata: any): void;
    public get_tab_metadata(tabIdx: number): any;
    public remove_tab(tabIdx: number): void;
    public add_tab(title: GDString | StringName | string = "", icon: Texture2D = null): void;
    public get_tab_idx_at_point(point: Vector2): number;
    public set_tab_alignment(alignment: number): void;
    public get_tab_alignment(): number;
    public set_clip_tabs(clitabs: boolean): void;
    public get_clip_tabs(): boolean;
    public get_tab_offset(): number;
    public get_offset_buttons_visible(): boolean;
    public ensure_tab_visible(idx: number): void;
    public get_tab_rect(tabIdx: number): Rect2;
    public move_tab(_from: number, to: number): void;
    public set_close_with_middle_mouse(enabled: boolean): void;
    public get_close_with_middle_mouse(): boolean;
    public set_tab_close_display_policy(policy: number): void;
    public get_tab_close_display_policy(): number;
    public set_max_tab_width(width: number): void;
    public get_max_tab_width(): number;
    public set_scrolling_enabled(enabled: boolean): void;
    public get_scrolling_enabled(): boolean;
    public set_drag_to_rearrange_enabled(enabled: boolean): void;
    public get_drag_to_rearrange_enabled(): boolean;
    public set_tabs_rearrange_group(grouid: number): void;
    public get_tabs_rearrange_group(): number;
    public set_scroll_to_selected(enabled: boolean): void;
    public get_scroll_to_selected(): boolean;
    public set_select_with_rmb(enabled: boolean): void;
    public get_select_with_rmb(): boolean;
    public set_deselect_enabled(enabled: boolean): void;
    public get_deselect_enabled(): boolean;
    public clear_tabs(): void;

    
    public readonly tab_selected: Signal<(tab: number) => void>;
    public readonly tab_changed: Signal<(tab: number) => void>;
    public readonly tab_clicked: Signal<(tab: number) => void>;
    public readonly tab_rmb_clicked: Signal<(tab: number) => void>;
    public readonly tab_close_pressed: Signal<(tab: number) => void>;
    public readonly tab_button_pressed: Signal<(tab: number) => void>;
    public readonly tab_hovered: Signal<(tab: number) => void>;
    public readonly active_tab_rearranged: Signal<(idxTo: number) => void>;

    public static readonly AlignmentMode: {
        ALIGNMENT_LEFT: 0;
        ALIGNMENT_CENTER: 1;
        ALIGNMENT_RIGHT: 2;
        ALIGNMENT_MAX: 3;
    };
    public static readonly CloseButtonDisplayPolicy: {
        CLOSE_BUTTON_SHOW_NEVER: 0;
        CLOSE_BUTTON_SHOW_ACTIVE_ONLY: 1;
        CLOSE_BUTTON_SHOW_ALWAYS: 2;
        CLOSE_BUTTON_MAX: 3;
    };
}

