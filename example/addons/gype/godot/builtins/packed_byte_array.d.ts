declare global {
    export interface PackedByteArray {

        get(index: number): number;
        set(index: number, value: number): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: number): boolean;
        append(value: number): boolean;
        append_array(array: PackedByteArray): void;
        remove_at(index: number): void;
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
        get_string_from_ascii(): GDString;
        get_string_from_utf8(): GDString;
        get_string_from_utf16(): GDString;
        get_string_from_utf32(): GDString;
        get_string_from_wchar(): GDString;
        get_string_from_multibyte_char(encoding: GDString | StringName | string = ""): GDString;
        hex_encode(): GDString;
        compress(compressionMode: number = 0): PackedByteArray;
        decompress(bufferSize: number, compressionMode: number = 0): PackedByteArray;
        decompress_dynamic(maxOutputSize: number, compressionMode: number = 0): PackedByteArray;
        decode_u8(byteOffset: number): number;
        decode_s8(byteOffset: number): number;
        decode_u16(byteOffset: number): number;
        decode_s16(byteOffset: number): number;
        decode_u32(byteOffset: number): number;
        decode_s32(byteOffset: number): number;
        decode_u64(byteOffset: number): number;
        decode_s64(byteOffset: number): number;
        decode_half(byteOffset: number): number;
        decode_float(byteOffset: number): number;
        decode_double(byteOffset: number): number;
        has_encoded_var(byteOffset: number, allowObjects: boolean = false): boolean;
        decode_var(byteOffset: number, allowObjects: boolean = false): any;
        decode_var_size(byteOffset: number, allowObjects: boolean = false): number;
        to_int32_array(): PackedInt32Array;
        to_int64_array(): PackedInt64Array;
        to_float32_array(): PackedFloat32Array;
        to_float64_array(): PackedFloat64Array;
        to_vector2_array(): PackedVector2Array;
        to_vector3_array(): PackedVector3Array;
        to_vector4_array(): PackedVector4Array;
        to_color_array(): PackedColorArray;
        bswap16(offset: number = 0, count: number = -1): void;
        bswap32(offset: number = 0, count: number = -1): void;
        bswap64(offset: number = 0, count: number = -1): void;
        encode_u8(byteOffset: number, value: number): void;
        encode_s8(byteOffset: number, value: number): void;
        encode_u16(byteOffset: number, value: number): void;
        encode_s16(byteOffset: number, value: number): void;
        encode_u32(byteOffset: number, value: number): void;
        encode_s32(byteOffset: number, value: number): void;
        encode_u64(byteOffset: number, value: number): void;
        encode_s64(byteOffset: number, value: number): void;
        encode_half(byteOffset: number, value: number): void;
        encode_float(byteOffset: number, value: number): void;
        encode_double(byteOffset: number, value: number): void;
        encode_var(byteOffset: number, value: any, allowObjects: boolean = false): number;
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
}

export {};