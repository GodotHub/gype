
import type { MultiplayerAPI } from '@godot/classes/multiplayer_api';


export declare class SceneMultiplayer extends MultiplayerAPI {

    
    /**     * The raw type is 'NodePath'     */
    public root_path: NodePath;    
    /**     * The raw type is 'Callable'     */
    public auth_callback: Callable;    
    /**     * The raw type is 'float'     */
    public auth_timeout: number;    
    /**     * The raw type is 'bool'     */
    public allow_object_decoding: boolean;    
    /**     * The raw type is 'bool'     */
    public refuse_new_connections: boolean;    
    /**     * The raw type is 'bool'     */
    public server_relay: boolean;    
    /**     * The raw type is 'int'     */
    public max_sync_packet_size: number;    
    /**     * The raw type is 'int'     */
    public max_delta_packet_size: number;
    public set_root_path(path: NodePath | GDString | string): void;
    public get_root_path(): NodePath;
    public clear(): void;
    public disconnect_peer(id: number): void;
    public get_authenticating_peers(): PackedInt32Array;
    public send_auth(id: number, data: PackedByteArray): number;
    public complete_auth(id: number): number;
    public set_auth_callback(callback: Callable | Function): void;
    public get_auth_callback(): Callable;
    public set_auth_timeout(timeout: number): void;
    public get_auth_timeout(): number;
    public set_refuse_new_connections(refuse: boolean): void;
    public is_refusing_new_connections(): boolean;
    public set_allow_object_decoding(enable: boolean): void;
    public is_object_decoding_allowed(): boolean;
    public set_server_relay_enabled(enabled: boolean): void;
    public is_server_relay_enabled(): boolean;
    public send_bytes(bytes: PackedByteArray, id: number = 0, mode: number = 2, channel: number = 0): number;
    public get_max_sync_packet_size(): number;
    public set_max_sync_packet_size(size: number): void;
    public get_max_delta_packet_size(): number;
    public set_max_delta_packet_size(size: number): void;

    
    public readonly peer_authenticating: Signal;
    public readonly peer_authentication_failed: Signal;
    public readonly peer_packet: Signal;

}

