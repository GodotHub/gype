
import type { GDString } from '@godot/builtins/gd_string';
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { TLSOptions } from '@godot/classes/tls_options';
import type { WebSocketPeer } from '@godot/classes/web_socket_peer';


export declare class WebSocketMultiplayerPeer extends MultiplayerPeer {

    
    /**     * The raw type is 'PackedStringArray'     */
    public supported_protocols: PackedStringArray;    
    /**     * The raw type is 'PackedStringArray'     */
    public handshake_headers: PackedStringArray;    
    /**     * The raw type is 'int'     */
    public inbound_buffer_size: number;    
    /**     * The raw type is 'int'     */
    public outbound_buffer_size: number;    
    /**     * The raw type is 'float'     */
    public handshake_timeout: number;    
    /**     * The raw type is 'int'     */
    public max_queued_packets: number;
    public create_client(url: GDString | StringName | string, tlsClientOptions: TLSOptions = null): number;
    public create_server(port: number, bindAddress: GDString | StringName | string = "*", tlsServerOptions: TLSOptions = null): number;
    public get_peer(peerId: number): WebSocketPeer;
    public get_peer_address(id: number): GDString;
    public get_peer_port(id: number): number;
    public get_supported_protocols(): PackedStringArray;
    public set_supported_protocols(protocols: PackedStringArray): void;
    public get_handshake_headers(): PackedStringArray;
    public set_handshake_headers(protocols: PackedStringArray): void;
    public get_inbound_buffer_size(): number;
    public set_inbound_buffer_size(bufferSize: number): void;
    public get_outbound_buffer_size(): number;
    public set_outbound_buffer_size(bufferSize: number): void;
    public get_handshake_timeout(): number;
    public set_handshake_timeout(timeout: number): void;
    public set_max_queued_packets(maxQueuedPackets: number): void;
    public get_max_queued_packets(): number;


}

