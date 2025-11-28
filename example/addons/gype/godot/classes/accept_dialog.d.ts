
import type { Button } from '@godot/classes/button';
import type { Label } from '@godot/classes/label';
import type { LineEdit } from '@godot/classes/line_edit';
import type { Window } from '@godot/classes/window';


export declare class AcceptDialog extends Window {

    
    /**     * The raw type is 'String'     */
    public ok_button_text: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public dialog_text: GDString | StringName | string;    
    /**     * The raw type is 'bool'     */
    public dialog_hide_on_ok: boolean;    
    /**     * The raw type is 'bool'     */
    public dialog_close_on_escape: boolean;    
    /**     * The raw type is 'bool'     */
    public dialog_autowrap: boolean;
    public get_ok_button(): Button;
    public get_label(): Label;
    public set_hide_on_ok(enabled: boolean): void;
    public get_hide_on_ok(): boolean;
    public set_close_on_escape(enabled: boolean): void;
    public get_close_on_escape(): boolean;
    public add_button(text: GDString | StringName | string, right: boolean = false, action: GDString | StringName | string = ""): Button;
    public add_cancel_button(name: GDString | StringName | string): Button;
    public remove_button(button: Button): void;
    public register_text_enter(lineEdit: LineEdit): void;
    public set_text(text: GDString | StringName | string): void;
    public get_text(): GDString;
    public set_autowrap(autowrap: boolean): void;
    public has_autowrap(): boolean;
    public set_ok_button_text(text: GDString | StringName | string): void;
    public get_ok_button_text(): GDString;

    
    public readonly confirmed: Signal;
    public readonly canceled: Signal;
    public readonly custom_action: Signal;

}

