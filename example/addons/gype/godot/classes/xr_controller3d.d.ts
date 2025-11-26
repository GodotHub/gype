
import type { XRNode3D } from '@godot/classes/xr_node3d';


export declare class XRController3D extends XRNode3D {


    public is_button_pressed(name: GDString | StringName | string): boolean;
    public get_input(name: GDString | StringName | string): any;
    public get_float(name: GDString | StringName | string): number;
    public get_vector2(name: GDString | StringName | string): Vector2;
    public get_tracker_hand(): number;

    
    public readonly button_pressed: Signal;
    public readonly button_released: Signal;
    public readonly input_float_changed: Signal;
    public readonly input_vector2_changed: Signal;
    public readonly profile_changed: Signal;

}

