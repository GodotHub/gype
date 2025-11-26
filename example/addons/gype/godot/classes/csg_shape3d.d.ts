
import type { ArrayMesh } from '@godot/classes/array_mesh';
import type { ConcavePolygonShape3D } from '@godot/classes/concave_polygon_shape3d';
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';


export declare class CSGShape3D extends GeometryInstance3D {

    
    /**     * The raw type is 'int'     */
    public operation: number;    
    /**     * The raw type is 'float'     */
    public snap: number;    
    /**     * The raw type is 'bool'     */
    public calculate_tangents: boolean;    
    /**     * The raw type is 'bool'     */
    public use_collision: boolean;    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'float'     */
    public collision_priority: number;
    public is_root_shape(): boolean;
    public set_operation(operation: number): void;
    public get_operation(): number;
    public set_snap(snap: number): void;
    public get_snap(): number;
    public set_use_collision(operation: boolean): void;
    public is_using_collision(): boolean;
    public set_collision_layer(layer: number): void;
    public get_collision_layer(): number;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public set_collision_mask_value(layerNumber: number, value: boolean): void;
    public get_collision_mask_value(layerNumber: number): boolean;
    public set_collision_layer_value(layerNumber: number, value: boolean): void;
    public get_collision_layer_value(layerNumber: number): boolean;
    public set_collision_priority(priority: number): void;
    public get_collision_priority(): number;
    public bake_collision_shape(): ConcavePolygonShape3D;
    public set_calculate_tangents(enabled: boolean): void;
    public is_calculating_tangents(): boolean;
    public get_meshes(): GDArray;
    public bake_static_mesh(): ArrayMesh;


    public static readonly Operation: {
        OPERATION_UNION: 0;
        OPERATION_INTERSECTION: 1;
        OPERATION_SUBTRACTION: 2;
    };
}

