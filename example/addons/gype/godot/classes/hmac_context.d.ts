
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class HMACContext extends RefCounted {


    public start(hashType: number, key: PackedByteArray): number;
    public update(data: PackedByteArray): number;
    public finish(): PackedByteArray;


}

