
import { AudioEffectInstance } from "@godot/classes/audio_effect_instance";
import { AudioEffect } from "@godot/classes/audio_effect";
import { AudioStream } from "@godot/classes/audio_stream";
import { Object } from "@godot/classes/object";
import { AudioBusLayout } from "@godot/classes/audio_bus_layout";

export declare class AudioServer extends Object{
  public set_bus_count(_amount: number): void;
  public get_bus_count(): number;
  public remove_bus(_index: number): void;
  public add_bus(_at_position: number): void;
  public move_bus(_index: number, _to_index: number): void;
  public set_bus_name(_bus_idx: number, _name: String): void;
  public get_bus_name(_bus_idx: number): String;
  public get_bus_index(_bus_name: StringName): number;
  public get_bus_channels(_bus_idx: number): number;
  public set_bus_volume_db(_bus_idx: number, _volume_db: number): void;
  public get_bus_volume_db(_bus_idx: number): number;
  public set_bus_send(_bus_idx: number, _send: StringName): void;
  public get_bus_send(_bus_idx: number): StringName;
  public set_bus_solo(_bus_idx: number, _enable: boolean): void;
  public is_bus_solo(_bus_idx: number): boolean;
  public set_bus_mute(_bus_idx: number, _enable: boolean): void;
  public is_bus_mute(_bus_idx: number): boolean;
  public set_bus_bypass_effects(_bus_idx: number, _enable: boolean): void;
  public is_bus_bypassing_effects(_bus_idx: number): boolean;
  public add_bus_effect(_bus_idx: number, _effect: AudioEffect, _at_position: number): void;
  public remove_bus_effect(_bus_idx: number, _effect_idx: number): void;
  public get_bus_effect_count(_bus_idx: number): number;
  public get_bus_effect(_bus_idx: number, _effect_idx: number): AudioEffect;
  public get_bus_effect_instance(_bus_idx: number, _effect_idx: number, _channel: number): AudioEffectInstance;
  public swap_bus_effects(_bus_idx: number, _effect_idx: number, _by_effect_idx: number): void;
  public set_bus_effect_enabled(_bus_idx: number, _effect_idx: number, _enabled: boolean): void;
  public is_bus_effect_enabled(_bus_idx: number, _effect_idx: number): boolean;
  public get_bus_peak_volume_left_db(_bus_idx: number, _channel: number): number;
  public get_bus_peak_volume_right_db(_bus_idx: number, _channel: number): number;
  public set_playback_speed_scale(_scale: number): void;
  public get_playback_speed_scale(): number;
  public lock(): void;
  public unlock(): void;
  public get_speaker_mode(): number;
  public get_mix_rate(): number;
  public get_output_device_list(): PackedStringArray;
  public get_output_device(): String;
  public set_output_device(_name: String): void;
  public get_time_to_next_mix(): number;
  public get_time_since_last_mix(): number;
  public get_output_latency(): number;
  public get_input_device_list(): PackedStringArray;
  public get_input_device(): String;
  public set_input_device(_name: String): void;
  public set_bus_layout(_bus_layout: AudioBusLayout): void;
  public generate_bus_layout(): AudioBusLayout;
  public set_enable_tagging_used_audio_streams(_enable: boolean): void;
  public is_stream_registered_as_sample(_stream: AudioStream): boolean;
  public register_stream_as_sample(_stream: AudioStream): void;
  public get bus_count(): number {
    get_bus_count();
  }
  public set bus_count(value): void {
    set_bus_count(value);
  }
  public get output_device(): String {
    get_output_device();
  }
  public set output_device(value): void {
    set_output_device(value);
  }
  public get input_device(): String {
    get_input_device();
  }
  public set input_device(value): void {
    set_input_device(value);
  }
  public get playback_speed_scale(): number {
    get_playback_speed_scale();
  }
  public set playback_speed_scale(value): void {
    set_playback_speed_scale(value);
  }
  static SpeakerMode = {
    SPEAKER_MODE_STEREO = 0,
    SPEAKER_SURROUND_31 = 1,
    SPEAKER_SURROUND_51 = 2,
    SPEAKER_SURROUND_71 = 3,
  }
  static PlaybackType = {
    PLAYBACK_TYPE_DEFAULT = 0,
    PLAYBACK_TYPE_STREAM = 1,
    PLAYBACK_TYPE_SAMPLE = 2,
    PLAYBACK_TYPE_MAX = 3,
  }
}