
import type { AudioStream } from '@godot/classes/audio_stream';
import type { AudioStreamPlayback } from '@godot/classes/audio_stream_playback';
import type { Node3D } from '@godot/classes/node3d';


export declare class AudioStreamPlayer3D extends Node3D {

    
    /**     * The raw type is 'AudioStream'     */
    public stream: AudioStream;    
    /**     * The raw type is 'int'     */
    public attenuation_model: number;    
    /**     * The raw type is 'float'     */
    public volume_db: number;    
    /**     * The raw type is 'float'     */
    public volume_linear: number;    
    /**     * The raw type is 'float'     */
    public unit_size: number;    
    /**     * The raw type is 'float'     */
    public max_db: number;    
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
    /**     * The raw type is 'int'     */
    public max_polyphony: number;    
    /**     * The raw type is 'float'     */
    public panning_strength: number;    
    /**     * The raw type is 'StringName'     */
    public bus: StringName;    
    /**     * The raw type is 'int'     */
    public area_mask: number;    
    /**     * The raw type is 'int'     */
    public playback_type: number;    
    /**     * The raw type is 'bool'     */
    public emission_angle_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public emission_angle_degrees: number;    
    /**     * The raw type is 'float'     */
    public emission_angle_filter_attenuation_db: number;    
    /**     * The raw type is 'float'     */
    public attenuation_filter_cutoff_hz: number;    
    /**     * The raw type is 'float'     */
    public attenuation_filter_db: number;    
    /**     * The raw type is 'int'     */
    public doppler_tracking: number;
    public set_stream(stream: AudioStream): void;
    public get_stream(): AudioStream;
    public set_volume_db(volumeDb: number): void;
    public get_volume_db(): number;
    public set_volume_linear(volumeLinear: number): void;
    public get_volume_linear(): number;
    public set_unit_size(unitSize: number): void;
    public get_unit_size(): number;
    public set_max_db(maxDb: number): void;
    public get_max_db(): number;
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
    public set_max_distance(meters: number): void;
    public get_max_distance(): number;
    public set_area_mask(mask: number): void;
    public get_area_mask(): number;
    public set_emission_angle(degrees: number): void;
    public get_emission_angle(): number;
    public set_emission_angle_enabled(enabled: boolean): void;
    public is_emission_angle_enabled(): boolean;
    public set_emission_angle_filter_attenuation_db(db: number): void;
    public get_emission_angle_filter_attenuation_db(): number;
    public set_attenuation_filter_cutoff_hz(degrees: number): void;
    public get_attenuation_filter_cutoff_hz(): number;
    public set_attenuation_filter_db(db: number): void;
    public get_attenuation_filter_db(): number;
    public set_attenuation_model(model: number): void;
    public get_attenuation_model(): number;
    public set_doppler_tracking(mode: number): void;
    public get_doppler_tracking(): number;
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

    
    public readonly finished: Signal;

    public static readonly AttenuationModel: {
        ATTENUATION_INVERSE_DISTANCE: 0;
        ATTENUATION_INVERSE_SQUARE_DISTANCE: 1;
        ATTENUATION_LOGARITHMIC: 2;
        ATTENUATION_DISABLED: 3;
    };
    public static readonly DopplerTracking: {
        DOPPLER_TRACKING_DISABLED: 0;
        DOPPLER_TRACKING_IDLE_STEP: 1;
        DOPPLER_TRACKING_PHYSICS_STEP: 2;
    };
}

