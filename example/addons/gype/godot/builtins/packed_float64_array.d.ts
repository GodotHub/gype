
/**
 * Godot's built-in PackedFloat64Array type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedFloat64Array = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedFloat64Array(1, 0);
 */
export interface PackedFloat64Array {

    get(index: number): number;
    set(index: number, value: number): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: number): boolean;
    append(value: number): boolean;
    appendArray(array: PackedFloat64Array): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: number): number;
    fill(value: number): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: number): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedFloat64Array;
    toByteArray(): PackedByteArray;
    sort(): void;
    bsearch(value: number, before: boolean = true): number;
    duplicate(): PackedFloat64Array;
    find(value: number, _from: number = 0): number;
    rfind(value: number, _from: number = -1): number;
    count(value: number): number;
    erase(value: number): boolean;
}

/**
 * A global constructor and namespace for the PackedFloat64Array type.
 *
 * Use `new PackedFloat64Array(...)` to create a new instance.
 * Access static members like `PackedFloat64Array.ZERO`.
 */
export declare const PackedFloat64Array: {
    new(): PackedFloat64Array;
    new(_from: PackedFloat64Array): PackedFloat64Array;
    new(_from: GDArray): PackedFloat64Array;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedFloat64Array): boolean
    // not_equals(PackedFloat64Array): boolean
    // add(PackedFloat64Array): PackedFloat64Array
    */
};