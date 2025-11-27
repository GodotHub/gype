declare global {
    export class Dictionary {
        constructor(): Dictionary;
        constructor(_from: Dictionary): Dictionary;
        constructor(base: Dictionary, keyType: number, keyClassName: GDString | StringName | string, keyScript: any, valueType: number, valueClassName: GDString | StringName | string, valueScript: any): Dictionary;
    

        size(): number;
        is_empty(): boolean;
        clear(): void;
        assign(dictionary: Dictionary): void;
        sort(): void;
        merge(dictionary: Dictionary, overwrite: boolean = false): void;
        merged(dictionary: Dictionary, overwrite: boolean = false): Dictionary;
        has(key: any): boolean;
        has_all(keys: GDArray | Array): boolean;
        find_key(value: any): any;
        erase(key: any): boolean;
        hash(): number;
        keys(): GDArray;
        values(): GDArray;
        duplicate(deep: boolean = false): Dictionary;
        duplicate_deep(deesubresourcesMode: number = 1): Dictionary;
        get(key: any, _default: any = null): any;
        get_or_add(key: any, _default: any = null): any;
        set(key: any, value: any): boolean;
        is_typed(): boolean;
        is_typed_key(): boolean;
        is_typed_value(): boolean;
        is_same_typed(dictionary: Dictionary): boolean;
        is_same_typed_key(dictionary: Dictionary): boolean;
        is_same_typed_value(dictionary: Dictionary): boolean;
        get_typed_key_builtin(): number;
        get_typed_value_builtin(): number;
        get_typed_key_class_name(): StringName;
        get_typed_value_class_name(): StringName;
        get_typed_key_script(): any;
        get_typed_value_script(): any;
        make_read_only(): void;
        is_read_only(): boolean;
        recursive_equal(dictionary: Dictionary, recursionCount: number): boolean;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Dictionary): boolean
        // not_equals(Dictionary): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    }
}

export {};