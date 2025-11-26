
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';


export declare class PrimitiveMesh extends Mesh {

    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material: Material;    
    /**     * The raw type is 'AABB'     */
    public custom_aabb: AABB;    
    /**     * The raw type is 'bool'     */
    public flip_faces: boolean;    
    /**     * The raw type is 'bool'     */
    public add_uv2: boolean;    
    /**     * The raw type is 'float'     */
    public uv2_padding: number;
    public _create_mesh_array(): GDArray;
    public set_material(material: Material): void;
    public get_material(): Material;
    public get_mesh_arrays(): GDArray;
    public set_custom_aabb(aabb: AABB): void;
    public get_custom_aabb(): AABB;
    public set_flip_faces(flifaces: boolean): void;
    public get_flip_faces(): boolean;
    public set_add_uv2(addUv2: boolean): void;
    public get_add_uv2(): boolean;
    public set_uv2_padding(uv2Padding: number): void;
    public get_uv2_padding(): number;
    public request_update(): void;


}

