
import type { Texture2D } from '@godot/classes/texture2d';
import type { TileData } from '@godot/classes/tile_data';
import type { TileSetSource } from '@godot/classes/tile_set_source';


export declare class TileSetAtlasSource extends TileSetSource {

    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'Vector2i'     */
    public margins: Vector2i;    
    /**     * The raw type is 'Vector2i'     */
    public separation: Vector2i;    
    /**     * The raw type is 'Vector2i'     */
    public texture_region_size: Vector2i;    
    /**     * The raw type is 'bool'     */
    public use_texture_padding: boolean;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_margins(margins: Vector2i): void;
    public get_margins(): Vector2i;
    public set_separation(separation: Vector2i): void;
    public get_separation(): Vector2i;
    public set_texture_region_size(textureRegionSize: Vector2i): void;
    public get_texture_region_size(): Vector2i;
    public set_use_texture_padding(useTexturePadding: boolean): void;
    public get_use_texture_padding(): boolean;
    public create_tile(atlasCoords: Vector2i, size: Vector2i = Vector2i(1, 1)): void;
    public remove_tile(atlasCoords: Vector2i): void;
    public move_tile_in_atlas(atlasCoords: Vector2i, newAtlasCoords: Vector2i = Vector2i(-1, -1), newSize: Vector2i = Vector2i(-1, -1)): void;
    public get_tile_size_in_atlas(atlasCoords: Vector2i): Vector2i;
    public has_room_for_tile(atlasCoords: Vector2i, size: Vector2i, animationColumns: number, animationSeparation: Vector2i, framesCount: number, ignoredTile: Vector2i = Vector2i(-1, -1)): boolean;
    public get_tiles_to_be_removed_on_change(texture: Texture2D, margins: Vector2i, separation: Vector2i, textureRegionSize: Vector2i): PackedVector2Array;
    public get_tile_at_coords(atlasCoords: Vector2i): Vector2i;
    public has_tiles_outside_texture(): boolean;
    public clear_tiles_outside_texture(): void;
    public set_tile_animation_columns(atlasCoords: Vector2i, frameColumns: number): void;
    public get_tile_animation_columns(atlasCoords: Vector2i): number;
    public set_tile_animation_separation(atlasCoords: Vector2i, separation: Vector2i): void;
    public get_tile_animation_separation(atlasCoords: Vector2i): Vector2i;
    public set_tile_animation_speed(atlasCoords: Vector2i, speed: number): void;
    public get_tile_animation_speed(atlasCoords: Vector2i): number;
    public set_tile_animation_mode(atlasCoords: Vector2i, mode: number): void;
    public get_tile_animation_mode(atlasCoords: Vector2i): number;
    public set_tile_animation_frames_count(atlasCoords: Vector2i, framesCount: number): void;
    public get_tile_animation_frames_count(atlasCoords: Vector2i): number;
    public set_tile_animation_frame_duration(atlasCoords: Vector2i, frameIndex: number, duration: number): void;
    public get_tile_animation_frame_duration(atlasCoords: Vector2i, frameIndex: number): number;
    public get_tile_animation_total_duration(atlasCoords: Vector2i): number;
    public create_alternative_tile(atlasCoords: Vector2i, alternativeIdOverride: number = -1): number;
    public remove_alternative_tile(atlasCoords: Vector2i, alternativeTile: number): void;
    public set_alternative_tile_id(atlasCoords: Vector2i, alternativeTile: number, newId: number): void;
    public get_next_alternative_tile_id(atlasCoords: Vector2i): number;
    public get_tile_data(atlasCoords: Vector2i, alternativeTile: number): TileData;
    public get_atlas_grid_size(): Vector2i;
    public get_tile_texture_region(atlasCoords: Vector2i, frame: number = 0): Rect2i;
    public get_runtime_texture(): Texture2D;
    public get_runtime_tile_texture_region(atlasCoords: Vector2i, frame: number): Rect2i;


    public static readonly TileAnimationMode: {
        TILE_ANIMATION_MODE_DEFAULT: 0;
        TILE_ANIMATION_MODE_RANDOM_START_TIMES: 1;
        TILE_ANIMATION_MODE_MAX: 2;
    };
}

