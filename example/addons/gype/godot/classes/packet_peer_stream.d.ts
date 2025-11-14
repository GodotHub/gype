
import type { PacketPeer } from '@godot/classes/packet_peer';
import type { StreamPeer } from '@godot/classes/stream_peer';


export declare class PacketPeerStream extends PacketPeer {

    
    /**     * The raw type is 'int'     */
    public input_buffer_max_size: number;    
    /**     * The raw type is 'int'     */
    public output_buffer_max_size: number;    
    /**     * The raw type is 'StreamPeer'     */
    public stream_peer: StreamPeer;
    public set_stream_peer(peer: StreamPeer): void;
    public get_stream_peer(): StreamPeer;
    public set_input_buffer_max_size(maxSizeBytes: number): void;
    public set_output_buffer_max_size(maxSizeBytes: number): void;
    public get_input_buffer_max_size(): number;
    public get_output_buffer_max_size(): number;


}

