
import type { Node3D } from '@godot/classes/node3d';
import type { NodePath } from '@godot/builtins/node_path';


export declare class OpenXRHand extends Node3D {

    
    /**     * The raw type is 'int'     */
    public hand: number;    
    /**     * The raw type is 'int'     */
    public motion_range: number;    
    /**     * The raw type is 'NodePath'     */
    public hand_skeleton: NodePath;    
    /**     * The raw type is 'int'     */
    public skeleton_rig: number;    
    /**     * The raw type is 'int'     */
    public bone_update: number;
    public set_hand(hand: number): void;
    public get_hand(): number;
    public set_hand_skeleton(handSkeleton: NodePath | GDString | string): void;
    public get_hand_skeleton(): NodePath;
    public set_motion_range(motionRange: number): void;
    public get_motion_range(): number;
    public set_skeleton_rig(skeletonRig: number): void;
    public get_skeleton_rig(): number;
    public set_bone_update(boneUpdate: number): void;
    public get_bone_update(): number;


    public static readonly Hands: {
        HAND_LEFT: 0;
        HAND_RIGHT: 1;
        HAND_MAX: 2;
    };
    public static readonly MotionRange: {
        MOTION_RANGE_UNOBSTRUCTED: 0;
        MOTION_RANGE_CONFORM_TO_CONTROLLER: 1;
        MOTION_RANGE_MAX: 2;
    };
    public static readonly SkeletonRig: {
        SKELETON_RIG_OPENXR: 0;
        SKELETON_RIG_HUMANOID: 1;
        SKELETON_RIG_MAX: 2;
    };
    public static readonly BoneUpdate: {
        BONE_UPDATE_FULL: 0;
        BONE_UPDATE_ROTATION_ONLY: 1;
        BONE_UPDATE_MAX: 2;
    };
}

