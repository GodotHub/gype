
import type { Node2D } from '@godot/classes/node2d';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { RID } from '@godot/builtins/rid';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class NavigationObstacle2D extends Node2D {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'PackedVector2Array'     */
    public vertices: PackedVector2Array;    
    /**     * The raw type is 'bool'     */
    public affect_navigation_mesh: boolean;    
    /**     * The raw type is 'bool'     */
    public carve_navigation_mesh: boolean;    
    /**     * The raw type is 'bool'     */
    public avoidance_enabled: boolean;    
    /**     * The raw type is 'Vector2'     */
    public velocity: Vector2;    
    /**     * The raw type is 'int'     */
    public avoidance_layers: number;
    public get_rid(): RID;
    public set_avoidance_enabled(enabled: boolean): void;
    public get_avoidance_enabled(): boolean;
    public set_navigation_map(navigationMap: RID): void;
    public get_navigation_map(): RID;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_velocity(velocity: Vector2): void;
    public get_velocity(): Vector2;
    public set_vertices(vertices: PackedVector2Array): void;
    public get_vertices(): PackedVector2Array;
    public set_avoidance_layers(layers: number): void;
    public get_avoidance_layers(): number;
    public set_avoidance_layer_value(layerNumber: number, value: boolean): void;
    public get_avoidance_layer_value(layerNumber: number): boolean;
    public set_affect_navigation_mesh(enabled: boolean): void;
    public get_affect_navigation_mesh(): boolean;
    public set_carve_navigation_mesh(enabled: boolean): void;
    public get_carve_navigation_mesh(): boolean;


}

