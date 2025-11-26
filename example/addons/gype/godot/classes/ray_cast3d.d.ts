
import type { CollisionObject3D } from '@godot/classes/collision_object3d';
import type { GodotObject } from '@godot/classes/godot_object';
import type { Node3D } from '@godot/classes/node3d';


export declare class RayCast3D extends Node3D {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public exclude_parent: boolean;    
    /**     * The raw type is 'Vector3'     */
    public target_position: Vector3;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'bool'     */
    public hit_from_inside: boolean;    
    /**     * The raw type is 'bool'     */
    public hit_back_faces: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;    
    /**     * The raw type is 'Color'     */
    public debug_shape_custom_color: Color;    
    /**     * The raw type is 'int'     */
    public debug_shape_thickness: number;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_target_position(localPoint: Vector3): void;
    public get_target_position(): Vector3;
    public is_colliding(): boolean;
    public force_raycast_update(): void;
    public get_collider(): GodotObject;
    public get_collider_rid(): RID;
    public get_collider_shape(): number;
    public get_collision_point(): Vector3;
    public get_collision_normal(): Vector3;
    public get_collision_face_index(): number;
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
    public set_hit_from_inside(enable: boolean): void;
    public is_hit_from_inside_enabled(): boolean;
    public set_hit_back_faces(enable: boolean): void;
    public is_hit_back_faces_enabled(): boolean;
    public set_debug_shape_custom_color(debugShapeCustomColor: Color): void;
    public get_debug_shape_custom_color(): Color;
    public set_debug_shape_thickness(debugShapeThickness: number): void;
    public get_debug_shape_thickness(): number;


}

