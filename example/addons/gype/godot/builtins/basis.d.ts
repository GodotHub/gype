
/**
 * Godot's built-in Basis type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Basis = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Basis(1, 0);
 */
export interface Basis {
    x: Vector3;
    y: Vector3;
    z: Vector3;

    inverse(): Basis;
    transposed(): Basis;
    orthonormalized(): Basis;
    determinant(): number;
    rotated(axis: Vector3, angle: number): Basis;
    scaled(scale: Vector3): Basis;
    scaledLocal(scale: Vector3): Basis;
    getScale(): Vector3;
    getEuler(order: number = 2): Vector3;
    tdotx(_with: Vector3): number;
    tdoty(_with: Vector3): number;
    tdotz(_with: Vector3): number;
    slerp(to: Basis, weight: number): Basis;
    isConformal(): boolean;
    isEqualApprox(b: Basis): boolean;
    isFinite(): boolean;
    getRotationQuaternion(): Quaternion;
    lookingAt(target: Vector3, up: Vector3 = Vector3(0, 1, 0), useModelFront: boolean = false): Basis;
    fromScale(scale: Vector3): Basis;
    fromEuler(euler: Vector3, order: number = 2): Basis;
}

/**
 * A global constructor and namespace for the Basis type.
 *
 * Use `new Basis(...)` to create a new instance.
 * Access static members like `Basis.ZERO`.
 */
export declare const Basis: {
    new(): Basis;
    new(_from: Basis): Basis;
    new(_from: Quaternion): Basis;
    new(axis: Vector3, angle: number): Basis;
    new(xAxis: Vector3, yAxis: Vector3, zAxis: Vector3): Basis;

    readonly IDENTITY: Basis;
    readonly FLIP_X: Basis;
    readonly FLIP_Y: Basis;
    readonly FLIP_Z: Basis;

    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // multiply(number): Basis
    // divide(number): Basis
    // multiply(number): Basis
    // divide(number): Basis
    // multiply(Vector3): Vector3
    // equals(Basis): boolean
    // not_equals(Basis): boolean
    // multiply(Basis): Basis
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    */
};