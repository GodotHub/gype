
import type { Joint2D } from '@godot/classes/joint2d';
import type { NodePath } from '@godot/builtins/node_path';
import type { RigidBody2D } from '@godot/classes/rigid_body2d';


export declare class PhysicalBone2D extends RigidBody2D {

    
    /**     * The raw type is 'NodePath'     */
    public bone2d_nodepath: NodePath;    
    /**     * The raw type is 'int'     */
    public bone2d_index: number;    
    /**     * The raw type is 'bool'     */
    public auto_configure_joint: boolean;    
    /**     * The raw type is 'bool'     */
    public simulate_physics: boolean;    
    /**     * The raw type is 'bool'     */
    public follow_bone_when_simulating: boolean;
    public get_joint(): Joint2D;
    public get_auto_configure_joint(): boolean;
    public set_auto_configure_joint(autoConfigureJoint: boolean): void;
    public set_simulate_physics(simulatePhysics: boolean): void;
    public get_simulate_physics(): boolean;
    public is_simulating_physics(): boolean;
    public set_bone2d_nodepath(nodepath: NodePath | GDString | string): void;
    public get_bone2d_nodepath(): NodePath;
    public set_bone2d_index(boneIndex: number): void;
    public get_bone2d_index(): number;
    public set_follow_bone_when_simulating(followBone: boolean): void;
    public get_follow_bone_when_simulating(): boolean;


}

