
import type { Node2D } from '@godot/classes/node2d';


export declare class CollisionPolygon2D extends Node2D {

    
    /**     * The raw type is 'int'     */
    public build_mode: number;    
    /**     * The raw type is 'PackedVector2Array'     */
    public polygon: PackedVector2Array;    
    /**     * The raw type is 'bool'     */
    public disabled: boolean;    
    /**     * The raw type is 'bool'     */
    public one_way_collision: boolean;    
    /**     * The raw type is 'float'     */
    public one_way_collision_margin: number;
    public set_polygon(polygon: PackedVector2Array): void;
    public get_polygon(): PackedVector2Array;
    public set_build_mode(buildMode: number): void;
    public get_build_mode(): number;
    public set_disabled(disabled: boolean): void;
    public is_disabled(): boolean;
    public set_one_way_collision(enabled: boolean): void;
    public is_one_way_collision_enabled(): boolean;
    public set_one_way_collision_margin(margin: number): void;
    public get_one_way_collision_margin(): number;


    public static readonly BuildMode: {
        BUILD_SOLIDS: 0;
        BUILD_SEGMENTS: 1;
    };
}

