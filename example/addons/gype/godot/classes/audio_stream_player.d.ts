
import type { AudioStream } from '@godot/classes/audio_stream';
import type { AudioStreamPlayback } from '@godot/classes/audio_stream_playback';
import type { GDString } from '@godot/builtins/gd_string';
import type { Node } from '@godot/classes/node';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class AudioStreamPlayer extends Node {

    
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
    /**     * The raw type is 'int'     */
    public mix_target: number;    
    /**     * The raw type is 'int'     */
    public max_polyphony: number;    
    /**     * The raw type is 'StringName'     */
    public bus: StringName;    
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
    public set_mix_target(mixTarget: number): void;
    public get_mix_target(): number;
    public set_playing(enable: boolean): void;
    public set_stream_paused(pause: boolean): void;
    public get_stream_paused(): boolean;
    public set_max_polyphony(maxPolyphony: number): void;
    public get_max_polyphony(): number;
    public has_stream_playback(): boolean;
    public get_stream_playback(): AudioStreamPlayback;
    public set_playback_type(playbackType: number): void;
    public get_playback_type(): number;

    
    public readonly finished: Signal<() => void>;

    public static readonly MixTarget: {
        MIX_TARGET_STEREO: 0;
        MIX_TARGET_SURROUND: 1;
        MIX_TARGET_CENTER: 2;
    };
}

