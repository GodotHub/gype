
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class TorusMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'float'     */
    public inner_radius: number;    
    /**     * The raw type is 'float'     */
    public outer_radius: number;    
    /**     * The raw type is 'int'     */
    public rings: number;    
    /**     * The raw type is 'int'     */
    public ring_segments: number;
    public set_inner_radius(radius: number): void;
    public get_inner_radius(): number;
    public set_outer_radius(radius: number): void;
    public get_outer_radius(): number;
    public set_rings(rings: number): void;
    public get_rings(): number;
    public set_ring_segments(rings: number): void;
    public get_ring_segments(): number;


}

