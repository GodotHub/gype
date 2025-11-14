
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectFilter extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public cutoff_hz: number;    
    /**     * The raw type is 'float'     */
    public resonance: number;    
    /**     * The raw type is 'float'     */
    public gain: number;    
    /**     * The raw type is 'int'     */
    public db: number;
    public set_cutoff(freq: number): void;
    public get_cutoff(): number;
    public set_resonance(amount: number): void;
    public get_resonance(): number;
    public set_gain(amount: number): void;
    public get_gain(): number;
    public set_db(amount: number): void;
    public get_db(): number;


    public static readonly FilterDB: {
        FILTER_6DB: 0;
        FILTER_12DB: 1;
        FILTER_18DB: 2;
        FILTER_24DB: 3;
    };
}

