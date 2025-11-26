
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';


export declare class SkeletonModification2DLookAt extends SkeletonModification2D {

    
    /**     * The raw type is 'int'     */
    public bone_index: number;    
    /**     * The raw type is 'NodePath'     */
    public bone2d_node: NodePath;    
    /**     * The raw type is 'NodePath'     */
    public target_nodepath: NodePath;
    public set_bone2d_node(bone2dNodepath: NodePath | GDString | string): void;
    public get_bone2d_node(): NodePath;
    public set_bone_index(boneIdx: number): void;
    public get_bone_index(): number;
    public set_target_node(targetNodepath: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_additional_rotation(rotation: number): void;
    public get_additional_rotation(): number;
    public set_enable_constraint(enableConstraint: boolean): void;
    public get_enable_constraint(): boolean;
    public set_constraint_angle_min(angleMin: number): void;
    public get_constraint_angle_min(): number;
    public set_constraint_angle_max(angleMax: number): void;
    public get_constraint_angle_max(): number;
    public set_constraint_angle_invert(invert: boolean): void;
    public get_constraint_angle_invert(): boolean;


}

