
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class AESContext extends RefCounted {


    public start(mode: number, key: PackedByteArray, iv: PackedByteArray = PackedByteArray()): number;
    public update(src: PackedByteArray): PackedByteArray;
    public get_iv_state(): PackedByteArray;
    public finish(): void;


    public static readonly Mode: {
        MODE_ECB_ENCRYPT: 0;
        MODE_ECB_DECRYPT: 1;
        MODE_CBC_ENCRYPT: 2;
        MODE_CBC_DECRYPT: 3;
        MODE_MAX: 4;
    };
}

