
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class AudioEffectInstance extends RefCounted {


    public _process(srcBuffer: any, dstBuffer: any, frameCount: number): void;
    public _process_silence(): boolean;


}

