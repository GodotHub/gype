
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';


export declare class SkeletonModification2DFABRIK extends SkeletonModification2D {

    
    /**     * The raw type is 'NodePath'     */
    public target_nodepath: NodePath;    
    /**     * The raw type is 'int'     */
    public fabrik_data_chain_length: number;
    public set_target_node(targetNodepath: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_fabrik_data_chain_length(length: number): void;
    public get_fabrik_data_chain_length(): number;
    public set_fabrik_joint_bone2d_node(jointIdx: number, bone2dNodepath: NodePath | GDString | string): void;
    public get_fabrik_joint_bone2d_node(jointIdx: number): NodePath;
    public set_fabrik_joint_bone_index(jointIdx: number, boneIdx: number): void;
    public get_fabrik_joint_bone_index(jointIdx: number): number;
    public set_fabrik_joint_magnet_position(jointIdx: number, magnetPosition: Vector2): void;
    public get_fabrik_joint_magnet_position(jointIdx: number): Vector2;
    public set_fabrik_joint_use_target_rotation(jointIdx: number, useTargetRotation: boolean): void;
    public get_fabrik_joint_use_target_rotation(jointIdx: number): boolean;


}

