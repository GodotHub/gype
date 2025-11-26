
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';


export declare class SkeletonModification2DCCDIK extends SkeletonModification2D {

    
    /**     * The raw type is 'NodePath'     */
    public target_nodepath: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public tip_nodepath: NodePath;    
    /**     * The raw type is 'int'     */
    public ccdik_data_chain_length: number;
    public set_target_node(targetNodepath: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_tip_node(tinodepath: NodePath | GDString | string): void;
    public get_tip_node(): NodePath;
    public set_ccdik_data_chain_length(length: number): void;
    public get_ccdik_data_chain_length(): number;
    public set_ccdik_joint_bone2d_node(jointIdx: number, bone2dNodepath: NodePath | GDString | string): void;
    public get_ccdik_joint_bone2d_node(jointIdx: number): NodePath;
    public set_ccdik_joint_bone_index(jointIdx: number, boneIdx: number): void;
    public get_ccdik_joint_bone_index(jointIdx: number): number;
    public set_ccdik_joint_rotate_from_joint(jointIdx: number, rotateFromJoint: boolean): void;
    public get_ccdik_joint_rotate_from_joint(jointIdx: number): boolean;
    public set_ccdik_joint_enable_constraint(jointIdx: number, enableConstraint: boolean): void;
    public get_ccdik_joint_enable_constraint(jointIdx: number): boolean;
    public set_ccdik_joint_constraint_angle_min(jointIdx: number, angleMin: number): void;
    public get_ccdik_joint_constraint_angle_min(jointIdx: number): number;
    public set_ccdik_joint_constraint_angle_max(jointIdx: number, angleMax: number): void;
    public get_ccdik_joint_constraint_angle_max(jointIdx: number): number;
    public set_ccdik_joint_constraint_angle_invert(jointIdx: number, invert: boolean): void;
    public get_ccdik_joint_constraint_angle_invert(jointIdx: number): boolean;


}

