
import type { AudioEffect } from '@godot/classes/audio_effect';
import type { AudioStreamWAV } from '@godot/classes/audio_stream_wav';


export declare class AudioEffectRecord extends AudioEffect {

    
    /**     * The raw type is 'int'     */
    public format: number;
    public set_recording_active(record: boolean): void;
    public is_recording_active(): boolean;
    public set_format(format: number): void;
    public get_format(): number;
    public get_recording(): AudioStreamWAV;


}

