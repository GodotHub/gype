
import type { PacketPeer } from '@godot/classes/packet_peer';


export declare class MultiplayerPeer extends PacketPeer {

    
    /**     * The raw type is 'bool'     */
    public refuse_new_connections: boolean;    
    /**     * The raw type is 'int'     */
    public transfer_mode: number;    
    /**     * The raw type is 'int'     */
    public transfer_channel: number;
    public set_transfer_channel(channel: number): void;
    public get_transfer_channel(): number;
    public set_transfer_mode(mode: number): void;
    public get_transfer_mode(): number;
    public set_target_peer(id: number): void;
    public get_packet_peer(): number;
    public get_packet_channel(): number;
    public get_packet_mode(): number;
    public poll(): void;
    public close(): void;
    public disconnect_peer(peer: number, force: boolean = false): void;
    public get_connection_status(): number;
    public get_unique_id(): number;
    public generate_unique_id(): number;
    public set_refuse_new_connections(enable: boolean): void;
    public is_refusing_new_connections(): boolean;
    public is_server_relay_supported(): boolean;

    
    public readonly peer_connected: Signal;
    public readonly peer_disconnected: Signal;

    public static readonly ConnectionStatus: {
        CONNECTION_DISCONNECTED: 0;
        CONNECTION_CONNECTING: 1;
        CONNECTION_CONNECTED: 2;
    };
    public static readonly TransferMode: {
        TRANSFER_MODE_UNRELIABLE: 0;
        TRANSFER_MODE_UNRELIABLE_ORDERED: 1;
        TRANSFER_MODE_RELIABLE: 2;
    };
}

