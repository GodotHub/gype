
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectStereoEnhance extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public pan_pullout: number;    
    /**     * The raw type is 'float'     */
    public time_pullout_ms: number;    
    /**     * The raw type is 'float'     */
    public surround: number;
    public set_pan_pullout(amount: number): void;
    public get_pan_pullout(): number;
    public set_time_pullout(amount: number): void;
    public get_time_pullout(): number;
    public set_surround(amount: number): void;
    public get_surround(): number;


}

