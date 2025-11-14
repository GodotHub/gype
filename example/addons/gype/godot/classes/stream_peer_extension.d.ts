
import type { StreamPeer } from '@godot/classes/stream_peer';


export declare class StreamPeerExtension extends StreamPeer {


    public _get_data(rBuffer: any, rBytes: number, rReceived: any): number;
    public _get_partial_data(rBuffer: any, rBytes: number, rReceived: any): number;
    public _put_data(data: any, bytes: number, rSent: any): number;
    public _put_partial_data(data: any, bytes: number, rSent: any): number;
    public _get_available_bytes(): number;


}

