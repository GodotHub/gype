
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';


export declare class _InputMap extends GodotObject {


    public has_action(action: GDString | StringName | string): boolean;
    public get_actions(): Array<any>;
    public add_action(action: GDString | StringName | string, deadzone: number = 0.2): void;
    public erase_action(action: GDString | StringName | string): void;
    public get_action_description(action: GDString | StringName | string): GDString;
    public action_set_deadzone(action: GDString | StringName | string, deadzone: number): void;
    public action_get_deadzone(action: GDString | StringName | string): number;
    public action_add_event(action: GDString | StringName | string, event: InputEvent): void;
    public action_has_event(action: GDString | StringName | string, event: InputEvent): boolean;
    public action_erase_event(action: GDString | StringName | string, event: InputEvent): void;
    public action_erase_events(action: GDString | StringName | string): void;
    public action_get_events(action: GDString | StringName | string): Array<any>;
    public event_is_action(event: InputEvent, action: GDString | StringName | string, exactMatch: boolean = false): boolean;
    public load_from_project_settings(): void;


}

export const InputMap: _InputMap;
