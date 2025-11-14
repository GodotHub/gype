
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ZIPReader extends RefCounted {


    public open(path: GDString | StringName | string): number;
    public close(): number;
    public get_files(): PackedStringArray;
    public read_file(path: GDString | StringName | string, caseSensitive: boolean = true): PackedByteArray;
    public file_exists(path: GDString | StringName | string, caseSensitive: boolean = true): boolean;
    public get_compression_level(path: GDString | StringName | string, caseSensitive: boolean = true): number;


}

