
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectHardLimiter extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public pre_gain_db: number;    
    /**     * The raw type is 'float'     */
    public ceiling_db: number;    
    /**     * The raw type is 'float'     */
    public release: number;
    public set_ceiling_db(ceiling: number): void;
    public get_ceiling_db(): number;
    public set_pre_gain_db(preGain: number): void;
    public get_pre_gain_db(): number;
    public set_release(release: number): void;
    public get_release(): number;


}

