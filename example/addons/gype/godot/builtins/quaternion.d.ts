declare global {
    export class Quaternion {
        constructor(): Quaternion;
        constructor(_from: Quaternion): Quaternion;
        constructor(_from: Basis): Quaternion;
        constructor(axis: Vector3, angle: number): Quaternion;
        constructor(arcFrom: Vector3, arcTo: Vector3): Quaternion;
        constructor(x: number, y: number, z: number, w: number): Quaternion;
        readonly IDENTITY: Quaternion;
    
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
    }
}

export {};