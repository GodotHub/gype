
import type { AudioStream } from '@godot/classes/audio_stream';


export declare class AudioStreamGenerator extends AudioStream {

    
    /**     * The raw type is 'int'     */
    public mix_rate_mode: number;    
    /**     * The raw type is 'float'     */
    public mix_rate: number;    
    /**     * The raw type is 'float'     */
    public buffer_length: number;
    public set_mix_rate(hz: number): void;
    public get_mix_rate(): number;
    public set_mix_rate_mode(mode: number): void;
    public get_mix_rate_mode(): number;
    public set_buffer_length(seconds: number): void;
    public get_buffer_length(): number;


    public static readonly AudioStreamGeneratorMixRate: {
        MIX_RATE_OUTPUT: 0;
        MIX_RATE_INPUT: 1;
        MIX_RATE_CUSTOM: 2;
        MIX_RATE_MAX: 3;
    };
}

