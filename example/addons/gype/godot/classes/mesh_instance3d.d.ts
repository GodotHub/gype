
import type { ArrayMesh } from '@godot/classes/array_mesh';
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';
import type { Material } from '@godot/classes/material';
import type { Mesh } from '@godot/classes/mesh';
import type { MeshConvexDecompositionSettings } from '@godot/classes/mesh_convex_decomposition_settings';
import type { Skin } from '@godot/classes/skin';
import type { SkinReference } from '@godot/classes/skin_reference';


export declare class MeshInstance3D extends GeometryInstance3D {

    
    /**     * The raw type is 'Mesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'Skin'     */
    public skin: Skin;    
    /**     * The raw type is 'NodePath'     */
    public skeleton: NodePath;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_skeleton_path(skeletonPath: NodePath | GDString | string): void;
    public get_skeleton_path(): NodePath;
    public set_skin(skin: Skin): void;
    public get_skin(): Skin;
    public get_skin_reference(): SkinReference;
    public get_surface_override_material_count(): number;
    public set_surface_override_material(surface: number, material: Material): void;
    public get_surface_override_material(surface: number): Material;
    public get_active_material(surface: number): Material;
    public create_trimesh_collision(): void;
    public create_convex_collision(clean: boolean = true, simplify: boolean = false): void;
    public create_multiple_convex_collisions(settings: MeshConvexDecompositionSettings = null): void;
    public get_blend_shape_count(): number;
    public find_blend_shape_by_name(name: GDString | StringName | string): number;
    public get_blend_shape_value(blendShapeIdx: number): number;
    public set_blend_shape_value(blendShapeIdx: number, value: number): void;
    public create_debug_tangents(): void;
    public bake_mesh_from_current_blend_shape_mix(existing: ArrayMesh = null): ArrayMesh;
    public bake_mesh_from_current_skeleton_pose(existing: ArrayMesh = null): ArrayMesh;


}

