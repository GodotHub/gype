
import type { EditorPlugin } from '@godot/classes/editor_plugin';
import type { GridMap } from '@godot/classes/grid_map';


export declare class GridMapEditorPlugin extends EditorPlugin {


    public get_current_grid_map(): GridMap;
    public set_selection(begin: Vector3i, end: Vector3i): void;
    public clear_selection(): void;
    public get_selection(): AABB;
    public has_selection(): boolean;
    public get_selected_cells(): GDArray;
    public set_selected_palette_item(item: number): void;
    public get_selected_palette_item(): number;


}

