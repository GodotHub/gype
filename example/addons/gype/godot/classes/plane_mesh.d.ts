
import type { PrimitiveMesh } from '@godot/classes/primitive_mesh';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PlaneMesh extends PrimitiveMesh {

    
    /**     * The raw type is 'Vector2'     */
    public size: Vector2;    
    /**     * The raw type is 'int'     */
    public subdivide_width: number;    
    /**     * The raw type is 'int'     */
    public subdivide_depth: number;    
    /**     * The raw type is 'Vector3'     */
    public center_offset: Vector3;    
    /**     * The raw type is 'int'     */
    public orientation: number;
    public set_size(size: Vector2): void;
    public get_size(): Vector2;
    public set_subdivide_width(subdivide: number): void;
    public get_subdivide_width(): number;
    public set_subdivide_depth(subdivide: number): void;
    public get_subdivide_depth(): number;
    public set_center_offset(offset: Vector3): void;
    public get_center_offset(): Vector3;
    public set_orientation(orientation: number): void;
    public get_orientation(): number;


    public static readonly Orientation: {
        FACE_X: 0;
        FACE_Y: 1;
        FACE_Z: 2;
    };
}

