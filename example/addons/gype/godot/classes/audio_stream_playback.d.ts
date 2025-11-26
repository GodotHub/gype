
import type { AudioSamplePlayback } from '@godot/classes/audio_sample_playback';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class AudioStreamPlayback extends RefCounted {


    public _start(fromPos: number): void;
    public _stop(): void;
    public _is_playing(): boolean;
    public _get_loop_count(): number;
    public _get_playback_position(): number;
    public _seek(position: number): void;
    public _mix(buffer: any, rateScale: number, frames: number): number;
    public _tag_used_streams(): void;
    public _set_parameter(name: GDString | StringName | string, value: any): void;
    public _get_parameter(name: GDString | StringName | string): any;
    public set_sample_playback(playbackSample: AudioSamplePlayback): void;
    public get_sample_playback(): AudioSamplePlayback;
    public mix_audio(rateScale: number, frames: number): PackedVector2Array;
    public start(fromPos: number = 0.0): void;
    public seek(time: number = 0.0): void;
    public stop(): void;
    public get_loop_count(): number;
    public get_playback_position(): number;
    public is_playing(): boolean;


}

