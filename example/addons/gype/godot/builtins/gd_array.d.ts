
/**
 * Godot's built-in GDArray type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: GDArray = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new GDArray(1, 0);
 */
export interface GDArray {

    size(): number;
    isEmpty(): boolean;
    clear(): void;
    hash(): number;
    assign(array: GDArray): void;
    get(index: number): any;
    set(index: number, value: any): void;
    pushBack(value: any): void;
    pushFront(value: any): void;
    append(value: any): void;
    appendArray(array: GDArray): void;
    resize(size: number): number;
    insert(position: number, value: any): number;
    removeAt(position: number): void;
    fill(value: any): void;
    erase(value: any): void;
    front(): any;
    back(): any;
    pickRandom(): any;
    find(what: any, _from: number = 0): number;
    findCustom(method: Callable, _from: number = 0): number;
    rfind(what: any, _from: number = -1): number;
    rfindCustom(method: Callable, _from: number = -1): number;
    count(value: any): number;
    has(value: any): boolean;
    popBack(): any;
    popFront(): any;
    popAt(position: number): any;
    sort(): void;
    sortCustom(func: Callable): void;
    shuffle(): void;
    bsearch(value: any, before: boolean = true): number;
    bsearchCustom(value: any, func: Callable, before: boolean = true): number;
    reverse(): void;
    duplicate(deep: boolean = false): GDArray;
    duplicateDeep(deesubresourcesMode: number = 1): GDArray;
    slice(begin: number, end: number = 2147483647, step: number = 1, deep: boolean = false): GDArray;
    filter(method: Callable): GDArray;
    map(method: Callable): GDArray;
    reduce(method: Callable, accum: any = null): any;
    any(method: Callable): boolean;
    all(method: Callable): boolean;
    max(): any;
    min(): any;
    isTyped(): boolean;
    isSameTyped(array: GDArray): boolean;
    getTypedBuiltin(): number;
    getTypedClassName(): StringName;
    getTypedScript(): any;
    makeReadOnly(): void;
    isReadOnly(): boolean;
}

/**
 * A global constructor and namespace for the GDArray type.
 *
 * Use `new GDArray(...)` to create a new instance.
 * Access static members like `GDArray.ZERO`.
 */
export declare const GDArray: {
    new(): GDArray;
    new(_from: GDArray): GDArray;
    new(base: GDArray, _type: number, className: GDString | StringName | string, script: any): GDArray;
    new(_from: PackedByteArray): GDArray;
    new(_from: PackedInt32Array): GDArray;
    new(_from: PackedInt64Array): GDArray;
    new(_from: PackedFloat32Array): GDArray;
    new(_from: PackedFloat64Array): GDArray;
    new(_from: PackedStringArray): GDArray;
    new(_from: PackedVector2Array): GDArray;
    new(_from: PackedVector3Array): GDArray;
    new(_from: PackedColorArray): GDArray;
    new(_from: PackedVector4Array): GDArray;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // equals(GDArray): boolean
    // not_equals(GDArray): boolean
    // less(GDArray): boolean
    // less_equal(GDArray): boolean
    // greater(GDArray): boolean
    // greater_equal(GDArray): boolean
    // add(GDArray): GDArray
    // in_op(GDArray): boolean
    */
};