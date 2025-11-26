
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';


export declare class SkeletonModification2DTwoBoneIK extends SkeletonModification2D {

    
    /**     * The raw type is 'NodePath'     */
    public target_nodepath: NodePath;    
    /**     * The raw type is 'float'     */
    public target_minimum_distance: number;    
    /**     * The raw type is 'float'     */
    public target_maximum_distance: number;    
    /**     * The raw type is 'bool'     */
    public flip_bend_direction: boolean;
    public set_target_node(targetNodepath: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_target_minimum_distance(minimumDistance: number): void;
    public get_target_minimum_distance(): number;
    public set_target_maximum_distance(maximumDistance: number): void;
    public get_target_maximum_distance(): number;
    public set_flip_bend_direction(flidirection: boolean): void;
    public get_flip_bend_direction(): boolean;
    public set_joint_one_bone2d_node(bone2dNode: NodePath | GDString | string): void;
    public get_joint_one_bone2d_node(): NodePath;
    public set_joint_one_bone_idx(boneIdx: number): void;
    public get_joint_one_bone_idx(): number;
    public set_joint_two_bone2d_node(bone2dNode: NodePath | GDString | string): void;
    public get_joint_two_bone2d_node(): NodePath;
    public set_joint_two_bone_idx(boneIdx: number): void;
    public get_joint_two_bone_idx(): number;


}

