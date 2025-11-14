
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { TextServer } from '@godot/classes/text_server';


export declare class TextServerManager extends GodotObject {


    public add_interface(_interface: TextServer): void;
    public get_interface_count(): number;
    public remove_interface(_interface: TextServer): void;
    public get_interface(idx: number): TextServer;
    public get_interfaces(): Array<any>;
    public find_interface(name: GDString | StringName | string): TextServer;
    public set_primary_interface(index: TextServer): void;
    public get_primary_interface(): TextServer;

    
    public readonly interface_added: Signal<(interfaceName: GDString | StringName | string) => void>;
    public readonly interface_removed: Signal<(interfaceName: GDString | StringName | string) => void>;

}


/**
 * A singleton instance of TextServerManager.
 * This is a global variable, available from anywhere.
 */
export const TextServerManager: TextServerManager;
