declare global {
    export class PackedVector2Array {
        constructor(): PackedVector2Array;
        constructor(_from: PackedVector2Array): PackedVector2Array;
        constructor(_from: GDArray | Array): PackedVector2Array;
    

        get(index: number): Vector2;
        set(index: number, value: Vector2): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: Vector2): boolean;
        append(value: Vector2): boolean;
        append_array(array: PackedVector2Array): void;
        remove_at(index: number): void;
        insert(atIndex: number, value: Vector2): number;
        fill(value: Vector2): void;
        resize(newSize: number): number;
        clear(): void;
        has(value: Vector2): boolean;
        reverse(): void;
        slice(begin: number, end: number = 2147483647): PackedVector2Array;
        to_byte_array(): PackedByteArray;
        sort(): void;
        bsearch(value: Vector2, before: boolean = true): number;
        duplicate(): PackedVector2Array;
        find(value: Vector2, _from: number = 0): number;
        rfind(value: Vector2, _from: number = -1): number;
        count(value: Vector2): number;
        erase(value: Vector2): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // multiply(Transform2D): PackedVector2Array
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // equals(PackedVector2Array): boolean
        // not_equals(PackedVector2Array): boolean
        // add(PackedVector2Array): PackedVector2Array
        */
    }
}

export {};