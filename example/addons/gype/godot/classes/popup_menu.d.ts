
import type { Color } from '@godot/builtins/color';
import type { GDString } from '@godot/builtins/gd_string';
import type { InputEvent } from '@godot/classes/input_event';
import type { Popup } from '@godot/classes/popup';
import type { Shortcut } from '@godot/classes/shortcut';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class PopupMenu extends Popup {

    
    /**     * The raw type is 'bool'     */
    public hide_on_item_selection: boolean;    
    /**     * The raw type is 'bool'     */
    public hide_on_checkable_item_selection: boolean;    
    /**     * The raw type is 'bool'     */
    public hide_on_state_item_selection: boolean;    
    /**     * The raw type is 'float'     */
    public submenu_popup_delay: number;    
    /**     * The raw type is 'bool'     */
    public allow_search: boolean;    
    /**     * The raw type is 'int'     */
    public system_menu_id: number;    
    /**     * The raw type is 'bool'     */
    public prefer_native_menu: boolean;    
    /**     * The raw type is 'int'     */
    public item_count: number;
    public activate_item_by_event(event: InputEvent, forGlobalOnly: boolean = false): boolean;
    public set_prefer_native_menu(enabled: boolean): void;
    public is_prefer_native_menu(): boolean;
    public is_native_menu(): boolean;
    public add_item(label: GDString | StringName | string, id: number = -1, accel: number = 0): void;
    public add_icon_item(texture: Texture2D, label: GDString | StringName | string, id: number = -1, accel: number = 0): void;
    public add_check_item(label: GDString | StringName | string, id: number = -1, accel: number = 0): void;
    public add_icon_check_item(texture: Texture2D, label: GDString | StringName | string, id: number = -1, accel: number = 0): void;
    public add_radio_check_item(label: GDString | StringName | string, id: number = -1, accel: number = 0): void;
    public add_icon_radio_check_item(texture: Texture2D, label: GDString | StringName | string, id: number = -1, accel: number = 0): void;
    public add_multistate_item(label: GDString | StringName | string, maxStates: number, defaultState: number = 0, id: number = -1, accel: number = 0): void;
    public add_shortcut(shortcut: Shortcut, id: number = -1, global: boolean = false, allowEcho: boolean = false): void;
    public add_icon_shortcut(texture: Texture2D, shortcut: Shortcut, id: number = -1, global: boolean = false, allowEcho: boolean = false): void;
    public add_check_shortcut(shortcut: Shortcut, id: number = -1, global: boolean = false): void;
    public add_icon_check_shortcut(texture: Texture2D, shortcut: Shortcut, id: number = -1, global: boolean = false): void;
    public add_radio_check_shortcut(shortcut: Shortcut, id: number = -1, global: boolean = false): void;
    public add_icon_radio_check_shortcut(texture: Texture2D, shortcut: Shortcut, id: number = -1, global: boolean = false): void;
    public add_submenu_item(label: GDString | StringName | string, submenu: GDString | StringName | string, id: number = -1): void;
    public add_submenu_node_item(label: GDString | StringName | string, submenu: PopupMenu, id: number = -1): void;
    public set_item_text(index: number, text: GDString | StringName | string): void;
    public set_item_text_direction(index: number, direction: number): void;
    public set_item_language(index: number, language: GDString | StringName | string): void;
    public set_item_auto_translate_mode(index: number, mode: number): void;
    public set_item_icon(index: number, icon: Texture2D): void;
    public set_item_icon_max_width(index: number, width: number): void;
    public set_item_icon_modulate(index: number, modulate: Color): void;
    public set_item_checked(index: number, checked: boolean): void;
    public set_item_id(index: number, id: number): void;
    public set_item_accelerator(index: number, accel: number): void;
    public set_item_metadata(index: number, metadata: any): void;
    public set_item_disabled(index: number, disabled: boolean): void;
    public set_item_submenu(index: number, submenu: GDString | StringName | string): void;
    public set_item_submenu_node(index: number, submenu: PopupMenu): void;
    public set_item_as_separator(index: number, enable: boolean): void;
    public set_item_as_checkable(index: number, enable: boolean): void;
    public set_item_as_radio_checkable(index: number, enable: boolean): void;
    public set_item_tooltip(index: number, tooltip: GDString | StringName | string): void;
    public set_item_shortcut(index: number, shortcut: Shortcut, global: boolean = false): void;
    public set_item_indent(index: number, indent: number): void;
    public set_item_multistate(index: number, state: number): void;
    public set_item_multistate_max(index: number, maxStates: number): void;
    public set_item_shortcut_disabled(index: number, disabled: boolean): void;
    public toggle_item_checked(index: number): void;
    public toggle_item_multistate(index: number): void;
    public get_item_text(index: number): GDString;
    public get_item_text_direction(index: number): number;
    public get_item_language(index: number): GDString;
    public get_item_auto_translate_mode(index: number): number;
    public get_item_icon(index: number): Texture2D;
    public get_item_icon_max_width(index: number): number;
    public get_item_icon_modulate(index: number): Color;
    public is_item_checked(index: number): boolean;
    public get_item_id(index: number): number;
    public get_item_index(id: number): number;
    public get_item_accelerator(index: number): number;
    public get_item_metadata(index: number): any;
    public is_item_disabled(index: number): boolean;
    public get_item_submenu(index: number): GDString;
    public get_item_submenu_node(index: number): PopupMenu;
    public is_item_separator(index: number): boolean;
    public is_item_checkable(index: number): boolean;
    public is_item_radio_checkable(index: number): boolean;
    public is_item_shortcut_disabled(index: number): boolean;
    public get_item_tooltip(index: number): GDString;
    public get_item_shortcut(index: number): Shortcut;
    public get_item_indent(index: number): number;
    public get_item_multistate_max(index: number): number;
    public get_item_multistate(index: number): number;
    public set_focused_item(index: number): void;
    public get_focused_item(): number;
    public set_item_count(count: number): void;
    public get_item_count(): number;
    public scroll_to_item(index: number): void;
    public remove_item(index: number): void;
    public add_separator(label: GDString | StringName | string = "", id: number = -1): void;
    public clear(freeSubmenus: boolean = false): void;
    public set_hide_on_item_selection(enable: boolean): void;
    public is_hide_on_item_selection(): boolean;
    public set_hide_on_checkable_item_selection(enable: boolean): void;
    public is_hide_on_checkable_item_selection(): boolean;
    public set_hide_on_state_item_selection(enable: boolean): void;
    public is_hide_on_state_item_selection(): boolean;
    public set_submenu_popup_delay(seconds: number): void;
    public get_submenu_popup_delay(): number;
    public set_allow_search(allow: boolean): void;
    public get_allow_search(): boolean;
    public is_system_menu(): boolean;
    public set_system_menu(systemMenuId: number): void;
    public get_system_menu(): number;

    
    public readonly id_pressed: Signal<(id: number) => void>;
    public readonly id_focused: Signal<(id: number) => void>;
    public readonly index_pressed: Signal<(index: number) => void>;
    public readonly menu_changed: Signal<() => void>;

}

