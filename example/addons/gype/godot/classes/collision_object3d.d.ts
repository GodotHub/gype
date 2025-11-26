
import type { Camera3D } from '@godot/classes/camera3d';
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';
import type { Node } from '@godot/classes/node';
import type { Node3D } from '@godot/classes/node3d';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class CollisionObject3D extends Node3D {

    
    /**     * The raw type is 'int'     */
    public disable_mode: number;    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'float'     */
    public collision_priority: number;    
    /**     * The raw type is 'bool'     */
    public input_ray_pickable: boolean;    
    /**     * The raw type is 'bool'     */
    public input_capture_on_drag: boolean;
    public _input_event(camera: Camera3D, event: InputEvent, eventPosition: Vector3, normal: Vector3, shapeIdx: number): void;
    public _mouse_enter(): void;
    public _mouse_exit(): void;
    public set_collision_layer(layer: number): void;
    public get_collision_layer(): number;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public set_collision_layer_value(layerNumber: number, value: boolean): void;
    public get_collision_layer_value(layerNumber: number): boolean;
    public set_collision_mask_value(layerNumber: number, value: boolean): void;
    public get_collision_mask_value(layerNumber: number): boolean;
    public set_collision_priority(priority: number): void;
    public get_collision_priority(): number;
    public set_disable_mode(mode: number): void;
    public get_disable_mode(): number;
    public set_ray_pickable(rayPickable: boolean): void;
    public is_ray_pickable(): boolean;
    public set_capture_input_on_drag(enable: boolean): void;
    public get_capture_input_on_drag(): boolean;
    public get_rid(): RID;
    public create_shape_owner(owner: GodotObject): number;
    public remove_shape_owner(ownerId: number): void;
    public get_shape_owners(): PackedInt32Array;
    public shape_owner_set_transform(ownerId: number, transform: Transform3D): void;
    public shape_owner_get_transform(ownerId: number): Transform3D;
    public shape_owner_get_owner(ownerId: number): GodotObject;
    public shape_owner_set_disabled(ownerId: number, disabled: boolean): void;
    public is_shape_owner_disabled(ownerId: number): boolean;
    public shape_owner_add_shape(ownerId: number, shape: Shape3D): void;
    public shape_owner_get_shape_count(ownerId: number): number;
    public shape_owner_get_shape(ownerId: number, shapeId: number): Shape3D;
    public shape_owner_get_shape_index(ownerId: number, shapeId: number): number;
    public shape_owner_remove_shape(ownerId: number, shapeId: number): void;
    public shape_owner_clear_shapes(ownerId: number): void;
    public shape_find_owner(shapeIndex: number): number;

    
    public readonly input_event: Signal;
    public readonly mouse_entered: Signal;
    public readonly mouse_exited: Signal;

    public static readonly DisableMode: {
        DISABLE_MODE_REMOVE: 0;
        DISABLE_MODE_MAKE_STATIC: 1;
        DISABLE_MODE_KEEP_ACTIVE: 2;
    };
}

