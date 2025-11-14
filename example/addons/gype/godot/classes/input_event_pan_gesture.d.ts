
import type { InputEventGesture } from '@godot/classes/input_event_gesture';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class InputEventPanGesture extends InputEventGesture {

    
    /**     * The raw type is 'Vector2'     */
    public delta: Vector2;
    public set_delta(delta: Vector2): void;
    public get_delta(): Vector2;


}

