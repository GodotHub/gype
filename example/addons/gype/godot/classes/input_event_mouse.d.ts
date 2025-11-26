
import type { InputEventWithModifiers } from '@godot/classes/input_event_with_modifiers';


export declare class InputEventMouse extends InputEventWithModifiers {

    
    /**     * The raw type is 'int'     */
    public button_mask: number;    
    /**     * The raw type is 'Vector2'     */
    public position: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public global_position: Vector2;
    public set_button_mask(buttonMask: number): void;
    public get_button_mask(): number;
    public set_position(position: Vector2): void;
    public get_position(): Vector2;
    public set_global_position(globalPosition: Vector2): void;
    public get_global_position(): Vector2;


}

