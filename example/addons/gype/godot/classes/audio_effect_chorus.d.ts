
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectChorus extends AudioEffect {

    
    /**     * The raw type is 'int'     */
    public voice_count: number;    
    /**     * The raw type is 'float'     */
    public dry: number;    
    /**     * The raw type is 'float'     */
    public wet: number;
    public set_voice_count(voices: number): void;
    public get_voice_count(): number;
    public set_voice_delay_ms(voiceIdx: number, delayMs: number): void;
    public get_voice_delay_ms(voiceIdx: number): number;
    public set_voice_rate_hz(voiceIdx: number, rateHz: number): void;
    public get_voice_rate_hz(voiceIdx: number): number;
    public set_voice_depth_ms(voiceIdx: number, depthMs: number): void;
    public get_voice_depth_ms(voiceIdx: number): number;
    public set_voice_level_db(voiceIdx: number, levelDb: number): void;
    public get_voice_level_db(voiceIdx: number): number;
    public set_voice_cutoff_hz(voiceIdx: number, cutoffHz: number): void;
    public get_voice_cutoff_hz(voiceIdx: number): number;
    public set_voice_pan(voiceIdx: number, pan: number): void;
    public get_voice_pan(voiceIdx: number): number;
    public set_wet(amount: number): void;
    public get_wet(): number;
    public set_dry(amount: number): void;
    public get_dry(): number;


}

