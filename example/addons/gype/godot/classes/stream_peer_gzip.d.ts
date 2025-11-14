
import type { StreamPeer } from '@godot/classes/stream_peer';


export declare class StreamPeerGZIP extends StreamPeer {


    public start_compression(useDeflate: boolean = false, bufferSize: number = 65535): number;
    public start_decompression(useDeflate: boolean = false, bufferSize: number = 65535): number;
    public finish(): number;
    public clear(): void;


}

