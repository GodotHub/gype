declare global {
    export interface GDArray {

        size(): number;
        is_empty(): boolean;
        clear(): void;
        hash(): number;
        assign(array: GDArray): void;
        get(index: number): any;
        set(index: number, value: any): void;
        push_back(value: any): void;
        push_front(value: any): void;
        append(value: any): void;
        append_array(array: GDArray): void;
        resize(size: number): number;
        insert(position: number, value: any): number;
        remove_at(position: number): void;
        fill(value: any): void;
        erase(value: any): void;
        front(): any;
        back(): any;
        pick_random(): any;
        find(what: any, _from: number = 0): number;
        find_custom(method: Callable, _from: number = 0): number;
        rfind(what: any, _from: number = -1): number;
        rfind_custom(method: Callable, _from: number = -1): number;
        count(value: any): number;
        has(value: any): boolean;
        pop_back(): any;
        pop_front(): any;
        pop_at(position: number): any;
        sort(): void;
        sort_custom(func: Callable): void;
        shuffle(): void;
        bsearch(value: any, before: boolean = true): number;
        bsearch_custom(value: any, func: Callable, before: boolean = true): number;
        reverse(): void;
        duplicate(deep: boolean = false): GDArray;
        duplicate_deep(deesubresourcesMode: number = 1): GDArray;
        slice(begin: number, end: number = 2147483647, step: number = 1, deep: boolean = false): GDArray;
        filter(method: Callable): GDArray;
        map(method: Callable): GDArray;
        reduce(method: Callable, accum: any = null): any;
        any(method: Callable): boolean;
        all(method: Callable): boolean;
        max(): any;
        min(): any;
        is_typed(): boolean;
        is_same_typed(array: GDArray): boolean;
        get_typed_builtin(): number;
        get_typed_class_name(): StringName;
        get_typed_script(): any;
        make_read_only(): void;
        is_read_only(): boolean;
    }

    /**
    * A global constructor and namespace for the GDArray type.
    *
    * Use `new GDArray(...)` to create a new instance.
    * Access static members like `GDArray.ZERO`.
    */
    export declare const GDArray: {
        new(): GDArray;
        new(_from: GDArray): GDArray;
        new(base: GDArray, _type: number, className: GDString | StringName | string, script: any): GDArray;
        new(_from: PackedByteArray): GDArray;
        new(_from: PackedInt32Array): GDArray;
        new(_from: PackedInt64Array): GDArray;
        new(_from: PackedFloat32Array): GDArray;
        new(_from: PackedFloat64Array): GDArray;
        new(_from: PackedStringArray): GDArray;
        new(_from: PackedVector2Array): GDArray;
        new(_from: PackedVector3Array): GDArray;
        new(_from: PackedColorArray): GDArray;
        new(_from: PackedVector4Array): GDArray;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // in_op(Dictionary): boolean
        // equals(GDArray): boolean
        // not_equals(GDArray): boolean
        // less(GDArray): boolean
        // less_equal(GDArray): boolean
        // greater(GDArray): boolean
        // greater_equal(GDArray): boolean
        // add(GDArray): GDArray
        // in_op(GDArray): boolean
        */
    };
}

export {};