
/**
 * Godot's built-in PackedColorArray type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedColorArray = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedColorArray(1, 0);
 */
export interface PackedColorArray {

    get(index: number): Color;
    set(index: number, value: Color): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: Color): boolean;
    append(value: Color): boolean;
    appendArray(array: PackedColorArray): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: Color): number;
    fill(value: Color): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: Color): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedColorArray;
    toByteArray(): PackedByteArray;
    sort(): void;
    bsearch(value: Color, before: boolean = true): number;
    duplicate(): PackedColorArray;
    find(value: Color, _from: number = 0): number;
    rfind(value: Color, _from: number = -1): number;
    count(value: Color): number;
    erase(value: Color): boolean;
}

/**
 * A global constructor and namespace for the PackedColorArray type.
 *
 * Use `new PackedColorArray(...)` to create a new instance.
 * Access static members like `PackedColorArray.ZERO`.
 */
export declare const PackedColorArray: {
    new(): PackedColorArray;
    new(_from: PackedColorArray): PackedColorArray;
    new(_from: GDArray): PackedColorArray;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedColorArray): boolean
    // not_equals(PackedColorArray): boolean
    // add(PackedColorArray): PackedColorArray
    */
};