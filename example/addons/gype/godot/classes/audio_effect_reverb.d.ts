
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectReverb extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public predelay_msec: number;    
    /**     * The raw type is 'float'     */
    public predelay_feedback: number;    
    /**     * The raw type is 'float'     */
    public room_size: number;    
    /**     * The raw type is 'float'     */
    public damping: number;    
    /**     * The raw type is 'float'     */
    public spread: number;    
    /**     * The raw type is 'float'     */
    public hipass: number;    
    /**     * The raw type is 'float'     */
    public dry: number;    
    /**     * The raw type is 'float'     */
    public wet: number;
    public set_predelay_msec(msec: number): void;
    public get_predelay_msec(): number;
    public set_predelay_feedback(feedback: number): void;
    public get_predelay_feedback(): number;
    public set_room_size(size: number): void;
    public get_room_size(): number;
    public set_damping(amount: number): void;
    public get_damping(): number;
    public set_spread(amount: number): void;
    public get_spread(): number;
    public set_dry(amount: number): void;
    public get_dry(): number;
    public set_wet(amount: number): void;
    public get_wet(): number;
    public set_hpf(amount: number): void;
    public get_hpf(): number;


}

