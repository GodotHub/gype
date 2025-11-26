
import type { GodotObject } from '@godot/classes/godot_object';
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

    
    public readonly interface_added: Signal;
    public readonly interface_removed: Signal;

}


/**
 * A singleton instance of TextServerManager.
 * This is a global variable, available from anywhere.
 */
export const TextServerManager: TextServerManager;
