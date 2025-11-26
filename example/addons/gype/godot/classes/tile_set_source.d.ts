
import type { Resource } from '@godot/classes/resource';


export declare class TileSetSource extends Resource {


    public get_tiles_count(): number;
    public get_tile_id(index: number): Vector2i;
    public has_tile(atlasCoords: Vector2i): boolean;
    public get_alternative_tiles_count(atlasCoords: Vector2i): number;
    public get_alternative_tile_id(atlasCoords: Vector2i, index: number): number;
    public has_alternative_tile(atlasCoords: Vector2i, alternativeTile: number): boolean;


}

