
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class SphereMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'int'     */
    public radial_segments: number;    
    /**     * The raw type is 'int'     */
    public rings: number;    
    /**     * The raw type is 'bool'     */
    public is_hemisphere: boolean;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;
    public set_radial_segments(radialSegments: number): void;
    public get_radial_segments(): number;
    public set_rings(rings: number): void;
    public get_rings(): number;
    public set_is_hemisphere(isHemisphere: boolean): void;
    public get_is_hemisphere(): boolean;


}

