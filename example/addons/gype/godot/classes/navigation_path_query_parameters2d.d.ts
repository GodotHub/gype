
import type { RID } from '@godot/builtins/rid';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class NavigationPathQueryParameters2D extends RefCounted {

    
    /**     * The raw type is 'RID'     */
    public map: RID;    
    /**     * The raw type is 'Vector2'     */
    public start_position: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public target_position: Vector2;    
    /**     * The raw type is 'int'     */
    public navigation_layers: number;    
    /**     * The raw type is 'int'     */
    public pathfinding_algorithm: number;    
    /**     * The raw type is 'int'     */
    public path_postprocessing: number;    
    /**     * The raw type is 'int'     */
    public metadata_flags: number;    
    /**     * The raw type is 'bool'     */
    public simplify_path: boolean;    
    /**     * The raw type is 'float'     */
    public simplify_epsilon: number;    
    /**     * The raw type is 'typedarray::RID'     */
    public excluded_regions: Array<any>;    
    /**     * The raw type is 'typedarray::RID'     */
    public included_regions: Array<any>;    
    /**     * The raw type is 'float'     */
    public path_return_max_length: number;    
    /**     * The raw type is 'float'     */
    public path_return_max_radius: number;    
    /**     * The raw type is 'int'     */
    public path_search_max_polygons: number;    
    /**     * The raw type is 'float'     */
    public path_search_max_distance: number;
    public set_pathfinding_algorithm(pathfindingAlgorithm: number): void;
    public get_pathfinding_algorithm(): number;
    public set_path_postprocessing(pathPostprocessing: number): void;
    public get_path_postprocessing(): number;
    public set_map(map: RID): void;
    public get_map(): RID;
    public set_start_position(startPosition: Vector2): void;
    public get_start_position(): Vector2;
    public set_target_position(targetPosition: Vector2): void;
    public get_target_position(): Vector2;
    public set_navigation_layers(navigationLayers: number): void;
    public get_navigation_layers(): number;
    public set_metadata_flags(flags: number): void;
    public get_metadata_flags(): number;
    public set_simplify_path(enabled: boolean): void;
    public get_simplify_path(): boolean;
    public set_simplify_epsilon(epsilon: number): void;
    public get_simplify_epsilon(): number;
    public set_included_regions(regions: Array<any>): void;
    public get_included_regions(): Array<any>;
    public set_excluded_regions(regions: Array<any>): void;
    public get_excluded_regions(): Array<any>;
    public set_path_return_max_length(length: number): void;
    public get_path_return_max_length(): number;
    public set_path_return_max_radius(radius: number): void;
    public get_path_return_max_radius(): number;
    public set_path_search_max_polygons(maxPolygons: number): void;
    public get_path_search_max_polygons(): number;
    public set_path_search_max_distance(distance: number): void;
    public get_path_search_max_distance(): number;


    public static readonly PathfindingAlgorithm: {
        PATHFINDING_ALGORITHM_ASTAR: 0;
    };
    public static readonly PathPostProcessing: {
        PATH_POSTPROCESSING_CORRIDORFUNNEL: 0;
        PATH_POSTPROCESSING_EDGECENTERED: 1;
        PATH_POSTPROCESSING_NONE: 2;
    };
    public static readonly PathMetadataFlags: {
        PATH_METADATA_INCLUDE_NONE: 0;
        PATH_METADATA_INCLUDE_TYPES: 1;
        PATH_METADATA_INCLUDE_RIDS: 2;
        PATH_METADATA_INCLUDE_OWNERS: 4;
        PATH_METADATA_INCLUDE_ALL: 7;
    };
}

