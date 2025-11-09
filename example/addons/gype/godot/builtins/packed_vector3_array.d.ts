declare global {
    export interface PackedVector3Array {

        get(index: number): Vector3;
        set(index: number, value: Vector3): void;
        size(): number;
        is_empty(): boolean;
        push_back(value: Vector3): boolean;
        append(value: Vector3): boolean;
        append_array(array: PackedVector3Array): void;
        remove_at(index: number): void;
        insert(atIndex: number, value: Vector3): number;
        fill(value: Vector3): void;
        resize(newSize: number): number;
        clear(): void;
        has(value: Vector3): boolean;
        reverse(): void;
        slice(begin: number, end: number = 2147483647): PackedVector3Array;
        to_byte_array(): PackedByteArray;
        sort(): void;
        bsearch(value: Vector3, before: boolean = true): number;
        duplicate(): PackedVector3Array;
        find(value: Vector3, _from: number = 0): number;
        rfind(value: Vector3, _from: number = -1): number;
        count(value: Vector3): number;
        erase(value: Vector3): boolean;
    }

    /**
    * A global constructor and namespace for the PackedVector3Array type.
    *
    * Use `new PackedVector3Array(...)` to create a new instance.
    * Access static members like `PackedVector3Array.ZERO`.
    */
    export declare const PackedVector3Array: {
        new(): PackedVector3Array;
        new(_from: PackedVector3Array): PackedVector3Array;
        new(_from: GDArray): PackedVector3Array;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // multiply(Transform3D): PackedVector3Array
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        // equals(PackedVector3Array): boolean
        // not_equals(PackedVector3Array): boolean
        // add(PackedVector3Array): PackedVector3Array
        */
    };
}

export {};