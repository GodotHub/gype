
/**
 * Godot's built-in AABB type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: AABB = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new AABB(1, 0);
 */
export interface AABB {
    position: Vector3;
    size: Vector3;
    end: Vector3;

    abs(): AABB;
    getCenter(): Vector3;
    getVolume(): number;
    hasVolume(): boolean;
    hasSurface(): boolean;
    hasPoint(point: Vector3): boolean;
    isEqualApprox(aabb: AABB): boolean;
    isFinite(): boolean;
    intersects(_with: AABB): boolean;
    encloses(_with: AABB): boolean;
    intersectsPlane(plane: Plane): boolean;
    intersection(_with: AABB): AABB;
    merge(_with: AABB): AABB;
    expand(toPoint: Vector3): AABB;
    grow(by: number): AABB;
    getSupport(direction: Vector3): Vector3;
    getLongestAxis(): Vector3;
    getLongestAxisIndex(): number;
    getLongestAxisSize(): number;
    getShortestAxis(): Vector3;
    getShortestAxisIndex(): number;
    getShortestAxisSize(): number;
    getEndpoint(idx: number): Vector3;
    intersectsSegment(_from: Vector3, to: Vector3): any;
    intersectsRay(_from: Vector3, dir: Vector3): any;
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