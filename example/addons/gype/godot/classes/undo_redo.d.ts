
import type { Callable } from '@godot/builtins/callable';
import type { GDString } from '@godot/builtins/gd_string';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class UndoRedo extends GodotObject {

    
    /**     * The raw type is 'int'     */
    public max_steps: number;
    public create_action(name: GDString | StringName | string, mergeMode: number = 0, backwardUndoOps: boolean = false): void;
    public commit_action(execute: boolean = true): void;
    public is_committing_action(): boolean;
    public add_do_method(callable: Callable | Function): void;
    public add_undo_method(callable: Callable | Function): void;
    public add_do_property(object: GodotObject, property: GDString | StringName | string, value: any): void;
    public add_undo_property(object: GodotObject, property: GDString | StringName | string, value: any): void;
    public add_do_reference(object: GodotObject): void;
    public add_undo_reference(object: GodotObject): void;
    public start_force_keep_in_merge_ends(): void;
    public end_force_keep_in_merge_ends(): void;
    public get_history_count(): number;
    public get_current_action(): number;
    public get_action_name(id: number): GDString;
    public clear_history(increaseVersion: boolean = true): void;
    public get_current_action_name(): GDString;
    public has_undo(): boolean;
    public has_redo(): boolean;
    public get_version(): number;
    public set_max_steps(maxSteps: number): void;
    public get_max_steps(): number;
    public redo(): boolean;
    public undo(): boolean;

    
    public readonly version_changed: Signal<() => void>;

    public static readonly MergeMode: {
        MERGE_DISABLE: 0;
        MERGE_ENDS: 1;
        MERGE_ALL: 2;
    };
}

