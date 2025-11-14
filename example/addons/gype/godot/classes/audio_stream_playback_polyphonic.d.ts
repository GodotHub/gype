
import type { AudioStream } from '@godot/classes/audio_stream';
import type { AudioStreamPlayback } from '@godot/classes/audio_stream_playback';
import type { GDString } from '@godot/builtins/gd_string';
import type { StringName } from '@godot/builtins/string_name';


export declare class AudioStreamPlaybackPolyphonic extends AudioStreamPlayback {


    public play_stream(stream: AudioStream, fromOffset: number = 0, volumeDb: number = 0, pitchScale: number = 1.0, playbackType: number = 0, bus: GDString | StringName | string = "Master"): number;
    public set_stream_volume(stream: number, volumeDb: number): void;
    public set_stream_pitch_scale(stream: number, pitchScale: number): void;
    public is_stream_playing(stream: number): boolean;
    public stop_stream(stream: number): void;


}

