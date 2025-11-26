
import type { Bone2D } from '@godot/classes/bone2d';
import type { Node2D } from '@godot/classes/node2d';
import type { SkeletonModificationStack2D } from '@godot/classes/skeleton_modification_stack2d';


export declare class Skeleton2D extends Node2D {


    public get_bone_count(): number;
    public get_bone(idx: number): Bone2D;
    public get_skeleton(): RID;
    public set_modification_stack(modificationStack: SkeletonModificationStack2D): void;
    public get_modification_stack(): SkeletonModificationStack2D;
    public execute_modifications(delta: number, executionMode: number): void;
    public set_bone_local_pose_override(boneIdx: number, overridePose: Transform2D, strength: number, persistent: boolean): void;
    public get_bone_local_pose_override(boneIdx: number): Transform2D;

    
    public readonly bone_setup_changed: Signal;

}

