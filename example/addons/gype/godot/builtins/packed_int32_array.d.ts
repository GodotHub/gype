declare global {
    export class PackedInt32Array {
        constructor(): PackedInt32Array;
        constructor(_from: PackedInt32Array): PackedInt32Array;
        constructor(_from: GDArray | Array): PackedInt32Array;
    

        get(index: number): number;
        set(index: number, value: number): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: number): boolean;
        append(value: number): boolean;
        append_array(array: PackedInt32Array): void;
        remove_at(index: number): void;
        insert(atIndex: number, value: number): number;
        fill(value: number): void;
        resize(newSize: number): number;
        clear(): void;
        has(value: number): boolean;
        reverse(): void;
        slice(begin: number, end: number = 2147483647): PackedInt32Array;
        to_byte_array(): PackedByteArray;
        sort(): void;
        bsearch(value: number, before: boolean = true): number;
        duplicate(): PackedInt32Array;
        find(value: number, _from: number = 0): number;
        rfind(value: number, _from: number = -1): number;
        count(value: number): number;
        erase(value: number): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // equals(PackedInt32Array): boolean
        // not_equals(PackedInt32Array): boolean
        // add(PackedInt32Array): PackedInt32Array
        */
    }
}

export {};