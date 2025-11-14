
import type { AudioStream } from '@godot/classes/audio_stream';


export declare class AudioStreamPolyphonic extends AudioStream {

    
    /**     * The raw type is 'int'     */
    public polyphony: number;
    public set_polyphony(voices: number): void;
    public get_polyphony(): number;


}

