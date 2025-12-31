
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _PhysicsServer2DManager extends GodotObject {


    public register_server(name: GDString | StringName | string, createCallback: Callable | Function): void;
    public set_default_server(name: GDString | StringName | string, priority: number): void;


}

export const PhysicsServer2DManager: _PhysicsServer2DManager;
