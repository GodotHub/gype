
/**
 * Godot's built-in Plane type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Plane = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Plane(1, 0);
 */
export interface Plane {
    x: number;
    y: number;
    z: number;
    d: number;
    normal: Vector3;

    normalized(): Plane;
    getCenter(): Vector3;
    isEqualApprox(toPlane: Plane): boolean;
    isFinite(): boolean;
    isPointOver(point: Vector3): boolean;
    distanceTo(point: Vector3): number;
    hasPoint(point: Vector3, tolerance: number = 1e-05): boolean;
    project(point: Vector3): Vector3;
    intersect3(b: Plane, c: Plane): any;
    intersectsRay(_from: Vector3, dir: Vector3): any;
    intersectsSegment(_from: Vector3, to: Vector3): any;
}

/**
 * A global constructor and namespace for the Plane type.
 *
 * Use `new Plane(...)` to create a new instance.
 * Access static members like `Plane.ZERO`.
 */
export declare const Plane: {
    new(): Plane;
    new(_from: Plane): Plane;
    new(normal: Vector3): Plane;
    new(normal: Vector3, d: number): Plane;
    new(normal: Vector3, point: Vector3): Plane;
    new(point1: Vector3, point2: Vector3, point3: Vector3): Plane;
    new(a: number, b: number, c: number, d: number): Plane;

    readonly PLANE_YZ: Plane;
    readonly PLANE_XZ: Plane;
    readonly PLANE_XY: Plane;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // negate(any): Plane
    // positive(any): Plane
    // op_not(any): boolean
    // equals(Plane): boolean
    // not_equals(Plane): boolean
    // multiply(Transform3D): Plane
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    */
};