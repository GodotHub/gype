
import type { GodotObject } from '@godot/classes/godot_object';
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class MultiplayerAPI extends RefCounted {

    
    /**     * The raw type is 'MultiplayerPeer'     */
    public multiplayer_peer: MultiplayerPeer;
    public has_multiplayer_peer(): boolean;
    public get_multiplayer_peer(): MultiplayerPeer;
    public set_multiplayer_peer(peer: MultiplayerPeer): void;
    public get_unique_id(): number;
    public is_server(): boolean;
    public get_remote_sender_id(): number;
    public poll(): number;
    public rpc(peer: number, object: GodotObject, method: GDString | StringName | string, arguments: GDArray = []): number;
    public object_configuration_add(object: GodotObject, configuration: any): number;
    public object_configuration_remove(object: GodotObject, configuration: any): number;
    public get_peers(): PackedInt32Array;
    public static set_default_interface(interfaceName: GDString | StringName | string): void;
    public static get_default_interface(): StringName;
    public static create_default_interface(): MultiplayerAPI;

    
    public readonly peer_connected: Signal;
    public readonly peer_disconnected: Signal;
    public readonly connected_to_server: Signal;
    public readonly connection_failed: Signal;
    public readonly server_disconnected: Signal;

    public static readonly RPCMode: {
        RPC_MODE_DISABLED: 0;
        RPC_MODE_ANY_PEER: 1;
        RPC_MODE_AUTHORITY: 2;
    };
}

