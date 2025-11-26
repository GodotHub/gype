
import type { Node2D } from '@godot/classes/node2d';
import type { TileData } from '@godot/classes/tile_data';
import type { TileMapPattern } from '@godot/classes/tile_map_pattern';
import type { TileSet } from '@godot/classes/tile_set';


export declare class TileMap extends Node2D {

    
    /**     * The raw type is 'TileSet'     */
    public tile_set: TileSet;    
    /**     * The raw type is 'int'     */
    public rendering_quadrant_size: number;    
    /**     * The raw type is 'bool'     */
    public collision_animatable: boolean;    
    /**     * The raw type is 'int'     */
    public collision_visibility_mode: number;    
    /**     * The raw type is 'int'     */
    public navigation_visibility_mode: number;
    public _use_tile_data_runtime_update(layer: number, coords: Vector2i): boolean;
    public _tile_data_runtime_update(layer: number, coords: Vector2i, tileData: TileData): void;
    public set_navigation_map(layer: number, map: RID): void;
    public get_navigation_map(layer: number): RID;
    public force_update(layer: number = -1): void;
    public set_tileset(tileset: TileSet): void;
    public get_tileset(): TileSet;
    public set_rendering_quadrant_size(size: number): void;
    public get_rendering_quadrant_size(): number;
    public get_layers_count(): number;
    public add_layer(toPosition: number): void;
    public move_layer(layer: number, toPosition: number): void;
    public remove_layer(layer: number): void;
    public set_layer_name(layer: number, name: GDString | StringName | string): void;
    public get_layer_name(layer: number): GDString;
    public set_layer_enabled(layer: number, enabled: boolean): void;
    public is_layer_enabled(layer: number): boolean;
    public set_layer_modulate(layer: number, modulate: Color): void;
    public get_layer_modulate(layer: number): Color;
    public set_layer_y_sort_enabled(layer: number, ySortEnabled: boolean): void;
    public is_layer_y_sort_enabled(layer: number): boolean;
    public set_layer_y_sort_origin(layer: number, ySortOrigin: number): void;
    public get_layer_y_sort_origin(layer: number): number;
    public set_layer_z_index(layer: number, zIndex: number): void;
    public get_layer_z_index(layer: number): number;
    public set_layer_navigation_enabled(layer: number, enabled: boolean): void;
    public is_layer_navigation_enabled(layer: number): boolean;
    public set_layer_navigation_map(layer: number, map: RID): void;
    public get_layer_navigation_map(layer: number): RID;
    public set_collision_animatable(enabled: boolean): void;
    public is_collision_animatable(): boolean;
    public set_collision_visibility_mode(collisionVisibilityMode: number): void;
    public get_collision_visibility_mode(): number;
    public set_navigation_visibility_mode(navigationVisibilityMode: number): void;
    public get_navigation_visibility_mode(): number;
    public set_cell(layer: number, coords: Vector2i, sourceId: number = -1, atlasCoords: Vector2i = Vector2i(-1, -1), alternativeTile: number = 0): void;
    public erase_cell(layer: number, coords: Vector2i): void;
    public get_cell_source_id(layer: number, coords: Vector2i, useProxies: boolean = false): number;
    public get_cell_atlas_coords(layer: number, coords: Vector2i, useProxies: boolean = false): Vector2i;
    public get_cell_alternative_tile(layer: number, coords: Vector2i, useProxies: boolean = false): number;
    public get_cell_tile_data(layer: number, coords: Vector2i, useProxies: boolean = false): TileData;
    public is_cell_flipped_h(layer: number, coords: Vector2i, useProxies: boolean = false): boolean;
    public is_cell_flipped_v(layer: number, coords: Vector2i, useProxies: boolean = false): boolean;
    public is_cell_transposed(layer: number, coords: Vector2i, useProxies: boolean = false): boolean;
    public get_coords_for_body_rid(body: RID): Vector2i;
    public get_layer_for_body_rid(body: RID): number;
    public get_pattern(layer: number, coordsArray: Array<any>): TileMapPattern;
    public map_pattern(positionInTilemap: Vector2i, coordsInPattern: Vector2i, pattern: TileMapPattern): Vector2i;
    public set_pattern(layer: number, position: Vector2i, pattern: TileMapPattern): void;
    public set_cells_terrain_connect(layer: number, cells: Array<any>, terrainSet: number, terrain: number, ignoreEmptyTerrains: boolean = true): void;
    public set_cells_terrain_path(layer: number, path: Array<any>, terrainSet: number, terrain: number, ignoreEmptyTerrains: boolean = true): void;
    public fix_invalid_tiles(): void;
    public clear_layer(layer: number): void;
    public clear(): void;
    public update_internals(): void;
    public notify_runtime_tile_data_update(layer: number = -1): void;
    public get_surrounding_cells(coords: Vector2i): Array<any>;
    public get_used_cells(layer: number): Array<any>;
    public get_used_cells_by_id(layer: number, sourceId: number = -1, atlasCoords: Vector2i = Vector2i(-1, -1), alternativeTile: number = -1): Array<any>;
    public get_used_rect(): Rect2i;
    public map_to_local(maposition: Vector2i): Vector2;
    public local_to_map(localPosition: Vector2): Vector2i;
    public get_neighbor_cell(coords: Vector2i, neighbor: number): Vector2i;

    
    public readonly changed: Signal;

    public static readonly VisibilityMode: {
        VISIBILITY_MODE_DEFAULT: 0;
        VISIBILITY_MODE_FORCE_HIDE: 2;
        VISIBILITY_MODE_FORCE_SHOW: 1;
    };
}

