
import type { PackedFloat32Array } from '@godot/builtins/packed_float32_array';
import type { Resource } from '@godot/classes/resource';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class VideoStreamPlayback extends Resource {


    public _stop(): void;
    public _play(): void;
    public _is_playing(): boolean;
    public _set_paused(paused: boolean): void;
    public _is_paused(): boolean;
    public _get_length(): number;
    public _get_playback_position(): number;
    public _seek(time: number): void;
    public _set_audio_track(idx: number): void;
    public _get_texture(): Texture2D;
    public _update(delta: number): void;
    public _get_channels(): number;
    public _get_mix_rate(): number;
    public mix_audio(numFrames: number, buffer: PackedFloat32Array = PackedFloat32Array(), offset: number = 0): number;


}

