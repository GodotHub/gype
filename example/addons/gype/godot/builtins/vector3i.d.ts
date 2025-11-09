
/**
 * Godot's built-in Vector3i type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Vector3i = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Vector3i(1, 0);
 */
export interface Vector3i {
    x: number;
    y: number;
    z: number;

    minAxisIndex(): number;
    maxAxisIndex(): number;
    distanceTo(to: Vector3i): number;
    distanceSquaredTo(to: Vector3i): number;
    length(): number;
    lengthSquared(): number;
    sign(): Vector3i;
    abs(): Vector3i;
    clamp(min: Vector3i, max: Vector3i): Vector3i;
    clampi(min: number, max: number): Vector3i;
    snapped(step: Vector3i): Vector3i;
    snappedi(step: number): Vector3i;
    min(_with: Vector3i): Vector3i;
    mini(_with: number): Vector3i;
    max(_with: Vector3i): Vector3i;
    maxi(_with: number): Vector3i;
}

/**
 * A global constructor and namespace for the Vector3i type.
 *
 * Use `new Vector3i(...)` to create a new instance.
 * Access static members like `Vector3i.ZERO`.
 */
export declare const Vector3i: {
    new(): Vector3i;
    new(_from: Vector3i): Vector3i;
    new(_from: Vector3): Vector3i;
    new(x: number, y: number, z: number): Vector3i;

    readonly ZERO: Vector3i;
    readonly ONE: Vector3i;
    readonly MIN: Vector3i;
    readonly MAX: Vector3i;
    readonly LEFT: Vector3i;
    readonly RIGHT: Vector3i;
    readonly UP: Vector3i;
    readonly DOWN: Vector3i;
    readonly FORWARD: Vector3i;
    readonly BACK: Vector3i;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // negate(any): Vector3i
    // positive(any): Vector3i
    // op_not(any): boolean
    // multiply(number): Vector3i
    // divide(number): Vector3i
    // module(number): Vector3i
    // multiply(number): Vector3
    // divide(number): Vector3
    // equals(Vector3i): boolean
    // not_equals(Vector3i): boolean
    // less(Vector3i): boolean
    // less_equal(Vector3i): boolean
    // greater(Vector3i): boolean
    // greater_equal(Vector3i): boolean
    // add(Vector3i): Vector3i
    // subtract(Vector3i): Vector3i
    // multiply(Vector3i): Vector3i
    // divide(Vector3i): Vector3i
    // module(Vector3i): Vector3i
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    */
};