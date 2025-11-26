
import type { Mesh } from '@godot/classes/mesh';


export declare class ArrayMesh extends Mesh {

    
    /**     * The raw type is 'int'     */
    public blend_shape_mode: number;    
    /**     * The raw type is 'AABB'     */
    public custom_aabb: AABB;    
    /**     * The raw type is 'ArrayMesh'     */
    public shadow_mesh: ArrayMesh;
    public add_blend_shape(name: GDString | StringName | string): void;
    public get_blend_shape_count(): number;
    public get_blend_shape_name(index: number): StringName;
    public set_blend_shape_name(index: number, name: GDString | StringName | string): void;
    public clear_blend_shapes(): void;
    public set_blend_shape_mode(mode: number): void;
    public get_blend_shape_mode(): number;
    public add_surface_from_arrays(primitive: number, arrays: GDArray, blendShapes: Array<any> = [], lods: Dictionary = {}, flags: number = 0): void;
    public clear_surfaces(): void;
    public surface_remove(surfIdx: number): void;
    public surface_update_vertex_region(surfIdx: number, offset: number, data: PackedByteArray): void;
    public surface_update_attribute_region(surfIdx: number, offset: number, data: PackedByteArray): void;
    public surface_update_skin_region(surfIdx: number, offset: number, data: PackedByteArray): void;
    public surface_get_array_len(surfIdx: number): number;
    public surface_get_array_index_len(surfIdx: number): number;
    public surface_get_format(surfIdx: number): number;
    public surface_get_primitive_type(surfIdx: number): number;
    public surface_find_by_name(name: GDString | StringName | string): number;
    public surface_set_name(surfIdx: number, name: GDString | StringName | string): void;
    public surface_get_name(surfIdx: number): GDString;
    public regen_normal_maps(): void;
    public lightmap_unwrap(transform: Transform3D, texelSize: number): number;
    public set_custom_aabb(aabb: AABB): void;
    public get_custom_aabb(): AABB;
    public set_shadow_mesh(mesh: ArrayMesh): void;
    public get_shadow_mesh(): ArrayMesh;


}

