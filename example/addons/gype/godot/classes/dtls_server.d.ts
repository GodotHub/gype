
import { RefCounted } from "@godot/classes/ref_counted";
import { TLSOptions } from "@godot/classes/tls_options";
import { PacketPeerDTLS } from "@godot/classes/packet_peer_dtls";
import { PacketPeerUDP } from "@godot/classes/packet_peer_udp";

export declare class DTLSServer extends RefCounted{
  public setup(_server_options: TLSOptions): number;
  public take_connection(_udp_peer: PacketPeerUDP): PacketPeerDTLS;
}