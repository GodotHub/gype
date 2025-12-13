
import type { AudioStream } from '@godot/classes/audio_stream';
import type { AudioStreamPlayback } from '@godot/classes/audio_stream_playback';
import type { Node2D } from '@godot/classes/node2d';


export declare class AudioStreamPlayer2D extends Node2D {

    
    /**     * The raw type is 'AudioStream'     */
    public stream: AudioStream;    
    /**     * The raw type is 'float'     */
    public volume_db: number;    
    /**     * The raw type is 'float'     */
    public volume_linear: number;    
    /**     * The raw type is 'float'     */
    public pitch_scale: number;    
    /**     * The raw type is 'bool'     */
    public playing: boolean;    
    /**     * The raw type is 'bool'     */
    public autoplay: boolean;    
    /**     * The raw type is 'bool'     */
    public stream_paused: boolean;    
    /**     * The raw type is 'float'     */
    public max_distance: number;    
    /**     * The raw type is 'float'     */
    public attenuation: number;    
    /**     * The raw type is 'int'     */
    public max_polyphony: number;    
    /**     * The raw type is 'float'     */
    public panning_strength: number;    
    /**     * The raw type is 'StringName'     */
    public bus: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public area_mask: number;    
    /**     * The raw type is 'int'     */
    public playback_type: number;
    public set_stream(stream: AudioStream): void;
    public get_stream(): AudioStream;
    public set_volume_db(volumeDb: number): void;
    public get_volume_db(): number;
    public set_volume_linear(volumeLinear: number): void;
    public get_volume_linear(): number;
    public set_pitch_scale(pitchScale: number): void;
    public get_pitch_scale(): number;
    public play(fromPosition: number = 0.0): void;
    public seek(toPosition: number): void;
    public stop(): void;
    public is_playing(): boolean;
    public get_playback_position(): number;
    public set_bus(bus: GDString | StringName | string): void;
    public get_bus(): StringName;
    public set_autoplay(enable: boolean): void;
    public is_autoplay_enabled(): boolean;
    public set_playing(enable: boolean): void;
    public set_max_distance(pixels: number): void;
    public get_max_distance(): number;
    public set_attenuation(curve: number): void;
    public get_attenuation(): number;
    public set_area_mask(mask: number): void;
    public get_area_mask(): number;
    public set_stream_paused(pause: boolean): void;
    public get_stream_paused(): boolean;
    public set_max_polyphony(maxPolyphony: number): void;
    public get_max_polyphony(): number;
    public set_panning_strength(panningStrength: number): void;
    public get_panning_strength(): number;
    public has_stream_playback(): boolean;
    public get_stream_playback(): AudioStreamPlayback;
    public set_playback_type(playbackType: number): void;
    public get_playback_type(): number;

    
    public readonly finished: Signal<() => void>;

}

