
import type { NodePath } from '@godot/builtins/node_path';
import type { SkeletonModification2D } from '@godot/classes/skeleton_modification2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class SkeletonModification2DJiggle extends SkeletonModification2D {

    
    /**     * The raw type is 'NodePath'     */
    public target_nodepath: NodePath;    
    /**     * The raw type is 'int'     */
    public jiggle_data_chain_length: number;    
    /**     * The raw type is 'float'     */
    public stiffness: number;    
    /**     * The raw type is 'float'     */
    public mass: number;    
    /**     * The raw type is 'float'     */
    public damping: number;    
    /**     * The raw type is 'bool'     */
    public use_gravity: boolean;    
    /**     * The raw type is 'Vector2'     */
    public gravity: Vector2;
    public set_target_node(targetNodepath: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_jiggle_data_chain_length(length: number): void;
    public get_jiggle_data_chain_length(): number;
    public set_stiffness(stiffness: number): void;
    public get_stiffness(): number;
    public set_mass(mass: number): void;
    public get_mass(): number;
    public set_damping(damping: number): void;
    public get_damping(): number;
    public set_use_gravity(useGravity: boolean): void;
    public get_use_gravity(): boolean;
    public set_gravity(gravity: Vector2): void;
    public get_gravity(): Vector2;
    public set_use_colliders(useColliders: boolean): void;
    public get_use_colliders(): boolean;
    public set_collision_mask(collisionMask: number): void;
    public get_collision_mask(): number;
    public set_jiggle_joint_bone2d_node(jointIdx: number, bone2dNode: NodePath | GDString | string): void;
    public get_jiggle_joint_bone2d_node(jointIdx: number): NodePath;
    public set_jiggle_joint_bone_index(jointIdx: number, boneIdx: number): void;
    public get_jiggle_joint_bone_index(jointIdx: number): number;
    public set_jiggle_joint_override(jointIdx: number, override: boolean): void;
    public get_jiggle_joint_override(jointIdx: number): boolean;
    public set_jiggle_joint_stiffness(jointIdx: number, stiffness: number): void;
    public get_jiggle_joint_stiffness(jointIdx: number): number;
    public set_jiggle_joint_mass(jointIdx: number, mass: number): void;
    public get_jiggle_joint_mass(jointIdx: number): number;
    public set_jiggle_joint_damping(jointIdx: number, damping: number): void;
    public get_jiggle_joint_damping(jointIdx: number): number;
    public set_jiggle_joint_use_gravity(jointIdx: number, useGravity: boolean): void;
    public get_jiggle_joint_use_gravity(jointIdx: number): boolean;
    public set_jiggle_joint_gravity(jointIdx: number, gravity: Vector2): void;
    public get_jiggle_joint_gravity(jointIdx: number): Vector2;


}

