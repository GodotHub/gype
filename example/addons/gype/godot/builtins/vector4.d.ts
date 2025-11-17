declare global {
    export class Vector4 {
        constructor(): Vector4;
        constructor(_from: Vector4): Vector4;
        constructor(_from: Vector4i): Vector4;
        constructor(x: number, y: number, z: number, w: number): Vector4;
        readonly static ZERO: Vector4;
        readonly static ONE: Vector4;
        readonly static INF: Vector4;
    
        x: number;
        y: number;
        z: number;
        w: number;

        min_axis_index(): number;
        max_axis_index(): number;
        length(): number;
        length_squared(): number;
        abs(): Vector4;
        sign(): Vector4;
        floor(): Vector4;
        ceil(): Vector4;
        round(): Vector4;
        lerp(to: Vector4, weight: number): Vector4;
        cubic_interpolate(b: Vector4, preA: Vector4, postB: Vector4, weight: number): Vector4;
        cubic_interpolate_in_time(b: Vector4, preA: Vector4, postB: Vector4, weight: number, bT: number, preAT: number, postBT: number): Vector4;
        posmod(mod: number): Vector4;
        posmodv(modv: Vector4): Vector4;
        snapped(step: Vector4): Vector4;
        snappedf(step: number): Vector4;
        clamp(min: Vector4, max: Vector4): Vector4;
        clampf(min: number, max: number): Vector4;
        normalized(): Vector4;
        is_normalized(): boolean;
        direction_to(to: Vector4): Vector4;
        distance_to(to: Vector4): number;
        distance_squared_to(to: Vector4): number;
        dot(_with: Vector4): number;
        inverse(): Vector4;
        is_equal_approx(to: Vector4): boolean;
        is_zero_approx(): boolean;
        is_finite(): boolean;
        min(_with: Vector4): Vector4;
        minf(_with: number): Vector4;
        max(_with: Vector4): Vector4;
        maxf(_with: number): Vector4;
        
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
    }
}

export {};