
import { AudioStreamWAV } from "@godot/classes/audio_stream_wav";
import { AudioEffect } from "@godot/classes/audio_effect";

export declare class AudioEffectRecord extends AudioEffect{
  public set_recording_active(_record: boolean): void;
  public is_recording_active(): boolean;
  public set_format(_format: number): void;
  public get_format(): number;
  public get_recording(): AudioStreamWAV;
  public get format(): number {
    get_format();
  }
  public set format(value): void {
    set_format(value);
  }
}