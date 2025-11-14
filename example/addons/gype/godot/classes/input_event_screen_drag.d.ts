
import type { InputEventFromWindow } from '@godot/classes/input_event_from_window';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class InputEventScreenDrag extends InputEventFromWindow {

    
    /**     * The raw type is 'int'     */
    public index: number;    
    /**     * The raw type is 'Vector2'     */
    public tilt: Vector2;    
    /**     * The raw type is 'float'     */
    public pressure: number;    
    /**     * The raw type is 'bool'     */
    public pen_inverted: boolean;    
    /**     * The raw type is 'Vector2'     */
    public position: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public relative: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public screen_relative: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public velocity: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public screen_velocity: Vector2;
    public set_index(index: number): void;
    public get_index(): number;
    public set_tilt(tilt: Vector2): void;
    public get_tilt(): Vector2;
    public set_pressure(pressure: number): void;
    public get_pressure(): number;
    public set_pen_inverted(penInverted: boolean): void;
    public get_pen_inverted(): boolean;
    public set_position(position: Vector2): void;
    public get_position(): Vector2;
    public set_relative(relative: Vector2): void;
    public get_relative(): Vector2;
    public set_screen_relative(relative: Vector2): void;
    public get_screen_relative(): Vector2;
    public set_velocity(velocity: Vector2): void;
    public get_velocity(): Vector2;
    public set_screen_velocity(velocity: Vector2): void;
    public get_screen_velocity(): Vector2;


}

