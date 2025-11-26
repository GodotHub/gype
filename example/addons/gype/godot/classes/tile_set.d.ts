
import type { PhysicsMaterial } from '@godot/classes/physics_material';
import type { Resource } from '@godot/classes/resource';
import type { TileMapPattern } from '@godot/classes/tile_map_pattern';
import type { TileSetSource } from '@godot/classes/tile_set_source';


export declare class TileSet extends Resource {

    
    /**     * The raw type is 'int'     */
    public tile_shape: number;    
    /**     * The raw type is 'int'     */
    public tile_layout: number;    
    /**     * The raw type is 'int'     */
    public tile_offset_axis: number;    
    /**     * The raw type is 'Vector2i'     */
    public tile_size: Vector2i;    
    /**     * The raw type is 'bool'     */
    public uv_clipping: boolean;
    public get_next_source_id(): number;
    public add_source(source: TileSetSource, atlasSourceIdOverride: number = -1): number;
    public remove_source(sourceId: number): void;
    public set_source_id(sourceId: number, newSourceId: number): void;
    public get_source_count(): number;
    public get_source_id(index: number): number;
    public has_source(sourceId: number): boolean;
    public get_source(sourceId: number): TileSetSource;
    public set_tile_shape(shape: number): void;
    public get_tile_shape(): number;
    public set_tile_layout(layout: number): void;
    public get_tile_layout(): number;
    public set_tile_offset_axis(alignment: number): void;
    public get_tile_offset_axis(): number;
    public set_tile_size(size: Vector2i): void;
    public get_tile_size(): Vector2i;
    public set_uv_clipping(uvClipping: boolean): void;
    public is_uv_clipping(): boolean;
    public get_occlusion_layers_count(): number;
    public add_occlusion_layer(toPosition: number = -1): void;
    public move_occlusion_layer(layerIndex: number, toPosition: number): void;
    public remove_occlusion_layer(layerIndex: number): void;
    public set_occlusion_layer_light_mask(layerIndex: number, lightMask: number): void;
    public get_occlusion_layer_light_mask(layerIndex: number): number;
    public set_occlusion_layer_sdf_collision(layerIndex: number, sdfCollision: boolean): void;
    public get_occlusion_layer_sdf_collision(layerIndex: number): boolean;
    public get_physics_layers_count(): number;
    public add_physics_layer(toPosition: number = -1): void;
    public move_physics_layer(layerIndex: number, toPosition: number): void;
    public remove_physics_layer(layerIndex: number): void;
    public set_physics_layer_collision_layer(layerIndex: number, layer: number): void;
    public get_physics_layer_collision_layer(layerIndex: number): number;
    public set_physics_layer_collision_mask(layerIndex: number, mask: number): void;
    public get_physics_layer_collision_mask(layerIndex: number): number;
    public set_physics_layer_collision_priority(layerIndex: number, priority: number): void;
    public get_physics_layer_collision_priority(layerIndex: number): number;
    public set_physics_layer_physics_material(layerIndex: number, physicsMaterial: PhysicsMaterial): void;
    public get_physics_layer_physics_material(layerIndex: number): PhysicsMaterial;
    public get_terrain_sets_count(): number;
    public add_terrain_set(toPosition: number = -1): void;
    public move_terrain_set(terrainSet: number, toPosition: number): void;
    public remove_terrain_set(terrainSet: number): void;
    public set_terrain_set_mode(terrainSet: number, mode: number): void;
    public get_terrain_set_mode(terrainSet: number): number;
    public get_terrains_count(terrainSet: number): number;
    public add_terrain(terrainSet: number, toPosition: number = -1): void;
    public move_terrain(terrainSet: number, terrainIndex: number, toPosition: number): void;
    public remove_terrain(terrainSet: number, terrainIndex: number): void;
    public set_terrain_name(terrainSet: number, terrainIndex: number, name: GDString | StringName | string): void;
    public get_terrain_name(terrainSet: number, terrainIndex: number): GDString;
    public set_terrain_color(terrainSet: number, terrainIndex: number, color: Color): void;
    public get_terrain_color(terrainSet: number, terrainIndex: number): Color;
    public get_navigation_layers_count(): number;
    public add_navigation_layer(toPosition: number = -1): void;
    public move_navigation_layer(layerIndex: number, toPosition: number): void;
    public remove_navigation_layer(layerIndex: number): void;
    public set_navigation_layer_layers(layerIndex: number, layers: number): void;
    public get_navigation_layer_layers(layerIndex: number): number;
    public set_navigation_layer_layer_value(layerIndex: number, layerNumber: number, value: boolean): void;
    public get_navigation_layer_layer_value(layerIndex: number, layerNumber: number): boolean;
    public get_custom_data_layers_count(): number;
    public add_custom_data_layer(toPosition: number = -1): void;
    public move_custom_data_layer(layerIndex: number, toPosition: number): void;
    public remove_custom_data_layer(layerIndex: number): void;
    public get_custom_data_layer_by_name(layerName: GDString | StringName | string): number;
    public set_custom_data_layer_name(layerIndex: number, layerName: GDString | StringName | string): void;
    public has_custom_data_layer_by_name(layerName: GDString | StringName | string): boolean;
    public get_custom_data_layer_name(layerIndex: number): GDString;
    public set_custom_data_layer_type(layerIndex: number, layerType: number): void;
    public get_custom_data_layer_type(layerIndex: number): number;
    public set_source_level_tile_proxy(sourceFrom: number, sourceTo: number): void;
    public get_source_level_tile_proxy(sourceFrom: number): number;
    public has_source_level_tile_proxy(sourceFrom: number): boolean;
    public remove_source_level_tile_proxy(sourceFrom: number): void;
    public set_coords_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i, sourceTo: number, coordsTo: Vector2i): void;
    public get_coords_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i): GDArray;
    public has_coords_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i): boolean;
    public remove_coords_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i): void;
    public set_alternative_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i, alternativeFrom: number, sourceTo: number, coordsTo: Vector2i, alternativeTo: number): void;
    public get_alternative_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i, alternativeFrom: number): GDArray;
    public has_alternative_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i, alternativeFrom: number): boolean;
    public remove_alternative_level_tile_proxy(sourceFrom: number, coordsFrom: Vector2i, alternativeFrom: number): void;
    public map_tile_proxy(sourceFrom: number, coordsFrom: Vector2i, alternativeFrom: number): GDArray;
    public cleanup_invalid_tile_proxies(): void;
    public clear_tile_proxies(): void;
    public add_pattern(pattern: TileMapPattern, index: number = -1): number;
    public get_pattern(index: number = -1): TileMapPattern;
    public remove_pattern(index: number): void;
    public get_patterns_count(): number;


    public static readonly TileShape: {
        TILE_SHAPE_SQUARE: 0;
        TILE_SHAPE_ISOMETRIC: 1;
        TILE_SHAPE_HALF_OFFSET_SQUARE: 2;
        TILE_SHAPE_HEXAGON: 3;
    };
    public static readonly TileLayout: {
        TILE_LAYOUT_STACKED: 0;
        TILE_LAYOUT_STACKED_OFFSET: 1;
        TILE_LAYOUT_STAIRS_RIGHT: 2;
        TILE_LAYOUT_STAIRS_DOWN: 3;
        TILE_LAYOUT_DIAMOND_RIGHT: 4;
        TILE_LAYOUT_DIAMOND_DOWN: 5;
    };
    public static readonly TileOffsetAxis: {
        TILE_OFFSET_AXIS_HORIZONTAL: 0;
        TILE_OFFSET_AXIS_VERTICAL: 1;
    };
    public static readonly CellNeighbor: {
        CELL_NEIGHBOR_RIGHT_SIDE: 0;
        CELL_NEIGHBOR_RIGHT_CORNER: 1;
        CELL_NEIGHBOR_BOTTOM_RIGHT_SIDE: 2;
        CELL_NEIGHBOR_BOTTOM_RIGHT_CORNER: 3;
        CELL_NEIGHBOR_BOTTOM_SIDE: 4;
        CELL_NEIGHBOR_BOTTOM_CORNER: 5;
        CELL_NEIGHBOR_BOTTOM_LEFT_SIDE: 6;
        CELL_NEIGHBOR_BOTTOM_LEFT_CORNER: 7;
        CELL_NEIGHBOR_LEFT_SIDE: 8;
        CELL_NEIGHBOR_LEFT_CORNER: 9;
        CELL_NEIGHBOR_TOP_LEFT_SIDE: 10;
        CELL_NEIGHBOR_TOP_LEFT_CORNER: 11;
        CELL_NEIGHBOR_TOP_SIDE: 12;
        CELL_NEIGHBOR_TOP_CORNER: 13;
        CELL_NEIGHBOR_TOP_RIGHT_SIDE: 14;
        CELL_NEIGHBOR_TOP_RIGHT_CORNER: 15;
    };
    public static readonly TerrainMode: {
        TERRAIN_MODE_MATCH_CORNERS_AND_SIDES: 0;
        TERRAIN_MODE_MATCH_CORNERS: 1;
        TERRAIN_MODE_MATCH_SIDES: 2;
    };
}

