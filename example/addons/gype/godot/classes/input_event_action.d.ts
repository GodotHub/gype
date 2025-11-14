
import type { GDString } from '@godot/builtins/gd_string';
import type { InputEvent } from '@godot/classes/input_event';
import type { StringName } from '@godot/builtins/string_name';


export declare class InputEventAction extends InputEvent {

    
    /**     * The raw type is 'StringName'     */
    public action: StringName;    
    /**     * The raw type is 'bool'     */
    public pressed: boolean;    
    /**     * The raw type is 'float'     */
    public strength: number;    
    /**     * The raw type is 'int'     */
    public event_index: number;
    public set_action(action: GDString | StringName | string): void;
    public get_action(): StringName;
    public set_pressed(pressed: boolean): void;
    public set_strength(strength: number): void;
    public get_strength(): number;
    public set_event_index(index: number): void;
    public get_event_index(): number;


}

