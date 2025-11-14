
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class CylinderMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'float'     */
    public top_radius: number;    
    /**     * The raw type is 'float'     */
    public bottom_radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'int'     */
    public radial_segments: number;    
    /**     * The raw type is 'int'     */
    public rings: number;    
    /**     * The raw type is 'bool'     */
    public cap_top: boolean;    
    /**     * The raw type is 'bool'     */
    public cap_bottom: boolean;
    public set_top_radius(radius: number): void;
    public get_top_radius(): number;
    public set_bottom_radius(radius: number): void;
    public get_bottom_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;
    public set_radial_segments(segments: number): void;
    public get_radial_segments(): number;
    public set_rings(rings: number): void;
    public get_rings(): number;
    public set_cap_top(catop: boolean): void;
    public is_cap_top(): boolean;
    public set_cap_bottom(cabottom: boolean): void;
    public is_cap_bottom(): boolean;


}

