
/**
 * Godot's built-in Dictionary type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Dictionary = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Dictionary(1, 0);
 */
export interface Dictionary {

    size(): number;
    isEmpty(): boolean;
    clear(): void;
    assign(dictionary: Dictionary): void;
    sort(): void;
    merge(dictionary: Dictionary, overwrite: boolean = false): void;
    merged(dictionary: Dictionary, overwrite: boolean = false): Dictionary;
    has(key: any): boolean;
    hasAll(keys: GDArray): boolean;
    findKey(value: any): any;
    erase(key: any): boolean;
    hash(): number;
    keys(): GDArray;
    values(): GDArray;
    duplicate(deep: boolean = false): Dictionary;
    duplicateDeep(deesubresourcesMode: number = 1): Dictionary;
    get(key: any, _default: any = null): any;
    getOrAdd(key: any, _default: any = null): any;
    set(key: any, value: any): boolean;
    isTyped(): boolean;
    isTypedKey(): boolean;
    isTypedValue(): boolean;
    isSameTyped(dictionary: Dictionary): boolean;
    isSameTypedKey(dictionary: Dictionary): boolean;
    isSameTypedValue(dictionary: Dictionary): boolean;
    getTypedKeyBuiltin(): number;
    getTypedValueBuiltin(): number;
    getTypedKeyClassName(): StringName;
    getTypedValueClassName(): StringName;
    getTypedKeyScript(): any;
    getTypedValueScript(): any;
    makeReadOnly(): void;
    isReadOnly(): boolean;
    recursiveEqual(dictionary: Dictionary, recursionCount: number): boolean;
}

/**
 * A global constructor and namespace for the Dictionary type.
 *
 * Use `new Dictionary(...)` to create a new instance.
 * Access static members like `Dictionary.ZERO`.
 */
export declare const Dictionary: {
    new(): Dictionary;
    new(_from: Dictionary): Dictionary;
    new(base: Dictionary, keyType: number, keyClassName: GDString | StringName | string, keyScript: any, valueType: number, valueClassName: GDString | StringName | string, valueScript: any): Dictionary;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // equals(Dictionary): boolean
    // not_equals(Dictionary): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    */
};