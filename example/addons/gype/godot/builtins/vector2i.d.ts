declare global {
    export interface Vector2i {
        x: number;
        y: number;

        aspect(): number;
        max_axis_index(): number;
        min_axis_index(): number;
        distance_to(to: Vector2i): number;
        distance_squared_to(to: Vector2i): number;
        length(): number;
        length_squared(): number;
        sign(): Vector2i;
        abs(): Vector2i;
        clamp(min: Vector2i, max: Vector2i): Vector2i;
        clampi(min: number, max: number): Vector2i;
        snapped(step: Vector2i): Vector2i;
        snappedi(step: number): Vector2i;
        min(_with: Vector2i): Vector2i;
        mini(_with: number): Vector2i;
        max(_with: Vector2i): Vector2i;
        maxi(_with: number): Vector2i;
    }

    /**
    * A global constructor and namespace for the Vector2i type.
    *
    * Use `new Vector2i(...)` to create a new instance.
    * Access static members like `Vector2i.ZERO`.
    */
    export declare const Vector2i: {
        new(): Vector2i;
        new(_from: Vector2i): Vector2i;
        new(_from: Vector2): Vector2i;
        new(x: number, y: number): Vector2i;

        readonly ZERO: Vector2i;
        readonly ONE: Vector2i;
        readonly MIN: Vector2i;
        readonly MAX: Vector2i;
        readonly LEFT: Vector2i;
        readonly RIGHT: Vector2i;
        readonly UP: Vector2i;
        readonly DOWN: Vector2i;

        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // negate(any): Vector2i
        // positive(any): Vector2i
        // op_not(any): boolean
        // multiply(number): Vector2i
        // divide(number): Vector2i
        // module(number): Vector2i
        // multiply(number): Vector2
        // divide(number): Vector2
        // equals(Vector2i): boolean
        // not_equals(Vector2i): boolean
        // less(Vector2i): boolean
        // less_equal(Vector2i): boolean
        // greater(Vector2i): boolean
        // greater_equal(Vector2i): boolean
        // add(Vector2i): Vector2i
        // subtract(Vector2i): Vector2i
        // multiply(Vector2i): Vector2i
        // divide(Vector2i): Vector2i
        // module(Vector2i): Vector2i
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};