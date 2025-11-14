
import type { AudioStream } from '@godot/classes/audio_stream';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { StringName } from '@godot/builtins/string_name';


export declare class AudioStreamInteractive extends AudioStream {

    
    /**     * The raw type is 'int'     */
    public clip_count: number;    
    /**     * The raw type is 'int'     */
    public initial_clip: number;
    public set_clip_count(clicount: number): void;
    public get_clip_count(): number;
    public set_initial_clip(cliindex: number): void;
    public get_initial_clip(): number;
    public set_clip_name(cliindex: number, name: GDString | StringName | string): void;
    public get_clip_name(cliindex: number): StringName;
    public set_clip_stream(cliindex: number, stream: AudioStream): void;
    public get_clip_stream(cliindex: number): AudioStream;
    public set_clip_auto_advance(cliindex: number, mode: number): void;
    public get_clip_auto_advance(cliindex: number): number;
    public set_clip_auto_advance_next_clip(cliindex: number, autoAdvanceNextClip: number): void;
    public get_clip_auto_advance_next_clip(cliindex: number): number;
    public add_transition(fromClip: number, toClip: number, fromTime: number, toTime: number, fadeMode: number, fadeBeats: number, useFillerClip: boolean = false, fillerClip: number = -1, holdPrevious: boolean = false): void;
    public has_transition(fromClip: number, toClip: number): boolean;
    public erase_transition(fromClip: number, toClip: number): void;
    public get_transition_list(): PackedInt32Array;
    public get_transition_from_time(fromClip: number, toClip: number): number;
    public get_transition_to_time(fromClip: number, toClip: number): number;
    public get_transition_fade_mode(fromClip: number, toClip: number): number;
    public get_transition_fade_beats(fromClip: number, toClip: number): number;
    public is_transition_using_filler_clip(fromClip: number, toClip: number): boolean;
    public get_transition_filler_clip(fromClip: number, toClip: number): number;
    public is_transition_holding_previous(fromClip: number, toClip: number): boolean;


    public static readonly TransitionFromTime: {
        TRANSITION_FROM_TIME_IMMEDIATE: 0;
        TRANSITION_FROM_TIME_NEXT_BEAT: 1;
        TRANSITION_FROM_TIME_NEXT_BAR: 2;
        TRANSITION_FROM_TIME_END: 3;
    };
    public static readonly TransitionToTime: {
        TRANSITION_TO_TIME_SAME_POSITION: 0;
        TRANSITION_TO_TIME_START: 1;
    };
    public static readonly FadeMode: {
        FADE_DISABLED: 0;
        FADE_IN: 1;
        FADE_OUT: 2;
        FADE_CROSS: 3;
        FADE_AUTOMATIC: 4;
    };
    public static readonly AutoAdvanceMode: {
        AUTO_ADVANCE_DISABLED: 0;
        AUTO_ADVANCE_ENABLED: 1;
        AUTO_ADVANCE_RETURN_TO_HOLD: 2;
    };
}

