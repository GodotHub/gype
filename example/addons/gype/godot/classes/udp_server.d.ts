
import type { PacketPeerUDP } from '@godot/classes/packet_peer_udp';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class UDPServer extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public max_pending_connections: number;
    public listen(port: number, bindAddress: GDString | StringName | string = "*"): number;
    public poll(): number;
    public is_connection_available(): boolean;
    public get_local_port(): number;
    public is_listening(): boolean;
    public take_connection(): PacketPeerUDP;
    public stop(): void;
    public set_max_pending_connections(maxPendingConnections: number): void;
    public get_max_pending_connections(): number;


}

