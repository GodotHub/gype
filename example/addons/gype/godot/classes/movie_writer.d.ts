
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Image } from '@godot/classes/image';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class MovieWriter extends GodotObject {


    public _get_audio_mix_rate(): number;
    public _get_audio_speaker_mode(): number;
    public _handles_file(path: GDString | StringName | string): boolean;
    public _write_begin(movieSize: Vector2i, fps: number, basePath: GDString | StringName | string): number;
    public _write_frame(frameImage: Image, audioFrameBlock: any): number;
    public _write_end(): void;
    public static add_writer(writer: MovieWriter): void;


}

