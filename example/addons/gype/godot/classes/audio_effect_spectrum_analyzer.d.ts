
import type { AudioEffect } from '@godot/classes/audio_effect';


export declare class AudioEffectSpectrumAnalyzer extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public buffer_length: number;    
    /**     * The raw type is 'float'     */
    public tap_back_pos: number;    
    /**     * The raw type is 'int'     */
    public fft_size: number;
    public set_buffer_length(seconds: number): void;
    public get_buffer_length(): number;
    public set_tap_back_pos(seconds: number): void;
    public get_tap_back_pos(): number;
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

