
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _Geometry2D extends GodotObject {


    public is_point_in_circle(point: Vector2, circlePosition: Vector2, circleRadius: number): boolean;
    public segment_intersects_circle(segmentFrom: Vector2, segmentTo: Vector2, circlePosition: Vector2, circleRadius: number): number;
    public segment_intersects_segment(fromA: Vector2, toA: Vector2, fromB: Vector2, toB: Vector2): any;
    public line_intersects_line(fromA: Vector2, dirA: Vector2, fromB: Vector2, dirB: Vector2): any;
    public get_closest_points_between_segments(p1: Vector2, q1: Vector2, p2: Vector2, q2: Vector2): PackedVector2Array;
    public get_closest_point_to_segment(point: Vector2, s1: Vector2, s2: Vector2): Vector2;
    public get_closest_point_to_segment_uncapped(point: Vector2, s1: Vector2, s2: Vector2): Vector2;
    public point_is_inside_triangle(point: Vector2, a: Vector2, b: Vector2, c: Vector2): boolean;
    public is_polygon_clockwise(polygon: PackedVector2Array): boolean;
    public is_point_in_polygon(point: Vector2, polygon: PackedVector2Array): boolean;
    public triangulate_polygon(polygon: PackedVector2Array): PackedInt32Array;
    public triangulate_delaunay(points: PackedVector2Array): PackedInt32Array;
    public convex_hull(points: PackedVector2Array): PackedVector2Array;
    public decompose_polygon_in_convex(polygon: PackedVector2Array): Array<any>;
    public merge_polygons(polygonA: PackedVector2Array, polygonB: PackedVector2Array): Array<any>;
    public clip_polygons(polygonA: PackedVector2Array, polygonB: PackedVector2Array): Array<any>;
    public intersect_polygons(polygonA: PackedVector2Array, polygonB: PackedVector2Array): Array<any>;
    public exclude_polygons(polygonA: PackedVector2Array, polygonB: PackedVector2Array): Array<any>;
    public clip_polyline_with_polygon(polyline: PackedVector2Array, polygon: PackedVector2Array): Array<any>;
    public intersect_polyline_with_polygon(polyline: PackedVector2Array, polygon: PackedVector2Array): Array<any>;
    public offset_polygon(polygon: PackedVector2Array, delta: number, joinType: number = 0): Array<any>;
    public offset_polyline(polyline: PackedVector2Array, delta: number, joinType: number = 0, endType: number = 3): Array<any>;
    public make_atlas(sizes: PackedVector2Array): Dictionary;
    public bresenham_line(_from: Vector2i, to: Vector2i): Array<any>;


    public static readonly PolyBooleanOperation: {
        OPERATION_UNION: 0;
        OPERATION_DIFFERENCE: 1;
        OPERATION_INTERSECTION: 2;
        OPERATION_XOR: 3;
    };
    public static readonly PolyJoinType: {
        JOIN_SQUARE: 0;
        JOIN_ROUND: 1;
        JOIN_MITER: 2;
    };
    public static readonly PolyEndType: {
        END_POLYGON: 0;
        END_JOINED: 1;
        END_BUTT: 2;
        END_SQUARE: 3;
        END_ROUND: 4;
    };
}

export const Geometry2D: _Geometry2D;
