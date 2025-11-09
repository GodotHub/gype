declare global {
    export interface Vector3 {
        x: number;
        y: number;
        z: number;

        min_axis_index(): number;
        max_axis_index(): number;
        angle_to(to: Vector3): number;
        signed_angle_to(to: Vector3, axis: Vector3): number;
        direction_to(to: Vector3): Vector3;
        distance_to(to: Vector3): number;
        distance_squared_to(to: Vector3): number;
        length(): number;
        length_squared(): number;
        limit_length(length: number = 1.0): Vector3;
        normalized(): Vector3;
        is_normalized(): boolean;
        is_equal_approx(to: Vector3): boolean;
        is_zero_approx(): boolean;
        is_finite(): boolean;
        inverse(): Vector3;
        clamp(min: Vector3, max: Vector3): Vector3;
        clampf(min: number, max: number): Vector3;
        snapped(step: Vector3): Vector3;
        snappedf(step: number): Vector3;
        rotated(axis: Vector3, angle: number): Vector3;
        lerp(to: Vector3, weight: number): Vector3;
        slerp(to: Vector3, weight: number): Vector3;
        cubic_interpolate(b: Vector3, preA: Vector3, postB: Vector3, weight: number): Vector3;
        cubic_interpolate_in_time(b: Vector3, preA: Vector3, postB: Vector3, weight: number, bT: number, preAT: number, postBT: number): Vector3;
        bezier_interpolate(control1: Vector3, control2: Vector3, end: Vector3, t: number): Vector3;
        bezier_derivative(control1: Vector3, control2: Vector3, end: Vector3, t: number): Vector3;
        move_toward(to: Vector3, delta: number): Vector3;
        dot(_with: Vector3): number;
        cross(_with: Vector3): Vector3;
        outer(_with: Vector3): Basis;
        abs(): Vector3;
        floor(): Vector3;
        ceil(): Vector3;
        round(): Vector3;
        posmod(mod: number): Vector3;
        posmodv(modv: Vector3): Vector3;
        project(b: Vector3): Vector3;
        slide(n: Vector3): Vector3;
        bounce(n: Vector3): Vector3;
        reflect(n: Vector3): Vector3;
        sign(): Vector3;
        octahedron_encode(): Vector2;
        min(_with: Vector3): Vector3;
        minf(_with: number): Vector3;
        max(_with: Vector3): Vector3;
        maxf(_with: number): Vector3;
        octahedron_decode(uv: Vector2): Vector3;
    }

    /**
    * A global constructor and namespace for the Vector3 type.
    *
    * Use `new Vector3(...)` to create a new instance.
    * Access static members like `Vector3.ZERO`.
    */
    export declare const Vector3: {
        new(): Vector3;
        new(_from: Vector3): Vector3;
        new(_from: Vector3i): Vector3;
        new(x: number, y: number, z: number): Vector3;

        readonly ZERO: Vector3;
        readonly ONE: Vector3;
        readonly INF: Vector3;
        readonly LEFT: Vector3;
        readonly RIGHT: Vector3;
        readonly UP: Vector3;
        readonly DOWN: Vector3;
        readonly FORWARD: Vector3;
        readonly BACK: Vector3;
        readonly MODEL_LEFT: Vector3;
        readonly MODEL_RIGHT: Vector3;
        readonly MODEL_TOP: Vector3;
        readonly MODEL_BOTTOM: Vector3;
        readonly MODEL_FRONT: Vector3;
        readonly MODEL_REAR: Vector3;

        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // negate(any): Vector3
        // positive(any): Vector3
        // op_not(any): boolean
        // multiply(number): Vector3
        // divide(number): Vector3
        // multiply(number): Vector3
        // divide(number): Vector3
        // equals(Vector3): boolean
        // not_equals(Vector3): boolean
        // less(Vector3): boolean
        // less_equal(Vector3): boolean
        // greater(Vector3): boolean
        // greater_equal(Vector3): boolean
        // add(Vector3): Vector3
        // subtract(Vector3): Vector3
        // multiply(Vector3): Vector3
        // divide(Vector3): Vector3
        // multiply(Quaternion): Vector3
        // multiply(Basis): Vector3
        // multiply(Transform3D): Vector3
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // in_op(PackedVector3Array): boolean
        */
    };
}

export {};