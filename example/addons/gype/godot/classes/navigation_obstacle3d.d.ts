
import type { Node3D } from '@godot/classes/node3d';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { RID } from '@godot/builtins/rid';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class NavigationObstacle3D extends Node3D {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'PackedVector3Array'     */
    public vertices: PackedVector3Array;    
    /**     * The raw type is 'bool'     */
    public affect_navigation_mesh: boolean;    
    /**     * The raw type is 'bool'     */
    public carve_navigation_mesh: boolean;    
    /**     * The raw type is 'bool'     */
    public avoidance_enabled: boolean;    
    /**     * The raw type is 'Vector3'     */
    public velocity: Vector3;    
    /**     * The raw type is 'int'     */
    public avoidance_layers: number;    
    /**     * The raw type is 'bool'     */
    public use_3d_avoidance: boolean;
    public get_rid(): RID;
    public set_avoidance_enabled(enabled: boolean): void;
    public get_avoidance_enabled(): boolean;
    public set_navigation_map(navigationMap: RID): void;
    public get_navigation_map(): RID;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_height(height: number): void;
    public get_height(): number;
    public set_velocity(velocity: Vector3): void;
    public get_velocity(): Vector3;
    public set_vertices(vertices: PackedVector3Array): void;
    public get_vertices(): PackedVector3Array;
    public set_avoidance_layers(layers: number): void;
    public get_avoidance_layers(): number;
    public set_avoidance_layer_value(layerNumber: number, value: boolean): void;
    public get_avoidance_layer_value(layerNumber: number): boolean;
    public set_use_3d_avoidance(enabled: boolean): void;
    public get_use_3d_avoidance(): boolean;
    public set_affect_navigation_mesh(enabled: boolean): void;
    public get_affect_navigation_mesh(): boolean;
    public set_carve_navigation_mesh(enabled: boolean): void;
    public get_carve_navigation_mesh(): boolean;


}

