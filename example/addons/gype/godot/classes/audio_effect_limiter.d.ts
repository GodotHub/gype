
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectLimiter extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public ceiling_db: number;    
    /**     * The raw type is 'float'     */
    public threshold_db: number;    
    /**     * The raw type is 'float'     */
    public soft_clip_db: number;    
    /**     * The raw type is 'float'     */
    public soft_clip_ratio: number;
    public set_ceiling_db(ceiling: number): void;
    public get_ceiling_db(): number;
    public set_threshold_db(threshold: number): void;
    public get_threshold_db(): number;
    public set_soft_clip_db(softClip: number): void;
    public get_soft_clip_db(): number;
    public set_soft_clip_ratio(softClip: number): void;
    public get_soft_clip_ratio(): number;


}

