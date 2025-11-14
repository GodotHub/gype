
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { StreamPeerTCP } from '@godot/classes/stream_peer_tcp';


export declare class TCPServer extends RefCounted {


    public listen(port: number, bindAddress: GDString | StringName | string = "*"): number;
    public is_connection_available(): boolean;
    public is_listening(): boolean;
    public get_local_port(): number;
    public take_connection(): StreamPeerTCP;
    public stop(): void;


}

