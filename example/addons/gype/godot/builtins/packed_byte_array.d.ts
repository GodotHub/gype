

declare global {
    declare class PackedByteArray {
        constructor();
        constructor(_from: PackedByteArray);
        constructor(_from: GDArray);


        public get(index: number): number;
        public set(index: number, value: number): void;
        public size(): number;
        public is_empty(): boolean;
        public push_back(value: number): boolean;
        public append(value: number): boolean;
        public append_array(array: PackedByteArray): void;
        public remove_at(index: number): void;
        public insert(atIndex: number, value: number): number;
        public fill(value: number): void;
        public resize(newSize: number): number;
        public clear(): void;
        public has(value: number): boolean;
        public reverse(): void;
        public slice(begin: number, end: number): PackedByteArray;
        public sort(): void;
        public bsearch(value: number, before: boolean): number;
        public duplicate(): PackedByteArray;
        public find(value: number, _from: number): number;
        public rfind(value: number, _from: number): number;
        public count(value: number): number;
        public erase(value: number): boolean;
        public get_string_from_ascii(): GDString;
        public get_string_from_utf8(): GDString;
        public get_string_from_utf16(): GDString;
        public get_string_from_utf32(): GDString;
        public get_string_from_wchar(): GDString;
        public get_string_from_multibyte_char(encoding: GDString | StringName | string): GDString;
        public hex_encode(): GDString;
        public compress(compressionMode: number): PackedByteArray;
        public decompress(bufferSize: number, compressionMode: number): PackedByteArray;
        public decompress_dynamic(maxOutputSize: number, compressionMode: number): PackedByteArray;
        public decode_u8(byteOffset: number): number;
        public decode_s8(byteOffset: number): number;
        public decode_u16(byteOffset: number): number;
        public decode_s16(byteOffset: number): number;
        public decode_u32(byteOffset: number): number;
        public decode_s32(byteOffset: number): number;
        public decode_u64(byteOffset: number): number;
        public decode_s64(byteOffset: number): number;
        public decode_half(byteOffset: number): number;
        public decode_float(byteOffset: number): number;
        public decode_double(byteOffset: number): number;
        public has_encoded_var(byteOffset: number, allowObjects: boolean): boolean;
        public decode_var(byteOffset: number, allowObjects: boolean): any;
        public decode_var_size(byteOffset: number, allowObjects: boolean): number;
        public to_int32_array(): PackedInt32Array;
        public to_int64_array(): PackedInt64Array;
        public to_float32_array(): PackedFloat32Array;
        public to_float64_array(): PackedFloat64Array;
        public to_vector2_array(): PackedVector2Array;
        public to_vector3_array(): PackedVector3Array;
        public to_vector4_array(): PackedVector4Array;
        public to_color_array(): PackedColorArray;
        public bswap16(offset: number, count: number): void;
        public bswap32(offset: number, count: number): void;
        public bswap64(offset: number, count: number): void;
        public encode_u8(byteOffset: number, value: number): void;
        public encode_s8(byteOffset: number, value: number): void;
        public encode_u16(byteOffset: number, value: number): void;
        public encode_s16(byteOffset: number, value: number): void;
        public encode_u32(byteOffset: number, value: number): void;
        public encode_s32(byteOffset: number, value: number): void;
        public encode_u64(byteOffset: number, value: number): void;
        public encode_s64(byteOffset: number, value: number): void;
        public encode_half(byteOffset: number, value: number): void;
        public encode_float(byteOffset: number, value: number): void;
        public encode_double(byteOffset: number, value: number): void;
        public encode_var(byteOffset: number, value: any, allowObjects: boolean): number;

    }
}

export {};