
import type { PacketPeer } from '@godot/classes/packet_peer';


export declare class PacketPeerUDP extends PacketPeer {


    public bind(port: number, bindAddress: GDString | StringName | string = "*", recvBufSize: number = 65536): number;
    public close(): void;
    public wait(): number;
    public is_bound(): boolean;
    public connect_to_host(host: GDString | StringName | string, port: number): number;
    public is_socket_connected(): boolean;
    public get_packet_ip(): GDString;
    public get_packet_port(): number;
    public get_local_port(): number;
    public set_dest_address(host: GDString | StringName | string, port: number): number;
    public set_broadcast_enabled(enabled: boolean): void;
    public join_multicast_group(multicastAddress: GDString | StringName | string, interfaceName: GDString | StringName | string): number;
    public leave_multicast_group(multicastAddress: GDString | StringName | string, interfaceName: GDString | StringName | string): number;


}

