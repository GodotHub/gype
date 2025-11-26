
import type { NavigationPolygon } from '@godot/classes/navigation_polygon';
import type { Node2D } from '@godot/classes/node2d';


export declare class NavigationRegion2D extends Node2D {

    
    /**     * The raw type is 'NavigationPolygon'     */
    public navigation_polygon: NavigationPolygon;    
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
    public set_navigation_polygon(navigationPolygon: NavigationPolygon): void;
    public get_navigation_polygon(): NavigationPolygon;
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
    public bake_navigation_polygon(onThread: boolean = true): void;
    public is_baking(): boolean;
    public get_bounds(): Rect2;

    
    public readonly navigation_polygon_changed: Signal;
    public readonly bake_finished: Signal;

}

