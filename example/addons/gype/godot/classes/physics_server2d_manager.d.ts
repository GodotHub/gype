
import type { Callable } from '@godot/builtins/callable';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class PhysicsServer2DManager extends GodotObject {


    public register_server(name: GDString | StringName | string, createCallback: Callable | Function): void;
    public set_default_server(name: GDString | StringName | string, priority: number): void;


}


/**
 * A singleton instance of PhysicsServer2DManager.
 * This is a global variable, available from anywhere.
 */
export const PhysicsServer2DManager: PhysicsServer2DManager;
