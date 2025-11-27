declare global {
    export class PackedColorArray {
        constructor(): PackedColorArray;
        constructor(_from: PackedColorArray): PackedColorArray;
        constructor(_from: GDArray | Array): PackedColorArray;
    

        get(index: number): Color;
        set(index: number, value: Color): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: Color): boolean;
        append(value: Color): boolean;
        append_array(array: PackedColorArray): void;
        remove_at(index: number): void;
        insert(atIndex: number, value: Color): number;
        fill(value: Color): void;
        resize(newSize: number): number;
        clear(): void;
        has(value: Color): boolean;
        reverse(): void;
        slice(begin: number, end: number = 2147483647): PackedColorArray;
        to_byte_array(): PackedByteArray;
        sort(): void;
        bsearch(value: Color, before: boolean = true): number;
        duplicate(): PackedColorArray;
        find(value: Color, _from: number = 0): number;
        rfind(value: Color, _from: number = -1): number;
        count(value: Color): number;
        erase(value: Color): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // equals(PackedColorArray): boolean
        // not_equals(PackedColorArray): boolean
        // add(PackedColorArray): PackedColorArray
        */
    }
}

export {};