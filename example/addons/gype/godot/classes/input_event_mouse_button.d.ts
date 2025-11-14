
import type { InputEventMouse } from '@godot/classes/input_event_mouse';


export declare class InputEventMouseButton extends InputEventMouse {

    
    /**     * The raw type is 'float'     */
    public factor: number;    
    /**     * The raw type is 'int'     */
    public button_index: number;    
    /**     * The raw type is 'bool'     */
    public canceled: boolean;    
    /**     * The raw type is 'bool'     */
    public pressed: boolean;    
    /**     * The raw type is 'bool'     */
    public double_click: boolean;
    public set_factor(factor: number): void;
    public get_factor(): number;
    public set_button_index(buttonIndex: number): void;
    public get_button_index(): number;
    public set_pressed(pressed: boolean): void;
    public set_canceled(canceled: boolean): void;
    public set_double_click(doubleClick: boolean): void;
    public is_double_click(): boolean;


}

