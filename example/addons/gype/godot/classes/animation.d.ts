
import type { Color } from '@godot/builtins/color';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { NodePath } from '@godot/builtins/node_path';
import type { PackedStringArray } from '@godot/builtins/packed_string_array';
import type { Quaternion } from '@godot/builtins/quaternion';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class Animation extends Resource {

    
    /**     * The raw type is 'float'     */
    public length: number;    
    /**     * The raw type is 'int'     */
    public loop_mode: number;    
    /**     * The raw type is 'float'     */
    public step: number;    
    /**     * The raw type is 'bool'     */
    public capture_included: boolean;
    public add_track(_type: number, atPosition: number = -1): number;
    public remove_track(trackIdx: number): void;
    public get_track_count(): number;
    public track_get_type(trackIdx: number): number;
    public track_get_path(trackIdx: number): NodePath;
    public track_set_path(trackIdx: number, path: NodePath | GDString | string): void;
    public find_track(path: NodePath | GDString | string, _type: number): number;
    public track_move_up(trackIdx: number): void;
    public track_move_down(trackIdx: number): void;
    public track_move_to(trackIdx: number, toIdx: number): void;
    public track_swap(trackIdx: number, withIdx: number): void;
    public track_set_imported(trackIdx: number, imported: boolean): void;
    public track_is_imported(trackIdx: number): boolean;
    public track_set_enabled(trackIdx: number, enabled: boolean): void;
    public track_is_enabled(trackIdx: number): boolean;
    public position_track_insert_key(trackIdx: number, time: number, position: Vector3): number;
    public rotation_track_insert_key(trackIdx: number, time: number, rotation: Quaternion): number;
    public scale_track_insert_key(trackIdx: number, time: number, scale: Vector3): number;
    public blend_shape_track_insert_key(trackIdx: number, time: number, amount: number): number;
    public position_track_interpolate(trackIdx: number, timeSec: number, backward: boolean = false): Vector3;
    public rotation_track_interpolate(trackIdx: number, timeSec: number, backward: boolean = false): Quaternion;
    public scale_track_interpolate(trackIdx: number, timeSec: number, backward: boolean = false): Vector3;
    public blend_shape_track_interpolate(trackIdx: number, timeSec: number, backward: boolean = false): number;
    public track_insert_key(trackIdx: number, time: number, key: any, transition: number = 1): number;
    public track_remove_key(trackIdx: number, keyIdx: number): void;
    public track_remove_key_at_time(trackIdx: number, time: number): void;
    public track_set_key_value(trackIdx: number, key: number, value: any): void;
    public track_set_key_transition(trackIdx: number, keyIdx: number, transition: number): void;
    public track_set_key_time(trackIdx: number, keyIdx: number, time: number): void;
    public track_get_key_transition(trackIdx: number, keyIdx: number): number;
    public track_get_key_count(trackIdx: number): number;
    public track_get_key_value(trackIdx: number, keyIdx: number): any;
    public track_get_key_time(trackIdx: number, keyIdx: number): number;
    public track_find_key(trackIdx: number, time: number, findMode: number = 0, limit: boolean = false, backward: boolean = false): number;
    public track_set_interpolation_type(trackIdx: number, interpolation: number): void;
    public track_get_interpolation_type(trackIdx: number): number;
    public track_set_interpolation_loop_wrap(trackIdx: number, interpolation: boolean): void;
    public track_get_interpolation_loop_wrap(trackIdx: number): boolean;
    public track_is_compressed(trackIdx: number): boolean;
    public value_track_set_update_mode(trackIdx: number, mode: number): void;
    public value_track_get_update_mode(trackIdx: number): number;
    public value_track_interpolate(trackIdx: number, timeSec: number, backward: boolean = false): any;
    public method_track_get_name(trackIdx: number, keyIdx: number): StringName;
    public method_track_get_params(trackIdx: number, keyIdx: number): GDArray;
    public bezier_track_insert_key(trackIdx: number, time: number, value: number, inHandle: Vector2 = Vector2(0, 0), outHandle: Vector2 = Vector2(0, 0)): number;
    public bezier_track_set_key_value(trackIdx: number, keyIdx: number, value: number): void;
    public bezier_track_set_key_in_handle(trackIdx: number, keyIdx: number, inHandle: Vector2, balancedValueTimeRatio: number = 1.0): void;
    public bezier_track_set_key_out_handle(trackIdx: number, keyIdx: number, outHandle: Vector2, balancedValueTimeRatio: number = 1.0): void;
    public bezier_track_get_key_value(trackIdx: number, keyIdx: number): number;
    public bezier_track_get_key_in_handle(trackIdx: number, keyIdx: number): Vector2;
    public bezier_track_get_key_out_handle(trackIdx: number, keyIdx: number): Vector2;
    public bezier_track_interpolate(trackIdx: number, time: number): number;
    public audio_track_insert_key(trackIdx: number, time: number, stream: Resource, startOffset: number = 0, endOffset: number = 0): number;
    public audio_track_set_key_stream(trackIdx: number, keyIdx: number, stream: Resource): void;
    public audio_track_set_key_start_offset(trackIdx: number, keyIdx: number, offset: number): void;
    public audio_track_set_key_end_offset(trackIdx: number, keyIdx: number, offset: number): void;
    public audio_track_get_key_stream(trackIdx: number, keyIdx: number): Resource;
    public audio_track_get_key_start_offset(trackIdx: number, keyIdx: number): number;
    public audio_track_get_key_end_offset(trackIdx: number, keyIdx: number): number;
    public audio_track_set_use_blend(trackIdx: number, enable: boolean): void;
    public audio_track_is_use_blend(trackIdx: number): boolean;
    public animation_track_insert_key(trackIdx: number, time: number, animation: GDString | StringName | string): number;
    public animation_track_set_key_animation(trackIdx: number, keyIdx: number, animation: GDString | StringName | string): void;
    public animation_track_get_key_animation(trackIdx: number, keyIdx: number): StringName;
    public add_marker(name: GDString | StringName | string, time: number): void;
    public remove_marker(name: GDString | StringName | string): void;
    public has_marker(name: GDString | StringName | string): boolean;
    public get_marker_at_time(time: number): StringName;
    public get_next_marker(time: number): StringName;
    public get_prev_marker(time: number): StringName;
    public get_marker_time(name: GDString | StringName | string): number;
    public get_marker_names(): PackedStringArray;
    public get_marker_color(name: GDString | StringName | string): Color;
    public set_marker_color(name: GDString | StringName | string, color: Color): void;
    public set_length(timeSec: number): void;
    public get_length(): number;
    public set_loop_mode(loomode: number): void;
    public get_loop_mode(): number;
    public set_step(sizeSec: number): void;
    public get_step(): number;
    public clear(): void;
    public copy_track(trackIdx: number, toAnimation: Animation): void;
    public optimize(allowedVelocityErr: number = 0.01, allowedAngularErr: number = 0.01, precision: number = 3): void;
    public compress(pageSize: number = 8192, fps: number = 120, splitTolerance: number = 4.0): void;
    public is_capture_included(): boolean;


    public static readonly TrackType: {
        TYPE_VALUE: 0;
        TYPE_POSITION_3D: 1;
        TYPE_ROTATION_3D: 2;
        TYPE_SCALE_3D: 3;
        TYPE_BLEND_SHAPE: 4;
        TYPE_METHOD: 5;
        TYPE_BEZIER: 6;
        TYPE_AUDIO: 7;
        TYPE_ANIMATION: 8;
    };
    public static readonly InterpolationType: {
        INTERPOLATION_NEAREST: 0;
        INTERPOLATION_LINEAR: 1;
        INTERPOLATION_CUBIC: 2;
        INTERPOLATION_LINEAR_ANGLE: 3;
        INTERPOLATION_CUBIC_ANGLE: 4;
    };
    public static readonly UpdateMode: {
        UPDATE_CONTINUOUS: 0;
        UPDATE_DISCRETE: 1;
        UPDATE_CAPTURE: 2;
    };
    public static readonly LoopMode: {
        LOOP_NONE: 0;
        LOOP_LINEAR: 1;
        LOOP_PINGPONG: 2;
    };
    public static readonly LoopedFlag: {
        LOOPED_FLAG_NONE: 0;
        LOOPED_FLAG_END: 1;
        LOOPED_FLAG_START: 2;
    };
    public static readonly FindMode: {
        FIND_MODE_NEAREST: 0;
        FIND_MODE_APPROX: 1;
        FIND_MODE_EXACT: 2;
    };
}

