declare global {
    export interface Rect2i {
        position: Vector2i;
        size: Vector2i;
        end: Vector2i;

        get_center(): Vector2i;
        get_area(): number;
        has_area(): boolean;
        has_point(point: Vector2i): boolean;
        intersects(b: Rect2i): boolean;
        encloses(b: Rect2i): boolean;
        intersection(b: Rect2i): Rect2i;
        merge(b: Rect2i): Rect2i;
        expand(to: Vector2i): Rect2i;
        grow(amount: number): Rect2i;
        grow_side(side: number, amount: number): Rect2i;
        grow_individual(left: number, top: number, right: number, bottom: number): Rect2i;
        abs(): Rect2i;
    }

    /**
    * A global constructor and namespace for the Rect2i type.
    *
    * Use `new Rect2i(...)` to create a new instance.
    * Access static members like `Rect2i.ZERO`.
    */
    export declare const Rect2i: {
        new(): Rect2i;
        new(_from: Rect2i): Rect2i;
        new(_from: Rect2): Rect2i;
        new(position: Vector2i, size: Vector2i): Rect2i;
        new(x: number, y: number, width: number, height: number): Rect2i;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Rect2i): boolean
        // not_equals(Rect2i): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};