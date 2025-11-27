
import type { MultiplayerPeer } from '@godot/classes/multiplayer_peer';
import type { WebRTCPeerConnection } from '@godot/classes/web_rtc_peer_connection';


export declare class WebRTCMultiplayerPeer extends MultiplayerPeer {


    public create_server(channelsConfig: GDArray | Array = []): number;
    public create_client(peerId: number, channelsConfig: GDArray | Array = []): number;
    public create_mesh(peerId: number, channelsConfig: GDArray | Array = []): number;
    public add_peer(peer: WebRTCPeerConnection, peerId: number, unreliableLifetime: number = 1): number;
    public remove_peer(peerId: number): void;
    public has_peer(peerId: number): boolean;
    public get_peer(peerId: number): Dictionary;
    public get_peers(): Dictionary;


}

