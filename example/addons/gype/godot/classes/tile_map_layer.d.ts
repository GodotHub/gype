
import type { Node2D } from '@godot/classes/node2d';
import type { PackedByteArray } from '@godot/builtins/packed_byte_array';
import type { RID } from '@godot/builtins/rid';
import type { Rect2i } from '@godot/builtins/rect2i';
import type { Signal } from '@godot/builtins/signal';
import type { TileData } from '@godot/classes/tile_data';
import type { TileMapPattern } from '@godot/classes/tile_map_pattern';
import type { TileSet } from '@godot/classes/tile_set';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class TileMapLayer extends Node2D {

    
    /**     * The raw type is 'PackedByteArray'     */
    public tile_map_data: PackedByteArray;    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'TileSet'     */
    public tile_set: TileSet;    
    /**     * The raw type is 'bool'     */
    public occlusion_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public y_sort_origin: number;    
    /**     * The raw type is 'bool'     */
    public x_draw_order_reversed: boolean;    
    /**     * The raw type is 'int'     */
    public rendering_quadrant_size: number;    
    /**     * The raw type is 'bool'     */
    public collision_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public use_kinematic_bodies: boolean;    
    /**     * The raw type is 'int'     */
    public collision_visibility_mode: number;    
    /**     * The raw type is 'int'     */
    public physics_quadrant_size: number;    
    /**     * The raw type is 'bool'     */
    public navigation_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public navigation_visibility_mode: number;
    public _use_tile_data_runtime_update(coords: Vector2i): boolean;
    public _tile_data_runtime_update(coords: Vector2i, tileData: TileData): void;
    public _update_cells(coords: Array<any>, forcedCleanup: boolean): void;
    public set_cell(coords: Vector2i, sourceId: number = -1, atlasCoords: Vector2i = Vector2i(-1, -1), alternativeTile: number = 0): void;
    public erase_cell(coords: Vector2i): void;
    public fix_invalid_tiles(): void;
    public clear(): void;
    public get_cell_source_id(coords: Vector2i): number;
    public get_cell_atlas_coords(coords: Vector2i): Vector2i;
    public get_cell_alternative_tile(coords: Vector2i): number;
    public get_cell_tile_data(coords: Vector2i): TileData;
    public is_cell_flipped_h(coords: Vector2i): boolean;
    public is_cell_flipped_v(coords: Vector2i): boolean;
    public is_cell_transposed(coords: Vector2i): boolean;
    public get_used_cells(): Array<any>;
    public get_used_cells_by_id(sourceId: number = -1, atlasCoords: Vector2i = Vector2i(-1, -1), alternativeTile: number = -1): Array<any>;
    public get_used_rect(): Rect2i;
    public get_pattern(coordsArray: Array<any>): TileMapPattern;
    public set_pattern(position: Vector2i, pattern: TileMapPattern): void;
    public set_cells_terrain_connect(cells: Array<any>, terrainSet: number, terrain: number, ignoreEmptyTerrains: boolean = true): void;
    public set_cells_terrain_path(path: Array<any>, terrainSet: number, terrain: number, ignoreEmptyTerrains: boolean = true): void;
    public has_body_rid(body: RID): boolean;
    public get_coords_for_body_rid(body: RID): Vector2i;
    public update_internals(): void;
    public notify_runtime_tile_data_update(): void;
    public map_pattern(positionInTilemap: Vector2i, coordsInPattern: Vector2i, pattern: TileMapPattern): Vector2i;
    public get_surrounding_cells(coords: Vector2i): Array<any>;
    public get_neighbor_cell(coords: Vector2i, neighbor: number): Vector2i;
    public map_to_local(maposition: Vector2i): Vector2;
    public local_to_map(localPosition: Vector2): Vector2i;
    public set_tile_map_data_from_array(tileMalayerData: PackedByteArray): void;
    public get_tile_map_data_as_array(): PackedByteArray;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_tile_set(tileSet: TileSet): void;
    public get_tile_set(): TileSet;
    public set_y_sort_origin(ySortOrigin: number): void;
    public get_y_sort_origin(): number;
    public set_x_draw_order_reversed(xDrawOrderReversed: boolean): void;
    public is_x_draw_order_reversed(): boolean;
    public set_rendering_quadrant_size(size: number): void;
    public get_rendering_quadrant_size(): number;
    public set_collision_enabled(enabled: boolean): void;
    public is_collision_enabled(): boolean;
    public set_use_kinematic_bodies(useKinematicBodies: boolean): void;
    public is_using_kinematic_bodies(): boolean;
    public set_collision_visibility_mode(visibilityMode: number): void;
    public get_collision_visibility_mode(): number;
    public set_physics_quadrant_size(size: number): void;
    public get_physics_quadrant_size(): number;
    public set_occlusion_enabled(enabled: boolean): void;
    public is_occlusion_enabled(): boolean;
    public set_navigation_enabled(enabled: boolean): void;
    public is_navigation_enabled(): boolean;
    public set_navigation_map(map: RID): void;
    public get_navigation_map(): RID;
    public set_navigation_visibility_mode(showNavigation: number): void;
    public get_navigation_visibility_mode(): number;

    
    public readonly changed: Signal<() => void>;

    public static readonly DebugVisibilityMode: {
        DEBUG_VISIBILITY_MODE_DEFAULT: 0;
        DEBUG_VISIBILITY_MODE_FORCE_HIDE: 2;
        DEBUG_VISIBILITY_MODE_FORCE_SHOW: 1;
    };
}

