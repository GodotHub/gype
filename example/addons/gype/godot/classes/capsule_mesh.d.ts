
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class CapsuleMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'int'     */
    public radial_segments: number;    
    /**     * The raw type is 'int'     */
    public rings: number;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;
    public set_radial_segments(segments: number): void;
    public get_radial_segments(): number;
    public set_rings(rings: number): void;
    public get_rings(): number;


}

