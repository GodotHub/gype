

declare global {
    declare class GDArray {
        constructor();
        constructor(_from: GDArray);
        constructor(base: GDArray, _type: number, className: GDString | StringName | string, script: any);
        constructor(_from: PackedByteArray);
        constructor(_from: PackedInt32Array);
        constructor(_from: PackedInt64Array);
        constructor(_from: PackedFloat32Array);
        constructor(_from: PackedFloat64Array);
        constructor(_from: PackedStringArray);
        constructor(_from: PackedVector2Array);
        constructor(_from: PackedVector3Array);
        constructor(_from: PackedColorArray);
        constructor(_from: PackedVector4Array);


        public size(): number;
        public is_empty(): boolean;
        public clear(): void;
        public hash(): number;
        public assign(array: GDArray): void;
        public get(index: number): any;
        public set(index: number, value: any): void;
        public push_back(value: any): void;
        public push_front(value: any): void;
        public append(value: any): void;
        public append_array(array: GDArray): void;
        public resize(size: number): number;
        public insert(position: number, value: any): number;
        public remove_at(position: number): void;
        public fill(value: any): void;
        public erase(value: any): void;
        public front(): any;
        public back(): any;
        public pick_random(): any;
        public find(what: any, _from: number): number;
        public find_custom(method: Callable, _from: number): number;
        public rfind(what: any, _from: number): number;
        public rfind_custom(method: Callable, _from: number): number;
        public count(value: any): number;
        public has(value: any): boolean;
        public pop_back(): any;
        public pop_front(): any;
        public pop_at(position: number): any;
        public sort(): void;
        public sort_custom(func: Callable): void;
        public shuffle(): void;
        public bsearch(value: any, before: boolean): number;
        public bsearch_custom(value: any, func: Callable, before: boolean): number;
        public reverse(): void;
        public duplicate(deep: boolean): GDArray;
        public duplicate_deep(deesubresourcesMode: number): GDArray;
        public slice(begin: number, end: number, step: number, deep: boolean): GDArray;
        public filter(method: Callable): GDArray;
        public map(method: Callable): GDArray;
        public reduce(method: Callable, accum: any): any;
        public any(method: Callable): boolean;
        public all(method: Callable): boolean;
        public max(): any;
        public min(): any;
        public is_typed(): boolean;
        public is_same_typed(array: GDArray): boolean;
        public get_typed_builtin(): number;
        public get_typed_class_name(): StringName;
        public get_typed_script(): any;
        public make_read_only(): void;
        public is_read_only(): boolean;

    }
}

export {};