
import type { PacketPeerDTLS } from '@godot/classes/packet_peer_dtls';
import type { PacketPeerUDP } from '@godot/classes/packet_peer_udp';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { TLSOptions } from '@godot/classes/tls_options';


export declare class DTLSServer extends RefCounted {


    public setup(serverOptions: TLSOptions): number;
    public take_connection(udpeer: PacketPeerUDP): PacketPeerDTLS;


}

