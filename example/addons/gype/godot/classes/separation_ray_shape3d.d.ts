
import type { Shape3D } from '@godot/classes/shape3d';


export declare class SeparationRayShape3D extends Shape3D {

    
    /**     * The raw type is 'float'     */
    public length: number;    
    /**     * The raw type is 'bool'     */
    public slide_on_slope: boolean;
    public set_length(length: number): void;
    public get_length(): number;
    public set_slide_on_slope(active: boolean): void;
    public get_slide_on_slope(): boolean;


}

