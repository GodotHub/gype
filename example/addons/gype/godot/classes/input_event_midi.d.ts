
import type { InputEvent } from '@godot/classes/input_event';


export declare class InputEventMIDI extends InputEvent {

    
    /**     * The raw type is 'int'     */
    public channel: number;    
    /**     * The raw type is 'int'     */
    public message: number;    
    /**     * The raw type is 'int'     */
    public pitch: number;    
    /**     * The raw type is 'int'     */
    public velocity: number;    
    /**     * The raw type is 'int'     */
    public instrument: number;    
    /**     * The raw type is 'int'     */
    public pressure: number;    
    /**     * The raw type is 'int'     */
    public controller_number: number;    
    /**     * The raw type is 'int'     */
    public controller_value: number;
    public set_channel(channel: number): void;
    public get_channel(): number;
    public set_message(message: number): void;
    public get_message(): number;
    public set_pitch(pitch: number): void;
    public get_pitch(): number;
    public set_velocity(velocity: number): void;
    public get_velocity(): number;
    public set_instrument(instrument: number): void;
    public get_instrument(): number;
    public set_pressure(pressure: number): void;
    public get_pressure(): number;
    public set_controller_number(controllerNumber: number): void;
    public get_controller_number(): number;
    public set_controller_value(controllerValue: number): void;
    public get_controller_value(): number;


}

