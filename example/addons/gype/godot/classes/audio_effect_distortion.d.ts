
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectDistortion extends AudioEffect {

    
    /**     * The raw type is 'int'     */
    public mode: number;    
    /**     * The raw type is 'float'     */
    public pre_gain: number;    
    /**     * The raw type is 'float'     */
    public keep_hf_hz: number;    
    /**     * The raw type is 'float'     */
    public drive: number;    
    /**     * The raw type is 'float'     */
    public post_gain: number;
    public set_mode(mode: number): void;
    public get_mode(): number;
    public set_pre_gain(preGain: number): void;
    public get_pre_gain(): number;
    public set_keep_hf_hz(keehfHz: number): void;
    public get_keep_hf_hz(): number;
    public set_drive(drive: number): void;
    public get_drive(): number;
    public set_post_gain(postGain: number): void;
    public get_post_gain(): number;


    public static readonly Mode: {
        MODE_CLIP: 0;
        MODE_ATAN: 1;
        MODE_LOFI: 2;
        MODE_OVERDRIVE: 3;
        MODE_WAVESHAPE: 4;
    };
}

