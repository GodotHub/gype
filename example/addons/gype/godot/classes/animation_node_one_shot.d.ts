
import type { AnimationNodeSync } from '@godot/classes/animation_node_sync';
import type { Curve } from '@godot/classes/curve';


export declare class AnimationNodeOneShot extends AnimationNodeSync {

    
    /**     * The raw type is 'int'     */
    public mix_mode: number;    
    /**     * The raw type is 'float'     */
    public fadein_time: number;    
    /**     * The raw type is 'Curve'     */
    public fadein_curve: Curve;    
    /**     * The raw type is 'float'     */
    public fadeout_time: number;    
    /**     * The raw type is 'Curve'     */
    public fadeout_curve: Curve;    
    /**     * The raw type is 'bool'     */
    public break_loop_at_end: boolean;    
    /**     * The raw type is 'bool'     */
    public autorestart: boolean;    
    /**     * The raw type is 'float'     */
    public autorestart_delay: number;    
    /**     * The raw type is 'float'     */
    public autorestart_random_delay: number;
    public set_fadein_time(time: number): void;
    public get_fadein_time(): number;
    public set_fadein_curve(curve: Curve): void;
    public get_fadein_curve(): Curve;
    public set_fadeout_time(time: number): void;
    public get_fadeout_time(): number;
    public set_fadeout_curve(curve: Curve): void;
    public get_fadeout_curve(): Curve;
    public set_break_loop_at_end(enable: boolean): void;
    public is_loop_broken_at_end(): boolean;
    public set_autorestart(active: boolean): void;
    public has_autorestart(): boolean;
    public set_autorestart_delay(time: number): void;
    public get_autorestart_delay(): number;
    public set_autorestart_random_delay(time: number): void;
    public get_autorestart_random_delay(): number;
    public set_mix_mode(mode: number): void;
    public get_mix_mode(): number;


    public static readonly OneShotRequest: {
        ONE_SHOT_REQUEST_NONE: 0;
        ONE_SHOT_REQUEST_FIRE: 1;
        ONE_SHOT_REQUEST_ABORT: 2;
        ONE_SHOT_REQUEST_FADE_OUT: 3;
    };
    public static readonly MixMode: {
        MIX_MODE_BLEND: 0;
        MIX_MODE_ADD: 1;
    };
}

