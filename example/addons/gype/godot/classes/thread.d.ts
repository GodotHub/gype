
import type { Callable } from '@godot/builtins/callable';
import type { GDString } from '@godot/builtins/gd_string';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class Thread extends RefCounted {


    public start(callable: Callable, priority: number = 1): number;
    public get_id(): GDString;
    public is_started(): boolean;
    public is_alive(): boolean;
    public wait_to_finish(): any;
    public static set_thread_safety_checks_enabled(enabled: boolean): void;


    public static readonly Priority: {
        PRIORITY_LOW: 0;
        PRIORITY_NORMAL: 1;
        PRIORITY_HIGH: 2;
    };
}

