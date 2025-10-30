
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PackedVector3Array {
    constructor();
    constructor(_from: PackedVector3Array);
    constructor(_from: GDArray);


    public get(index: number): Vector3;
    public set(index: number, value: Vector3): void;
    public size(): number;
    public is_empty(): boolean;
    public push_back(value: Vector3): boolean;
    public append(value: Vector3): boolean;
    public append_array(array: PackedVector3Array): void;
    public remove_at(index: number): void;
    public insert(at_index: number, value: Vector3): number;
    public fill(value: Vector3): void;
    public resize(new_size: number): number;
    public clear(): void;
    public has(value: Vector3): boolean;
    public reverse(): void;
    public slice(begin: number, end: number): PackedVector3Array;
    public to_byte_array(): PackedByteArray;
    public sort(): void;
    public bsearch(value: Vector3, before: boolean): number;
    public duplicate(): PackedVector3Array;
    public find(value: Vector3, _from: number): number;
    public rfind(value: Vector3, _from: number): number;
    public count(value: Vector3): number;
    public erase(value: Vector3): boolean;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public multiply(right: Transform3D): PackedVector3Array;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public equals(right: PackedVector3Array): boolean;
    public not_equals(right: PackedVector3Array): boolean;
    public add(right: PackedVector3Array): PackedVector3Array;

}