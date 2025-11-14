
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { PacketPeer } from '@godot/classes/packet_peer';
import type { StreamPeer } from '@godot/classes/stream_peer';
import type { TLSOptions } from '@godot/classes/tls_options';


export declare class WebSocketPeer extends PacketPeer {

    
    /**     * The raw type is 'PackedStringArray'     */
    public supported_protocols: PackedStringArray;    
    /**     * The raw type is 'PackedStringArray'     */
    public handshake_headers: PackedStringArray;    
    /**     * The raw type is 'int'     */
    public inbound_buffer_size: number;    
    /**     * The raw type is 'int'     */
    public outbound_buffer_size: number;    
    /**     * The raw type is 'int'     */
    public max_queued_packets: number;    
    /**     * The raw type is 'int'     */
    public heartbeat_interval: number;
    public connect_to_url(url: GDString | StringName | string, tlsClientOptions: TLSOptions = null): number;
    public accept_stream(stream: StreamPeer): number;
    public send(message: PackedByteArray, writeMode: number = 1): number;
    public send_text(message: GDString | StringName | string): number;
    public was_string_packet(): boolean;
    public poll(): void;
    public close(code: number = 1000, reason: GDString | StringName | string = ""): void;
    public get_connected_host(): GDString;
    public get_connected_port(): number;
    public get_selected_protocol(): GDString;
    public get_requested_url(): GDString;
    public set_no_delay(enabled: boolean): void;
    public get_current_outbound_buffered_amount(): number;
    public get_ready_state(): number;
    public get_close_code(): number;
    public get_close_reason(): GDString;
    public get_supported_protocols(): PackedStringArray;
    public set_supported_protocols(protocols: PackedStringArray): void;
    public get_handshake_headers(): PackedStringArray;
    public set_handshake_headers(protocols: PackedStringArray): void;
    public get_inbound_buffer_size(): number;
    public set_inbound_buffer_size(bufferSize: number): void;
    public get_outbound_buffer_size(): number;
    public set_outbound_buffer_size(bufferSize: number): void;
    public set_max_queued_packets(bufferSize: number): void;
    public get_max_queued_packets(): number;
    public set_heartbeat_interval(interval: number): void;
    public get_heartbeat_interval(): number;


    public static readonly WriteMode: {
        WRITE_MODE_TEXT: 0;
        WRITE_MODE_BINARY: 1;
    };
    public static readonly State: {
        STATE_CONNECTING: 0;
        STATE_OPEN: 1;
        STATE_CLOSING: 2;
        STATE_CLOSED: 3;
    };
}

