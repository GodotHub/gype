
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class HashingContext extends RefCounted {


    public start(_type: number): number;
    public update(chunk: PackedByteArray): number;
    public finish(): PackedByteArray;


    public static readonly HashType: {
        HASH_MD5: 0;
        HASH_SHA1: 1;
        HASH_SHA256: 2;
    };
}

