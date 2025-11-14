
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { MultiplayerAPI } from '@godot/classes/multiplayer_api';
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { StringName } from '@godot/builtins/string_name';


export declare class MultiplayerAPIExtension extends MultiplayerAPI {


    public _poll(): number;
    public _set_multiplayer_peer(multiplayerPeer: MultiplayerPeer): void;
    public _get_multiplayer_peer(): MultiplayerPeer;
    public _get_unique_id(): number;
    public _get_peer_ids(): PackedInt32Array;
    public _rpc(peer: number, object: GodotObject, method: GDString | StringName | string, args: GDArray): number;
    public _get_remote_sender_id(): number;
    public _object_configuration_add(object: GodotObject, configuration: any): number;
    public _object_configuration_remove(object: GodotObject, configuration: any): number;


}

