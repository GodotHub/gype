
import type { AABB } from '@godot/builtins/aabb';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Mesh } from '@godot/classes/mesh';
import type { PackedFloat32Array } from '@godot/builtins/packed_float32_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Resource } from '@godot/classes/resource';
import type { Transform3D } from '@godot/builtins/transform3d';


export declare class NavigationMeshSourceGeometryData3D extends Resource {

    
    /**     * The raw type is 'PackedVector3Array'     */
    public vertices: PackedFloat32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public indices: PackedInt32Array;    
    /**     * The raw type is 'Array'     */
    public projected_obstructions: GDArray;
    public set_vertices(vertices: PackedFloat32Array): void;
    public get_vertices(): PackedFloat32Array;
    public set_indices(indices: PackedInt32Array): void;
    public get_indices(): PackedInt32Array;
    public append_arrays(vertices: PackedFloat32Array, indices: PackedInt32Array): void;
    public clear(): void;
    public has_data(): boolean;
    public add_mesh(mesh: Mesh, xform: Transform3D): void;
    public add_mesh_array(meshArray: GDArray, xform: Transform3D): void;
    public add_faces(faces: PackedVector3Array, xform: Transform3D): void;
    public merge(otherGeometry: NavigationMeshSourceGeometryData3D): void;
    public add_projected_obstruction(vertices: PackedVector3Array, elevation: number, height: number, carve: boolean): void;
    public clear_projected_obstructions(): void;
    public set_projected_obstructions(projectedObstructions: GDArray): void;
    public get_projected_obstructions(): GDArray;
    public get_bounds(): AABB;


}

