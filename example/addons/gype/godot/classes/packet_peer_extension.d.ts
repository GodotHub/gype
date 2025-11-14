
import type { PacketPeer } from '@godot/classes/packet_peer';


export declare class PacketPeerExtension extends PacketPeer {


    public _get_packet(rBuffer: any, rBufferSize: any): number;
    public _put_packet(buffer: any, bufferSize: number): number;
    public _get_available_packet_count(): number;
    public _get_max_packet_size(): number;


}

