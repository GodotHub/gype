
/**
 * Godot's built-in Vector2 type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Vector2 = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Vector2(1, 0);
 */
export interface Vector2 {
    x: number;
    y: number;

    angle(): number;
    angleTo(to: Vector2): number;
    angleToPoint(to: Vector2): number;
    directionTo(to: Vector2): Vector2;
    distanceTo(to: Vector2): number;
    distanceSquaredTo(to: Vector2): number;
    length(): number;
    lengthSquared(): number;
    limitLength(length: number = 1.0): Vector2;
    normalized(): Vector2;
    isNormalized(): boolean;
    isEqualApprox(to: Vector2): boolean;
    isZeroApprox(): boolean;
    isFinite(): boolean;
    posmod(mod: number): Vector2;
    posmodv(modv: Vector2): Vector2;
    project(b: Vector2): Vector2;
    lerp(to: Vector2, weight: number): Vector2;
    slerp(to: Vector2, weight: number): Vector2;
    cubicInterpolate(b: Vector2, preA: Vector2, postB: Vector2, weight: number): Vector2;
    cubicInterpolateInTime(b: Vector2, preA: Vector2, postB: Vector2, weight: number, bT: number, preAT: number, postBT: number): Vector2;
    bezierInterpolate(control1: Vector2, control2: Vector2, end: Vector2, t: number): Vector2;
    bezierDerivative(control1: Vector2, control2: Vector2, end: Vector2, t: number): Vector2;
    maxAxisIndex(): number;
    minAxisIndex(): number;
    moveToward(to: Vector2, delta: number): Vector2;
    rotated(angle: number): Vector2;
    orthogonal(): Vector2;
    floor(): Vector2;
    ceil(): Vector2;
    round(): Vector2;
    aspect(): number;
    dot(_with: Vector2): number;
    slide(n: Vector2): Vector2;
    bounce(n: Vector2): Vector2;
    reflect(line: Vector2): Vector2;
    cross(_with: Vector2): number;
    abs(): Vector2;
    sign(): Vector2;
    clamp(min: Vector2, max: Vector2): Vector2;
    clampf(min: number, max: number): Vector2;
    snapped(step: Vector2): Vector2;
    snappedf(step: number): Vector2;
    min(_with: Vector2): Vector2;
    minf(_with: number): Vector2;
    max(_with: Vector2): Vector2;
    maxf(_with: number): Vector2;
    fromAngle(angle: number): Vector2;
}

/**
 * A global constructor and namespace for the Vector2 type.
 *
 * Use `new Vector2(...)` to create a new instance.
 * Access static members like `Vector2.ZERO`.
 */
export declare const Vector2: {
    new(): Vector2;
    new(_from: Vector2): Vector2;
    new(_from: Vector2i): Vector2;
    new(x: number, y: number): Vector2;

    readonly ZERO: Vector2;
    readonly ONE: Vector2;
    readonly INF: Vector2;
    readonly LEFT: Vector2;
    readonly RIGHT: Vector2;
    readonly UP: Vector2;
    readonly DOWN: Vector2;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // negate(any): Vector2
    // positive(any): Vector2
    // op_not(any): boolean
    // multiply(number): Vector2
    // divide(number): Vector2
    // multiply(number): Vector2
    // divide(number): Vector2
    // equals(Vector2): boolean
    // not_equals(Vector2): boolean
    // less(Vector2): boolean
    // less_equal(Vector2): boolean
    // greater(Vector2): boolean
    // greater_equal(Vector2): boolean
    // add(Vector2): Vector2
    // subtract(Vector2): Vector2
    // multiply(Vector2): Vector2
    // divide(Vector2): Vector2
    // multiply(Transform2D): Vector2
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // in_op(PackedVector2Array): boolean
    */
};