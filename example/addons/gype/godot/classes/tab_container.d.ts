
import type { Container } from '@godot/classes/container';
import type { Control } from '@godot/classes/control';
import type { Node } from '@godot/classes/node';
import type { Popup } from '@godot/classes/popup';
import type { TabBar } from '@godot/classes/tab_bar';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class TabContainer extends Container {

    
    /**     * The raw type is 'int'     */
    public tab_alignment: number;    
    /**     * The raw type is 'int'     */
    public current_tab: number;    
    /**     * The raw type is 'int'     */
    public tabs_position: number;    
    /**     * The raw type is 'bool'     */
    public clip_tabs: boolean;    
    /**     * The raw type is 'bool'     */
    public tabs_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public all_tabs_in_front: boolean;    
    /**     * The raw type is 'bool'     */
    public drag_to_rearrange_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public tabs_rearrange_group: number;    
    /**     * The raw type is 'bool'     */
    public use_hidden_tabs_for_min_size: boolean;    
    /**     * The raw type is 'int'     */
    public tab_focus_mode: number;    
    /**     * The raw type is 'bool'     */
    public deselect_enabled: boolean;
    public get_tab_count(): number;
    public set_current_tab(tabIdx: number): void;
    public get_current_tab(): number;
    public get_previous_tab(): number;
    public select_previous_available(): boolean;
    public select_next_available(): boolean;
    public get_current_tab_control(): Control;
    public get_tab_bar(): TabBar;
    public get_tab_control(tabIdx: number): Control;
    public set_tab_alignment(alignment: number): void;
    public get_tab_alignment(): number;
    public set_tabs_position(tabsPosition: number): void;
    public get_tabs_position(): number;
    public set_clip_tabs(clitabs: boolean): void;
    public get_clip_tabs(): boolean;
    public set_tabs_visible(visible: boolean): void;
    public are_tabs_visible(): boolean;
    public set_all_tabs_in_front(isFront: boolean): void;
    public is_all_tabs_in_front(): boolean;
    public set_tab_title(tabIdx: number, title: GDString | StringName | string): void;
    public get_tab_title(tabIdx: number): GDString;
    public set_tab_tooltip(tabIdx: number, tooltip: GDString | StringName | string): void;
    public get_tab_tooltip(tabIdx: number): GDString;
    public set_tab_icon(tabIdx: number, icon: Texture2D): void;
    public get_tab_icon(tabIdx: number): Texture2D;
    public set_tab_icon_max_width(tabIdx: number, width: number): void;
    public get_tab_icon_max_width(tabIdx: number): number;
    public set_tab_disabled(tabIdx: number, disabled: boolean): void;
    public is_tab_disabled(tabIdx: number): boolean;
    public set_tab_hidden(tabIdx: number, hidden: boolean): void;
    public is_tab_hidden(tabIdx: number): boolean;
    public set_tab_metadata(tabIdx: number, metadata: any): void;
    public get_tab_metadata(tabIdx: number): any;
    public set_tab_button_icon(tabIdx: number, icon: Texture2D): void;
    public get_tab_button_icon(tabIdx: number): Texture2D;
    public get_tab_idx_at_point(point: Vector2): number;
    public get_tab_idx_from_control(control: Control): number;
    public set_popup(popup: Node): void;
    public get_popup(): Popup;
    public set_drag_to_rearrange_enabled(enabled: boolean): void;
    public get_drag_to_rearrange_enabled(): boolean;
    public set_tabs_rearrange_group(grouid: number): void;
    public get_tabs_rearrange_group(): number;
    public set_use_hidden_tabs_for_min_size(enabled: boolean): void;
    public get_use_hidden_tabs_for_min_size(): boolean;
    public set_tab_focus_mode(focusMode: number): void;
    public get_tab_focus_mode(): number;
    public set_deselect_enabled(enabled: boolean): void;
    public get_deselect_enabled(): boolean;

    
    public readonly active_tab_rearranged: Signal;
    public readonly tab_changed: Signal;
    public readonly tab_clicked: Signal;
    public readonly tab_hovered: Signal;
    public readonly tab_selected: Signal;
    public readonly tab_button_pressed: Signal;
    public readonly pre_popup_pressed: Signal;

    public static readonly TabPosition: {
        POSITION_TOP: 0;
        POSITION_BOTTOM: 1;
        POSITION_MAX: 2;
    };
}

