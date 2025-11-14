
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { Resource } from '@godot/classes/resource';
import type { Skin } from '@godot/classes/skin';


export declare class GLTFSkin extends Resource {

    
    /**     * The raw type is 'int'     */
    public skin_root: number;    
    /**     * The raw type is 'PackedInt32Array'     */
    public joints_original: PackedInt32Array;    
    /**     * The raw type is 'Array'     */
    public inverse_binds: Array<any>;    
    /**     * The raw type is 'PackedInt32Array'     */
    public joints: PackedInt32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public non_joints: PackedInt32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public roots: PackedInt32Array;    
    /**     * The raw type is 'int'     */
    public skeleton: number;    
    /**     * The raw type is 'Dictionary'     */
    public joint_i_to_bone_i: Dictionary;    
    /**     * The raw type is 'Dictionary'     */
    public joint_i_to_name: Dictionary;    
    /**     * The raw type is 'Skin'     */
    public godot_skin: Skin;
    public get_skin_root(): number;
    public set_skin_root(skinRoot: number): void;
    public get_joints_original(): PackedInt32Array;
    public set_joints_original(jointsOriginal: PackedInt32Array): void;
    public get_inverse_binds(): Array<any>;
    public set_inverse_binds(inverseBinds: Array<any>): void;
    public get_joints(): PackedInt32Array;
    public set_joints(joints: PackedInt32Array): void;
    public get_non_joints(): PackedInt32Array;
    public set_non_joints(nonJoints: PackedInt32Array): void;
    public get_roots(): PackedInt32Array;
    public set_roots(roots: PackedInt32Array): void;
    public get_skeleton(): number;
    public set_skeleton(skeleton: number): void;
    public get_joint_i_to_bone_i(): Dictionary;
    public set_joint_i_to_bone_i(jointIToBoneI: Dictionary): void;
    public get_joint_i_to_name(): Dictionary;
    public set_joint_i_to_name(jointIToName: Dictionary): void;
    public get_godot_skin(): Skin;
    public set_godot_skin(godotSkin: Skin): void;


}

