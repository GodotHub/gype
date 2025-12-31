
import type { AudioBusLayout } from '@godot/classes/audio_bus_layout';
import type { AudioEffect } from '@godot/classes/audio_effect';
import type { AudioEffectInstance } from '@godot/classes/audio_effect_instance';
import type { AudioStream } from '@godot/classes/audio_stream';
import type { GodotObject } from '@godot/classes/godot_object';


export declare class _AudioServer extends GodotObject {

    
    /**     * The raw type is 'int'     */
    public bus_count: number;    
    /**     * The raw type is 'String'     */
    public output_device: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public input_device: GDString | StringName | string;    
    /**     * The raw type is 'float'     */
    public playback_speed_scale: number;
    public set_bus_count(amount: number): void;
    public get_bus_count(): number;
    public remove_bus(index: number): void;
    public add_bus(atPosition: number = -1): void;
    public move_bus(index: number, toIndex: number): void;
    public set_bus_name(busIdx: number, name: GDString | StringName | string): void;
    public get_bus_name(busIdx: number): GDString;
    public get_bus_index(busName: GDString | StringName | string): number;
    public get_bus_channels(busIdx: number): number;
    public set_bus_volume_db(busIdx: number, volumeDb: number): void;
    public get_bus_volume_db(busIdx: number): number;
    public set_bus_volume_linear(busIdx: number, volumeLinear: number): void;
    public get_bus_volume_linear(busIdx: number): number;
    public set_bus_send(busIdx: number, send: GDString | StringName | string): void;
    public get_bus_send(busIdx: number): StringName;
    public set_bus_solo(busIdx: number, enable: boolean): void;
    public is_bus_solo(busIdx: number): boolean;
    public set_bus_mute(busIdx: number, enable: boolean): void;
    public is_bus_mute(busIdx: number): boolean;
    public set_bus_bypass_effects(busIdx: number, enable: boolean): void;
    public is_bus_bypassing_effects(busIdx: number): boolean;
    public add_bus_effect(busIdx: number, effect: AudioEffect, atPosition: number = -1): void;
    public remove_bus_effect(busIdx: number, effectIdx: number): void;
    public get_bus_effect_count(busIdx: number): number;
    public get_bus_effect(busIdx: number, effectIdx: number): AudioEffect;
    public get_bus_effect_instance(busIdx: number, effectIdx: number, channel: number = 0): AudioEffectInstance;
    public swap_bus_effects(busIdx: number, effectIdx: number, byEffectIdx: number): void;
    public set_bus_effect_enabled(busIdx: number, effectIdx: number, enabled: boolean): void;
    public is_bus_effect_enabled(busIdx: number, effectIdx: number): boolean;
    public get_bus_peak_volume_left_db(busIdx: number, channel: number): number;
    public get_bus_peak_volume_right_db(busIdx: number, channel: number): number;
    public set_playback_speed_scale(scale: number): void;
    public get_playback_speed_scale(): number;
    public lock(): void;
    public unlock(): void;
    public get_speaker_mode(): number;
    public get_mix_rate(): number;
    public get_input_mix_rate(): number;
    public get_driver_name(): GDString;
    public get_output_device_list(): PackedStringArray;
    public get_output_device(): GDString;
    public set_output_device(name: GDString | StringName | string): void;
    public get_time_to_next_mix(): number;
    public get_time_since_last_mix(): number;
    public get_output_latency(): number;
    public get_input_device_list(): PackedStringArray;
    public get_input_device(): GDString;
    public set_input_device(name: GDString | StringName | string): void;
    public set_bus_layout(busLayout: AudioBusLayout): void;
    public generate_bus_layout(): AudioBusLayout;
    public set_enable_tagging_used_audio_streams(enable: boolean): void;
    public is_stream_registered_as_sample(stream: AudioStream): boolean;
    public register_stream_as_sample(stream: AudioStream): void;

    
    public readonly bus_layout_changed: Signal<() => void>;
    public readonly bus_renamed: Signal<(busIndex: number, oldName: GDString | StringName | string, newName: GDString | StringName | string) => void>;

    public static readonly SpeakerMode: {
        SPEAKER_MODE_STEREO: 0;
        SPEAKER_SURROUND_31: 1;
        SPEAKER_SURROUND_51: 2;
        SPEAKER_SURROUND_71: 3;
    };
    public static readonly PlaybackType: {
        PLAYBACK_TYPE_DEFAULT: 0;
        PLAYBACK_TYPE_STREAM: 1;
        PLAYBACK_TYPE_SAMPLE: 2;
        PLAYBACK_TYPE_MAX: 3;
    };
}

export const AudioServer: _AudioServer;
