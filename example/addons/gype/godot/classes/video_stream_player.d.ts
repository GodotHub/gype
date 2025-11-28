
import type { Control } from '@godot/classes/control';
import type { Texture2D } from '@godot/classes/texture2d';
import type { VideoStream } from '@godot/classes/video_stream';


export declare class VideoStreamPlayer extends Control {

    
    /**     * The raw type is 'int'     */
    public audio_track: number;    
    /**     * The raw type is 'VideoStream'     */
    public stream: VideoStream;    
    /**     * The raw type is 'float'     */
    public volume_db: number;    
    /**     * The raw type is 'float'     */
    public volume: number;    
    /**     * The raw type is 'float'     */
    public speed_scale: number;    
    /**     * The raw type is 'bool'     */
    public autoplay: boolean;    
    /**     * The raw type is 'bool'     */
    public paused: boolean;    
    /**     * The raw type is 'bool'     */
    public expand: boolean;    
    /**     * The raw type is 'bool'     */
    public loop: boolean;    
    /**     * The raw type is 'int'     */
    public buffering_msec: number;    
    /**     * The raw type is 'float'     */
    public stream_position: number;    
    /**     * The raw type is 'StringName'     */
    public bus: GDString | StringName | string;
    public set_stream(stream: VideoStream): void;
    public get_stream(): VideoStream;
    public play(): void;
    public stop(): void;
    public is_playing(): boolean;
    public set_paused(paused: boolean): void;
    public is_paused(): boolean;
    public set_loop(loop: boolean): void;
    public has_loop(): boolean;
    public set_volume(volume: number): void;
    public get_volume(): number;
    public set_volume_db(db: number): void;
    public get_volume_db(): number;
    public set_speed_scale(speedScale: number): void;
    public get_speed_scale(): number;
    public set_audio_track(track: number): void;
    public get_audio_track(): number;
    public get_stream_name(): GDString;
    public get_stream_length(): number;
    public set_stream_position(position: number): void;
    public get_stream_position(): number;
    public set_autoplay(enabled: boolean): void;
    public has_autoplay(): boolean;
    public set_expand(enable: boolean): void;
    public has_expand(): boolean;
    public set_buffering_msec(msec: number): void;
    public get_buffering_msec(): number;
    public set_bus(bus: GDString | StringName | string): void;
    public get_bus(): StringName;
    public get_video_texture(): Texture2D;

    
    public readonly finished: Signal;

}

