
/**
 * Godot's built-in PackedVector2Array type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedVector2Array = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedVector2Array(1, 0);
 */
export interface PackedVector2Array {

    get(index: number): Vector2;
    set(index: number, value: Vector2): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: Vector2): boolean;
    append(value: Vector2): boolean;
    appendArray(array: PackedVector2Array): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: Vector2): number;
    fill(value: Vector2): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: Vector2): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedVector2Array;
    toByteArray(): PackedByteArray;
    sort(): void;
    bsearch(value: Vector2, before: boolean = true): number;
    duplicate(): PackedVector2Array;
    find(value: Vector2, _from: number = 0): number;
    rfind(value: Vector2, _from: number = -1): number;
    count(value: Vector2): number;
    erase(value: Vector2): boolean;
}

/**
 * A global constructor and namespace for the PackedVector2Array type.
 *
 * Use `new PackedVector2Array(...)` to create a new instance.
 * Access static members like `PackedVector2Array.ZERO`.
 */
export declare const PackedVector2Array: {
    new(): PackedVector2Array;
    new(_from: PackedVector2Array): PackedVector2Array;
    new(_from: GDArray): PackedVector2Array;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // multiply(Transform2D): PackedVector2Array
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedVector2Array): boolean
    // not_equals(PackedVector2Array): boolean
    // add(PackedVector2Array): PackedVector2Array
    */
};