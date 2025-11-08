

declare global {
    declare class PackedInt32Array {
        constructor();
        constructor(_from: PackedInt32Array);
        constructor(_from: GDArray);


        public get(index: number): number;
        public set(index: number, value: number): void;
        public size(): number;
        public is_empty(): boolean;
        public push_back(value: number): boolean;
        public append(value: number): boolean;
        public append_array(array: PackedInt32Array): void;
        public remove_at(index: number): void;
        public insert(atIndex: number, value: number): number;
        public fill(value: number): void;
        public resize(newSize: number): number;
        public clear(): void;
        public has(value: number): boolean;
        public reverse(): void;
        public slice(begin: number, end: number): PackedInt32Array;
        public to_byte_array(): PackedByteArray;
        public sort(): void;
        public bsearch(value: number, before: boolean): number;
        public duplicate(): PackedInt32Array;
        public find(value: number, _from: number): number;
        public rfind(value: number, _from: number): number;
        public count(value: number): number;
        public erase(value: number): boolean;

    }
}

export {};