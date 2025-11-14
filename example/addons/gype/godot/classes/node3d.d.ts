
import type { Basis } from '@godot/builtins/basis';
import type { Node } from '@godot/classes/node';
import type { Node3DGizmo } from '@godot/classes/node3d_gizmo';
import type { NodePath } from '@godot/builtins/node_path';
import type { Quaternion } from '@godot/builtins/quaternion';
import type { Signal } from '@godot/builtins/signal';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';
import type { World3D } from '@godot/classes/world3d';


export declare class Node3D extends Node {

    
    /**     * The raw type is 'Transform3D'     */
    public transform: Transform3D;    
    /**     * The raw type is 'Transform3D'     */
    public global_transform: Transform3D;    
    /**     * The raw type is 'Vector3'     */
    public position: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public rotation: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public rotation_degrees: Vector3;    
    /**     * The raw type is 'Quaternion'     */
    public quaternion: Quaternion;    
    /**     * The raw type is 'Basis'     */
    public basis: Basis;    
    /**     * The raw type is 'Vector3'     */
    public scale: Vector3;    
    /**     * The raw type is 'int'     */
    public rotation_edit_mode: number;    
    /**     * The raw type is 'int'     */
    public rotation_order: number;    
    /**     * The raw type is 'bool'     */
    public top_level: boolean;    
    /**     * The raw type is 'Vector3'     */
    public global_position: Vector3;    
    /**     * The raw type is 'Basis'     */
    public global_basis: Basis;    
    /**     * The raw type is 'Vector3'     */
    public global_rotation: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public global_rotation_degrees: Vector3;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;    
    /**     * The raw type is 'NodePath'     */
    public visibility_parent: NodePath;
    public set_transform(local: Transform3D): void;
    public get_transform(): Transform3D;
    public set_position(position: Vector3): void;
    public get_position(): Vector3;
    public set_rotation(eulerRadians: Vector3): void;
    public get_rotation(): Vector3;
    public set_rotation_degrees(eulerDegrees: Vector3): void;
    public get_rotation_degrees(): Vector3;
    public set_rotation_order(order: number): void;
    public get_rotation_order(): number;
    public set_rotation_edit_mode(editMode: number): void;
    public get_rotation_edit_mode(): number;
    public set_scale(scale: Vector3): void;
    public get_scale(): Vector3;
    public set_quaternion(quaternion: Quaternion): void;
    public get_quaternion(): Quaternion;
    public set_basis(basis: Basis): void;
    public get_basis(): Basis;
    public set_global_transform(global: Transform3D): void;
    public get_global_transform(): Transform3D;
    public get_global_transform_interpolated(): Transform3D;
    public set_global_position(position: Vector3): void;
    public get_global_position(): Vector3;
    public set_global_basis(basis: Basis): void;
    public get_global_basis(): Basis;
    public set_global_rotation(eulerRadians: Vector3): void;
    public get_global_rotation(): Vector3;
    public set_global_rotation_degrees(eulerDegrees: Vector3): void;
    public get_global_rotation_degrees(): Vector3;
    public get_parent_node_3d(): Node3D;
    public set_ignore_transform_notification(enabled: boolean): void;
    public set_as_top_level(enable: boolean): void;
    public is_set_as_top_level(): boolean;
    public set_disable_scale(disable: boolean): void;
    public is_scale_disabled(): boolean;
    public get_world_3d(): World3D;
    public force_update_transform(): void;
    public set_visibility_parent(path: NodePath | GDString | string): void;
    public get_visibility_parent(): NodePath;
    public update_gizmos(): void;
    public add_gizmo(gizmo: Node3DGizmo): void;
    public get_gizmos(): Array<any>;
    public clear_gizmos(): void;
    public set_subgizmo_selection(gizmo: Node3DGizmo, id: number, transform: Transform3D): void;
    public clear_subgizmo_selection(): void;
    public set_visible(visible: boolean): void;
    public is_visible(): boolean;
    public is_visible_in_tree(): boolean;
    public show(): void;
    public hide(): void;
    public set_notify_local_transform(enable: boolean): void;
    public is_local_transform_notification_enabled(): boolean;
    public set_notify_transform(enable: boolean): void;
    public is_transform_notification_enabled(): boolean;
    public rotate(axis: Vector3, angle: number): void;
    public global_rotate(axis: Vector3, angle: number): void;
    public global_scale(scale: Vector3): void;
    public global_translate(offset: Vector3): void;
    public rotate_object_local(axis: Vector3, angle: number): void;
    public scale_object_local(scale: Vector3): void;
    public translate_object_local(offset: Vector3): void;
    public rotate_x(angle: number): void;
    public rotate_y(angle: number): void;
    public rotate_z(angle: number): void;
    public translate(offset: Vector3): void;
    public orthonormalize(): void;
    public set_identity(): void;
    public look_at(target: Vector3, up: Vector3 = Vector3(0, 1, 0), useModelFront: boolean = false): void;
    public look_at_from_position(position: Vector3, target: Vector3, up: Vector3 = Vector3(0, 1, 0), useModelFront: boolean = false): void;
    public to_local(globalPoint: Vector3): Vector3;
    public to_global(localPoint: Vector3): Vector3;

    
    public readonly visibility_changed: Signal<() => void>;

    public static readonly RotationEditMode: {
        ROTATION_EDIT_MODE_EULER: 0;
        ROTATION_EDIT_MODE_QUATERNION: 1;
        ROTATION_EDIT_MODE_BASIS: 2;
    };
}

