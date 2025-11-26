
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class ZIPReader extends RefCounted {


    public open(path: GDString | StringName | string): number;
    public close(): number;
    public get_files(): PackedStringArray;
    public read_file(path: GDString | StringName | string, caseSensitive: boolean = true): PackedByteArray;
    public file_exists(path: GDString | StringName | string, caseSensitive: boolean = true): boolean;
    public get_compression_level(path: GDString | StringName | string, caseSensitive: boolean = true): number;


}

