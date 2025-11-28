
import type { NavigationMesh } from '@godot/classes/navigation_mesh';
import type { Resource } from '@godot/classes/resource';


export declare class NavigationPolygon extends Resource {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public vertices: PackedVector2Array;    
    /**     * The raw type is 'Array'     */
    public polygons: GDArray | Array;    
    /**     * The raw type is 'Array'     */
    public outlines: GDArray | Array;    
    /**     * The raw type is 'int'     */
    public sample_partition_type: number;    
    /**     * The raw type is 'int'     */
    public parsed_geometry_type: number;    
    /**     * The raw type is 'int'     */
    public parsed_collision_mask: number;    
    /**     * The raw type is 'int'     */
    public source_geometry_mode: number;    
    /**     * The raw type is 'String'     */
    public source_geometry_group_name: GDString | StringName | string;    
    /**     * The raw type is 'float'     */
    public cell_size: number;    
    /**     * The raw type is 'float'     */
    public border_size: number;    
    /**     * The raw type is 'float'     */
    public agent_radius: number;    
    /**     * The raw type is 'Rect2'     */
    public baking_rect: Rect2;    
    /**     * The raw type is 'Vector2'     */
    public baking_rect_offset: Vector2;
    public set_vertices(vertices: PackedVector2Array): void;
    public get_vertices(): PackedVector2Array;
    public add_polygon(polygon: PackedInt32Array): void;
    public get_polygon_count(): number;
    public get_polygon(idx: number): PackedInt32Array;
    public clear_polygons(): void;
    public get_navigation_mesh(): NavigationMesh;
    public add_outline(outline: PackedVector2Array): void;
    public add_outline_at_index(outline: PackedVector2Array, index: number): void;
    public get_outline_count(): number;
    public set_outline(idx: number, outline: PackedVector2Array): void;
    public get_outline(idx: number): PackedVector2Array;
    public remove_outline(idx: number): void;
    public clear_outlines(): void;
    public make_polygons_from_outlines(): void;
    public set_cell_size(cellSize: number): void;
    public get_cell_size(): number;
    public set_border_size(borderSize: number): void;
    public get_border_size(): number;
    public set_sample_partition_type(samplePartitionType: number): void;
    public get_sample_partition_type(): number;
    public set_parsed_geometry_type(geometryType: number): void;
    public get_parsed_geometry_type(): number;
    public set_parsed_collision_mask(mask: number): void;
    public get_parsed_collision_mask(): number;
    public set_parsed_collision_mask_value(layerNumber: number, value: boolean): void;
    public get_parsed_collision_mask_value(layerNumber: number): boolean;
    public set_source_geometry_mode(geometryMode: number): void;
    public get_source_geometry_mode(): number;
    public set_source_geometry_group_name(grouname: GDString | StringName | string): void;
    public get_source_geometry_group_name(): StringName;
    public set_agent_radius(agentRadius: number): void;
    public get_agent_radius(): number;
    public set_baking_rect(rect: Rect2): void;
    public get_baking_rect(): Rect2;
    public set_baking_rect_offset(rectOffset: Vector2): void;
    public get_baking_rect_offset(): Vector2;
    public clear(): void;


    public static readonly SamplePartitionType: {
        SAMPLE_PARTITION_CONVEX_PARTITION: 0;
        SAMPLE_PARTITION_TRIANGULATE: 1;
        SAMPLE_PARTITION_MAX: 2;
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

