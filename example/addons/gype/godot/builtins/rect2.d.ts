
/**
 * Godot's built-in Rect2 type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Rect2 = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Rect2(1, 0);
 */
export interface Rect2 {
    position: Vector2;
    size: Vector2;
    end: Vector2;

    getCenter(): Vector2;
    getArea(): number;
    hasArea(): boolean;
    hasPoint(point: Vector2): boolean;
    isEqualApprox(rect: Rect2): boolean;
    isFinite(): boolean;
    intersects(b: Rect2, includeBorders: boolean = false): boolean;
    encloses(b: Rect2): boolean;
    intersection(b: Rect2): Rect2;
    merge(b: Rect2): Rect2;
    expand(to: Vector2): Rect2;
    getSupport(direction: Vector2): Vector2;
    grow(amount: number): Rect2;
    growSide(side: number, amount: number): Rect2;
    growIndividual(left: number, top: number, right: number, bottom: number): Rect2;
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