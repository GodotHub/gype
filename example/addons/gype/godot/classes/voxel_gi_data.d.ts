
import type { AABB } from '@godot/builtins/aabb';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { Resource } from '@godot/classes/resource';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class VoxelGIData extends Resource {

    
    /**     * The raw type is 'float'     */
    public dynamic_range: number;    
    /**     * The raw type is 'float'     */
    public energy: number;    
    /**     * The raw type is 'float'     */
    public bias: number;    
    /**     * The raw type is 'float'     */
    public normal_bias: number;    
    /**     * The raw type is 'float'     */
    public propagation: number;    
    /**     * The raw type is 'bool'     */
    public use_two_bounces: boolean;    
    /**     * The raw type is 'bool'     */
    public interior: boolean;
    public allocate(toCellXform: Transform3D, aabb: AABB, octreeSize: Vector3, octreeCells: PackedByteArray, dataCells: PackedByteArray, distanceField: PackedByteArray, levelCounts: PackedInt32Array): void;
    public get_bounds(): AABB;
    public get_octree_size(): Vector3;
    public get_to_cell_xform(): Transform3D;
    public get_octree_cells(): PackedByteArray;
    public get_data_cells(): PackedByteArray;
    public get_level_counts(): PackedInt32Array;
    public set_dynamic_range(dynamicRange: number): void;
    public get_dynamic_range(): number;
    public set_energy(energy: number): void;
    public get_energy(): number;
    public set_bias(bias: number): void;
    public get_bias(): number;
    public set_normal_bias(bias: number): void;
    public get_normal_bias(): number;
    public set_propagation(propagation: number): void;
    public get_propagation(): number;
    public set_interior(interior: boolean): void;
    public is_interior(): boolean;
    public set_use_two_bounces(enable: boolean): void;
    public is_using_two_bounces(): boolean;


}

