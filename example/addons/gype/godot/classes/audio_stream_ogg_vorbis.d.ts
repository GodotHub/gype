
import type { AudioStream } from '@godot/classes/audio_stream';
import type { GodotObject } from '@godot/classes/godot_object';
import type { OggPacketSequence } from '@godot/classes/ogg_packet_sequence';


export declare class AudioStreamOggVorbis extends AudioStream {

    
    /**     * The raw type is 'Object'     */
    public packet_sequence: OggPacketSequence;    
    /**     * The raw type is 'float'     */
    public bpm: number;    
    /**     * The raw type is 'int'     */
    public beat_count: number;    
    /**     * The raw type is 'int'     */
    public bar_beats: number;    
    /**     * The raw type is 'Dictionary'     */
    public tags: Dictionary;    
    /**     * The raw type is 'bool'     */
    public loop: boolean;    
    /**     * The raw type is 'float'     */
    public loop_offset: number;
    public static load_from_buffer(streamData: PackedByteArray): AudioStreamOggVorbis;
    public static load_from_file(path: GDString | StringName | string): AudioStreamOggVorbis;
    public set_packet_sequence(packetSequence: OggPacketSequence): void;
    public get_packet_sequence(): OggPacketSequence;
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
    public set_tags(tags: Dictionary): void;
    public get_tags(): Dictionary;


}

