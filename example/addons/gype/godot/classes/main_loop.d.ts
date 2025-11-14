
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Signal } from '@godot/builtins/signal';


export declare class MainLoop extends GodotObject {


    public _initialize(): void;
    public _physics_process(delta: number): boolean;
    public _process(delta: number): boolean;
    public _finalize(): void;

    
    public readonly on_request_permissions_result: Signal<(permission: GDString | StringName | string, granted: boolean) => void>;

}

