
import type { RefCounted } from '@godot/classes/ref_counted';
import type { WebRTCDataChannel } from '@godot/classes/web_rtc_data_channel';


export declare class WebRTCPeerConnection extends RefCounted {


    public static set_default_extension(extensionClass: GDString | StringName | string): void;
    public initialize(configuration: Dictionary = {}): number;
    public create_data_channel(label: GDString | StringName | string, options: Dictionary = {}): WebRTCDataChannel;
    public create_offer(): number;
    public set_local_description(_type: GDString | StringName | string, sdp: GDString | StringName | string): number;
    public set_remote_description(_type: GDString | StringName | string, sdp: GDString | StringName | string): number;
    public add_ice_candidate(media: GDString | StringName | string, index: number, name: GDString | StringName | string): number;
    public poll(): number;
    public close(): void;
    public get_connection_state(): number;
    public get_gathering_state(): number;
    public get_signaling_state(): number;

    
    public readonly session_description_created: Signal<(_type: GDString | StringName | string, sdp: GDString | StringName | string) => void>;
    public readonly ice_candidate_created: Signal<(media: GDString | StringName | string, index: number, name: GDString | StringName | string) => void>;
    public readonly data_channel_received: Signal<(channel: WebRTCDataChannel) => void>;

    public static readonly ConnectionState: {
        STATE_NEW: 0;
        STATE_CONNECTING: 1;
        STATE_CONNECTED: 2;
        STATE_DISCONNECTED: 3;
        STATE_FAILED: 4;
        STATE_CLOSED: 5;
    };
    public static readonly GatheringState: {
        GATHERING_STATE_NEW: 0;
        GATHERING_STATE_GATHERING: 1;
        GATHERING_STATE_COMPLETE: 2;
    };
    public static readonly SignalingState: {
        SIGNALING_STATE_STABLE: 0;
        SIGNALING_STATE_HAVE_LOCAL_OFFER: 1;
        SIGNALING_STATE_HAVE_REMOTE_OFFER: 2;
        SIGNALING_STATE_HAVE_LOCAL_PRANSWER: 3;
        SIGNALING_STATE_HAVE_REMOTE_PRANSWER: 4;
        SIGNALING_STATE_CLOSED: 5;
    };
}

