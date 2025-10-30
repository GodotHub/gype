
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';


export declare class PackedInt32Array {
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
    public insert(at_index: number, value: number): number;
    public fill(value: number): void;
    public resize(new_size: number): number;
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