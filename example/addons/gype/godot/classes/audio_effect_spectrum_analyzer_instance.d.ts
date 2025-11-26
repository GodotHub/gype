
import type { AudioEffectInstance } from '@godot/classes/audio_effect_instance';


export declare class AudioEffectSpectrumAnalyzerInstance extends AudioEffectInstance {


    public get_magnitude_for_frequency_range(fromHz: number, toHz: number, mode: number = 1): Vector2;


    public static readonly MagnitudeMode: {
        MAGNITUDE_AVERAGE: 0;
        MAGNITUDE_MAX: 1;
    };
}

