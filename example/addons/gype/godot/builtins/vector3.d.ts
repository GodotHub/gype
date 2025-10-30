
import type { Basis } from '@godot/builtins/basis';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Quaternion } from '@godot/builtins/quaternion';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3i } from '@godot/builtins/vector3i';


export declare class Vector3 {
    constructor();
    constructor(_from: Vector3);
    constructor(_from: Vector3i);
    constructor(x: number, y: number, z: number);

    public x: number;
    public y: number;
    public z: number;

    public min_axis_index(): number;
    public max_axis_index(): number;
    public angle_to(to: Vector3): number;
    public signed_angle_to(to: Vector3, axis: Vector3): number;
    public direction_to(to: Vector3): Vector3;
    public distance_to(to: Vector3): number;
    public distance_squared_to(to: Vector3): number;
    public length(): number;
    public length_squared(): number;
    public limit_length(length: number): Vector3;
    public normalized(): Vector3;
    public is_normalized(): boolean;
    public is_equal_approx(to: Vector3): boolean;
    public is_zero_approx(): boolean;
    public is_finite(): boolean;
    public inverse(): Vector3;
    public clamp(min: Vector3, max: Vector3): Vector3;
    public clampf(min: number, max: number): Vector3;
    public snapped(step: Vector3): Vector3;
    public snappedf(step: number): Vector3;
    public rotated(axis: Vector3, angle: number): Vector3;
    public lerp(to: Vector3, weight: number): Vector3;
    public slerp(to: Vector3, weight: number): Vector3;
    public cubic_interpolate(b: Vector3, pre_a: Vector3, post_b: Vector3, weight: number): Vector3;
    public cubic_interpolate_in_time(b: Vector3, pre_a: Vector3, post_b: Vector3, weight: number, b_t: number, pre_a_t: number, post_b_t: number): Vector3;
    public bezier_interpolate(control_1: Vector3, control_2: Vector3, end: Vector3, t: number): Vector3;
    public bezier_derivative(control_1: Vector3, control_2: Vector3, end: Vector3, t: number): Vector3;
    public move_toward(to: Vector3, delta: number): Vector3;
    public dot(_with: Vector3): number;
    public cross(_with: Vector3): Vector3;
    public outer(_with: Vector3): Basis;
    public abs(): Vector3;
    public floor(): Vector3;
    public ceil(): Vector3;
    public round(): Vector3;
    public posmod(mod: number): Vector3;
    public posmodv(modv: Vector3): Vector3;
    public project(b: Vector3): Vector3;
    public slide(n: Vector3): Vector3;
    public bounce(n: Vector3): Vector3;
    public reflect(n: Vector3): Vector3;
    public sign(): Vector3;
    public octahedron_encode(): Vector2;
    public min(_with: Vector3): Vector3;
    public minf(_with: number): Vector3;
    public max(_with: Vector3): Vector3;
    public maxf(_with: number): Vector3;
    public static octahedron_decode(uv: Vector2): Vector3;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public negate(): Vector3;
    public positive(): Vector3;
    public op_not(): boolean;
    public multiply(right: number): Vector3;
    public divide(right: number): Vector3;
    public multiply(right: number): Vector3;
    public divide(right: number): Vector3;
    public equals(right: Vector3): boolean;
    public not_equals(right: Vector3): boolean;
    public less(right: Vector3): boolean;
    public less_equal(right: Vector3): boolean;
    public greater(right: Vector3): boolean;
    public greater_equal(right: Vector3): boolean;
    public add(right: Vector3): Vector3;
    public subtract(right: Vector3): Vector3;
    public multiply(right: Vector3): Vector3;
    public divide(right: Vector3): Vector3;
    public multiply(right: Quaternion): Vector3;
    public multiply(right: Basis): Vector3;
    public multiply(right: Transform3D): Vector3;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public in_op(right: PackedVector3Array): boolean;

    public static readonly Axis: {
        AXIS_X: 0;
        AXIS_Y: 1;
        AXIS_Z: 2;
    };
}