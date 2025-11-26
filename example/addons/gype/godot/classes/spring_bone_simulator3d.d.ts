
import type { Curve } from '@godot/classes/curve';
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';


export declare class SpringBoneSimulator3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'Vector3'     */
    public external_force: Vector3;    
    /**     * The raw type is 'int'     */
    public setting_count: number;
    public set_root_bone_name(index: number, boneName: GDString | StringName | string): void;
    public get_root_bone_name(index: number): GDString;
    public set_root_bone(index: number, bone: number): void;
    public get_root_bone(index: number): number;
    public set_end_bone_name(index: number, boneName: GDString | StringName | string): void;
    public get_end_bone_name(index: number): GDString;
    public set_end_bone(index: number, bone: number): void;
    public get_end_bone(index: number): number;
    public set_extend_end_bone(index: number, enabled: boolean): void;
    public is_end_bone_extended(index: number): boolean;
    public set_end_bone_direction(index: number, boneDirection: number): void;
    public get_end_bone_direction(index: number): number;
    public set_end_bone_length(index: number, length: number): void;
    public get_end_bone_length(index: number): number;
    public set_center_from(index: number, centerFrom: number): void;
    public get_center_from(index: number): number;
    public set_center_node(index: number, nodePath: NodePath | GDString | string): void;
    public get_center_node(index: number): NodePath;
    public set_center_bone_name(index: number, boneName: GDString | StringName | string): void;
    public get_center_bone_name(index: number): GDString;
    public set_center_bone(index: number, bone: number): void;
    public get_center_bone(index: number): number;
    public set_radius(index: number, radius: number): void;
    public get_radius(index: number): number;
    public set_rotation_axis(index: number, axis: number): void;
    public get_rotation_axis(index: number): number;
    public set_rotation_axis_vector(index: number, vector: Vector3): void;
    public get_rotation_axis_vector(index: number): Vector3;
    public set_radius_damping_curve(index: number, curve: Curve): void;
    public get_radius_damping_curve(index: number): Curve;
    public set_stiffness(index: number, stiffness: number): void;
    public get_stiffness(index: number): number;
    public set_stiffness_damping_curve(index: number, curve: Curve): void;
    public get_stiffness_damping_curve(index: number): Curve;
    public set_drag(index: number, drag: number): void;
    public get_drag(index: number): number;
    public set_drag_damping_curve(index: number, curve: Curve): void;
    public get_drag_damping_curve(index: number): Curve;
    public set_gravity(index: number, gravity: number): void;
    public get_gravity(index: number): number;
    public set_gravity_damping_curve(index: number, curve: Curve): void;
    public get_gravity_damping_curve(index: number): Curve;
    public set_gravity_direction(index: number, gravityDirection: Vector3): void;
    public get_gravity_direction(index: number): Vector3;
    public set_setting_count(count: number): void;
    public get_setting_count(): number;
    public clear_settings(): void;
    public set_individual_config(index: number, enabled: boolean): void;
    public is_config_individual(index: number): boolean;
    public get_joint_bone_name(index: number, joint: number): GDString;
    public get_joint_bone(index: number, joint: number): number;
    public set_joint_rotation_axis(index: number, joint: number, axis: number): void;
    public get_joint_rotation_axis(index: number, joint: number): number;
    public set_joint_rotation_axis_vector(index: number, joint: number, vector: Vector3): void;
    public get_joint_rotation_axis_vector(index: number, joint: number): Vector3;
    public set_joint_radius(index: number, joint: number, radius: number): void;
    public get_joint_radius(index: number, joint: number): number;
    public set_joint_stiffness(index: number, joint: number, stiffness: number): void;
    public get_joint_stiffness(index: number, joint: number): number;
    public set_joint_drag(index: number, joint: number, drag: number): void;
    public get_joint_drag(index: number, joint: number): number;
    public set_joint_gravity(index: number, joint: number, gravity: number): void;
    public get_joint_gravity(index: number, joint: number): number;
    public set_joint_gravity_direction(index: number, joint: number, gravityDirection: Vector3): void;
    public get_joint_gravity_direction(index: number, joint: number): Vector3;
    public get_joint_count(index: number): number;
    public set_enable_all_child_collisions(index: number, enabled: boolean): void;
    public are_all_child_collisions_enabled(index: number): boolean;
    public set_exclude_collision_path(index: number, collision: number, nodePath: NodePath | GDString | string): void;
    public get_exclude_collision_path(index: number, collision: number): NodePath;
    public set_exclude_collision_count(index: number, count: number): void;
    public get_exclude_collision_count(index: number): number;
    public clear_exclude_collisions(index: number): void;
    public set_collision_path(index: number, collision: number, nodePath: NodePath | GDString | string): void;
    public get_collision_path(index: number, collision: number): NodePath;
    public set_collision_count(index: number, count: number): void;
    public get_collision_count(index: number): number;
    public clear_collisions(index: number): void;
    public set_external_force(force: Vector3): void;
    public get_external_force(): Vector3;
    public reset(): void;


    public static readonly BoneDirection: {
        BONE_DIRECTION_PLUS_X: 0;
        BONE_DIRECTION_MINUS_X: 1;
        BONE_DIRECTION_PLUS_Y: 2;
        BONE_DIRECTION_MINUS_Y: 3;
        BONE_DIRECTION_PLUS_Z: 4;
        BONE_DIRECTION_MINUS_Z: 5;
        BONE_DIRECTION_FROM_PARENT: 6;
    };
    public static readonly CenterFrom: {
        CENTER_FROM_WORLD_ORIGIN: 0;
        CENTER_FROM_NODE: 1;
        CENTER_FROM_BONE: 2;
    };
    public static readonly RotationAxis: {
        ROTATION_AXIS_X: 0;
        ROTATION_AXIS_Y: 1;
        ROTATION_AXIS_Z: 2;
        ROTATION_AXIS_ALL: 3;
        ROTATION_AXIS_CUSTOM: 4;
    };
}

