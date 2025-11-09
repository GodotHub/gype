
/**
 * Godot's built-in Transform3D type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Transform3D = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Transform3D(1, 0);
 */
export interface Transform3D {
    basis: Basis;
    origin: Vector3;

    inverse(): Transform3D;
    affineInverse(): Transform3D;
    orthonormalized(): Transform3D;
    rotated(axis: Vector3, angle: number): Transform3D;
    rotatedLocal(axis: Vector3, angle: number): Transform3D;
    scaled(scale: Vector3): Transform3D;
    scaledLocal(scale: Vector3): Transform3D;
    translated(offset: Vector3): Transform3D;
    translatedLocal(offset: Vector3): Transform3D;
    lookingAt(target: Vector3, up: Vector3 = Vector3(0, 1, 0), useModelFront: boolean = false): Transform3D;
    interpolateWith(xform: Transform3D, weight: number): Transform3D;
    isEqualApprox(xform: Transform3D): boolean;
    isFinite(): boolean;
}

/**
 * A global constructor and namespace for the Transform3D type.
 *
 * Use `new Transform3D(...)` to create a new instance.
 * Access static members like `Transform3D.ZERO`.
 */
export declare const Transform3D: {
    new(): Transform3D;
    new(_from: Transform3D): Transform3D;
    new(basis: Basis, origin: Vector3): Transform3D;
    new(xAxis: Vector3, yAxis: Vector3, zAxis: Vector3, origin: Vector3): Transform3D;
    new(_from: Projection): Transform3D;

    readonly IDENTITY: Transform3D;
    readonly FLIP_X: Transform3D;
    readonly FLIP_Y: Transform3D;
    readonly FLIP_Z: Transform3D;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // multiply(number): Transform3D
    // divide(number): Transform3D
    // multiply(number): Transform3D
    // divide(number): Transform3D
    // multiply(Vector3): Vector3
    // multiply(Plane): Plane
    // multiply(AABB): AABB
    // equals(Transform3D): boolean
    // not_equals(Transform3D): boolean
    // multiply(Transform3D): Transform3D
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // multiply(PackedVector3Array): PackedVector3Array
    */
};