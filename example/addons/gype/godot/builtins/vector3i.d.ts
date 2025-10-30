
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Vector3i {
    constructor();
    constructor(_from: Vector3i);
    constructor(_from: Vector3);
    constructor(x: number, y: number, z: number);

    public x: number;
    public y: number;
    public z: number;

    public min_axis_index(): number;
    public max_axis_index(): number;
    public distance_to(to: Vector3i): number;
    public distance_squared_to(to: Vector3i): number;
    public length(): number;
    public length_squared(): number;
    public sign(): Vector3i;
    public abs(): Vector3i;
    public clamp(min: Vector3i, max: Vector3i): Vector3i;
    public clampi(min: number, max: number): Vector3i;
    public snapped(step: Vector3i): Vector3i;
    public snappedi(step: number): Vector3i;
    public min(_with: Vector3i): Vector3i;
    public mini(_with: number): Vector3i;
    public max(_with: Vector3i): Vector3i;
    public maxi(_with: number): Vector3i;

    public static readonly Axis: {
        AXIS_X: 0;
        AXIS_Y: 1;
        AXIS_Z: 2;
    };
}