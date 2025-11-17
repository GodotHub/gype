declare global {
    export class Vector3i {
        constructor(): Vector3i;
        constructor(_from: Vector3i): Vector3i;
        constructor(_from: Vector3): Vector3i;
        constructor(x: number, y: number, z: number): Vector3i;
        readonly static ZERO: Vector3i;
        readonly static ONE: Vector3i;
        readonly static MIN: Vector3i;
        readonly static MAX: Vector3i;
        readonly static LEFT: Vector3i;
        readonly static RIGHT: Vector3i;
        readonly static UP: Vector3i;
        readonly static DOWN: Vector3i;
        readonly static FORWARD: Vector3i;
        readonly static BACK: Vector3i;
    
        x: number;
        y: number;
        z: number;

        min_axis_index(): number;
        max_axis_index(): number;
        distance_to(to: Vector3i): number;
        distance_squared_to(to: Vector3i): number;
        length(): number;
        length_squared(): number;
        sign(): Vector3i;
        abs(): Vector3i;
        clamp(min: Vector3i, max: Vector3i): Vector3i;
        clampi(min: number, max: number): Vector3i;
        snapped(step: Vector3i): Vector3i;
        snappedi(step: number): Vector3i;
        min(_with: Vector3i): Vector3i;
        mini(_with: number): Vector3i;
        max(_with: Vector3i): Vector3i;
        maxi(_with: number): Vector3i;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // negate(any): Vector3i
        // positive(any): Vector3i
        // op_not(any): boolean
        // multiply(number): Vector3i
        // divide(number): Vector3i
        // module(number): Vector3i
        // multiply(number): Vector3
        // divide(number): Vector3
        // equals(Vector3i): boolean
        // not_equals(Vector3i): boolean
        // less(Vector3i): boolean
        // less_equal(Vector3i): boolean
        // greater(Vector3i): boolean
        // greater_equal(Vector3i): boolean
        // add(Vector3i): Vector3i
        // subtract(Vector3i): Vector3i
        // multiply(Vector3i): Vector3i
        // divide(Vector3i): Vector3i
        // module(Vector3i): Vector3i
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    }
}

export {};