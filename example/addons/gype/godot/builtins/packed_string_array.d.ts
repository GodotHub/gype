
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';


export declare class PackedStringArray {
    constructor();
    constructor(_from: PackedStringArray);
    constructor(_from: GDArray);


    public get(index: number): GDString;
    public set(index: number, value: GDString | StringName | string): void;
    public size(): number;
    public is_empty(): boolean;
    public push_back(value: GDString | StringName | string): boolean;
    public append(value: GDString | StringName | string): boolean;
    public append_array(array: PackedStringArray): void;
    public remove_at(index: number): void;
    public insert(at_index: number, value: GDString | StringName | string): number;
    public fill(value: GDString | StringName | string): void;
    public resize(new_size: number): number;
    public clear(): void;
    public has(value: GDString | StringName | string): boolean;
    public reverse(): void;
    public slice(begin: number, end: number): PackedStringArray;
    public to_byte_array(): PackedByteArray;
    public sort(): void;
    public bsearch(value: GDString | StringName | string, before: boolean): number;
    public duplicate(): PackedStringArray;
    public find(value: GDString | StringName | string, _from: number): number;
    public rfind(value: GDString | StringName | string, _from: number): number;
    public count(value: GDString | StringName | string): number;
    public erase(value: GDString | StringName | string): boolean;

}