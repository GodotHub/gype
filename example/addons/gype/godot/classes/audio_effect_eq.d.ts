
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectEQ extends AudioEffect {


    public set_band_gain_db(bandIdx: number, volumeDb: number): void;
    public get_band_gain_db(bandIdx: number): number;
    public get_band_count(): number;


}

