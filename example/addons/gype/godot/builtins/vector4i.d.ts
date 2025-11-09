declare global {
    export interface Vector4i {
        x: number;
        y: number;
        z: number;
        w: number;

        min_axis_index(): number;
        max_axis_index(): number;
        length(): number;
        length_squared(): number;
        sign(): Vector4i;
        abs(): Vector4i;
        clamp(min: Vector4i, max: Vector4i): Vector4i;
        clampi(min: number, max: number): Vector4i;
        snapped(step: Vector4i): Vector4i;
        snappedi(step: number): Vector4i;
        min(_with: Vector4i): Vector4i;
        mini(_with: number): Vector4i;
        max(_with: Vector4i): Vector4i;
        maxi(_with: number): Vector4i;
        distance_to(to: Vector4i): number;
        distance_squared_to(to: Vector4i): number;
    }

    /**
    * A global constructor and namespace for the Vector4i type.
    *
    * Use `new Vector4i(...)` to create a new instance.
    * Access static members like `Vector4i.ZERO`.
    */
    export declare const Vector4i: {
        new(): Vector4i;
        new(_from: Vector4i): Vector4i;
        new(_from: Vector4): Vector4i;
        new(x: number, y: number, z: number, w: number): Vector4i;

        readonly ZERO: Vector4i;
        readonly ONE: Vector4i;
        readonly MIN: Vector4i;
        readonly MAX: Vector4i;

        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // negate(any): Vector4i
        // positive(any): Vector4i
        // op_not(any): boolean
        // multiply(number): Vector4i
        // divide(number): Vector4i
        // module(number): Vector4i
        // multiply(number): Vector4
        // divide(number): Vector4
        // equals(Vector4i): boolean
        // not_equals(Vector4i): boolean
        // less(Vector4i): boolean
        // less_equal(Vector4i): boolean
        // greater(Vector4i): boolean
        // greater_equal(Vector4i): boolean
        // add(Vector4i): Vector4i
        // subtract(Vector4i): Vector4i
        // multiply(Vector4i): Vector4i
        // divide(Vector4i): Vector4i
        // module(Vector4i): Vector4i
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};