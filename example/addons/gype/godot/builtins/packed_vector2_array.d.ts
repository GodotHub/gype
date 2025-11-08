

declare global {
    declare class PackedVector2Array {
        constructor();
        constructor(_from: PackedVector2Array);
        constructor(_from: GDArray);


        public get(index: number): Vector2;
        public set(index: number, value: Vector2): void;
        public size(): number;
        public is_empty(): boolean;
        public push_back(value: Vector2): boolean;
        public append(value: Vector2): boolean;
        public append_array(array: PackedVector2Array): void;
        public remove_at(index: number): void;
        public insert(atIndex: number, value: Vector2): number;
        public fill(value: Vector2): void;
        public resize(newSize: number): number;
        public clear(): void;
        public has(value: Vector2): boolean;
        public reverse(): void;
        public slice(begin: number, end: number): PackedVector2Array;
        public to_byte_array(): PackedByteArray;
        public sort(): void;
        public bsearch(value: Vector2, before: boolean): number;
        public duplicate(): PackedVector2Array;
        public find(value: Vector2, _from: number): number;
        public rfind(value: Vector2, _from: number): number;
        public count(value: Vector2): number;
        public erase(value: Vector2): boolean;

    }
}

export {};