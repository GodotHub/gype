
import type { StreamPeer } from '@godot/classes/stream_peer';


export declare class StreamPeerBuffer extends StreamPeer {

    
    /**     * The raw type is 'PackedByteArray'     */
    public data_array: PackedByteArray;
    public seek(position: number): void;
    public get_size(): number;
    public get_position(): number;
    public resize(size: number): void;
    public set_data_array(data: PackedByteArray): void;
    public get_data_array(): PackedByteArray;
    public clear(): void;
    public duplicate(): StreamPeerBuffer;


}

