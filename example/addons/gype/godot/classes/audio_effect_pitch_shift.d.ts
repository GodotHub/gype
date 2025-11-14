
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectPitchShift extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public pitch_scale: number;    
    /**     * The raw type is 'float'     */
    public oversampling: number;    
    /**     * The raw type is 'int'     */
    public fft_size: number;
    public set_pitch_scale(rate: number): void;
    public get_pitch_scale(): number;
    public set_oversampling(amount: number): void;
    public get_oversampling(): number;
    public set_fft_size(size: number): void;
    public get_fft_size(): number;


    public static readonly FFTSize: {
        FFT_SIZE_256: 0;
        FFT_SIZE_512: 1;
        FFT_SIZE_1024: 2;
        FFT_SIZE_2048: 3;
        FFT_SIZE_4096: 4;
        FFT_SIZE_MAX: 5;
    };
}

