
/**
 * Godot's built-in PackedInt64Array type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedInt64Array = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedInt64Array(1, 0);
 */
export interface PackedInt64Array {

    get(index: number): number;
    set(index: number, value: number): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: number): boolean;
    append(value: number): boolean;
    appendArray(array: PackedInt64Array): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: number): number;
    fill(value: number): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: number): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedInt64Array;
    toByteArray(): PackedByteArray;
    sort(): void;
    bsearch(value: number, before: boolean = true): number;
    duplicate(): PackedInt64Array;
    find(value: number, _from: number = 0): number;
    rfind(value: number, _from: number = -1): number;
    count(value: number): number;
    erase(value: number): boolean;
}

/**
 * A global constructor and namespace for the PackedInt64Array type.
 *
 * Use `new PackedInt64Array(...)` to create a new instance.
 * Access static members like `PackedInt64Array.ZERO`.
 */
export declare const PackedInt64Array: {
    new(): PackedInt64Array;
    new(_from: PackedInt64Array): PackedInt64Array;
    new(_from: GDArray): PackedInt64Array;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedInt64Array): boolean
    // not_equals(PackedInt64Array): boolean
    // add(PackedInt64Array): PackedInt64Array
    */
};