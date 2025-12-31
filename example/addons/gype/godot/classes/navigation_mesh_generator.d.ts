
import type { GodotObject } from '@godot/classes/godot_object';
import type { NavigationMesh } from '@godot/classes/navigation_mesh';
import type { NavigationMeshSourceGeometryData3D } from '@godot/classes/navigation_mesh_source_geometry_data3d';
import type { Node } from '@godot/classes/node';


export declare class _NavigationMeshGenerator extends GodotObject {


    public bake(navigationMesh: NavigationMesh, rootNode: Node): void;
    public clear(navigationMesh: NavigationMesh): void;
    public parse_source_geometry_data(navigationMesh: NavigationMesh, sourceGeometryData: NavigationMeshSourceGeometryData3D, rootNode: Node, callback: Callable | Function = Callable()): void;
    public bake_from_source_geometry_data(navigationMesh: NavigationMesh, sourceGeometryData: NavigationMeshSourceGeometryData3D, callback: Callable | Function = Callable()): void;


}

export const NavigationMeshGenerator: _NavigationMeshGenerator;
