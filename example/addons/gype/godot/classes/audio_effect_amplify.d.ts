
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectAmplify extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public volume_db: number;    
    /**     * The raw type is 'float'     */
    public volume_linear: number;
    public set_volume_db(volume: number): void;
    public get_volume_db(): number;
    public set_volume_linear(volume: number): void;
    public get_volume_linear(): number;


}

