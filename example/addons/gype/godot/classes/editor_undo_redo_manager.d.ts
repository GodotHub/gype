
import type { GodotObject } from '@godot/classes/godot_object';
import type { UndoRedo } from '@godot/classes/undo_redo';


export declare class EditorUndoRedoManager extends GodotObject {


    public create_action(name: GDString | StringName | string, mergeMode: number = 0, customContext: GodotObject = null, backwardUndoOps: boolean = false, markUnsaved: boolean = true): void;
    public commit_action(execute: boolean = true): void;
    public is_committing_action(): boolean;
    public force_fixed_history(): void;
    public add_do_method(object: GodotObject, method: GDString | StringName | string, ...args: any[]): void;
    public add_undo_method(object: GodotObject, method: GDString | StringName | string, ...args: any[]): void;
    public add_do_property(object: GodotObject, property: GDString | StringName | string, value: any): void;
    public add_undo_property(object: GodotObject, property: GDString | StringName | string, value: any): void;
    public add_do_reference(object: GodotObject): void;
    public add_undo_reference(object: GodotObject): void;
    public get_object_history_id(object: GodotObject): number;
    public get_history_undo_redo(id: number): UndoRedo;
    public clear_history(id: number = -99, increaseVersion: boolean = true): void;

    
    public readonly history_changed: Signal<() => void>;
    public readonly version_changed: Signal<() => void>;

    public static readonly SpecialHistory: {
        GLOBAL_HISTORY: 0;
        REMOTE_HISTORY: -9;
        INVALID_HISTORY: -99;
    };
}

