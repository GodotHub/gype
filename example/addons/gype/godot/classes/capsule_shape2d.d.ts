
import type { Shape2D } from '@godot/classes/shape2d';


export declare class CapsuleShape2D extends Shape2D {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'float'     */
    public mid_height: number;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;
    public set_mid_height(midHeight: number): void;
    public get_mid_height(): number;


}

