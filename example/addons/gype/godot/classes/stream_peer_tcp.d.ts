
import type { GDString } from '@godot/builtins/gd_string';
import type { StreamPeer } from '@godot/classes/stream_peer';


export declare class StreamPeerTCP extends StreamPeer {


    public bind(port: number, host: GDString | StringName | string = "*"): number;
    public connect_to_host(host: GDString | StringName | string, port: number): number;
    public poll(): number;
    public get_status(): number;
    public get_connected_host(): GDString;
    public get_connected_port(): number;
    public get_local_port(): number;
    public disconnect_from_host(): void;
    public set_no_delay(enabled: boolean): void;


    public static readonly Status: {
        STATUS_NONE: 0;
        STATUS_CONNECTING: 1;
        STATUS_CONNECTED: 2;
        STATUS_ERROR: 3;
    };
}

