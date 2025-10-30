
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Plane } from '@godot/builtins/plane';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class AABB {
    constructor();
    constructor(_from: AABB);
    constructor(position: Vector3, size: Vector3);

    public position: Vector3;
    public size: Vector3;
    public end: Vector3;

    public abs(): AABB;
    public get_center(): Vector3;
    public get_volume(): number;
    public has_volume(): boolean;
    public has_surface(): boolean;
    public has_point(point: Vector3): boolean;
    public is_equal_approx(aabb: AABB): boolean;
    public is_finite(): boolean;
    public intersects(_with: AABB): boolean;
    public encloses(_with: AABB): boolean;
    public intersects_plane(plane: Plane): boolean;
    public intersection(_with: AABB): AABB;
    public merge(_with: AABB): AABB;
    public expand(to_point: Vector3): AABB;
    public grow(by: number): AABB;
    public get_support(direction: Vector3): Vector3;
    public get_longest_axis(): Vector3;
    public get_longest_axis_index(): number;
    public get_longest_axis_size(): number;
    public get_shortest_axis(): Vector3;
    public get_shortest_axis_index(): number;
    public get_shortest_axis_size(): number;
    public get_endpoint(idx: number): Vector3;
    public intersects_segment(_from: Vector3, to: Vector3): any;
    public intersects_ray(_from: Vector3, dir: Vector3): any;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public equals(right: AABB): boolean;
    public not_equals(right: AABB): boolean;
    public multiply(right: Transform3D): AABB;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;

}