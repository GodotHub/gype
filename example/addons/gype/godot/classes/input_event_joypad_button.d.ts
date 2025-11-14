
import type { InputEvent } from '@godot/classes/input_event';


export declare class InputEventJoypadButton extends InputEvent {

    
    /**     * The raw type is 'int'     */
    public button_index: number;    
    /**     * The raw type is 'float'     */
    public pressure: number;    
    /**     * The raw type is 'bool'     */
    public pressed: boolean;
    public set_button_index(buttonIndex: number): void;
    public get_button_index(): number;
    public set_pressure(pressure: number): void;
    public get_pressure(): number;
    public set_pressed(pressed: boolean): void;


}

