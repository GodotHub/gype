
import type { AudioStream } from '@godot/classes/audio_stream';


export declare class AudioStreamWAV extends AudioStream {

    
    /**     * The raw type is 'PackedByteArray'     */
    public data: PackedByteArray;    
    /**     * The raw type is 'int'     */
    public format: number;    
    /**     * The raw type is 'int'     */
    public loop_mode: number;    
    /**     * The raw type is 'int'     */
    public loop_begin: number;    
    /**     * The raw type is 'int'     */
    public loop_end: number;    
    /**     * The raw type is 'int'     */
    public mix_rate: number;    
    /**     * The raw type is 'bool'     */
    public stereo: boolean;    
    /**     * The raw type is 'Dictionary'     */
    public tags: Dictionary;
    public static load_from_buffer(streamData: PackedByteArray, options: Dictionary = {}): AudioStreamWAV;
    public static load_from_file(path: GDString | StringName | string, options: Dictionary = {}): AudioStreamWAV;
    public set_data(data: PackedByteArray): void;
    public get_data(): PackedByteArray;
    public set_format(format: number): void;
    public get_format(): number;
    public set_loop_mode(loomode: number): void;
    public get_loop_mode(): number;
    public set_loop_begin(loobegin: number): void;
    public get_loop_begin(): number;
    public set_loop_end(looend: number): void;
    public get_loop_end(): number;
    public set_mix_rate(mixRate: number): void;
    public get_mix_rate(): number;
    public set_stereo(stereo: boolean): void;
    public is_stereo(): boolean;
    public set_tags(tags: Dictionary): void;
    public get_tags(): Dictionary;
    public save_to_wav(path: GDString | StringName | string): number;


    public static readonly Format: {
        FORMAT_8_BITS: 0;
        FORMAT_16_BITS: 1;
        FORMAT_IMA_ADPCM: 2;
        FORMAT_QOA: 3;
    };
    public static readonly LoopMode: {
        LOOP_DISABLED: 0;
        LOOP_FORWARD: 1;
        LOOP_PINGPONG: 2;
        LOOP_BACKWARD: 3;
    };
}

