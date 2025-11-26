
import type { PacketPeer } from '@godot/classes/packet_peer';


export declare class ENetPacketPeer extends PacketPeer {


    public peer_disconnect(data: number = 0): void;
    public peer_disconnect_later(data: number = 0): void;
    public peer_disconnect_now(data: number = 0): void;
    public ping(): void;
    public ping_interval(pingInterval: number): void;
    public reset(): void;
    public send(channel: number, packet: PackedByteArray, flags: number): number;
    public throttle_configure(interval: number, acceleration: number, deceleration: number): void;
    public set_timeout(timeout: number, timeoutMin: number, timeoutMax: number): void;
    public get_packet_flags(): number;
    public get_remote_address(): GDString;
    public get_remote_port(): number;
    public get_statistic(statistic: number): number;
    public get_state(): number;
    public get_channels(): number;
    public is_active(): boolean;


    public static readonly PeerState: {
        STATE_DISCONNECTED: 0;
        STATE_CONNECTING: 1;
        STATE_ACKNOWLEDGING_CONNECT: 2;
        STATE_CONNECTION_PENDING: 3;
        STATE_CONNECTION_SUCCEEDED: 4;
        STATE_CONNECTED: 5;
        STATE_DISCONNECT_LATER: 6;
        STATE_DISCONNECTING: 7;
        STATE_ACKNOWLEDGING_DISCONNECT: 8;
        STATE_ZOMBIE: 9;
    };
    public static readonly PeerStatistic: {
        PEER_PACKET_LOSS: 0;
        PEER_PACKET_LOSS_VARIANCE: 1;
        PEER_PACKET_LOSS_EPOCH: 2;
        PEER_ROUND_TRIP_TIME: 3;
        PEER_ROUND_TRIP_TIME_VARIANCE: 4;
        PEER_LAST_ROUND_TRIP_TIME: 5;
        PEER_LAST_ROUND_TRIP_TIME_VARIANCE: 6;
        PEER_PACKET_THROTTLE: 7;
        PEER_PACKET_THROTTLE_LIMIT: 8;
        PEER_PACKET_THROTTLE_COUNTER: 9;
        PEER_PACKET_THROTTLE_EPOCH: 10;
        PEER_PACKET_THROTTLE_ACCELERATION: 11;
        PEER_PACKET_THROTTLE_DECELERATION: 12;
        PEER_PACKET_THROTTLE_INTERVAL: 13;
    };
}

