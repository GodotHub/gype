
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectPhaser extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public range_min_hz: number;    
    /**     * The raw type is 'float'     */
    public range_max_hz: number;    
    /**     * The raw type is 'float'     */
    public rate_hz: number;    
    /**     * The raw type is 'float'     */
    public feedback: number;    
    /**     * The raw type is 'float'     */
    public depth: number;
    public set_range_min_hz(hz: number): void;
    public get_range_min_hz(): number;
    public set_range_max_hz(hz: number): void;
    public get_range_max_hz(): number;
    public set_rate_hz(hz: number): void;
    public get_rate_hz(): number;
    public set_feedback(fbk: number): void;
    public get_feedback(): number;
    public set_depth(depth: number): void;
    public get_depth(): number;


}

