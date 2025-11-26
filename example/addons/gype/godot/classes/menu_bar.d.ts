
import type { Control } from '@godot/classes/control';
import type { PopupMenu } from '@godot/classes/popup_menu';


export declare class MenuBar extends Control {

    
    /**     * The raw type is 'bool'     */
    public flat: boolean;    
    /**     * The raw type is 'int'     */
    public start_index: number;    
    /**     * The raw type is 'bool'     */
    public switch_on_hover: boolean;    
    /**     * The raw type is 'bool'     */
    public prefer_global_menu: boolean;    
    /**     * The raw type is 'int'     */
    public text_direction: number;    
    /**     * The raw type is 'String'     */
    public language: GDString;
    public set_switch_on_hover(enable: boolean): void;
    public is_switch_on_hover(): boolean;
    public set_disable_shortcuts(disabled: boolean): void;
    public set_prefer_global_menu(enabled: boolean): void;
    public is_prefer_global_menu(): boolean;
    public is_native_menu(): boolean;
    public get_menu_count(): number;
    public set_text_direction(direction: number): void;
    public get_text_direction(): number;
    public set_language(language: GDString | StringName | string): void;
    public get_language(): GDString;
    public set_flat(enabled: boolean): void;
    public is_flat(): boolean;
    public set_start_index(enabled: number): void;
    public get_start_index(): number;
    public set_menu_title(menu: number, title: GDString | StringName | string): void;
    public get_menu_title(menu: number): GDString;
    public set_menu_tooltip(menu: number, tooltip: GDString | StringName | string): void;
    public get_menu_tooltip(menu: number): GDString;
    public set_menu_disabled(menu: number, disabled: boolean): void;
    public is_menu_disabled(menu: number): boolean;
    public set_menu_hidden(menu: number, hidden: boolean): void;
    public is_menu_hidden(menu: number): boolean;
    public get_menu_popup(menu: number): PopupMenu;


}

