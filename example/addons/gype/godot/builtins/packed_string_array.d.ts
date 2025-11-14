declare global {
    export class PackedStringArray {
        constructor(): PackedStringArray;
        constructor(_from: PackedStringArray): PackedStringArray;
        constructor(_from: GDArray): PackedStringArray;
    

        get(index: number): GDString;
        set(index: number, value: GDString | StringName | string): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: GDString | StringName | string): boolean;
        append(value: GDString | StringName | string): boolean;
        append_array(array: PackedStringArray): void;
        remove_at(index: number): void;
        insert(atIndex: number, value: GDString | StringName | string): number;
        fill(value: GDString | StringName | string): void;
        resize(newSize: number): number;
        clear(): void;
        has(value: GDString | StringName | string): boolean;
        reverse(): void;
        slice(begin: number, end: number = 2147483647): PackedStringArray;
        to_byte_array(): PackedByteArray;
        sort(): void;
        bsearch(value: GDString | StringName | string, before: boolean = true): number;
        duplicate(): PackedStringArray;
        find(value: GDString | StringName | string, _from: number = 0): number;
        rfind(value: GDString | StringName | string, _from: number = -1): number;
        count(value: GDString | StringName | string): number;
        erase(value: GDString | StringName | string): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // equals(PackedStringArray): boolean
        // not_equals(PackedStringArray): boolean
        // add(PackedStringArray): PackedStringArray
        */
    }
}

export {};