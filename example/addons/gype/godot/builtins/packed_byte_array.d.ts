
/**
 * Godot's built-in PackedByteArray type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: PackedByteArray = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new PackedByteArray(1, 0);
 */
export interface PackedByteArray {

    get(index: number): number;
    set(index: number, value: number): void;
    size(): number;
    isEmpty(): boolean;
    pushBack(value: number): boolean;
    append(value: number): boolean;
    appendArray(array: PackedByteArray): void;
    removeAt(index: number): void;
    insert(atIndex: number, value: number): number;
    fill(value: number): void;
    resize(newSize: number): number;
    clear(): void;
    has(value: number): boolean;
    reverse(): void;
    slice(begin: number, end: number = 2147483647): PackedByteArray;
    sort(): void;
    bsearch(value: number, before: boolean = true): number;
    duplicate(): PackedByteArray;
    find(value: number, _from: number = 0): number;
    rfind(value: number, _from: number = -1): number;
    count(value: number): number;
    erase(value: number): boolean;
    getStringFromAscii(): GDString;
    getStringFromUtf8(): GDString;
    getStringFromUtf16(): GDString;
    getStringFromUtf32(): GDString;
    getStringFromWchar(): GDString;
    getStringFromMultibyteChar(encoding: GDString | StringName | string = ""): GDString;
    hexEncode(): GDString;
    compress(compressionMode: number = 0): PackedByteArray;
    decompress(bufferSize: number, compressionMode: number = 0): PackedByteArray;
    decompressDynamic(maxOutputSize: number, compressionMode: number = 0): PackedByteArray;
    decodeU8(byteOffset: number): number;
    decodeS8(byteOffset: number): number;
    decodeU16(byteOffset: number): number;
    decodeS16(byteOffset: number): number;
    decodeU32(byteOffset: number): number;
    decodeS32(byteOffset: number): number;
    decodeU64(byteOffset: number): number;
    decodeS64(byteOffset: number): number;
    decodeHalf(byteOffset: number): number;
    decodeFloat(byteOffset: number): number;
    decodeDouble(byteOffset: number): number;
    hasEncodedVar(byteOffset: number, allowObjects: boolean = false): boolean;
    decodeVar(byteOffset: number, allowObjects: boolean = false): any;
    decodeVarSize(byteOffset: number, allowObjects: boolean = false): number;
    toInt32Array(): PackedInt32Array;
    toInt64Array(): PackedInt64Array;
    toFloat32Array(): PackedFloat32Array;
    toFloat64Array(): PackedFloat64Array;
    toVector2Array(): PackedVector2Array;
    toVector3Array(): PackedVector3Array;
    toVector4Array(): PackedVector4Array;
    toColorArray(): PackedColorArray;
    bswap16(offset: number = 0, count: number = -1): void;
    bswap32(offset: number = 0, count: number = -1): void;
    bswap64(offset: number = 0, count: number = -1): void;
    encodeU8(byteOffset: number, value: number): void;
    encodeS8(byteOffset: number, value: number): void;
    encodeU16(byteOffset: number, value: number): void;
    encodeS16(byteOffset: number, value: number): void;
    encodeU32(byteOffset: number, value: number): void;
    encodeS32(byteOffset: number, value: number): void;
    encodeU64(byteOffset: number, value: number): void;
    encodeS64(byteOffset: number, value: number): void;
    encodeHalf(byteOffset: number, value: number): void;
    encodeFloat(byteOffset: number, value: number): void;
    encodeDouble(byteOffset: number, value: number): void;
    encodeVar(byteOffset: number, value: any, allowObjects: boolean = false): number;
}

/**
 * A global constructor and namespace for the PackedByteArray type.
 *
 * Use `new PackedByteArray(...)` to create a new instance.
 * Access static members like `PackedByteArray.ZERO`.
 */
export declare const PackedByteArray: {
    new(): PackedByteArray;
    new(_from: PackedByteArray): PackedByteArray;
    new(_from: GDArray): PackedByteArray;


    /*
    // equals(any): boolean
    // not_equals(any): boolean
    // op_not(any): boolean
    // in_op(Dictionary): boolean
    // in_op(GDArray): boolean
    // equals(PackedByteArray): boolean
    // not_equals(PackedByteArray): boolean
    // add(PackedByteArray): PackedByteArray
    */
};