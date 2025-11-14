
import type { Resource } from '@godot/classes/resource';
import type { Signal } from '@godot/builtins/signal';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Curve extends Resource {

    
    /**     * The raw type is 'float'     */
    public min_domain: number;    
    /**     * The raw type is 'float'     */
    public max_domain: number;    
    /**     * The raw type is 'float'     */
    public min_value: number;    
    /**     * The raw type is 'float'     */
    public max_value: number;    
    /**     * The raw type is 'int'     */
    public bake_resolution: number;    
    /**     * The raw type is 'int'     */
    public point_count: number;
    public get_point_count(): number;
    public set_point_count(count: number): void;
    public add_point(position: Vector2, leftTangent: number = 0, rightTangent: number = 0, leftMode: number = 0, rightMode: number = 0): number;
    public remove_point(index: number): void;
    public clear_points(): void;
    public get_point_position(index: number): Vector2;
    public set_point_value(index: number, y: number): void;
    public set_point_offset(index: number, offset: number): number;
    public sample(offset: number): number;
    public sample_baked(offset: number): number;
    public get_point_left_tangent(index: number): number;
    public get_point_right_tangent(index: number): number;
    public get_point_left_mode(index: number): number;
    public get_point_right_mode(index: number): number;
    public set_point_left_tangent(index: number, tangent: number): void;
    public set_point_right_tangent(index: number, tangent: number): void;
    public set_point_left_mode(index: number, mode: number): void;
    public set_point_right_mode(index: number, mode: number): void;
    public get_min_value(): number;
    public set_min_value(min: number): void;
    public get_max_value(): number;
    public set_max_value(max: number): void;
    public get_value_range(): number;
    public get_min_domain(): number;
    public set_min_domain(min: number): void;
    public get_max_domain(): number;
    public set_max_domain(max: number): void;
    public get_domain_range(): number;
    public clean_dupes(): void;
    public bake(): void;
    public get_bake_resolution(): number;
    public set_bake_resolution(resolution: number): void;

    
    public readonly range_changed: Signal<() => void>;
    public readonly domain_changed: Signal<() => void>;

    public static readonly TangentMode: {
        TANGENT_FREE: 0;
        TANGENT_LINEAR: 1;
        TANGENT_MODE_COUNT: 2;
    };
}

