
/**
 * Godot's built-in Vector4 type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Vector4 = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Vector4(1, 0);
 */
export interface Vector4 {
    x: number;
    y: number;
    z: number;
    w: number;

    minAxisIndex(): number;
    maxAxisIndex(): number;
    length(): number;
    lengthSquared(): number;
    abs(): Vector4;
    sign(): Vector4;
    floor(): Vector4;
    ceil(): Vector4;
    round(): Vector4;
    lerp(to: Vector4, weight: number): Vector4;
    cubicInterpolate(b: Vector4, preA: Vector4, postB: Vector4, weight: number): Vector4;
    cubicInterpolateInTime(b: Vector4, preA: Vector4, postB: Vector4, weight: number, bT: number, preAT: number, postBT: number): Vector4;
    posmod(mod: number): Vector4;
    posmodv(modv: Vector4): Vector4;
    snapped(step: Vector4): Vector4;
    snappedf(step: number): Vector4;
    clamp(min: Vector4, max: Vector4): Vector4;
    clampf(min: number, max: number): Vector4;
    normalized(): Vector4;
    isNormalized(): boolean;
    directionTo(to: Vector4): Vector4;
    distanceTo(to: Vector4): number;
    distanceSquaredTo(to: Vector4): number;
    dot(_with: Vector4): number;
    inverse(): Vector4;
    isEqualApprox(to: Vector4): boolean;
    isZeroApprox(): boolean;
    isFinite(): boolean;
    min(_with: Vector4): Vector4;
    minf(_with: number): Vector4;
    max(_with: Vector4): Vector4;
    maxf(_with: number): Vector4;
}

/**
 * A global constructor and namespace for the Vector4 type.
 *
 * Use `new Vector4(...)` to create a new instance.
 * Access static members like `Vector4.ZERO`.
 */
export declare const Vector4: {
    new(): Vector4;
    new(_from: Vector4): Vector4;
    new(_from: Vector4i): Vector4;
    new(x: number, y: number, z: number, w: number): Vector4;

    readonly ZERO: Vector4;
    readonly ONE: Vector4;
    readonly INF: Vector4;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // negate(any): Vector4
    // positive(any): Vector4
    // op_not(any): boolean
    // multiply(number): Vector4
    // divide(number): Vector4
    // multiply(number): Vector4
    // divide(number): Vector4
    // equals(Vector4): boolean
    // not_equals(Vector4): boolean
    // less(Vector4): boolean
    // less_equal(Vector4): boolean
    // greater(Vector4): boolean
    // greater_equal(Vector4): boolean
    // add(Vector4): Vector4
    // subtract(Vector4): Vector4
    // multiply(Vector4): Vector4
    // divide(Vector4): Vector4
    // multiply(Projection): Vector4
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // in_op(PackedVector4Array): boolean
    */
};