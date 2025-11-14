
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


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

    
    public readonly peer_connected: Signal<(id: number) => void>;
    public readonly peer_disconnected: Signal<(id: number) => void>;
    public readonly connected_to_server: Signal<() => void>;
    public readonly connection_failed: Signal<() => void>;
    public readonly server_disconnected: Signal<() => void>;

    public static readonly RPCMode: {
        RPC_MODE_DISABLED: 0;
        RPC_MODE_ANY_PEER: 1;
        RPC_MODE_AUTHORITY: 2;
    };
}

