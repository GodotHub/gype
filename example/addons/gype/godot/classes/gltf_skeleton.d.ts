
import type { BoneAttachment3D } from '@godot/classes/bone_attachment3d';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { Resource } from '@godot/classes/resource';
import type { Skeleton3D } from '@godot/classes/skeleton3d';


export declare class GLTFSkeleton extends Resource {

    
    /**     * The raw type is 'PackedInt32Array'     */
    public joints: PackedInt32Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public roots: PackedInt32Array;    
    /**     * The raw type is 'Array'     */
    public unique_names: Array<any>;    
    /**     * The raw type is 'Dictionary'     */
    public godot_bone_node: Dictionary;
    public get_joints(): PackedInt32Array;
    public set_joints(joints: PackedInt32Array): void;
    public get_roots(): PackedInt32Array;
    public set_roots(roots: PackedInt32Array): void;
    public get_godot_skeleton(): Skeleton3D;
    public get_unique_names(): Array<any>;
    public set_unique_names(uniqueNames: Array<any>): void;
    public get_godot_bone_node(): Dictionary;
    public set_godot_bone_node(godotBoneNode: Dictionary): void;
    public get_bone_attachment_count(): number;
    public get_bone_attachment(idx: number): BoneAttachment3D;


}

