
import type { CollisionObject2D } from '@godot/classes/collision_object2d';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node2D } from '@godot/classes/node2d';
import type { RID } from '@godot/builtins/rid';
import type { Shape2D } from '@godot/classes/shape2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class ShapeCast2D extends Node2D {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'Shape2D'     */
    public shape: Shape2D;    
    /**     * The raw type is 'bool'     */
    public exclude_parent: boolean;    
    /**     * The raw type is 'Vector2'     */
    public target_position: Vector2;    
    /**     * The raw type is 'float'     */
    public margin: number;    
    /**     * The raw type is 'int'     */
    public max_results: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'Array'     */
    public collision_result: GDArray;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_shape(shape: Shape2D): void;
    public get_shape(): Shape2D;
    public set_target_position(localPoint: Vector2): void;
    public get_target_position(): Vector2;
    public set_margin(margin: number): void;
    public get_margin(): number;
    public set_max_results(maxResults: number): void;
    public get_max_results(): number;
    public is_colliding(): boolean;
    public get_collision_count(): number;
    public force_shapecast_update(): void;
    public get_collider(index: number): GodotObject;
    public get_collider_rid(index: number): RID;
    public get_collider_shape(index: number): number;
    public get_collision_point(index: number): Vector2;
    public get_collision_normal(index: number): Vector2;
    public get_closest_collision_safe_fraction(): number;
    public get_closest_collision_unsafe_fraction(): number;
    public add_exception_rid(rid: RID): void;
    public add_exception(node: CollisionObject2D): void;
    public remove_exception_rid(rid: RID): void;
    public remove_exception(node: CollisionObject2D): void;
    public clear_exceptions(): void;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public set_collision_mask_value(layerNumber: number, value: boolean): void;
    public get_collision_mask_value(layerNumber: number): boolean;
    public set_exclude_parent_body(mask: boolean): void;
    public get_exclude_parent_body(): boolean;
    public set_collide_with_areas(enable: boolean): void;
    public is_collide_with_areas_enabled(): boolean;
    public set_collide_with_bodies(enable: boolean): void;
    public is_collide_with_bodies_enabled(): boolean;
    public get_collision_result(): GDArray;


}

