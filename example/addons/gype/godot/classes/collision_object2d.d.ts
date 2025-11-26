
import type { GodotObject } from '@godot/classes/godot_object';
import type { InputEvent } from '@godot/classes/input_event';
import type { Node } from '@godot/classes/node';
import type { Node2D } from '@godot/classes/node2d';
import type { Shape2D } from '@godot/classes/shape2d';
import type { Viewport } from '@godot/classes/viewport';


export declare class CollisionObject2D extends Node2D {

    
    /**     * The raw type is 'int'     */
    public disable_mode: number;    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'float'     */
    public collision_priority: number;    
    /**     * The raw type is 'bool'     */
    public input_pickable: boolean;
    public _input_event(viewport: Viewport, event: InputEvent, shapeIdx: number): void;
    public _mouse_enter(): void;
    public _mouse_exit(): void;
    public _mouse_shape_enter(shapeIdx: number): void;
    public _mouse_shape_exit(shapeIdx: number): void;
    public get_rid(): RID;
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
    public set_pickable(enabled: boolean): void;
    public is_pickable(): boolean;
    public create_shape_owner(owner: GodotObject): number;
    public remove_shape_owner(ownerId: number): void;
    public get_shape_owners(): PackedInt32Array;
    public shape_owner_set_transform(ownerId: number, transform: Transform2D): void;
    public shape_owner_get_transform(ownerId: number): Transform2D;
    public shape_owner_get_owner(ownerId: number): GodotObject;
    public shape_owner_set_disabled(ownerId: number, disabled: boolean): void;
    public is_shape_owner_disabled(ownerId: number): boolean;
    public shape_owner_set_one_way_collision(ownerId: number, enable: boolean): void;
    public is_shape_owner_one_way_collision_enabled(ownerId: number): boolean;
    public shape_owner_set_one_way_collision_margin(ownerId: number, margin: number): void;
    public get_shape_owner_one_way_collision_margin(ownerId: number): number;
    public shape_owner_add_shape(ownerId: number, shape: Shape2D): void;
    public shape_owner_get_shape_count(ownerId: number): number;
    public shape_owner_get_shape(ownerId: number, shapeId: number): Shape2D;
    public shape_owner_get_shape_index(ownerId: number, shapeId: number): number;
    public shape_owner_remove_shape(ownerId: number, shapeId: number): void;
    public shape_owner_clear_shapes(ownerId: number): void;
    public shape_find_owner(shapeIndex: number): number;

    
    public readonly input_event: Signal;
    public readonly mouse_entered: Signal;
    public readonly mouse_exited: Signal;
    public readonly mouse_shape_entered: Signal;
    public readonly mouse_shape_exited: Signal;

    public static readonly DisableMode: {
        DISABLE_MODE_REMOVE: 0;
        DISABLE_MODE_MAKE_STATIC: 1;
        DISABLE_MODE_KEEP_ACTIVE: 2;
    };
}

