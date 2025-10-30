
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { Vector4 } from '@godot/builtins/vector4';


export declare class PackedVector4Array {
    constructor();
    constructor(_from: PackedVector4Array);
    constructor(_from: GDArray);


    public get(index: number): Vector4;
    public set(index: number, value: Vector4): void;
    public size(): number;
    public is_empty(): boolean;
    public push_back(value: Vector4): boolean;
    public append(value: Vector4): boolean;
    public append_array(array: PackedVector4Array): void;
    public remove_at(index: number): void;
    public insert(at_index: number, value: Vector4): number;
    public fill(value: Vector4): void;
    public resize(new_size: number): number;
    public clear(): void;
    public has(value: Vector4): boolean;
    public reverse(): void;
    public slice(begin: number, end: number): PackedVector4Array;
    public to_byte_array(): PackedByteArray;
    public sort(): void;
    public bsearch(value: Vector4, before: boolean): number;
    public duplicate(): PackedVector4Array;
    public find(value: Vector4, _from: number): number;
    public rfind(value: Vector4, _from: number): number;
    public count(value: Vector4): number;
    public erase(value: Vector4): boolean;

}