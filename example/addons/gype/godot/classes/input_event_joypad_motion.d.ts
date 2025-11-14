
import type { InputEvent } from '@godot/classes/input_event';


export declare class InputEventJoypadMotion extends InputEvent {

    
    /**     * The raw type is 'int'     */
    public axis: number;    
    /**     * The raw type is 'float'     */
    public axis_value: number;
    public set_axis(axis: number): void;
    public get_axis(): number;
    public set_axis_value(axisValue: number): void;
    public get_axis_value(): number;


}

