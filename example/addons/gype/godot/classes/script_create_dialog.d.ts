
import type { ConfirmationDialog } from '@godot/classes/confirmation_dialog';
import type { GDString } from '@godot/builtins/gd_string';
import type { Script } from '@godot/classes/script';
import type { Signal } from '@godot/builtins/signal';


export declare class ScriptCreateDialog extends ConfirmationDialog {


    public config(inherits: GDString | StringName | string, path: GDString | StringName | string, builtInEnabled: boolean = true, loadEnabled: boolean = true): void;

    
    public readonly script_created: Signal<(script: Script) => void>;

}

