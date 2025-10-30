
import type { Color } from '@godot/builtins/color';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';


export declare class PackedColorArray {
    constructor();
    constructor(_from: PackedColorArray);
    constructor(_from: GDArray);


    public get(index: number): Color;
    public set(index: number, value: Color): void;
    public size(): number;
    public is_empty(): boolean;
    public push_back(value: Color): boolean;
    public append(value: Color): boolean;
    public append_array(array: PackedColorArray): void;
    public remove_at(index: number): void;
    public insert(at_index: number, value: Color): number;
    public fill(value: Color): void;
    public resize(new_size: number): number;
    public clear(): void;
    public has(value: Color): boolean;
    public reverse(): void;
    public slice(begin: number, end: number): PackedColorArray;
    public to_byte_array(): PackedByteArray;
    public sort(): void;
    public bsearch(value: Color, before: boolean): number;
    public duplicate(): PackedColorArray;
    public find(value: Color, _from: number): number;
    public rfind(value: Color, _from: number): number;
    public count(value: Color): number;
    public erase(value: Color): boolean;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public equals(right: PackedColorArray): boolean;
    public not_equals(right: PackedColorArray): boolean;
    public add(right: PackedColorArray): PackedColorArray;

}