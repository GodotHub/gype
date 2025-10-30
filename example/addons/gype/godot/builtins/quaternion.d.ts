
import type { Basis } from '@godot/builtins/basis';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Quaternion {
    constructor();
    constructor(_from: Quaternion);
    constructor(_from: Basis);
    constructor(axis: Vector3, angle: number);
    constructor(arc_from: Vector3, arc_to: Vector3);
    constructor(x: number, y: number, z: number, w: number);

    public x: number;
    public y: number;
    public z: number;
    public w: number;

    public length(): number;
    public length_squared(): number;
    public normalized(): Quaternion;
    public is_normalized(): boolean;
    public is_equal_approx(to: Quaternion): boolean;
    public is_finite(): boolean;
    public inverse(): Quaternion;
    public log(): Quaternion;
    public exp(): Quaternion;
    public angle_to(to: Quaternion): number;
    public dot(_with: Quaternion): number;
    public slerp(to: Quaternion, weight: number): Quaternion;
    public slerpni(to: Quaternion, weight: number): Quaternion;
    public spherical_cubic_interpolate(b: Quaternion, pre_a: Quaternion, post_b: Quaternion, weight: number): Quaternion;
    public spherical_cubic_interpolate_in_time(b: Quaternion, pre_a: Quaternion, post_b: Quaternion, weight: number, b_t: number, pre_a_t: number, post_b_t: number): Quaternion;
    public get_euler(order: number): Vector3;
    public static from_euler(euler: Vector3): Quaternion;
    public get_axis(): Vector3;
    public get_angle(): number;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public negate(): Quaternion;
    public positive(): Quaternion;
    public op_not(): boolean;
    public multiply(right: number): Quaternion;
    public divide(right: number): Quaternion;
    public multiply(right: number): Quaternion;
    public divide(right: number): Quaternion;
    public multiply(right: Vector3): Vector3;
    public equals(right: Quaternion): boolean;
    public not_equals(right: Quaternion): boolean;
    public add(right: Quaternion): Quaternion;
    public subtract(right: Quaternion): Quaternion;
    public multiply(right: Quaternion): Quaternion;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;

}