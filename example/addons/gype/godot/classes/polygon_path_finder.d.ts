
import type { Dictionary } from '@godot/builtins/dictionary';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Resource } from '@godot/classes/resource';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class PolygonPathFinder extends Resource {

    
    /**     * The raw type is 'Dictionary'     */
    public data: Dictionary;
    public setup(points: PackedVector2Array, connections: PackedInt32Array): void;
    public find_path(_from: Vector2, to: Vector2): PackedVector2Array;
    public get_intersections(_from: Vector2, to: Vector2): PackedVector2Array;
    public get_closest_point(point: Vector2): Vector2;
    public is_point_inside(point: Vector2): boolean;
    public set_point_penalty(idx: number, penalty: number): void;
    public get_point_penalty(idx: number): number;
    public get_bounds(): Rect2;


}

