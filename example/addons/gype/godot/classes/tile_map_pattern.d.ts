
import type { Resource } from '@godot/classes/resource';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class TileMapPattern extends Resource {


    public set_cell(coords: Vector2i, sourceId: number = -1, atlasCoords: Vector2i = Vector2i(-1, -1), alternativeTile: number = -1): void;
    public has_cell(coords: Vector2i): boolean;
    public remove_cell(coords: Vector2i, updateSize: boolean): void;
    public get_cell_source_id(coords: Vector2i): number;
    public get_cell_atlas_coords(coords: Vector2i): Vector2i;
    public get_cell_alternative_tile(coords: Vector2i): number;
    public get_used_cells(): Array<any>;
    public get_size(): Vector2i;
    public set_size(size: Vector2i): void;
    public is_empty(): boolean;


}

