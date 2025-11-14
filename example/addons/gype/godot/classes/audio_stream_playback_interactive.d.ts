
import type { AudioStreamPlayback } from '@godot/classes/audio_stream_playback';
import type { GDString } from '@godot/builtins/gd_string';
import type { StringName } from '@godot/builtins/string_name';


export declare class AudioStreamPlaybackInteractive extends AudioStreamPlayback {


    public switch_to_clip_by_name(cliname: GDString | StringName | string): void;
    public switch_to_clip(cliindex: number): void;
    public get_current_clip_index(): number;


}

