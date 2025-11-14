
import type { CollisionObject2D } from '@godot/classes/collision_object2d';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node2D } from '@godot/classes/node2d';
import type { RID } from '@godot/builtins/rid';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class RayCast2D extends Node2D {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public exclude_parent: boolean;    
    /**     * The raw type is 'Vector2'     */
    public target_position: Vector2;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'bool'     */
    public hit_from_inside: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_target_position(localPoint: Vector2): void;
    public get_target_position(): Vector2;
    public is_colliding(): boolean;
    public force_raycast_update(): void;
    public get_collider(): GodotObject;
    public get_collider_rid(): RID;
    public get_collider_shape(): number;
    public get_collision_point(): Vector2;
    public get_collision_normal(): Vector2;
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
    public set_hit_from_inside(enable: boolean): void;
    public is_hit_from_inside_enabled(): boolean;


}

