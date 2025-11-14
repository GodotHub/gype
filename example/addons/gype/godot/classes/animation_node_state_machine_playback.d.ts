
import type { GDString } from '@godot/builtins/gd_string';
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';


export declare class AnimationNodeStateMachinePlayback extends Resource {


    public travel(toNode: GDString | StringName | string, resetOnTeleport: boolean = true): void;
    public start(node: GDString | StringName | string, reset: boolean = true): void;
    public next(): void;
    public stop(): void;
    public is_playing(): boolean;
    public get_current_node(): StringName;
    public get_current_play_position(): number;
    public get_current_length(): number;
    public get_fading_from_node(): StringName;
    public get_travel_path(): Array<any>;

    
    public readonly state_started: Signal<(state: GDString | StringName | string) => void>;
    public readonly state_finished: Signal<(state: GDString | StringName | string) => void>;

}

