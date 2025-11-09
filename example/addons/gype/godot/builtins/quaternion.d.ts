declare global {
    export interface Quaternion {
        x: number;
        y: number;
        z: number;
        w: number;

        length(): number;
        length_squared(): number;
        normalized(): Quaternion;
        is_normalized(): boolean;
        is_equal_approx(to: Quaternion): boolean;
        is_finite(): boolean;
        inverse(): Quaternion;
        log(): Quaternion;
        exp(): Quaternion;
        angle_to(to: Quaternion): number;
        dot(_with: Quaternion): number;
        slerp(to: Quaternion, weight: number): Quaternion;
        slerpni(to: Quaternion, weight: number): Quaternion;
        spherical_cubic_interpolate(b: Quaternion, preA: Quaternion, postB: Quaternion, weight: number): Quaternion;
        spherical_cubic_interpolate_in_time(b: Quaternion, preA: Quaternion, postB: Quaternion, weight: number, bT: number, preAT: number, postBT: number): Quaternion;
        get_euler(order: number = 2): Vector3;
        from_euler(euler: Vector3): Quaternion;
        get_axis(): Vector3;
        get_angle(): number;
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
}

export {};