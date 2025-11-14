
import type { AudioStream } from '@godot/classes/audio_stream';


export declare class AudioStreamRandomizer extends AudioStream {

    
    /**     * The raw type is 'int'     */
    public playback_mode: number;    
    /**     * The raw type is 'float'     */
    public random_pitch: number;    
    /**     * The raw type is 'float'     */
    public random_volume_offset_db: number;    
    /**     * The raw type is 'int'     */
    public streams_count: number;
    public add_stream(index: number, stream: AudioStream, weight: number = 1.0): void;
    public move_stream(indexFrom: number, indexTo: number): void;
    public remove_stream(index: number): void;
    public set_stream(index: number, stream: AudioStream): void;
    public get_stream(index: number): AudioStream;
    public set_stream_probability_weight(index: number, weight: number): void;
    public get_stream_probability_weight(index: number): number;
    public set_streams_count(count: number): void;
    public get_streams_count(): number;
    public set_random_pitch(scale: number): void;
    public get_random_pitch(): number;
    public set_random_volume_offset_db(dbOffset: number): void;
    public get_random_volume_offset_db(): number;
    public set_playback_mode(mode: number): void;
    public get_playback_mode(): number;


    public static readonly PlaybackMode: {
        PLAYBACK_RANDOM_NO_REPEATS: 0;
        PLAYBACK_RANDOM: 1;
        PLAYBACK_SEQUENTIAL: 2;
    };
}

