
import type { Animation } from '@godot/classes/animation';
import type { AnimationLibrary } from '@godot/classes/animation_library';
import type { Node } from '@godot/classes/node';


export declare class AnimationMixer extends Node {

    
    /**     * The raw type is 'bool'     */
    public active: boolean;    
    /**     * The raw type is 'bool'     */
    public deterministic: boolean;    
    /**     * The raw type is 'bool'     */
    public reset_on_save: boolean;    
    /**     * The raw type is 'NodePath'     */
    public root_node: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public root_motion_track: NodePath;    
    /**     * The raw type is 'bool'     */
    public root_motion_local: boolean;    
    /**     * The raw type is 'int'     */
    public audio_max_polyphony: number;    
    /**     * The raw type is 'int'     */
    public callback_mode_process: number;    
    /**     * The raw type is 'int'     */
    public callback_mode_method: number;    
    /**     * The raw type is 'int'     */
    public callback_mode_discrete: number;
    public _post_process_key_value(animation: Animation, track: number, value: any, objectId: number, objectSubIdx: number): any;
    public add_animation_library(name: GDString | StringName | string, library: AnimationLibrary): number;
    public remove_animation_library(name: GDString | StringName | string): void;
    public rename_animation_library(name: GDString | StringName | string, newname: GDString | StringName | string): void;
    public has_animation_library(name: GDString | StringName | string): boolean;
    public get_animation_library(name: GDString | StringName | string): AnimationLibrary;
    public get_animation_library_list(): Array<any>;
    public has_animation(name: GDString | StringName | string): boolean;
    public get_animation(name: GDString | StringName | string): Animation;
    public get_animation_list(): PackedStringArray;
    public set_active(active: boolean): void;
    public is_active(): boolean;
    public set_deterministic(deterministic: boolean): void;
    public is_deterministic(): boolean;
    public set_root_node(path: NodePath | GDString | string): void;
    public get_root_node(): NodePath;
    public set_callback_mode_process(mode: number): void;
    public get_callback_mode_process(): number;
    public set_callback_mode_method(mode: number): void;
    public get_callback_mode_method(): number;
    public set_callback_mode_discrete(mode: number): void;
    public get_callback_mode_discrete(): number;
    public set_audio_max_polyphony(maxPolyphony: number): void;
    public get_audio_max_polyphony(): number;
    public set_root_motion_track(path: NodePath | GDString | string): void;
    public get_root_motion_track(): NodePath;
    public set_root_motion_local(enabled: boolean): void;
    public is_root_motion_local(): boolean;
    public get_root_motion_position(): Vector3;
    public get_root_motion_rotation(): Quaternion;
    public get_root_motion_scale(): Vector3;
    public get_root_motion_position_accumulator(): Vector3;
    public get_root_motion_rotation_accumulator(): Quaternion;
    public get_root_motion_scale_accumulator(): Vector3;
    public clear_caches(): void;
    public advance(delta: number): void;
    public capture(name: GDString | StringName | string, duration: number, transType: number = 0, easeType: number = 0): void;
    public set_reset_on_save_enabled(enabled: boolean): void;
    public is_reset_on_save_enabled(): boolean;
    public find_animation(animation: Animation): StringName;
    public find_animation_library(animation: Animation): StringName;

    
    public readonly animation_list_changed: Signal;
    public readonly animation_libraries_updated: Signal;
    public readonly animation_finished: Signal;
    public readonly animation_started: Signal;
    public readonly caches_cleared: Signal;
    public readonly mixer_applied: Signal;
    public readonly mixer_updated: Signal;

    public static readonly AnimationCallbackModeProcess: {
        ANIMATION_CALLBACK_MODE_PROCESS_PHYSICS: 0;
        ANIMATION_CALLBACK_MODE_PROCESS_IDLE: 1;
        ANIMATION_CALLBACK_MODE_PROCESS_MANUAL: 2;
    };
    public static readonly AnimationCallbackModeMethod: {
        ANIMATION_CALLBACK_MODE_METHOD_DEFERRED: 0;
        ANIMATION_CALLBACK_MODE_METHOD_IMMEDIATE: 1;
    };
    public static readonly AnimationCallbackModeDiscrete: {
        ANIMATION_CALLBACK_MODE_DISCRETE_DOMINANT: 0;
        ANIMATION_CALLBACK_MODE_DISCRETE_RECESSIVE: 1;
        ANIMATION_CALLBACK_MODE_DISCRETE_FORCE_CONTINUOUS: 2;
    };
}

