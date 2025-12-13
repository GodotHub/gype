
import type { MeshLibrary } from '@godot/classes/mesh_library';
import type { Node3D } from '@godot/classes/node3d';
import type { PhysicsMaterial } from '@godot/classes/physics_material';
import type { Resource } from '@godot/classes/resource';


export declare class GridMap extends Node3D {

    
    /**     * The raw type is 'MeshLibrary'     */
    public mesh_library: MeshLibrary;    
    /**     * The raw type is 'PhysicsMaterial'     */
    public physics_material: PhysicsMaterial;    
    /**     * The raw type is 'Vector3'     */
    public cell_size: Vector3;    
    /**     * The raw type is 'int'     */
    public cell_octant_size: number;    
    /**     * The raw type is 'bool'     */
    public cell_center_x: boolean;    
    /**     * The raw type is 'bool'     */
    public cell_center_y: boolean;    
    /**     * The raw type is 'bool'     */
    public cell_center_z: boolean;    
    /**     * The raw type is 'float'     */
    public cell_scale: number;    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'float'     */
    public collision_priority: number;    
    /**     * The raw type is 'bool'     */
    public bake_navigation: boolean;
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
    public set_physics_material(material: PhysicsMaterial): void;
    public get_physics_material(): PhysicsMaterial;
    public set_bake_navigation(bakeNavigation: boolean): void;
    public is_baking_navigation(): boolean;
    public set_navigation_map(navigationMap: RID): void;
    public get_navigation_map(): RID;
    public set_mesh_library(meshLibrary: MeshLibrary): void;
    public get_mesh_library(): MeshLibrary;
    public set_cell_size(size: Vector3): void;
    public get_cell_size(): Vector3;
    public set_cell_scale(scale: number): void;
    public get_cell_scale(): number;
    public set_octant_size(size: number): void;
    public get_octant_size(): number;
    public set_cell_item(position: Vector3i, item: number, orientation: number = 0): void;
    public get_cell_item(position: Vector3i): number;
    public get_cell_item_orientation(position: Vector3i): number;
    public get_cell_item_basis(position: Vector3i): Basis;
    public get_basis_with_orthogonal_index(index: number): Basis;
    public get_orthogonal_index_from_basis(basis: Basis): number;
    public local_to_map(localPosition: Vector3): Vector3i;
    public map_to_local(maposition: Vector3i): Vector3;
    public resource_changed(resource: Resource): void;
    public set_center_x(enable: boolean): void;
    public get_center_x(): boolean;
    public set_center_y(enable: boolean): void;
    public get_center_y(): boolean;
    public set_center_z(enable: boolean): void;
    public get_center_z(): boolean;
    public clear(): void;
    public get_used_cells(): Array<any>;
    public get_used_cells_by_item(item: number): Array<any>;
    public get_meshes(): GDArray;
    public get_bake_meshes(): GDArray;
    public get_bake_mesh_instance(idx: number): RID;
    public clear_baked_meshes(): void;
    public make_baked_meshes(genLightmauv: boolean = false, lightmauvTexelSize: number = 0.1): void;

    
    public readonly cell_size_changed: Signal<(cellSize: Vector3) => void>;
    public readonly changed: Signal<() => void>;

}

