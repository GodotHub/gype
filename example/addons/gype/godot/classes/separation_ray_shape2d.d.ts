
import type { Shape2D } from '@godot/classes/shape2d';


export declare class SeparationRayShape2D extends Shape2D {

    
    /**     * The raw type is 'float'     */
    public length: number;    
    /**     * The raw type is 'bool'     */
    public slide_on_slope: boolean;
    public set_length(length: number): void;
    public get_length(): number;
    public set_slide_on_slope(active: boolean): void;
    public get_slide_on_slope(): boolean;


}

