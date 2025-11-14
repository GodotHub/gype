
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectDelay extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public dry: number;    
    /**     * The raw type is 'bool'     */
    public tap1_active: boolean;    
    /**     * The raw type is 'float'     */
    public tap1_delay_ms: number;    
    /**     * The raw type is 'float'     */
    public tap1_level_db: number;    
    /**     * The raw type is 'float'     */
    public tap1_pan: number;    
    /**     * The raw type is 'bool'     */
    public tap2_active: boolean;    
    /**     * The raw type is 'float'     */
    public tap2_delay_ms: number;    
    /**     * The raw type is 'float'     */
    public tap2_level_db: number;    
    /**     * The raw type is 'float'     */
    public tap2_pan: number;    
    /**     * The raw type is 'bool'     */
    public feedback_active: boolean;    
    /**     * The raw type is 'float'     */
    public feedback_delay_ms: number;    
    /**     * The raw type is 'float'     */
    public feedback_level_db: number;    
    /**     * The raw type is 'float'     */
    public feedback_lowpass: number;
    public set_dry(amount: number): void;
    public get_dry(): number;
    public set_tap1_active(amount: boolean): void;
    public is_tap1_active(): boolean;
    public set_tap1_delay_ms(amount: number): void;
    public get_tap1_delay_ms(): number;
    public set_tap1_level_db(amount: number): void;
    public get_tap1_level_db(): number;
    public set_tap1_pan(amount: number): void;
    public get_tap1_pan(): number;
    public set_tap2_active(amount: boolean): void;
    public is_tap2_active(): boolean;
    public set_tap2_delay_ms(amount: number): void;
    public get_tap2_delay_ms(): number;
    public set_tap2_level_db(amount: number): void;
    public get_tap2_level_db(): number;
    public set_tap2_pan(amount: number): void;
    public get_tap2_pan(): number;
    public set_feedback_active(amount: boolean): void;
    public is_feedback_active(): boolean;
    public set_feedback_delay_ms(amount: number): void;
    public get_feedback_delay_ms(): number;
    public set_feedback_level_db(amount: number): void;
    public get_feedback_level_db(): number;
    public set_feedback_lowpass(amount: number): void;
    public get_feedback_lowpass(): number;


}

