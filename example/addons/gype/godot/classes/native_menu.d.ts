
import type { GodotObject } from '@godot/classes/godot_object';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class NativeMenu extends GodotObject {


    public has_feature(feature: number): boolean;
    public has_system_menu(menuId: number): boolean;
    public get_system_menu(menuId: number): RID;
    public get_system_menu_name(menuId: number): GDString;
    public create_menu(): RID;
    public has_menu(rid: RID): boolean;
    public free_menu(rid: RID): void;
    public get_size(rid: RID): Vector2;
    public popup(rid: RID, position: Vector2i): void;
    public set_interface_direction(rid: RID, isRtl: boolean): void;
    public set_popup_open_callback(rid: RID, callback: Callable | Function): void;
    public get_popup_open_callback(rid: RID): Callable;
    public set_popup_close_callback(rid: RID, callback: Callable | Function): void;
    public get_popup_close_callback(rid: RID): Callable;
    public set_minimum_width(rid: RID, width: number): void;
    public get_minimum_width(rid: RID): number;
    public is_opened(rid: RID): boolean;
    public add_submenu_item(rid: RID, label: GDString | StringName | string, submenuRid: RID, tag: any = null, index: number = -1): number;
    public add_item(rid: RID, label: GDString | StringName | string, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_check_item(rid: RID, label: GDString | StringName | string, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_icon_item(rid: RID, icon: Texture2D, label: GDString | StringName | string, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_icon_check_item(rid: RID, icon: Texture2D, label: GDString | StringName | string, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_radio_check_item(rid: RID, label: GDString | StringName | string, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_icon_radio_check_item(rid: RID, icon: Texture2D, label: GDString | StringName | string, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_multistate_item(rid: RID, label: GDString | StringName | string, maxStates: number, defaultState: number, callback: Callable | Function = Callable(), keyCallback: Callable | Function = Callable(), tag: any = null, accelerator: number = 0, index: number = -1): number;
    public add_separator(rid: RID, index: number = -1): number;
    public find_item_index_with_text(rid: RID, text: GDString | StringName | string): number;
    public find_item_index_with_tag(rid: RID, tag: any): number;
    public find_item_index_with_submenu(rid: RID, submenuRid: RID): number;
    public is_item_checked(rid: RID, idx: number): boolean;
    public is_item_checkable(rid: RID, idx: number): boolean;
    public is_item_radio_checkable(rid: RID, idx: number): boolean;
    public get_item_callback(rid: RID, idx: number): Callable;
    public get_item_key_callback(rid: RID, idx: number): Callable;
    public get_item_tag(rid: RID, idx: number): any;
    public get_item_text(rid: RID, idx: number): GDString;
    public get_item_submenu(rid: RID, idx: number): RID;
    public get_item_accelerator(rid: RID, idx: number): number;
    public is_item_disabled(rid: RID, idx: number): boolean;
    public is_item_hidden(rid: RID, idx: number): boolean;
    public get_item_tooltip(rid: RID, idx: number): GDString;
    public get_item_state(rid: RID, idx: number): number;
    public get_item_max_states(rid: RID, idx: number): number;
    public get_item_icon(rid: RID, idx: number): Texture2D;
    public get_item_indentation_level(rid: RID, idx: number): number;
    public set_item_checked(rid: RID, idx: number, checked: boolean): void;
    public set_item_checkable(rid: RID, idx: number, checkable: boolean): void;
    public set_item_radio_checkable(rid: RID, idx: number, checkable: boolean): void;
    public set_item_callback(rid: RID, idx: number, callback: Callable | Function): void;
    public set_item_hover_callbacks(rid: RID, idx: number, callback: Callable | Function): void;
    public set_item_key_callback(rid: RID, idx: number, keyCallback: Callable | Function): void;
    public set_item_tag(rid: RID, idx: number, tag: any): void;
    public set_item_text(rid: RID, idx: number, text: GDString | StringName | string): void;
    public set_item_submenu(rid: RID, idx: number, submenuRid: RID): void;
    public set_item_accelerator(rid: RID, idx: number, keycode: number): void;
    public set_item_disabled(rid: RID, idx: number, disabled: boolean): void;
    public set_item_hidden(rid: RID, idx: number, hidden: boolean): void;
    public set_item_tooltip(rid: RID, idx: number, tooltip: GDString | StringName | string): void;
    public set_item_state(rid: RID, idx: number, state: number): void;
    public set_item_max_states(rid: RID, idx: number, maxStates: number): void;
    public set_item_icon(rid: RID, idx: number, icon: Texture2D): void;
    public set_item_indentation_level(rid: RID, idx: number, level: number): void;
    public get_item_count(rid: RID): number;
    public is_system_menu(rid: RID): boolean;
    public remove_item(rid: RID, idx: number): void;
    public clear(rid: RID): void;


    public static readonly Feature: {
        FEATURE_GLOBAL_MENU: 0;
        FEATURE_POPUP_MENU: 1;
        FEATURE_OPEN_CLOSE_CALLBACK: 2;
        FEATURE_HOVER_CALLBACK: 3;
        FEATURE_KEY_CALLBACK: 4;
    };
    public static readonly SystemMenus: {
        INVALID_MENU_ID: 0;
        MAIN_MENU_ID: 1;
        APPLICATION_MENU_ID: 2;
        WINDOW_MENU_ID: 3;
        HELP_MENU_ID: 4;
        DOCK_MENU_ID: 5;
    };
}


/**
 * A singleton instance of NativeMenu.
 * This is a global variable, available from anywhere.
 */
export const NativeMenu: NativeMenu;
