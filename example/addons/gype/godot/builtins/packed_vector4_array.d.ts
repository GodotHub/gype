declare global {
    export class PackedVector4Array {
        constructor(): PackedVector4Array;
        constructor(_from: PackedVector4Array): PackedVector4Array;
        constructor(_from: GDArray | Array): PackedVector4Array;
    

        get(index: number): Vector4;
        set(index: number, value: Vector4): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: Vector4): boolean;
        append(value: Vector4): boolean;
        append_array(array: PackedVector4Array): void;
        remove_at(index: number): void;
        insert(atIndex: number, value: Vector4): number;
        fill(value: Vector4): void;
        resize(newSize: number): number;
        clear(): void;
        has(value: Vector4): boolean;
        reverse(): void;
        slice(begin: number, end: number = 2147483647): PackedVector4Array;
        to_byte_array(): PackedByteArray;
        sort(): void;
        bsearch(value: Vector4, before: boolean = true): number;
        duplicate(): PackedVector4Array;
        find(value: Vector4, _from: number = 0): number;
        rfind(value: Vector4, _from: number = -1): number;
        count(value: Vector4): number;
        erase(value: Vector4): boolean;
        
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
    }
}

export {};