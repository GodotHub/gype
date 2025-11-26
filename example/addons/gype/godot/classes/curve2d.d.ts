
import type { Resource } from '@godot/classes/resource';


export declare class Curve2D extends Resource {

    
    /**     * The raw type is 'float'     */
    public bake_interval: number;    
    /**     * The raw type is 'int'     */
    public point_count: number;
    public get_point_count(): number;
    public set_point_count(count: number): void;
    public add_point(position: Vector2, _in: Vector2 = Vector2(0, 0), out: Vector2 = Vector2(0, 0), index: number = -1): void;
    public set_point_position(idx: number, position: Vector2): void;
    public get_point_position(idx: number): Vector2;
    public set_point_in(idx: number, position: Vector2): void;
    public get_point_in(idx: number): Vector2;
    public set_point_out(idx: number, position: Vector2): void;
    public get_point_out(idx: number): Vector2;
    public remove_point(idx: number): void;
    public clear_points(): void;
    public sample(idx: number, t: number): Vector2;
    public samplef(fofs: number): Vector2;
    public set_bake_interval(distance: number): void;
    public get_bake_interval(): number;
    public get_baked_length(): number;
    public sample_baked(offset: number = 0.0, cubic: boolean = false): Vector2;
    public sample_baked_with_rotation(offset: number = 0.0, cubic: boolean = false): Transform2D;
    public get_baked_points(): PackedVector2Array;
    public get_closest_point(toPoint: Vector2): Vector2;
    public get_closest_offset(toPoint: Vector2): number;
    public tessellate(maxStages: number = 5, toleranceDegrees: number = 4): PackedVector2Array;
    public tessellate_even_length(maxStages: number = 5, toleranceLength: number = 20.0): PackedVector2Array;


}

