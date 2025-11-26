
import type { ConfirmationDialog } from '@godot/classes/confirmation_dialog';
import type { Script } from '@godot/classes/script';


export declare class ScriptCreateDialog extends ConfirmationDialog {


    public config(inherits: GDString | StringName | string, path: GDString | StringName | string, builtInEnabled: boolean = true, loadEnabled: boolean = true): void;

    
    public readonly script_created: Signal;

}

