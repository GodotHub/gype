
import type { Node3D } from '@godot/classes/node3d';
import type { Skin } from '@godot/classes/skin';
import type { SkinReference } from '@godot/classes/skin_reference';


export declare class Skeleton3D extends Node3D {

    
    /**     * The raw type is 'float'     */
    public motion_scale: number;    
    /**     * The raw type is 'bool'     */
    public show_rest_only: boolean;    
    /**     * The raw type is 'int'     */
    public modifier_callback_mode_process: number;    
    /**     * The raw type is 'bool'     */
    public animate_physical_bones: boolean;
    public add_bone(name: GDString | StringName | string): number;
    public find_bone(name: GDString | StringName | string): number;
    public get_bone_name(boneIdx: number): GDString;
    public set_bone_name(boneIdx: number, name: GDString | StringName | string): void;
    public get_bone_meta(boneIdx: number, key: GDString | StringName | string): any;
    public get_bone_meta_list(boneIdx: number): Array<any>;
    public has_bone_meta(boneIdx: number, key: GDString | StringName | string): boolean;
    public set_bone_meta(boneIdx: number, key: GDString | StringName | string, value: any): void;
    public get_concatenated_bone_names(): StringName;
    public get_bone_parent(boneIdx: number): number;
    public set_bone_parent(boneIdx: number, parentIdx: number): void;
    public get_bone_count(): number;
    public get_version(): number;
    public unparent_bone_and_rest(boneIdx: number): void;
    public get_bone_children(boneIdx: number): PackedInt32Array;
    public get_parentless_bones(): PackedInt32Array;
    public get_bone_rest(boneIdx: number): Transform3D;
    public set_bone_rest(boneIdx: number, rest: Transform3D): void;
    public get_bone_global_rest(boneIdx: number): Transform3D;
    public create_skin_from_rest_transforms(): Skin;
    public register_skin(skin: Skin): SkinReference;
    public localize_rests(): void;
    public clear_bones(): void;
    public get_bone_pose(boneIdx: number): Transform3D;
    public set_bone_pose(boneIdx: number, pose: Transform3D): void;
    public set_bone_pose_position(boneIdx: number, position: Vector3): void;
    public set_bone_pose_rotation(boneIdx: number, rotation: Quaternion): void;
    public set_bone_pose_scale(boneIdx: number, scale: Vector3): void;
    public get_bone_pose_position(boneIdx: number): Vector3;
    public get_bone_pose_rotation(boneIdx: number): Quaternion;
    public get_bone_pose_scale(boneIdx: number): Vector3;
    public reset_bone_pose(boneIdx: number): void;
    public reset_bone_poses(): void;
    public is_bone_enabled(boneIdx: number): boolean;
    public set_bone_enabled(boneIdx: number, enabled: boolean = true): void;
    public get_bone_global_pose(boneIdx: number): Transform3D;
    public set_bone_global_pose(boneIdx: number, pose: Transform3D): void;
    public force_update_all_bone_transforms(): void;
    public force_update_bone_child_transform(boneIdx: number): void;
    public set_motion_scale(motionScale: number): void;
    public get_motion_scale(): number;
    public set_show_rest_only(enabled: boolean): void;
    public is_show_rest_only(): boolean;
    public set_modifier_callback_mode_process(mode: number): void;
    public get_modifier_callback_mode_process(): number;
    public advance(delta: number): void;
    public clear_bones_global_pose_override(): void;
    public set_bone_global_pose_override(boneIdx: number, pose: Transform3D, amount: number, persistent: boolean = false): void;
    public get_bone_global_pose_override(boneIdx: number): Transform3D;
    public get_bone_global_pose_no_override(boneIdx: number): Transform3D;
    public set_animate_physical_bones(enabled: boolean): void;
    public get_animate_physical_bones(): boolean;
    public physical_bones_stop_simulation(): void;
    public physical_bones_start_simulation(bones: Array<any> = []): void;
    public physical_bones_add_collision_exception(exception: RID): void;
    public physical_bones_remove_collision_exception(exception: RID): void;

    
    public readonly rest_updated: Signal;
    public readonly pose_updated: Signal;
    public readonly skeleton_updated: Signal;
    public readonly bone_enabled_changed: Signal;
    public readonly bone_list_changed: Signal;
    public readonly show_rest_only_changed: Signal;

    public static readonly ModifierCallbackModeProcess: {
        MODIFIER_CALLBACK_MODE_PROCESS_PHYSICS: 0;
        MODIFIER_CALLBACK_MODE_PROCESS_IDLE: 1;
        MODIFIER_CALLBACK_MODE_PROCESS_MANUAL: 2;
    };
}

