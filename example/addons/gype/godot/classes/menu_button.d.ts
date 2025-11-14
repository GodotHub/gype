
import type { Button } from '@godot/classes/button';
import type { PopupMenu } from '@godot/classes/popup_menu';
import type { Signal } from '@godot/builtins/signal';


export declare class MenuButton extends Button {

    
    /**     * The raw type is 'bool'     */
    public switch_on_hover: boolean;    
    /**     * The raw type is 'int'     */
    public item_count: number;
    public get_popup(): PopupMenu;
    public show_popup(): void;
    public set_switch_on_hover(enable: boolean): void;
    public is_switch_on_hover(): boolean;
    public set_disable_shortcuts(disabled: boolean): void;
    public set_item_count(count: number): void;
    public get_item_count(): number;

    
    public readonly about_to_popup: Signal<() => void>;

}

