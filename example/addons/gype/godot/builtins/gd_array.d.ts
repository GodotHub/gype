declare global {
    export class GDArray {
        constructor(): GDArray;
        constructor(_from: GDArray | Array): GDArray;
        constructor(base: GDArray | Array, _type: number, className: GDString | StringName | string, script: any): GDArray;
        constructor(_from: PackedByteArray): GDArray;
        constructor(_from: PackedInt32Array): GDArray;
        constructor(_from: PackedInt64Array): GDArray;
        constructor(_from: PackedFloat32Array): GDArray;
        constructor(_from: PackedFloat64Array): GDArray;
        constructor(_from: PackedStringArray): GDArray;
        constructor(_from: PackedVector2Array): GDArray;
        constructor(_from: PackedVector3Array): GDArray;
        constructor(_from: PackedColorArray): GDArray;
        constructor(_from: PackedVector4Array): GDArray;
    

        size(): number;
        is_empty(): boolean;
        clear(): void;
        hash(): number;
        assign(array: GDArray | Array): void;
        get(index: number): any;
        set(index: number, value: any): void;
        push_back(value: any): void;
        push_front(value: any): void;
        append(value: any): void;
        append_array(array: GDArray | Array): void;
        resize(size: number): number;
        insert(position: number, value: any): number;
        remove_at(position: number): void;
        fill(value: any): void;
        erase(value: any): void;
        front(): any;
        back(): any;
        pick_random(): any;
        find(what: any, _from: number = 0): number;
        find_custom(method: Callable | Function, _from: number = 0): number;
        rfind(what: any, _from: number = -1): number;
        rfind_custom(method: Callable | Function, _from: number = -1): number;
        count(value: any): number;
        has(value: any): boolean;
        pop_back(): any;
        pop_front(): any;
        pop_at(position: number): any;
        sort(): void;
        sort_custom(func: Callable | Function): void;
        shuffle(): void;
        bsearch(value: any, before: boolean = true): number;
        bsearch_custom(value: any, func: Callable | Function, before: boolean = true): number;
        reverse(): void;
        duplicate(deep: boolean = false): GDArray;
        duplicate_deep(deesubresourcesMode: number = 1): GDArray;
        slice(begin: number, end: number = 2147483647, step: number = 1, deep: boolean = false): GDArray;
        filter(method: Callable | Function): GDArray;
        map(method: Callable | Function): GDArray;
        reduce(method: Callable | Function, accum: any = null): any;
        any(method: Callable | Function): boolean;
        all(method: Callable | Function): boolean;
        max(): any;
        min(): any;
        is_typed(): boolean;
        is_same_typed(array: GDArray | Array): boolean;
        get_typed_builtin(): number;
        get_typed_class_name(): StringName;
        get_typed_script(): any;
        make_read_only(): void;
        is_read_only(): boolean;
        
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
    }
}

export {};