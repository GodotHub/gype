
import type { GDString } from '@godot/builtins/gd_string';
import type { StreamPeer } from '@godot/classes/stream_peer';
import type { TLSOptions } from '@godot/classes/tls_options';


export declare class StreamPeerTLS extends StreamPeer {


    public poll(): void;
    public accept_stream(stream: StreamPeer, serverOptions: TLSOptions): number;
    public connect_to_stream(stream: StreamPeer, commonName: GDString | StringName | string, clientOptions: TLSOptions = null): number;
    public get_status(): number;
    public get_stream(): StreamPeer;
    public disconnect_from_stream(): void;


    public static readonly Status: {
        STATUS_DISCONNECTED: 0;
        STATUS_HANDSHAKING: 1;
        STATUS_CONNECTED: 2;
        STATUS_ERROR: 3;
        STATUS_ERROR_HOSTNAME_MISMATCH: 4;
    };
}

