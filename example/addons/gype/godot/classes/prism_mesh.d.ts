
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PrismMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'float'     */
    public left_to_right: number;    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'int'     */
    public subdivide_width: number;    
    /**     * The raw type is 'int'     */
    public subdivide_height: number;    
    /**     * The raw type is 'int'     */
    public subdivide_depth: number;
    public set_left_to_right(leftToRight: number): void;
    public get_left_to_right(): number;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_subdivide_width(segments: number): void;
    public get_subdivide_width(): number;
    public set_subdivide_height(segments: number): void;
    public get_subdivide_height(): number;
    public set_subdivide_depth(segments: number): void;
    public get_subdivide_depth(): number;


}

