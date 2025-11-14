
import type { Joint2D } from '@godot/classes/joint2d';


export declare class DampedSpringJoint2D extends Joint2D {

    
    /**     * The raw type is 'float'     */
    public length: number;    
    /**     * The raw type is 'float'     */
    public rest_length: number;    
    /**     * The raw type is 'float'     */
    public stiffness: number;    
    /**     * The raw type is 'float'     */
    public damping: number;
    public set_length(length: number): void;
    public get_length(): number;
    public set_rest_length(restLength: number): void;
    public get_rest_length(): number;
    public set_stiffness(stiffness: number): void;
    public get_stiffness(): number;
    public set_damping(damping: number): void;
    public get_damping(): number;


}

