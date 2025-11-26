
import type { Mesh } from '@godot/classes/mesh';
import type { NavigationMesh } from '@godot/classes/navigation_mesh';
import type { Resource } from '@godot/classes/resource';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class MeshLibrary extends Resource {


    public create_item(id: number): void;
    public set_item_name(id: number, name: GDString | StringName | string): void;
    public set_item_mesh(id: number, mesh: Mesh): void;
    public set_item_mesh_transform(id: number, meshTransform: Transform3D): void;
    public set_item_mesh_cast_shadow(id: number, shadowCastingSetting: number): void;
    public set_item_navigation_mesh(id: number, navigationMesh: NavigationMesh): void;
    public set_item_navigation_mesh_transform(id: number, navigationMesh: Transform3D): void;
    public set_item_navigation_layers(id: number, navigationLayers: number): void;
    public set_item_shapes(id: number, shapes: GDArray): void;
    public set_item_preview(id: number, texture: Texture2D): void;
    public get_item_name(id: number): GDString;
    public get_item_mesh(id: number): Mesh;
    public get_item_mesh_transform(id: number): Transform3D;
    public get_item_mesh_cast_shadow(id: number): number;
    public get_item_navigation_mesh(id: number): NavigationMesh;
    public get_item_navigation_mesh_transform(id: number): Transform3D;
    public get_item_navigation_layers(id: number): number;
    public get_item_shapes(id: number): GDArray;
    public get_item_preview(id: number): Texture2D;
    public remove_item(id: number): void;
    public find_item_by_name(name: GDString | StringName | string): number;
    public clear(): void;
    public get_item_list(): PackedInt32Array;
    public get_last_unused_item_id(): number;


}

