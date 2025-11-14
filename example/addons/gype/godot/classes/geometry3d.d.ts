
import type { GodotObject } from '@godot/classes/godot_object';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Plane } from '@godot/builtins/plane';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Geometry3D extends GodotObject {


    public compute_convex_mesh_points(planes: Array<any>): PackedVector3Array;
    public build_box_planes(extents: Vector3): Array<any>;
    public build_cylinder_planes(radius: number, height: number, sides: number, axis: number = 2): Array<any>;
    public build_capsule_planes(radius: number, height: number, sides: number, lats: number, axis: number = 2): Array<any>;
    public get_closest_points_between_segments(p1: Vector3, p2: Vector3, q1: Vector3, q2: Vector3): PackedVector3Array;
    public get_closest_point_to_segment(point: Vector3, s1: Vector3, s2: Vector3): Vector3;
    public get_closest_point_to_segment_uncapped(point: Vector3, s1: Vector3, s2: Vector3): Vector3;
    public get_triangle_barycentric_coords(point: Vector3, a: Vector3, b: Vector3, c: Vector3): Vector3;
    public ray_intersects_triangle(_from: Vector3, dir: Vector3, a: Vector3, b: Vector3, c: Vector3): any;
    public segment_intersects_triangle(_from: Vector3, to: Vector3, a: Vector3, b: Vector3, c: Vector3): any;
    public segment_intersects_sphere(_from: Vector3, to: Vector3, spherePosition: Vector3, sphereRadius: number): PackedVector3Array;
    public segment_intersects_cylinder(_from: Vector3, to: Vector3, height: number, radius: number): PackedVector3Array;
    public segment_intersects_convex(_from: Vector3, to: Vector3, planes: Array<any>): PackedVector3Array;
    public clip_polygon(points: PackedVector3Array, plane: Plane): PackedVector3Array;
    public tetrahedralize_delaunay(points: PackedVector3Array): PackedInt32Array;


}


/**
 * A singleton instance of Geometry3D.
 * This is a global variable, available from anywhere.
 */
export const Geometry3D: Geometry3D;
