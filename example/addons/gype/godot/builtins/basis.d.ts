declare global {
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
        scaled_local(scale: Vector3): Basis;
        get_scale(): Vector3;
        get_euler(order: number = 2): Vector3;
        tdotx(_with: Vector3): number;
        tdoty(_with: Vector3): number;
        tdotz(_with: Vector3): number;
        slerp(to: Basis, weight: number): Basis;
        is_conformal(): boolean;
        is_equal_approx(b: Basis): boolean;
        is_finite(): boolean;
        get_rotation_quaternion(): Quaternion;
        looking_at(target: Vector3, up: Vector3 = Vector3(0, 1, 0), useModelFront: boolean = false): Basis;
        from_scale(scale: Vector3): Basis;
        from_euler(euler: Vector3, order: number = 2): Basis;
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
}

export {};