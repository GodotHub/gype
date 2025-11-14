
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ZIPPacker extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public compression_level: number;
    public open(path: GDString | StringName | string, append: number = 0): number;
    public set_compression_level(compressionLevel: number): void;
    public get_compression_level(): number;
    public start_file(path: GDString | StringName | string): number;
    public write_file(data: PackedByteArray): number;
    public close_file(): number;
    public close(): number;


    public static readonly ZipAppend: {
        APPEND_CREATE: 0;
        APPEND_CREATEAFTER: 1;
        APPEND_ADDINZIP: 2;
    };
    public static readonly CompressionLevel: {
        COMPRESSION_DEFAULT: -1;
        COMPRESSION_NONE: 0;
        COMPRESSION_FAST: 1;
        COMPRESSION_BEST: 9;
    };
}

