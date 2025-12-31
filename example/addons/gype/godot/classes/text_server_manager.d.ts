
import type { GodotObject } from '@godot/classes/godot_object';
import type { TextServer } from '@godot/classes/text_server';


export declare class _TextServerManager extends GodotObject {


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

export const TextServerManager: _TextServerManager;
