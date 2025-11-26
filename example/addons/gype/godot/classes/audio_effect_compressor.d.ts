
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectCompressor extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public threshold: number;    
    /**     * The raw type is 'float'     */
    public ratio: number;    
    /**     * The raw type is 'float'     */
    public gain: number;    
    /**     * The raw type is 'float'     */
    public attack_us: number;    
    /**     * The raw type is 'float'     */
    public release_ms: number;    
    /**     * The raw type is 'float'     */
    public mix: number;    
    /**     * The raw type is 'StringName'     */
    public sidechain: StringName;
    public set_threshold(threshold: number): void;
    public get_threshold(): number;
    public set_ratio(ratio: number): void;
    public get_ratio(): number;
    public set_gain(gain: number): void;
    public get_gain(): number;
    public set_attack_us(attackUs: number): void;
    public get_attack_us(): number;
    public set_release_ms(releaseMs: number): void;
    public get_release_ms(): number;
    public set_mix(mix: number): void;
    public get_mix(): number;
    public set_sidechain(sidechain: GDString | StringName | string): void;
    public get_sidechain(): StringName;


}

