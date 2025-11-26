
import type { NavigationPathQueryResult2D } from '@godot/classes/navigation_path_query_result2d';
import type { Node } from '@godot/classes/node';


export declare class NavigationAgent2D extends Node {

    
    /**     * The raw type is 'Vector2'     */
    public target_position: Vector2;    
    /**     * The raw type is 'float'     */
    public path_desired_distance: number;    
    /**     * The raw type is 'float'     */
    public target_desired_distance: number;    
    /**     * The raw type is 'float'     */
    public path_max_distance: number;    
    /**     * The raw type is 'int'     */
    public navigation_layers: number;    
    /**     * The raw type is 'int'     */
    public pathfinding_algorithm: number;    
    /**     * The raw type is 'int'     */
    public path_postprocessing: number;    
    /**     * The raw type is 'int'     */
    public path_metadata_flags: number;    
    /**     * The raw type is 'bool'     */
    public simplify_path: boolean;    
    /**     * The raw type is 'float'     */
    public simplify_epsilon: number;    
    /**     * The raw type is 'float'     */
    public path_return_max_length: number;    
    /**     * The raw type is 'float'     */
    public path_return_max_radius: number;    
    /**     * The raw type is 'int'     */
    public path_search_max_polygons: number;    
    /**     * The raw type is 'float'     */
    public path_search_max_distance: number;    
    /**     * The raw type is 'bool'     */
    public avoidance_enabled: boolean;    
    /**     * The raw type is 'Vector2'     */
    public velocity: Vector2;    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public neighbor_distance: number;    
    /**     * The raw type is 'int'     */
    public max_neighbors: number;    
    /**     * The raw type is 'float'     */
    public time_horizon_agents: number;    
    /**     * The raw type is 'float'     */
    public time_horizon_obstacles: number;    
    /**     * The raw type is 'float'     */
    public max_speed: number;    
    /**     * The raw type is 'int'     */
    public avoidance_layers: number;    
    /**     * The raw type is 'int'     */
    public avoidance_mask: number;    
    /**     * The raw type is 'float'     */
    public avoidance_priority: number;    
    /**     * The raw type is 'bool'     */
    public debug_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public debug_use_custom: boolean;    
    /**     * The raw type is 'Color'     */
    public debug_path_custom_color: Color;    
    /**     * The raw type is 'float'     */
    public debug_path_custom_point_size: number;    
    /**     * The raw type is 'float'     */
    public debug_path_custom_line_width: number;
    public get_rid(): RID;
    public set_avoidance_enabled(enabled: boolean): void;
    public get_avoidance_enabled(): boolean;
    public set_path_desired_distance(desiredDistance: number): void;
    public get_path_desired_distance(): number;
    public set_target_desired_distance(desiredDistance: number): void;
    public get_target_desired_distance(): number;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_neighbor_distance(neighborDistance: number): void;
    public get_neighbor_distance(): number;
    public set_max_neighbors(maxNeighbors: number): void;
    public get_max_neighbors(): number;
    public set_time_horizon_agents(timeHorizon: number): void;
    public get_time_horizon_agents(): number;
    public set_time_horizon_obstacles(timeHorizon: number): void;
    public get_time_horizon_obstacles(): number;
    public set_max_speed(maxSpeed: number): void;
    public get_max_speed(): number;
    public set_path_max_distance(maxSpeed: number): void;
    public get_path_max_distance(): number;
    public set_navigation_layers(navigationLayers: number): void;
    public get_navigation_layers(): number;
    public set_navigation_layer_value(layerNumber: number, value: boolean): void;
    public get_navigation_layer_value(layerNumber: number): boolean;
    public set_pathfinding_algorithm(pathfindingAlgorithm: number): void;
    public get_pathfinding_algorithm(): number;
    public set_path_postprocessing(pathPostprocessing: number): void;
    public get_path_postprocessing(): number;
    public set_path_metadata_flags(flags: number): void;
    public get_path_metadata_flags(): number;
    public set_navigation_map(navigationMap: RID): void;
    public get_navigation_map(): RID;
    public set_target_position(position: Vector2): void;
    public get_target_position(): Vector2;
    public set_simplify_path(enabled: boolean): void;
    public get_simplify_path(): boolean;
    public set_simplify_epsilon(epsilon: number): void;
    public get_simplify_epsilon(): number;
    public set_path_return_max_length(length: number): void;
    public get_path_return_max_length(): number;
    public set_path_return_max_radius(radius: number): void;
    public get_path_return_max_radius(): number;
    public set_path_search_max_polygons(maxPolygons: number): void;
    public get_path_search_max_polygons(): number;
    public set_path_search_max_distance(distance: number): void;
    public get_path_search_max_distance(): number;
    public get_path_length(): number;
    public get_next_path_position(): Vector2;
    public set_velocity_forced(velocity: Vector2): void;
    public set_velocity(velocity: Vector2): void;
    public get_velocity(): Vector2;
    public distance_to_target(): number;
    public get_current_navigation_result(): NavigationPathQueryResult2D;
    public get_current_navigation_path(): PackedVector2Array;
    public get_current_navigation_path_index(): number;
    public is_target_reached(): boolean;
    public is_target_reachable(): boolean;
    public is_navigation_finished(): boolean;
    public get_final_position(): Vector2;
    public set_avoidance_layers(layers: number): void;
    public get_avoidance_layers(): number;
    public set_avoidance_mask(mask: number): void;
    public get_avoidance_mask(): number;
    public set_avoidance_layer_value(layerNumber: number, value: boolean): void;
    public get_avoidance_layer_value(layerNumber: number): boolean;
    public set_avoidance_mask_value(maskNumber: number, value: boolean): void;
    public get_avoidance_mask_value(maskNumber: number): boolean;
    public set_avoidance_priority(priority: number): void;
    public get_avoidance_priority(): number;
    public set_debug_enabled(enabled: boolean): void;
    public get_debug_enabled(): boolean;
    public set_debug_use_custom(enabled: boolean): void;
    public get_debug_use_custom(): boolean;
    public set_debug_path_custom_color(color: Color): void;
    public get_debug_path_custom_color(): Color;
    public set_debug_path_custom_point_size(pointSize: number): void;
    public get_debug_path_custom_point_size(): number;
    public set_debug_path_custom_line_width(lineWidth: number): void;
    public get_debug_path_custom_line_width(): number;

    
    public readonly path_changed: Signal;
    public readonly target_reached: Signal;
    public readonly waypoint_reached: Signal;
    public readonly link_reached: Signal;
    public readonly navigation_finished: Signal;
    public readonly velocity_computed: Signal;

}

