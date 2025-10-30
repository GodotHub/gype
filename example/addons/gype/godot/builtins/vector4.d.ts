
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedVector4Array } from '@godot/builtins/packed_vector4_array';
import type { Projection } from '@godot/builtins/projection';
import type { Vector4i } from '@godot/builtins/vector4i';


export declare class Vector4 {
    constructor();
    constructor(_from: Vector4);
    constructor(_from: Vector4i);
    constructor(x: number, y: number, z: number, w: number);

    public x: number;
    public y: number;
    public z: number;
    public w: number;

    public min_axis_index(): number;
    public max_axis_index(): number;
    public length(): number;
    public length_squared(): number;
    public abs(): Vector4;
    public sign(): Vector4;
    public floor(): Vector4;
    public ceil(): Vector4;
    public round(): Vector4;
    public lerp(to: Vector4, weight: number): Vector4;
    public cubic_interpolate(b: Vector4, pre_a: Vector4, post_b: Vector4, weight: number): Vector4;
    public cubic_interpolate_in_time(b: Vector4, pre_a: Vector4, post_b: Vector4, weight: number, b_t: number, pre_a_t: number, post_b_t: number): Vector4;
    public posmod(mod: number): Vector4;
    public posmodv(modv: Vector4): Vector4;
    public snapped(step: Vector4): Vector4;
    public snappedf(step: number): Vector4;
    public clamp(min: Vector4, max: Vector4): Vector4;
    public clampf(min: number, max: number): Vector4;
    public normalized(): Vector4;
    public is_normalized(): boolean;
    public direction_to(to: Vector4): Vector4;
    public distance_to(to: Vector4): number;
    public distance_squared_to(to: Vector4): number;
    public dot(_with: Vector4): number;
    public inverse(): Vector4;
    public is_equal_approx(to: Vector4): boolean;
    public is_zero_approx(): boolean;
    public is_finite(): boolean;
    public min(_with: Vector4): Vector4;
    public minf(_with: number): Vector4;
    public max(_with: Vector4): Vector4;
    public maxf(_with: number): Vector4;

    public static readonly Axis: {
        AXIS_X: 0;
        AXIS_Y: 1;
        AXIS_Z: 2;
        AXIS_W: 3;
    };
}