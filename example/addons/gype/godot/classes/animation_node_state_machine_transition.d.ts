
import type { Curve } from '@godot/classes/curve';
import type { Resource } from '@godot/classes/resource';


export declare class AnimationNodeStateMachineTransition extends Resource {

    
    /**     * The raw type is 'float'     */
    public xfade_time: number;    
    /**     * The raw type is 'Curve'     */
    public xfade_curve: Curve;    
    /**     * The raw type is 'bool'     */
    public break_loop_at_end: boolean;    
    /**     * The raw type is 'bool'     */
    public reset: boolean;    
    /**     * The raw type is 'int'     */
    public priority: number;    
    /**     * The raw type is 'int'     */
    public switch_mode: number;    
    /**     * The raw type is 'int'     */
    public advance_mode: number;    
    /**     * The raw type is 'StringName'     */
    public advance_condition: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public advance_expression: GDString | StringName | string;
    public set_switch_mode(mode: number): void;
    public get_switch_mode(): number;
    public set_advance_mode(mode: number): void;
    public get_advance_mode(): number;
    public set_advance_condition(name: GDString | StringName | string): void;
    public get_advance_condition(): StringName;
    public set_xfade_time(secs: number): void;
    public get_xfade_time(): number;
    public set_xfade_curve(curve: Curve): void;
    public get_xfade_curve(): Curve;
    public set_break_loop_at_end(enable: boolean): void;
    public is_loop_broken_at_end(): boolean;
    public set_reset(reset: boolean): void;
    public is_reset(): boolean;
    public set_priority(priority: number): void;
    public get_priority(): number;
    public set_advance_expression(text: GDString | StringName | string): void;
    public get_advance_expression(): GDString;

    
    public readonly advance_condition_changed: Signal;

    public static readonly SwitchMode: {
        SWITCH_MODE_IMMEDIATE: 0;
        SWITCH_MODE_SYNC: 1;
        SWITCH_MODE_AT_END: 2;
    };
    public static readonly AdvanceMode: {
        ADVANCE_MODE_DISABLED: 0;
        ADVANCE_MODE_ENABLED: 1;
        ADVANCE_MODE_AUTO: 2;
    };
}

