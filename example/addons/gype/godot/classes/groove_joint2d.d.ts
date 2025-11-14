
import type { Joint2D } from '@godot/classes/joint2d';


export declare class GrooveJoint2D extends Joint2D {

    
    /**     * The raw type is 'float'     */
    public length: number;    
    /**     * The raw type is 'float'     */
    public initial_offset: number;
    public set_length(length: number): void;
    public get_length(): number;
    public set_initial_offset(offset: number): void;
    public get_initial_offset(): number;


}

