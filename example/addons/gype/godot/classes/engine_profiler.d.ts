
import type { GDArray } from '@godot/builtins/gd_array';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class EngineProfiler extends RefCounted {


    public _toggle(enable: boolean, options: GDArray): void;
    public _add_frame(data: GDArray): void;
    public _tick(frameTime: number, processTime: number, physicsTime: number, physicsFrameTime: number): void;


}

