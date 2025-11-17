declare global {
    export class Vector2 {
        constructor(): Vector2;
        constructor(_from: Vector2): Vector2;
        constructor(_from: Vector2i): Vector2;
        constructor(x: number, y: number): Vector2;
        readonly static ZERO: Vector2;
        readonly static ONE: Vector2;
        readonly static INF: Vector2;
        readonly static LEFT: Vector2;
        readonly static RIGHT: Vector2;
        readonly static UP: Vector2;
        readonly static DOWN: Vector2;
    
        x: number;
        y: number;

        angle(): number;
        angle_to(to: Vector2): number;
        angle_to_point(to: Vector2): number;
        direction_to(to: Vector2): Vector2;
        distance_to(to: Vector2): number;
        distance_squared_to(to: Vector2): number;
        length(): number;
        length_squared(): number;
        limit_length(length: number = 1.0): Vector2;
        normalized(): Vector2;
        is_normalized(): boolean;
        is_equal_approx(to: Vector2): boolean;
        is_zero_approx(): boolean;
        is_finite(): boolean;
        posmod(mod: number): Vector2;
        posmodv(modv: Vector2): Vector2;
        project(b: Vector2): Vector2;
        lerp(to: Vector2, weight: number): Vector2;
        slerp(to: Vector2, weight: number): Vector2;
        cubic_interpolate(b: Vector2, preA: Vector2, postB: Vector2, weight: number): Vector2;
        cubic_interpolate_in_time(b: Vector2, preA: Vector2, postB: Vector2, weight: number, bT: number, preAT: number, postBT: number): Vector2;
        bezier_interpolate(control1: Vector2, control2: Vector2, end: Vector2, t: number): Vector2;
        bezier_derivative(control1: Vector2, control2: Vector2, end: Vector2, t: number): Vector2;
        max_axis_index(): number;
        min_axis_index(): number;
        move_toward(to: Vector2, delta: number): Vector2;
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
        from_angle(angle: number): Vector2;
        
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
    }
}

export {};