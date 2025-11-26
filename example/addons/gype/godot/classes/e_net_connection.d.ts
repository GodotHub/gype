
import type { ENetPacketPeer } from '@godot/classes/e_net_packet_peer';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { TLSOptions } from '@godot/classes/tls_options';


export declare class ENetConnection extends RefCounted {


    public create_host_bound(bindAddress: GDString | StringName | string, bindPort: number, maxPeers: number = 32, maxChannels: number = 0, inBandwidth: number = 0, outBandwidth: number = 0): number;
    public create_host(maxPeers: number = 32, maxChannels: number = 0, inBandwidth: number = 0, outBandwidth: number = 0): number;
    public destroy(): void;
    public connect_to_host(address: GDString | StringName | string, port: number, channels: number = 0, data: number = 0): ENetPacketPeer;
    public service(timeout: number = 0): GDArray;
    public flush(): void;
    public bandwidth_limit(inBandwidth: number = 0, outBandwidth: number = 0): void;
    public channel_limit(limit: number): void;
    public broadcast(channel: number, packet: PackedByteArray, flags: number): void;
    public compress(mode: number): void;
    public dtls_server_setup(serverOptions: TLSOptions): number;
    public dtls_client_setup(hostname: GDString | StringName | string, clientOptions: TLSOptions = null): number;
    public refuse_new_connections(refuse: boolean): void;
    public pop_statistic(statistic: number): number;
    public get_max_channels(): number;
    public get_local_port(): number;
    public get_peers(): Array<any>;
    public socket_send(destinationAddress: GDString | StringName | string, destinationPort: number, packet: PackedByteArray): void;


    public static readonly CompressionMode: {
        COMPRESS_NONE: 0;
        COMPRESS_RANGE_CODER: 1;
        COMPRESS_FASTLZ: 2;
        COMPRESS_ZLIB: 3;
        COMPRESS_ZSTD: 4;
    };
    public static readonly EventType: {
        EVENT_ERROR: -1;
        EVENT_NONE: 0;
        EVENT_CONNECT: 1;
        EVENT_DISCONNECT: 2;
        EVENT_RECEIVE: 3;
    };
    public static readonly HostStatistic: {
        HOST_TOTAL_SENT_DATA: 0;
        HOST_TOTAL_SENT_PACKETS: 1;
        HOST_TOTAL_RECEIVED_DATA: 2;
        HOST_TOTAL_RECEIVED_PACKETS: 3;
    };
}

