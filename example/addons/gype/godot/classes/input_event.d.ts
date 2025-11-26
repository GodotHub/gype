
import type { Resource } from '@godot/classes/resource';


export declare class InputEvent extends Resource {

    
    /**     * The raw type is 'int'     */
    public device: number;
    public set_device(device: number): void;
    public get_device(): number;
    public is_action(action: GDString | StringName | string, exactMatch: boolean = false): boolean;
    public is_action_pressed(action: GDString | StringName | string, allowEcho: boolean = false, exactMatch: boolean = false): boolean;
    public is_action_released(action: GDString | StringName | string, exactMatch: boolean = false): boolean;
    public get_action_strength(action: GDString | StringName | string, exactMatch: boolean = false): number;
    public is_canceled(): boolean;
    public is_pressed(): boolean;
    public is_released(): boolean;
    public is_echo(): boolean;
    public as_text(): GDString;
    public is_match(event: InputEvent, exactMatch: boolean = true): boolean;
    public is_action_type(): boolean;
    public accumulate(withEvent: InputEvent): boolean;
    public xformed_by(xform: Transform2D, localOfs: Vector2 = Vector2(0, 0)): InputEvent;


}

