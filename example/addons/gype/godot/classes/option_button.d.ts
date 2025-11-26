
import type { Button } from '@godot/classes/button';
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class OptionButton extends Button {

    
    /**     * The raw type is 'int'     */
    public selected: number;    
    /**     * The raw type is 'bool'     */
    public fit_to_longest_item: boolean;    
    /**     * The raw type is 'bool'     */
    public allow_reselect: boolean;    
    /**     * The raw type is 'int'     */
    public item_count: number;
    public add_item(label: GDString | StringName | string, id: number = -1): void;
    public add_icon_item(texture: Texture2D, label: GDString | StringName | string, id: number = -1): void;
    public set_item_text(idx: number, text: GDString | StringName | string): void;
    public set_item_icon(idx: number, texture: Texture2D): void;
    public set_item_disabled(idx: number, disabled: boolean): void;
    public set_item_id(idx: number, id: number): void;
    public set_item_metadata(idx: number, metadata: any): void;
    public set_item_tooltip(idx: number, tooltip: GDString | StringName | string): void;
    public set_item_auto_translate_mode(idx: number, mode: number): void;
    public get_item_text(idx: number): GDString;
    public get_item_icon(idx: number): Texture2D;
    public get_item_id(idx: number): number;
    public get_item_index(id: number): number;
    public get_item_metadata(idx: number): any;
    public get_item_tooltip(idx: number): GDString;
    public get_item_auto_translate_mode(idx: number): number;
    public is_item_disabled(idx: number): boolean;
    public is_item_separator(idx: number): boolean;
    public add_separator(text: GDString | StringName | string = ""): void;
    public clear(): void;
    public select(idx: number): void;
    public get_selected(): number;
    public get_selected_id(): number;
    public get_selected_metadata(): any;
    public remove_item(idx: number): void;
    public get_popup(): PopupMenu;
    public show_popup(): void;
    public set_item_count(count: number): void;
    public get_item_count(): number;
    public has_selectable_items(): boolean;
    public get_selectable_item(fromLast: boolean = false): number;
    public set_fit_to_longest_item(fit: boolean): void;
    public is_fit_to_longest_item(): boolean;
    public set_allow_reselect(allow: boolean): void;
    public get_allow_reselect(): boolean;
    public set_disable_shortcuts(disabled: boolean): void;

    
    public readonly item_selected: Signal;
    public readonly item_focused: Signal;

}

