
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class FileAccess extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public big_endian: boolean;
    public static open(path: GDString | StringName | string, flags: number): FileAccess;
    public static open_encrypted(path: GDString | StringName | string, modeFlags: number, key: PackedByteArray, iv: PackedByteArray = PackedByteArray()): FileAccess;
    public static open_encrypted_with_pass(path: GDString | StringName | string, modeFlags: number, pass: GDString | StringName | string): FileAccess;
    public static open_compressed(path: GDString | StringName | string, modeFlags: number, compressionMode: number = 0): FileAccess;
    public static get_open_error(): number;
    public static create_temp(modeFlags: number, prefix: GDString | StringName | string = "", extension: GDString | StringName | string = "", keep: boolean = false): FileAccess;
    public static get_file_as_bytes(path: GDString | StringName | string): PackedByteArray;
    public static get_file_as_string(path: GDString | StringName | string): GDString;
    public resize(length: number): number;
    public flush(): void;
    public get_path(): GDString;
    public get_path_absolute(): GDString;
    public is_open(): boolean;
    public seek(position: number): void;
    public seek_end(position: number = 0): void;
    public get_position(): number;
    public get_length(): number;
    public eof_reached(): boolean;
    public get_8(): number;
    public get_16(): number;
    public get_32(): number;
    public get_64(): number;
    public get_half(): number;
    public get_float(): number;
    public get_double(): number;
    public get_real(): number;
    public get_buffer(length: number): PackedByteArray;
    public get_line(): GDString;
    public get_csv_line(delim: GDString | StringName | string = ","): PackedStringArray;
    public get_as_text(skicr: boolean = false): GDString;
    public static get_md5(path: GDString | StringName | string): GDString;
    public static get_sha256(path: GDString | StringName | string): GDString;
    public is_big_endian(): boolean;
    public set_big_endian(bigEndian: boolean): void;
    public get_error(): number;
    public get_var(allowObjects: boolean = false): any;
    public store_8(value: number): boolean;
    public store_16(value: number): boolean;
    public store_32(value: number): boolean;
    public store_64(value: number): boolean;
    public store_half(value: number): boolean;
    public store_float(value: number): boolean;
    public store_double(value: number): boolean;
    public store_real(value: number): boolean;
    public store_buffer(buffer: PackedByteArray): boolean;
    public store_line(line: GDString | StringName | string): boolean;
    public store_csv_line(values: PackedStringArray, delim: GDString | StringName | string = ","): boolean;
    public store_string(_string: GDString | StringName | string): boolean;
    public store_var(value: any, fullObjects: boolean = false): boolean;
    public store_pascal_string(_string: GDString | StringName | string): boolean;
    public get_pascal_string(): GDString;
    public close(): void;
    public static file_exists(path: GDString | StringName | string): boolean;
    public static get_modified_time(file: GDString | StringName | string): number;
    public static get_access_time(file: GDString | StringName | string): number;
    public static get_size(file: GDString | StringName | string): number;
    public static get_unix_permissions(file: GDString | StringName | string): number;
    public static set_unix_permissions(file: GDString | StringName | string, permissions: number): number;
    public static get_hidden_attribute(file: GDString | StringName | string): boolean;
    public static set_hidden_attribute(file: GDString | StringName | string, hidden: boolean): number;
    public static set_read_only_attribute(file: GDString | StringName | string, ro: boolean): number;
    public static get_read_only_attribute(file: GDString | StringName | string): boolean;


    public static readonly ModeFlags: {
        READ: 1;
        WRITE: 2;
        READ_WRITE: 3;
        WRITE_READ: 7;
    };
    public static readonly CompressionMode: {
        COMPRESSION_FASTLZ: 0;
        COMPRESSION_DEFLATE: 1;
        COMPRESSION_ZSTD: 2;
        COMPRESSION_GZIP: 3;
        COMPRESSION_BROTLI: 4;
    };
    public static readonly UnixPermissionFlags: {
        UNIX_READ_OWNER: 256;
        UNIX_WRITE_OWNER: 128;
        UNIX_EXECUTE_OWNER: 64;
        UNIX_READ_GROUP: 32;
        UNIX_WRITE_GROUP: 16;
        UNIX_EXECUTE_GROUP: 8;
        UNIX_READ_OTHER: 4;
        UNIX_WRITE_OTHER: 2;
        UNIX_EXECUTE_OTHER: 1;
        UNIX_SET_USER_ID: 2048;
        UNIX_SET_GROUP_ID: 1024;
        UNIX_RESTRICTED_DELETE: 512;
    };
}

