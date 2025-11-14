
import type { CollisionObject3D } from '@godot/classes/collision_object3d';
import type { Color } from '@godot/builtins/color';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node3D } from '@godot/classes/node3d';
import type { RID } from '@godot/builtins/rid';
import type { Resource } from '@godot/classes/resource';
import type { Shape3D } from '@godot/classes/shape3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class ShapeCast3D extends Node3D {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'Shape3D'     */
    public shape: Shape3D;    
    /**     * The raw type is 'bool'     */
    public exclude_parent: boolean;    
    /**     * The raw type is 'Vector3'     */
    public target_position: Vector3;    
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
    /**     * The raw type is 'Color'     */
    public debug_shape_custom_color: Color;
    public resource_changed(resource: Resource): void;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_shape(shape: Shape3D): void;
    public get_shape(): Shape3D;
    public set_target_position(localPoint: Vector3): void;
    public get_target_position(): Vector3;
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
    public get_collision_point(index: number): Vector3;
    public get_collision_normal(index: number): Vector3;
    public get_closest_collision_safe_fraction(): number;
    public get_closest_collision_unsafe_fraction(): number;
    public add_exception_rid(rid: RID): void;
    public add_exception(node: CollisionObject3D): void;
    public remove_exception_rid(rid: RID): void;
    public remove_exception(node: CollisionObject3D): void;
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
    public set_debug_shape_custom_color(debugShapeCustomColor: Color): void;
    public get_debug_shape_custom_color(): Color;


}

