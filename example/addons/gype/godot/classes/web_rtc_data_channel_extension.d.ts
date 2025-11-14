
import type { GDString } from '@godot/builtins/gd_string';
import type { WebRTCDataChannel } from '@godot/classes/web_rtc_data_channel';


export declare class WebRTCDataChannelExtension extends WebRTCDataChannel {


    public _get_packet(rBuffer: any, rBufferSize: any): number;
    public _put_packet(buffer: any, bufferSize: number): number;
    public _get_available_packet_count(): number;
    public _get_max_packet_size(): number;
    public _poll(): number;
    public _close(): void;
    public _set_write_mode(writeMode: number): void;
    public _get_write_mode(): number;
    public _was_string_packet(): boolean;
    public _get_ready_state(): number;
    public _get_label(): GDString;
    public _is_ordered(): boolean;
    public _get_id(): number;
    public _get_max_packet_life_time(): number;
    public _get_max_retransmits(): number;
    public _get_protocol(): GDString;
    public _is_negotiated(): boolean;
    public _get_buffered_amount(): number;


}

