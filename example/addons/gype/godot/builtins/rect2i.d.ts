
/**
 * Godot's built-in Rect2i type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Rect2i = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Rect2i(1, 0);
 */
export interface Rect2i {
    position: Vector2i;
    size: Vector2i;
    end: Vector2i;

    getCenter(): Vector2i;
    getArea(): number;
    hasArea(): boolean;
    hasPoint(point: Vector2i): boolean;
    intersects(b: Rect2i): boolean;
    encloses(b: Rect2i): boolean;
    intersection(b: Rect2i): Rect2i;
    merge(b: Rect2i): Rect2i;
    expand(to: Vector2i): Rect2i;
    grow(amount: number): Rect2i;
    growSide(side: number, amount: number): Rect2i;
    growIndividual(left: number, top: number, right: number, bottom: number): Rect2i;
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