
import type { AnimationNodeSync } from '@godot/classes/animation_node_sync';
import type { Curve } from '@godot/classes/curve';


export declare class AnimationNodeTransition extends AnimationNodeSync {

    
    /**     * The raw type is 'float'     */
    public xfade_time: number;    
    /**     * The raw type is 'Curve'     */
    public xfade_curve: Curve;    
    /**     * The raw type is 'bool'     */
    public allow_transition_to_self: boolean;    
    /**     * The raw type is 'int'     */
    public input_count: number;
    public set_input_count(inputCount: number): void;
    public set_input_as_auto_advance(input: number, enable: boolean): void;
    public is_input_set_as_auto_advance(input: number): boolean;
    public set_input_break_loop_at_end(input: number, enable: boolean): void;
    public is_input_loop_broken_at_end(input: number): boolean;
    public set_input_reset(input: number, enable: boolean): void;
    public is_input_reset(input: number): boolean;
    public set_xfade_time(time: number): void;
    public get_xfade_time(): number;
    public set_xfade_curve(curve: Curve): void;
    public get_xfade_curve(): Curve;
    public set_allow_transition_to_self(enable: boolean): void;
    public is_allow_transition_to_self(): boolean;


}

