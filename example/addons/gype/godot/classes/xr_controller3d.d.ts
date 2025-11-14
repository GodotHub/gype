
import type { GDString } from '@godot/builtins/gd_string';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector2 } from '@godot/builtins/vector2';
import type { XRNode3D } from '@godot/classes/xr_node3d';


export declare class XRController3D extends XRNode3D {


    public is_button_pressed(name: GDString | StringName | string): boolean;
    public get_input(name: GDString | StringName | string): any;
    public get_float(name: GDString | StringName | string): number;
    public get_vector2(name: GDString | StringName | string): Vector2;
    public get_tracker_hand(): number;

    
    public readonly button_pressed: Signal<(name: GDString | StringName | string) => void>;
    public readonly button_released: Signal<(name: GDString | StringName | string) => void>;
    public readonly input_float_changed: Signal<(name: GDString | StringName | string, value: number) => void>;
    public readonly input_vector2_changed: Signal<(name: GDString | StringName | string, value: Vector2) => void>;
    public readonly profile_changed: Signal<(role: GDString | StringName | string) => void>;

}

