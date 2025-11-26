
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class PacketPeer extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public encode_buffer_max_size: number;
    public get_var(allowObjects: boolean = false): any;
    public put_var(_var: any, fullObjects: boolean = false): number;
    public get_packet(): PackedByteArray;
    public put_packet(buffer: PackedByteArray): number;
    public get_packet_error(): number;
    public get_available_packet_count(): number;
    public get_encode_buffer_max_size(): number;
    public set_encode_buffer_max_size(maxSize: number): void;


}

