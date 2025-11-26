
import type { PacketPeer } from '@godot/classes/packet_peer';
import type { PacketPeerUDP } from '@godot/classes/packet_peer_udp';
import type { TLSOptions } from '@godot/classes/tls_options';


export declare class PacketPeerDTLS extends PacketPeer {


    public poll(): void;
    public connect_to_peer(packetPeer: PacketPeerUDP, hostname: GDString | StringName | string, clientOptions: TLSOptions = null): number;
    public get_status(): number;
    public disconnect_from_peer(): void;


    public static readonly Status: {
        STATUS_DISCONNECTED: 0;
        STATUS_HANDSHAKING: 1;
        STATUS_CONNECTED: 2;
        STATUS_ERROR: 3;
        STATUS_ERROR_HOSTNAME_MISMATCH: 4;
    };
}

