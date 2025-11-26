
import type { AudioStream } from '@godot/classes/audio_stream';


export declare class AudioStreamMP3 extends AudioStream {

    
    /**     * The raw type is 'PackedByteArray'     */
    public data: PackedByteArray;    
    /**     * The raw type is 'float'     */
    public bpm: number;    
    /**     * The raw type is 'int'     */
    public beat_count: number;    
    /**     * The raw type is 'int'     */
    public bar_beats: number;    
    /**     * The raw type is 'bool'     */
    public loop: boolean;    
    /**     * The raw type is 'float'     */
    public loop_offset: number;
    public static load_from_buffer(streamData: PackedByteArray): AudioStreamMP3;
    public static load_from_file(path: GDString | StringName | string): AudioStreamMP3;
    public set_data(data: PackedByteArray): void;
    public get_data(): PackedByteArray;
    public set_loop(enable: boolean): void;
    public has_loop(): boolean;
    public set_loop_offset(seconds: number): void;
    public get_loop_offset(): number;
    public set_bpm(bpm: number): void;
    public get_bpm(): number;
    public set_beat_count(count: number): void;
    public get_beat_count(): number;
    public set_bar_beats(count: number): void;
    public get_bar_beats(): number;


}

