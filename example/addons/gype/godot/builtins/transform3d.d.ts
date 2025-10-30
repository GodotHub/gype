
import type { AABB } from '@godot/builtins/aabb';
import type { Basis } from '@godot/builtins/basis';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Plane } from '@godot/builtins/plane';
import type { Projection } from '@godot/builtins/projection';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Transform3D {
    constructor();
    constructor(_from: Transform3D);
    constructor(basis: Basis, origin: Vector3);
    constructor(x_axis: Vector3, y_axis: Vector3, z_axis: Vector3, origin: Vector3);
    constructor(_from: Projection);

    public basis: Basis;
    public origin: Vector3;

    public inverse(): Transform3D;
    public affine_inverse(): Transform3D;
    public orthonormalized(): Transform3D;
    public rotated(axis: Vector3, angle: number): Transform3D;
    public rotated_local(axis: Vector3, angle: number): Transform3D;
    public scaled(scale: Vector3): Transform3D;
    public scaled_local(scale: Vector3): Transform3D;
    public translated(offset: Vector3): Transform3D;
    public translated_local(offset: Vector3): Transform3D;
    public looking_at(target: Vector3, up: Vector3, use_model_front: boolean): Transform3D;
    public interpolate_with(xform: Transform3D, weight: number): Transform3D;
    public is_equal_approx(xform: Transform3D): boolean;
    public is_finite(): boolean;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public multiply(right: number): Transform3D;
    public divide(right: number): Transform3D;
    public multiply(right: number): Transform3D;
    public divide(right: number): Transform3D;
    public multiply(right: Vector3): Vector3;
    public multiply(right: Plane): Plane;
    public multiply(right: AABB): AABB;
    public equals(right: Transform3D): boolean;
    public not_equals(right: Transform3D): boolean;
    public multiply(right: Transform3D): Transform3D;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public multiply(right: PackedVector3Array): PackedVector3Array;

}