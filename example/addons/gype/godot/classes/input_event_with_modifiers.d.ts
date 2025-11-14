
import type { InputEventFromWindow } from '@godot/classes/input_event_from_window';


export declare class InputEventWithModifiers extends InputEventFromWindow {

    
    /**     * The raw type is 'bool'     */
    public command_or_control_autoremap: boolean;    
    /**     * The raw type is 'bool'     */
    public alt_pressed: boolean;    
    /**     * The raw type is 'bool'     */
    public shift_pressed: boolean;    
    /**     * The raw type is 'bool'     */
    public ctrl_pressed: boolean;    
    /**     * The raw type is 'bool'     */
    public meta_pressed: boolean;
    public set_command_or_control_autoremap(enable: boolean): void;
    public is_command_or_control_autoremap(): boolean;
    public is_command_or_control_pressed(): boolean;
    public set_alt_pressed(pressed: boolean): void;
    public is_alt_pressed(): boolean;
    public set_shift_pressed(pressed: boolean): void;
    public is_shift_pressed(): boolean;
    public set_ctrl_pressed(pressed: boolean): void;
    public is_ctrl_pressed(): boolean;
    public set_meta_pressed(pressed: boolean): void;
    public is_meta_pressed(): boolean;
    public get_modifiers_mask(): number;


}

