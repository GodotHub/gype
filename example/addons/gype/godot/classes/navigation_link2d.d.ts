
import type { Node2D } from '@godot/classes/node2d';
import type { RID } from '@godot/builtins/rid';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class NavigationLink2D extends Node2D {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public bidirectional: boolean;    
    /**     * The raw type is 'int'     */
    public navigation_layers: number;    
    /**     * The raw type is 'Vector2'     */
    public start_position: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public end_position: Vector2;    
    /**     * The raw type is 'float'     */
    public enter_cost: number;    
    /**     * The raw type is 'float'     */
    public travel_cost: number;
    public get_rid(): RID;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_navigation_map(navigationMap: RID): void;
    public get_navigation_map(): RID;
    public set_bidirectional(bidirectional: boolean): void;
    public is_bidirectional(): boolean;
    public set_navigation_layers(navigationLayers: number): void;
    public get_navigation_layers(): number;
    public set_navigation_layer_value(layerNumber: number, value: boolean): void;
    public get_navigation_layer_value(layerNumber: number): boolean;
    public set_start_position(position: Vector2): void;
    public get_start_position(): Vector2;
    public set_end_position(position: Vector2): void;
    public get_end_position(): Vector2;
    public set_global_start_position(position: Vector2): void;
    public get_global_start_position(): Vector2;
    public set_global_end_position(position: Vector2): void;
    public get_global_end_position(): Vector2;
    public set_enter_cost(enterCost: number): void;
    public get_enter_cost(): number;
    public set_travel_cost(travelCost: number): void;
    public get_travel_cost(): number;


}

