
import type { InputEventWithModifiers } from '@godot/classes/input_event_with_modifiers';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class InputEventGesture extends InputEventWithModifiers {

    
    /**     * The raw type is 'Vector2'     */
    public position: Vector2;
    public set_position(position: Vector2): void;
    public get_position(): Vector2;


}

