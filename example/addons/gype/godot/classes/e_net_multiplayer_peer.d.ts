
import type { ENetConnection } from '@godot/classes/e_net_connection';
import type { ENetPacketPeer } from '@godot/classes/e_net_packet_peer';
import type { GDString } from '@godot/builtins/gd_string';
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';


export declare class ENetMultiplayerPeer extends MultiplayerPeer {

    
    /**     * The raw type is 'ENetConnection'     */
    public host: ENetConnection;
    public create_server(port: number, maxClients: number = 32, maxChannels: number = 0, inBandwidth: number = 0, outBandwidth: number = 0): number;
    public create_client(address: GDString | StringName | string, port: number, channelCount: number = 0, inBandwidth: number = 0, outBandwidth: number = 0, localPort: number = 0): number;
    public create_mesh(uniqueId: number): number;
    public add_mesh_peer(peerId: number, host: ENetConnection): number;
    public set_bind_ip(ip: GDString | StringName | string): void;
    public get_host(): ENetConnection;
    public get_peer(id: number): ENetPacketPeer;


}

