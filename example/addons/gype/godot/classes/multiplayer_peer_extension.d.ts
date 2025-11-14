
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';


export declare class MultiplayerPeerExtension extends MultiplayerPeer {


    public _get_packet(rBuffer: any, rBufferSize: any): number;
    public _put_packet(buffer: any, bufferSize: number): number;
    public _get_available_packet_count(): number;
    public _get_max_packet_size(): number;
    public _get_packet_script(): PackedByteArray;
    public _put_packet_script(buffer: PackedByteArray): number;
    public _get_packet_channel(): number;
    public _get_packet_mode(): number;
    public _set_transfer_channel(channel: number): void;
    public _get_transfer_channel(): number;
    public _set_transfer_mode(mode: number): void;
    public _get_transfer_mode(): number;
    public _set_target_peer(peer: number): void;
    public _get_packet_peer(): number;
    public _is_server(): boolean;
    public _poll(): void;
    public _close(): void;
    public _disconnect_peer(peer: number, force: boolean): void;
    public _get_unique_id(): number;
    public _set_refuse_new_connections(enable: boolean): void;
    public _is_refusing_new_connections(): boolean;
    public _is_server_relay_supported(): boolean;
    public _get_connection_status(): number;


}

