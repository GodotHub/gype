
import type { Callable } from '@godot/builtins/callable';
import type { CallbackTweener } from '@godot/classes/callback_tweener';
import type { GodotObject } from '@godot/classes/godot_object';
import type { IntervalTweener } from '@godot/classes/interval_tweener';
import type { MethodTweener } from '@godot/classes/method_tweener';
import type { Node } from '@godot/classes/node';
import type { NodePath } from '@godot/builtins/node_path';
import type { PropertyTweener } from '@godot/classes/property_tweener';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Signal } from '@godot/builtins/signal';
import type { SubtweenTweener } from '@godot/classes/subtween_tweener';


export declare class Tween extends RefCounted {


    public tween_property(object: GodotObject, property: NodePath | GDString | string, finalVal: any, duration: number): PropertyTweener;
    public tween_interval(time: number): IntervalTweener;
    public tween_callback(callback: Callable | Function): CallbackTweener;
    public tween_method(method: Callable | Function, _from: any, to: any, duration: number): MethodTweener;
    public tween_subtween(subtween: Tween): SubtweenTweener;
    public custom_step(delta: number): boolean;
    public stop(): void;
    public pause(): void;
    public play(): void;
    public kill(): void;
    public get_total_elapsed_time(): number;
    public is_running(): boolean;
    public is_valid(): boolean;
    public bind_node(node: Node): Tween;
    public set_process_mode(mode: number): Tween;
    public set_pause_mode(mode: number): Tween;
    public set_ignore_time_scale(ignore: boolean = true): Tween;
    public set_parallel(parallel: boolean = true): Tween;
    public set_loops(loops: number = 0): Tween;
    public get_loops_left(): number;
    public set_speed_scale(speed: number): Tween;
    public set_trans(trans: number): Tween;
    public set_ease(ease: number): Tween;
    public parallel(): Tween;
    public chain(): Tween;
    public static interpolate_value(initialValue: any, deltaValue: any, elapsedTime: number, duration: number, transType: number, easeType: number): any;

    
    public readonly step_finished: Signal<(idx: number) => void>;
    public readonly loop_finished: Signal<(loocount: number) => void>;
    public readonly finished: Signal<() => void>;

    public static readonly TweenProcessMode: {
        TWEEN_PROCESS_PHYSICS: 0;
        TWEEN_PROCESS_IDLE: 1;
    };
    public static readonly TweenPauseMode: {
        TWEEN_PAUSE_BOUND: 0;
        TWEEN_PAUSE_STOP: 1;
        TWEEN_PAUSE_PROCESS: 2;
    };
    public static readonly TransitionType: {
        TRANS_LINEAR: 0;
        TRANS_SINE: 1;
        TRANS_QUINT: 2;
        TRANS_QUART: 3;
        TRANS_QUAD: 4;
        TRANS_EXPO: 5;
        TRANS_ELASTIC: 6;
        TRANS_CUBIC: 7;
        TRANS_CIRC: 8;
        TRANS_BOUNCE: 9;
        TRANS_BACK: 10;
        TRANS_SPRING: 11;
    };
    public static readonly EaseType: {
        EASE_IN: 0;
        EASE_OUT: 1;
        EASE_IN_OUT: 2;
        EASE_OUT_IN: 3;
    };
}

