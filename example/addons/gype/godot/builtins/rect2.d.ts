declare global {
    export interface Rect2 {
        position: Vector2;
        size: Vector2;
        end: Vector2;

        get_center(): Vector2;
        get_area(): number;
        has_area(): boolean;
        has_point(point: Vector2): boolean;
        is_equal_approx(rect: Rect2): boolean;
        is_finite(): boolean;
        intersects(b: Rect2, includeBorders: boolean = false): boolean;
        encloses(b: Rect2): boolean;
        intersection(b: Rect2): Rect2;
        merge(b: Rect2): Rect2;
        expand(to: Vector2): Rect2;
        get_support(direction: Vector2): Vector2;
        grow(amount: number): Rect2;
        grow_side(side: number, amount: number): Rect2;
        grow_individual(left: number, top: number, right: number, bottom: number): Rect2;
        abs(): Rect2;
    }

    /**
    * A global constructor and namespace for the Rect2 type.
    *
    * Use `new Rect2(...)` to create a new instance.
    * Access static members like `Rect2.ZERO`.
    */
    export declare const Rect2: {
        new(): Rect2;
        new(_from: Rect2): Rect2;
        new(_from: Rect2i): Rect2;
        new(position: Vector2, size: Vector2): Rect2;
        new(x: number, y: number, width: number, height: number): Rect2;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Rect2): boolean
        // not_equals(Rect2): boolean
        // multiply(Transform2D): Rect2
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};