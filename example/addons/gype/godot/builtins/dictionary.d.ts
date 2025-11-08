

declare global {
    declare class Dictionary {
        constructor();
        constructor(_from: Dictionary);
        constructor(base: Dictionary, keyType: number, keyClassName: GDString | StringName | string, keyScript: any, valueType: number, valueClassName: GDString | StringName | string, valueScript: any);


        public size(): number;
        public is_empty(): boolean;
        public clear(): void;
        public assign(dictionary: Dictionary): void;
        public sort(): void;
        public merge(dictionary: Dictionary, overwrite: boolean): void;
        public merged(dictionary: Dictionary, overwrite: boolean): Dictionary;
        public has(key: any): boolean;
        public has_all(keys: GDArray): boolean;
        public find_key(value: any): any;
        public erase(key: any): boolean;
        public hash(): number;
        public keys(): GDArray;
        public values(): GDArray;
        public duplicate(deep: boolean): Dictionary;
        public duplicate_deep(deesubresourcesMode: number): Dictionary;
        public get(key: any, _default: any): any;
        public get_or_add(key: any, _default: any): any;
        public set(key: any, value: any): boolean;
        public is_typed(): boolean;
        public is_typed_key(): boolean;
        public is_typed_value(): boolean;
        public is_same_typed(dictionary: Dictionary): boolean;
        public is_same_typed_key(dictionary: Dictionary): boolean;
        public is_same_typed_value(dictionary: Dictionary): boolean;
        public get_typed_key_builtin(): number;
        public get_typed_value_builtin(): number;
        public get_typed_key_class_name(): StringName;
        public get_typed_value_class_name(): StringName;
        public get_typed_key_script(): any;
        public get_typed_value_script(): any;
        public make_read_only(): void;
        public is_read_only(): boolean;
        public recursive_equal(dictionary: Dictionary, recursionCount: number): boolean;

    }
}

export {};