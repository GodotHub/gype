
import type { Callable } from '@godot/builtins/callable';
import type { ConfirmationDialog } from '@godot/classes/confirmation_dialog';
import type { GDString } from '@godot/builtins/gd_string';


export declare class EditorCommandPalette extends ConfirmationDialog {


    public add_command(commandName: GDString | StringName | string, keyName: GDString | StringName | string, bindedCallable: Callable | Function, shortcutText: GDString | StringName | string = "None"): void;
    public remove_command(keyName: GDString | StringName | string): void;


}

