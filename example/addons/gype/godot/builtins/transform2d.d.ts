
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Transform2D {
    constructor();
    constructor(_from: Transform2D);
    constructor(rotation: number, position: Vector2);
    constructor(rotation: number, scale: Vector2, skew: number, position: Vector2);
    constructor(x_axis: Vector2, y_axis: Vector2, origin: Vector2);

    public x: Vector2;
    public y: Vector2;
    public origin: Vector2;

    public inverse(): Transform2D;
    public affine_inverse(): Transform2D;
    public get_rotation(): number;
    public get_origin(): Vector2;
    public get_scale(): Vector2;
    public get_skew(): number;
    public orthonormalized(): Transform2D;
    public rotated(angle: number): Transform2D;
    public rotated_local(angle: number): Transform2D;
    public scaled(scale: Vector2): Transform2D;
    public scaled_local(scale: Vector2): Transform2D;
    public translated(offset: Vector2): Transform2D;
    public translated_local(offset: Vector2): Transform2D;
    public determinant(): number;
    public basis_xform(v: Vector2): Vector2;
    public basis_xform_inv(v: Vector2): Vector2;
    public interpolate_with(xform: Transform2D, weight: number): Transform2D;
    public is_conformal(): boolean;
    public is_equal_approx(xform: Transform2D): boolean;
    public is_finite(): boolean;
    public looking_at(target: Vector2): Transform2D;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public multiply(right: number): Transform2D;
    public divide(right: number): Transform2D;
    public multiply(right: number): Transform2D;
    public divide(right: number): Transform2D;
    public multiply(right: Vector2): Vector2;
    public multiply(right: Rect2): Rect2;
    public equals(right: Transform2D): boolean;
    public not_equals(right: Transform2D): boolean;
    public multiply(right: Transform2D): Transform2D;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public multiply(right: PackedVector2Array): PackedVector2Array;

}