
import type { WebRTCDataChannel } from '@godot/classes/web_rtc_data_channel';
import type { WebRTCPeerConnection } from '@godot/classes/web_rtc_peer_connection';


export declare class WebRTCPeerConnectionExtension extends WebRTCPeerConnection {


    public _get_connection_state(): number;
    public _get_gathering_state(): number;
    public _get_signaling_state(): number;
    public _initialize(config: Dictionary): number;
    public _create_data_channel(label: GDString | StringName | string, config: Dictionary): WebRTCDataChannel;
    public _create_offer(): number;
    public _set_remote_description(_type: GDString | StringName | string, sdp: GDString | StringName | string): number;
    public _set_local_description(_type: GDString | StringName | string, sdp: GDString | StringName | string): number;
    public _add_ice_candidate(sdmidName: GDString | StringName | string, sdmlineIndex: number, sdname: GDString | StringName | string): number;
    public _poll(): number;
    public _close(): void;


}

