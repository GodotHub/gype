
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class SceneTreeTimer extends RefCounted {

    
    /**     * The raw type is 'float'     */
    public time_left: number;
    public set_time_left(time: number): void;
    public get_time_left(): number;

    
    public readonly timeout: Signal<() => void>;

}

