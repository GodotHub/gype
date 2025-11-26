
import type { InputEventFromWindow } from '@godot/classes/input_event_from_window';


export declare class InputEventScreenTouch extends InputEventFromWindow {

    
    /**     * The raw type is 'int'     */
    public index: number;    
    /**     * The raw type is 'Vector2'     */
    public position: Vector2;    
    /**     * The raw type is 'bool'     */
    public canceled: boolean;    
    /**     * The raw type is 'bool'     */
    public pressed: boolean;    
    /**     * The raw type is 'bool'     */
    public double_tap: boolean;
    public set_index(index: number): void;
    public get_index(): number;
    public set_position(position: Vector2): void;
    public get_position(): Vector2;
    public set_pressed(pressed: boolean): void;
    public set_canceled(canceled: boolean): void;
    public set_double_tap(doubleTap: boolean): void;
    public is_double_tap(): boolean;


}

