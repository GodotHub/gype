
import type { Container } from '@godot/classes/container';
import type { InputEvent } from '@godot/classes/input_event';


export declare class SubViewportContainer extends Container {

    
    /**     * The raw type is 'bool'     */
    public stretch: boolean;    
    /**     * The raw type is 'int'     */
    public stretch_shrink: number;    
    /**     * The raw type is 'bool'     */
    public mouse_target: boolean;
    public _propagate_input_event(event: InputEvent): boolean;
    public set_stretch(enable: boolean): void;
    public is_stretch_enabled(): boolean;
    public set_stretch_shrink(amount: number): void;
    public get_stretch_shrink(): number;
    public set_mouse_target(amount: boolean): void;
    public is_mouse_target_enabled(): boolean;


}

