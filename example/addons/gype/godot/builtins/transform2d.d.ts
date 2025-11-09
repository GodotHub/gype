
/**
 * Godot's built-in Transform2D type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Transform2D = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Transform2D(1, 0);
 */
export interface Transform2D {
    x: Vector2;
    y: Vector2;
    origin: Vector2;

    inverse(): Transform2D;
    affineInverse(): Transform2D;
    getRotation(): number;
    getOrigin(): Vector2;
    getScale(): Vector2;
    getSkew(): number;
    orthonormalized(): Transform2D;
    rotated(angle: number): Transform2D;
    rotatedLocal(angle: number): Transform2D;
    scaled(scale: Vector2): Transform2D;
    scaledLocal(scale: Vector2): Transform2D;
    translated(offset: Vector2): Transform2D;
    translatedLocal(offset: Vector2): Transform2D;
    determinant(): number;
    basisXform(v: Vector2): Vector2;
    basisXformInv(v: Vector2): Vector2;
    interpolateWith(xform: Transform2D, weight: number): Transform2D;
    isConformal(): boolean;
    isEqualApprox(xform: Transform2D): boolean;
    isFinite(): boolean;
    lookingAt(target: Vector2 = Vector2(0, 0)): Transform2D;
}

/**
 * A global constructor and namespace for the Transform2D type.
 *
 * Use `new Transform2D(...)` to create a new instance.
 * Access static members like `Transform2D.ZERO`.
 */
export declare const Transform2D: {
    new(): Transform2D;
    new(_from: Transform2D): Transform2D;
    new(rotation: number, position: Vector2): Transform2D;
    new(rotation: number, scale: Vector2, skew: number, position: Vector2): Transform2D;
    new(xAxis: Vector2, yAxis: Vector2, origin: Vector2): Transform2D;

    readonly IDENTITY: Transform2D;
    readonly FLIP_X: Transform2D;
    readonly FLIP_Y: Transform2D;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // multiply(number): Transform2D
    // divide(number): Transform2D
    // multiply(number): Transform2D
    // divide(number): Transform2D
    // multiply(Vector2): Vector2
    // multiply(Rect2): Rect2
    // equals(Transform2D): boolean
    // not_equals(Transform2D): boolean
    // multiply(Transform2D): Transform2D
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // multiply(PackedVector2Array): PackedVector2Array
    */
};