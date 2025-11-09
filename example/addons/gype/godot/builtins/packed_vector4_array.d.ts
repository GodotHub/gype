
/**
 * Godot's built-in PackedVector4Array type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedVector4Array = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedVector4Array(1, 0);
 */
export interface PackedVector4Array {

    get(index: number): Vector4;
    set(index: number, value: Vector4): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: Vector4): boolean;
    append(value: Vector4): boolean;
    appendArray(array: PackedVector4Array): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: Vector4): number;
    fill(value: Vector4): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: Vector4): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedVector4Array;
    toByteArray(): PackedByteArray;
    sort(): void;
    bsearch(value: Vector4, before: boolean = true): number;
    duplicate(): PackedVector4Array;
    find(value: Vector4, _from: number = 0): number;
    rfind(value: Vector4, _from: number = -1): number;
    count(value: Vector4): number;
    erase(value: Vector4): boolean;
}

/**
 * A global constructor and namespace for the PackedVector4Array type.
 *
 * Use `new PackedVector4Array(...)` to create a new instance.
 * Access static members like `PackedVector4Array.ZERO`.
 */
export declare const PackedVector4Array: {
    new(): PackedVector4Array;
    new(_from: PackedVector4Array): PackedVector4Array;
    new(_from: GDArray): PackedVector4Array;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedVector4Array): boolean
    // not_equals(PackedVector4Array): boolean
    // add(PackedVector4Array): PackedVector4Array
    */
};