
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Quaternion } from '@godot/builtins/quaternion';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Basis {
    constructor();
    constructor(_from: Basis);
    constructor(_from: Quaternion);
    constructor(axis: Vector3, angle: number);
    constructor(x_axis: Vector3, y_axis: Vector3, z_axis: Vector3);

    public x: Vector3;
    public y: Vector3;
    public z: Vector3;

    public inverse(): Basis;
    public transposed(): Basis;
    public orthonormalized(): Basis;
    public determinant(): number;
    public rotated(axis: Vector3, angle: number): Basis;
    public scaled(scale: Vector3): Basis;
    public scaled_local(scale: Vector3): Basis;
    public get_scale(): Vector3;
    public get_euler(order: number): Vector3;
    public tdotx(_with: Vector3): number;
    public tdoty(_with: Vector3): number;
    public tdotz(_with: Vector3): number;
    public slerp(to: Basis, weight: number): Basis;
    public is_conformal(): boolean;
    public is_equal_approx(b: Basis): boolean;
    public is_finite(): boolean;
    public get_rotation_quaternion(): Quaternion;
    public static looking_at(target: Vector3, up: Vector3, use_model_front: boolean): Basis;
    public static from_scale(scale: Vector3): Basis;
    public static from_euler(euler: Vector3, order: number): Basis;

}