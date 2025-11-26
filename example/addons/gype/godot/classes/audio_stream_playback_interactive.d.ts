
import type { AudioStreamPlayback } from '@godot/classes/audio_stream_playback';


export declare class AudioStreamPlaybackInteractive extends AudioStreamPlayback {


    public switch_to_clip_by_name(cliname: GDString | StringName | string): void;
    public switch_to_clip(cliindex: number): void;
    public get_current_clip_index(): number;


}

