
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Rect2i } from '@godot/builtins/rect2i';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Vector2 } from '@godot/builtins/vector2';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class AStarGrid2D extends RefCounted {

    
    /**     * The raw type is 'Rect2i'     */
    public region: Rect2i;    
    /**     * The raw type is 'Vector2i'     */
    public size: Vector2i;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public cell_size: Vector2;    
    /**     * The raw type is 'int'     */
    public cell_shape: number;    
    /**     * The raw type is 'bool'     */
    public jumping_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public default_compute_heuristic: number;    
    /**     * The raw type is 'int'     */
    public default_estimate_heuristic: number;    
    /**     * The raw type is 'int'     */
    public diagonal_mode: number;
    public _estimate_cost(fromId: Vector2i, endId: Vector2i): number;
    public _compute_cost(fromId: Vector2i, toId: Vector2i): number;
    public set_region(region: Rect2i): void;
    public get_region(): Rect2i;
    public set_size(size: Vector2i): void;
    public get_size(): Vector2i;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_cell_size(cellSize: Vector2): void;
    public get_cell_size(): Vector2;
    public set_cell_shape(cellShape: number): void;
    public get_cell_shape(): number;
    public is_in_bounds(x: number, y: number): boolean;
    public is_in_boundsv(id: Vector2i): boolean;
    public is_dirty(): boolean;
    public update(): void;
    public set_jumping_enabled(enabled: boolean): void;
    public is_jumping_enabled(): boolean;
    public set_diagonal_mode(mode: number): void;
    public get_diagonal_mode(): number;
    public set_default_compute_heuristic(heuristic: number): void;
    public get_default_compute_heuristic(): number;
    public set_default_estimate_heuristic(heuristic: number): void;
    public get_default_estimate_heuristic(): number;
    public set_point_solid(id: Vector2i, solid: boolean = true): void;
    public is_point_solid(id: Vector2i): boolean;
    public set_point_weight_scale(id: Vector2i, weightScale: number): void;
    public get_point_weight_scale(id: Vector2i): number;
    public fill_solid_region(region: Rect2i, solid: boolean = true): void;
    public fill_weight_scale_region(region: Rect2i, weightScale: number): void;
    public clear(): void;
    public get_point_position(id: Vector2i): Vector2;
    public get_point_data_in_region(region: Rect2i): Array<any>;
    public get_point_path(fromId: Vector2i, toId: Vector2i, allowPartialPath: boolean = false): PackedVector2Array;
    public get_id_path(fromId: Vector2i, toId: Vector2i, allowPartialPath: boolean = false): Array<any>;


    public static readonly Heuristic: {
        HEURISTIC_EUCLIDEAN: 0;
        HEURISTIC_MANHATTAN: 1;
        HEURISTIC_OCTILE: 2;
        HEURISTIC_CHEBYSHEV: 3;
        HEURISTIC_MAX: 4;
    };
    public static readonly DiagonalMode: {
        DIAGONAL_MODE_ALWAYS: 0;
        DIAGONAL_MODE_NEVER: 1;
        DIAGONAL_MODE_AT_LEAST_ONE_WALKABLE: 2;
        DIAGONAL_MODE_ONLY_IF_NO_OBSTACLES: 3;
        DIAGONAL_MODE_MAX: 4;
    };
    public static readonly CellShape: {
        CELL_SHAPE_SQUARE: 0;
        CELL_SHAPE_ISOMETRIC_RIGHT: 1;
        CELL_SHAPE_ISOMETRIC_DOWN: 2;
        CELL_SHAPE_MAX: 3;
    };
}

