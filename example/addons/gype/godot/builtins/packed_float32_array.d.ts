
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';


export declare class PackedFloat32Array {
    constructor();
    constructor(_from: PackedFloat32Array);
    constructor(_from: GDArray);


    public get(index: number): number;
    public set(index: number, value: number): void;
    public size(): number;
    public is_empty(): boolean;
    public push_back(value: number): boolean;
    public append(value: number): boolean;
    public append_array(array: PackedFloat32Array): void;
    public remove_at(index: number): void;
    public insert(at_index: number, value: number): number;
    public fill(value: number): void;
    public resize(new_size: number): number;
    public clear(): void;
    public has(value: number): boolean;
    public reverse(): void;
    public slice(begin: number, end: number): PackedFloat32Array;
    public to_byte_array(): PackedByteArray;
    public sort(): void;
    public bsearch(value: number, before: boolean): number;
    public duplicate(): PackedFloat32Array;
    public find(value: number, _from: number): number;
    public rfind(value: number, _from: number): number;
    public count(value: number): number;
    public erase(value: number): boolean;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public equals(right: PackedFloat32Array): boolean;
    public not_equals(right: PackedFloat32Array): boolean;
    public add(right: PackedFloat32Array): PackedFloat32Array;

}