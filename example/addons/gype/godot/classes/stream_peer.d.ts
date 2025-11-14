
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class StreamPeer extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public big_endian: boolean;
    public put_data(data: PackedByteArray): number;
    public put_partial_data(data: PackedByteArray): GDArray;
    public get_data(bytes: number): GDArray;
    public get_partial_data(bytes: number): GDArray;
    public get_available_bytes(): number;
    public set_big_endian(enable: boolean): void;
    public is_big_endian_enabled(): boolean;
    public put_8(value: number): void;
    public put_u8(value: number): void;
    public put_16(value: number): void;
    public put_u16(value: number): void;
    public put_32(value: number): void;
    public put_u32(value: number): void;
    public put_64(value: number): void;
    public put_u64(value: number): void;
    public put_half(value: number): void;
    public put_float(value: number): void;
    public put_double(value: number): void;
    public put_string(value: GDString | StringName | string): void;
    public put_utf8_string(value: GDString | StringName | string): void;
    public put_var(value: any, fullObjects: boolean = false): void;
    public get_8(): number;
    public get_u8(): number;
    public get_16(): number;
    public get_u16(): number;
    public get_32(): number;
    public get_u32(): number;
    public get_64(): number;
    public get_u64(): number;
    public get_half(): number;
    public get_float(): number;
    public get_double(): number;
    public get_string(bytes: number = -1): GDString;
    public get_utf8_string(bytes: number = -1): GDString;
    public get_var(allowObjects: boolean = false): any;


}

