
/**
 * Godot's built-in PackedFloat32Array type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedFloat32Array = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedFloat32Array(1, 0);
 */
export interface PackedFloat32Array {

    get(index: number): number;
    set(index: number, value: number): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: number): boolean;
    append(value: number): boolean;
    appendArray(array: PackedFloat32Array): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: number): number;
    fill(value: number): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: number): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedFloat32Array;
    toByteArray(): PackedByteArray;
    sort(): void;
    bsearch(value: number, before: boolean = true): number;
    duplicate(): PackedFloat32Array;
    find(value: number, _from: number = 0): number;
    rfind(value: number, _from: number = -1): number;
    count(value: number): number;
    erase(value: number): boolean;
}

/**
 * A global constructor and namespace for the PackedFloat32Array type.
 *
 * Use `new PackedFloat32Array(...)` to create a new instance.
 * Access static members like `PackedFloat32Array.ZERO`.
 */
export declare const PackedFloat32Array: {
    new(): PackedFloat32Array;
    new(_from: PackedFloat32Array): PackedFloat32Array;
    new(_from: GDArray): PackedFloat32Array;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedFloat32Array): boolean
    // not_equals(PackedFloat32Array): boolean
    // add(PackedFloat32Array): PackedFloat32Array
    */
};