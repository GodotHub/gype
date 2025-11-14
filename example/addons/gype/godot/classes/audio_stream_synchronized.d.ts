
import type { AudioStream } from '@godot/classes/audio_stream';


export declare class AudioStreamSynchronized extends AudioStream {

    
    /**     * The raw type is 'int'     */
    public stream_count: number;
    public set_stream_count(streamCount: number): void;
    public get_stream_count(): number;
    public set_sync_stream(streamIndex: number, audioStream: AudioStream): void;
    public get_sync_stream(streamIndex: number): AudioStream;
    public set_sync_stream_volume(streamIndex: number, volumeDb: number): void;
    public get_sync_stream_volume(streamIndex: number): number;


}

