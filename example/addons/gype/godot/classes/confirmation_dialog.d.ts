
import type { AcceptDialog } from '@godot/classes/accept_dialog';
import type { Button } from '@godot/classes/button';


export declare class ConfirmationDialog extends AcceptDialog {

    
    /**     * The raw type is 'String'     */
    public cancel_button_text: GDString | StringName | string;
    public get_cancel_button(): Button;
    public set_cancel_button_text(text: GDString | StringName | string): void;
    public get_cancel_button_text(): GDString;


}

