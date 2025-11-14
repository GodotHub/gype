
import type { Shape3D } from '@godot/classes/shape3d';


export declare class CylinderShape3D extends Shape3D {

    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'float'     */
    public radius: number;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;


}

