
import type { AudioEffect } from '@godot/classes/audio_effect';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';


export declare class AudioEffectCapture extends AudioEffect {

    
    /**     * The raw type is 'float'     */
    public buffer_length: number;
    public can_get_buffer(frames: number): boolean;
    public get_buffer(frames: number): PackedVector2Array;
    public clear_buffer(): void;
    public set_buffer_length(bufferLengthSeconds: number): void;
    public get_buffer_length(): number;
    public get_frames_available(): number;
    public get_discarded_frames(): number;
    public get_buffer_length_frames(): number;
    public get_pushed_frames(): number;


}

