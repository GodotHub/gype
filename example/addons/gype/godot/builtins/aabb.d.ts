declare global {
    export interface AABB {
        position: Vector3;
        size: Vector3;
        end: Vector3;

        abs(): AABB;
        get_center(): Vector3;
        get_volume(): number;
        has_volume(): boolean;
        has_surface(): boolean;
        has_point(point: Vector3): boolean;
        is_equal_approx(aabb: AABB): boolean;
        is_finite(): boolean;
        intersects(_with: AABB): boolean;
        encloses(_with: AABB): boolean;
        intersects_plane(plane: Plane): boolean;
        intersection(_with: AABB): AABB;
        merge(_with: AABB): AABB;
        expand(toPoint: Vector3): AABB;
        grow(by: number): AABB;
        get_support(direction: Vector3): Vector3;
        get_longest_axis(): Vector3;
        get_longest_axis_index(): number;
        get_longest_axis_size(): number;
        get_shortest_axis(): Vector3;
        get_shortest_axis_index(): number;
        get_shortest_axis_size(): number;
        get_endpoint(idx: number): Vector3;
        intersects_segment(_from: Vector3, to: Vector3): any;
        intersects_ray(_from: Vector3, dir: Vector3): any;
    }

    /**
    * A global constructor and namespace for the AABB type.
    *
    * Use `new AABB(...)` to create a new instance.
    * Access static members like `AABB.ZERO`.
    */
    export declare const AABB: {
        new(): AABB;
        new(_from: AABB): AABB;
        new(position: Vector3, size: Vector3): AABB;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(AABB): boolean
        // not_equals(AABB): boolean
        // multiply(Transform3D): AABB
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};