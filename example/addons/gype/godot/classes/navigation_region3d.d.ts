
import type { AABB } from '@godot/builtins/aabb';
import type { NavigationMesh } from '@godot/classes/navigation_mesh';
import type { Node3D } from '@godot/classes/node3d';
import type { RID } from '@godot/builtins/rid';
import type { Signal } from '@godot/builtins/signal';


export declare class NavigationRegion3D extends Node3D {

    
    /**     * The raw type is 'NavigationMesh'     */
    public navigation_mesh: NavigationMesh;    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public use_edge_connections: boolean;    
    /**     * The raw type is 'int'     */
    public navigation_layers: number;    
    /**     * The raw type is 'float'     */
    public enter_cost: number;    
    /**     * The raw type is 'float'     */
    public travel_cost: number;
    public get_rid(): RID;
    public set_navigation_mesh(navigationMesh: NavigationMesh): void;
    public get_navigation_mesh(): NavigationMesh;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_navigation_map(navigationMap: RID): void;
    public get_navigation_map(): RID;
    public set_use_edge_connections(enabled: boolean): void;
    public get_use_edge_connections(): boolean;
    public set_navigation_layers(navigationLayers: number): void;
    public get_navigation_layers(): number;
    public set_navigation_layer_value(layerNumber: number, value: boolean): void;
    public get_navigation_layer_value(layerNumber: number): boolean;
    public get_region_rid(): RID;
    public set_enter_cost(enterCost: number): void;
    public get_enter_cost(): number;
    public set_travel_cost(travelCost: number): void;
    public get_travel_cost(): number;
    public bake_navigation_mesh(onThread: boolean = true): void;
    public is_baking(): boolean;
    public get_bounds(): AABB;

    
    public readonly navigation_mesh_changed: Signal<() => void>;
    public readonly bake_finished: Signal<() => void>;

}

