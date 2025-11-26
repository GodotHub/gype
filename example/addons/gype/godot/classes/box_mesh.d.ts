
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';


export declare class BoxMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'int'     */
    public subdivide_width: number;    
    /**     * The raw type is 'int'     */
    public subdivide_height: number;    
    /**     * The raw type is 'int'     */
    public subdivide_depth: number;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_subdivide_width(subdivide: number): void;
    public get_subdivide_width(): number;
    public set_subdivide_height(divisions: number): void;
    public get_subdivide_height(): number;
    public set_subdivide_depth(divisions: number): void;
    public get_subdivide_depth(): number;


}

