
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _PhysicsServer3DManager extends GodotObject {


    public register_server(name: GDString | StringName | string, createCallback: Callable | Function): void;
    public set_default_server(name: GDString | StringName | string, priority: number): void;


}

export const PhysicsServer3DManager: _PhysicsServer3DManager;
