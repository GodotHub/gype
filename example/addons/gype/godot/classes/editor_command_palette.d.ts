
import type { ConfirmationDialog } from '@godot/classes/confirmation_dialog';


export declare class EditorCommandPalette extends ConfirmationDialog {


    public add_command(commandName: GDString | StringName | string, keyName: GDString | StringName | string, bindedCallable: Callable | Function, shortcutText: GDString | StringName | string = "None"): void;
    public remove_command(keyName: GDString | StringName | string): void;


}

