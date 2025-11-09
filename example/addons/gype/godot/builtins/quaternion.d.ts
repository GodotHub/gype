
/**
 * Godot's built-in Quaternion type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Quaternion = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Quaternion(1, 0);
 */
export interface Quaternion {
    x: number;
    y: number;
    z: number;
    w: number;

    length(): number;
    lengthSquared(): number;
    normalized(): Quaternion;
    isNormalized(): boolean;
    isEqualApprox(to: Quaternion): boolean;
    isFinite(): boolean;
    inverse(): Quaternion;
    log(): Quaternion;
    exp(): Quaternion;
    angleTo(to: Quaternion): number;
    dot(_with: Quaternion): number;
    slerp(to: Quaternion, weight: number): Quaternion;
    slerpni(to: Quaternion, weight: number): Quaternion;
    sphericalCubicInterpolate(b: Quaternion, preA: Quaternion, postB: Quaternion, weight: number): Quaternion;
    sphericalCubicInterpolateInTime(b: Quaternion, preA: Quaternion, postB: Quaternion, weight: number, bT: number, preAT: number, postBT: number): Quaternion;
    getEuler(order: number = 2): Vector3;
    fromEuler(euler: Vector3): Quaternion;
    getAxis(): Vector3;
    getAngle(): number;
}

/**
 * A global constructor and namespace for the Quaternion type.
 *
 * Use `new Quaternion(...)` to create a new instance.
 * Access static members like `Quaternion.ZERO`.
 */
export declare const Quaternion: {
    new(): Quaternion;
    new(_from: Quaternion): Quaternion;
    new(_from: Basis): Quaternion;
    new(axis: Vector3, angle: number): Quaternion;
    new(arcFrom: Vector3, arcTo: Vector3): Quaternion;
    new(x: number, y: number, z: number, w: number): Quaternion;

    readonly IDENTITY: Quaternion;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // negate(any): Quaternion
    // positive(any): Quaternion
    // op_not(any): boolean
    // multiply(number): Quaternion
    // divide(number): Quaternion
    // multiply(number): Quaternion
    // divide(number): Quaternion
    // multiply(Vector3): Vector3
    // equals(Quaternion): boolean
    // not_equals(Quaternion): boolean
    // add(Quaternion): Quaternion
    // subtract(Quaternion): Quaternion
    // multiply(Quaternion): Quaternion
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    */
};