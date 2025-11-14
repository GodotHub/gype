
import type { PackedScene } from '@godot/classes/packed_scene';
import type { TileSetSource } from '@godot/classes/tile_set_source';


export declare class TileSetScenesCollectionSource extends TileSetSource {


    public get_scene_tiles_count(): number;
    public get_scene_tile_id(index: number): number;
    public has_scene_tile_id(id: number): boolean;
    public create_scene_tile(packedScene: PackedScene, idOverride: number = -1): number;
    public set_scene_tile_id(id: number, newId: number): void;
    public set_scene_tile_scene(id: number, packedScene: PackedScene): void;
    public get_scene_tile_scene(id: number): PackedScene;
    public set_scene_tile_display_placeholder(id: number, displayPlaceholder: boolean): void;
    public get_scene_tile_display_placeholder(id: number): boolean;
    public remove_scene_tile(id: number): void;
    public get_next_scene_tile_id(): number;


}

