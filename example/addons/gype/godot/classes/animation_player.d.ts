
import type { AnimationMixer } from '@godot/classes/animation_mixer';
import type { GDString } from '@godot/builtins/gd_string';
import type { NodePath } from '@godot/builtins/node_path';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class AnimationPlayer extends AnimationMixer {

    
    /**     * The raw type is 'StringName'     */
    public current_animation: GDString;    
    /**     * The raw type is 'StringName'     */
    public assigned_animation: GDString;    
    /**     * The raw type is 'StringName'     */
    public autoplay: GDString;    
    /**     * The raw type is 'float'     */
    public current_animation_length: number;    
    /**     * The raw type is 'float'     */
    public current_animation_position: number;    
    /**     * The raw type is 'bool'     */
    public playback_auto_capture: boolean;    
    /**     * The raw type is 'float'     */
    public playback_auto_capture_duration: number;    
    /**     * The raw type is 'int'     */
    public playback_auto_capture_transition_type: number;    
    /**     * The raw type is 'int'     */
    public playback_auto_capture_ease_type: number;    
    /**     * The raw type is 'float'     */
    public playback_default_blend_time: number;    
    /**     * The raw type is 'float'     */
    public speed_scale: number;    
    /**     * The raw type is 'bool'     */
    public movie_quit_on_finish: boolean;
    public animation_set_next(animationFrom: GDString | StringName | string, animationTo: GDString | StringName | string): void;
    public animation_get_next(animationFrom: GDString | StringName | string): StringName;
    public set_blend_time(animationFrom: GDString | StringName | string, animationTo: GDString | StringName | string, sec: number): void;
    public get_blend_time(animationFrom: GDString | StringName | string, animationTo: GDString | StringName | string): number;
    public set_default_blend_time(sec: number): void;
    public get_default_blend_time(): number;
    public set_auto_capture(autoCapture: boolean): void;
    public is_auto_capture(): boolean;
    public set_auto_capture_duration(autoCaptureDuration: number): void;
    public get_auto_capture_duration(): number;
    public set_auto_capture_transition_type(autoCaptureTransitionType: number): void;
    public get_auto_capture_transition_type(): number;
    public set_auto_capture_ease_type(autoCaptureEaseType: number): void;
    public get_auto_capture_ease_type(): number;
    public play(name: GDString | StringName | string = "", customBlend: number = -1, customSpeed: number = 1.0, fromEnd: boolean = false): void;
    public play_section_with_markers(name: GDString | StringName | string = "", startMarker: GDString | StringName | string = "", endMarker: GDString | StringName | string = "", customBlend: number = -1, customSpeed: number = 1.0, fromEnd: boolean = false): void;
    public play_section(name: GDString | StringName | string = "", startTime: number = -1, endTime: number = -1, customBlend: number = -1, customSpeed: number = 1.0, fromEnd: boolean = false): void;
    public play_backwards(name: GDString | StringName | string = "", customBlend: number = -1): void;
    public play_section_with_markers_backwards(name: GDString | StringName | string = "", startMarker: GDString | StringName | string = "", endMarker: GDString | StringName | string = "", customBlend: number = -1): void;
    public play_section_backwards(name: GDString | StringName | string = "", startTime: number = -1, endTime: number = -1, customBlend: number = -1): void;
    public play_with_capture(name: GDString | StringName | string = "", duration: number = -1.0, customBlend: number = -1, customSpeed: number = 1.0, fromEnd: boolean = false, transType: number = 0, easeType: number = 0): void;
    public pause(): void;
    public stop(keestate: boolean = false): void;
    public is_playing(): boolean;
    public set_current_animation(animation: GDString | StringName | string): void;
    public get_current_animation(): GDString;
    public set_assigned_animation(animation: GDString | StringName | string): void;
    public get_assigned_animation(): GDString;
    public queue(name: GDString | StringName | string): void;
    public get_queue(): PackedStringArray;
    public clear_queue(): void;
    public set_speed_scale(speed: number): void;
    public get_speed_scale(): number;
    public get_playing_speed(): number;
    public set_autoplay(name: GDString | StringName | string): void;
    public get_autoplay(): GDString;
    public set_movie_quit_on_finish_enabled(enabled: boolean): void;
    public is_movie_quit_on_finish_enabled(): boolean;
    public get_current_animation_position(): number;
    public get_current_animation_length(): number;
    public set_section_with_markers(startMarker: GDString | StringName | string = "", endMarker: GDString | StringName | string = ""): void;
    public set_section(startTime: number = -1, endTime: number = -1): void;
    public reset_section(): void;
    public get_section_start_time(): number;
    public get_section_end_time(): number;
    public has_section(): boolean;
    public seek(seconds: number, update: boolean = false, updateOnly: boolean = false): void;
    public set_process_callback(mode: number): void;
    public get_process_callback(): number;
    public set_method_call_mode(mode: number): void;
    public get_method_call_mode(): number;
    public set_root(path: NodePath | GDString | string): void;
    public get_root(): NodePath;

    
    public readonly current_animation_changed: Signal<(name: GDString | StringName | string) => void>;
    public readonly animation_changed: Signal<(oldName: GDString | StringName | string, newName: GDString | StringName | string) => void>;

    public static readonly AnimationProcessCallback: {
        ANIMATION_PROCESS_PHYSICS: 0;
        ANIMATION_PROCESS_IDLE: 1;
        ANIMATION_PROCESS_MANUAL: 2;
    };
    public static readonly AnimationMethodCallMode: {
        ANIMATION_METHOD_CALL_DEFERRED: 0;
        ANIMATION_METHOD_CALL_IMMEDIATE: 1;
    };
}

