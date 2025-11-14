
import type { AABB } from '@godot/builtins/aabb';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { Mesh } from '@godot/classes/mesh';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Resource } from '@godot/classes/resource';
import type { StringName } from '@godot/builtins/string_name';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class NavigationMesh extends Resource {

    
    /**     * The raw type is 'PackedVector3Array'     */
    public vertices: PackedVector3Array;    
    /**     * The raw type is 'Array'     */
    public polygons: GDArray;    
    /**     * The raw type is 'int'     */
    public sample_partition_type: number;    
    /**     * The raw type is 'int'     */
    public geometry_parsed_geometry_type: number;    
    /**     * The raw type is 'int'     */
    public geometry_collision_mask: number;    
    /**     * The raw type is 'int'     */
    public geometry_source_geometry_mode: number;    
    /**     * The raw type is 'String'     */
    public geometry_source_group_name: StringName;    
    /**     * The raw type is 'float'     */
    public cell_size: number;    
    /**     * The raw type is 'float'     */
    public cell_height: number;    
    /**     * The raw type is 'float'     */
    public border_size: number;    
    /**     * The raw type is 'float'     */
    public agent_height: number;    
    /**     * The raw type is 'float'     */
    public agent_radius: number;    
    /**     * The raw type is 'float'     */
    public agent_max_climb: number;    
    /**     * The raw type is 'float'     */
    public agent_max_slope: number;    
    /**     * The raw type is 'float'     */
    public region_min_size: number;    
    /**     * The raw type is 'float'     */
    public region_merge_size: number;    
    /**     * The raw type is 'float'     */
    public edge_max_length: number;    
    /**     * The raw type is 'float'     */
    public edge_max_error: number;    
    /**     * The raw type is 'float'     */
    public vertices_per_polygon: number;    
    /**     * The raw type is 'float'     */
    public detail_sample_distance: number;    
    /**     * The raw type is 'float'     */
    public detail_sample_max_error: number;    
    /**     * The raw type is 'bool'     */
    public filter_low_hanging_obstacles: boolean;    
    /**     * The raw type is 'bool'     */
    public filter_ledge_spans: boolean;    
    /**     * The raw type is 'bool'     */
    public filter_walkable_low_height_spans: boolean;    
    /**     * The raw type is 'AABB'     */
    public filter_baking_aabb: AABB;    
    /**     * The raw type is 'Vector3'     */
    public filter_baking_aabb_offset: Vector3;
    public set_sample_partition_type(samplePartitionType: number): void;
    public get_sample_partition_type(): number;
    public set_parsed_geometry_type(geometryType: number): void;
    public get_parsed_geometry_type(): number;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public set_collision_mask_value(layerNumber: number, value: boolean): void;
    public get_collision_mask_value(layerNumber: number): boolean;
    public set_source_geometry_mode(mask: number): void;
    public get_source_geometry_mode(): number;
    public set_source_group_name(mask: GDString | StringName | string): void;
    public get_source_group_name(): StringName;
    public set_cell_size(cellSize: number): void;
    public get_cell_size(): number;
    public set_cell_height(cellHeight: number): void;
    public get_cell_height(): number;
    public set_border_size(borderSize: number): void;
    public get_border_size(): number;
    public set_agent_height(agentHeight: number): void;
    public get_agent_height(): number;
    public set_agent_radius(agentRadius: number): void;
    public get_agent_radius(): number;
    public set_agent_max_climb(agentMaxClimb: number): void;
    public get_agent_max_climb(): number;
    public set_agent_max_slope(agentMaxSlope: number): void;
    public get_agent_max_slope(): number;
    public set_region_min_size(regionMinSize: number): void;
    public get_region_min_size(): number;
    public set_region_merge_size(regionMergeSize: number): void;
    public get_region_merge_size(): number;
    public set_edge_max_length(edgeMaxLength: number): void;
    public get_edge_max_length(): number;
    public set_edge_max_error(edgeMaxError: number): void;
    public get_edge_max_error(): number;
    public set_vertices_per_polygon(verticesPerPolygon: number): void;
    public get_vertices_per_polygon(): number;
    public set_detail_sample_distance(detailSampleDist: number): void;
    public get_detail_sample_distance(): number;
    public set_detail_sample_max_error(detailSampleMaxError: number): void;
    public get_detail_sample_max_error(): number;
    public set_filter_low_hanging_obstacles(filterLowHangingObstacles: boolean): void;
    public get_filter_low_hanging_obstacles(): boolean;
    public set_filter_ledge_spans(filterLedgeSpans: boolean): void;
    public get_filter_ledge_spans(): boolean;
    public set_filter_walkable_low_height_spans(filterWalkableLowHeightSpans: boolean): void;
    public get_filter_walkable_low_height_spans(): boolean;
    public set_filter_baking_aabb(bakingAabb: AABB): void;
    public get_filter_baking_aabb(): AABB;
    public set_filter_baking_aabb_offset(bakingAabbOffset: Vector3): void;
    public get_filter_baking_aabb_offset(): Vector3;
    public set_vertices(vertices: PackedVector3Array): void;
    public get_vertices(): PackedVector3Array;
    public add_polygon(polygon: PackedInt32Array): void;
    public get_polygon_count(): number;
    public get_polygon(idx: number): PackedInt32Array;
    public clear_polygons(): void;
    public create_from_mesh(mesh: Mesh): void;
    public clear(): void;


    public static readonly SamplePartitionType: {
        SAMPLE_PARTITION_WATERSHED: 0;
        SAMPLE_PARTITION_MONOTONE: 1;
        SAMPLE_PARTITION_LAYERS: 2;
        SAMPLE_PARTITION_MAX: 3;
    };
    public static readonly ParsedGeometryType: {
        PARSED_GEOMETRY_MESH_INSTANCES: 0;
        PARSED_GEOMETRY_STATIC_COLLIDERS: 1;
        PARSED_GEOMETRY_BOTH: 2;
        PARSED_GEOMETRY_MAX: 3;
    };
    public static readonly SourceGeometryMode: {
        SOURCE_GEOMETRY_ROOT_NODE_CHILDREN: 0;
        SOURCE_GEOMETRY_GROUPS_WITH_CHILDREN: 1;
        SOURCE_GEOMETRY_GROUPS_EXPLICIT: 2;
        SOURCE_GEOMETRY_MAX: 3;
    };
}

