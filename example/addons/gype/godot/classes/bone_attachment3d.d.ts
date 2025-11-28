
import type { Node3D } from '@godot/classes/node3d';
import type { Skeleton3D } from '@godot/classes/skeleton3d';


export declare class BoneAttachment3D extends Node3D {

    
    /**     * The raw type is 'StringName'     */
    public bone_name: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public bone_idx: number;    
    /**     * The raw type is 'bool'     */
    public override_pose: boolean;    
    /**     * The raw type is 'bool'     */
    public use_external_skeleton: boolean;    
    /**     * The raw type is 'NodePath'     */
    public external_skeleton: NodePath;
    public get_skeleton(): Skeleton3D;
    public set_bone_name(boneName: GDString | StringName | string): void;
    public get_bone_name(): GDString;
    public set_bone_idx(boneIdx: number): void;
    public get_bone_idx(): number;
    public on_skeleton_update(): void;
    public set_override_pose(overridePose: boolean): void;
    public get_override_pose(): boolean;
    public set_use_external_skeleton(useExternalSkeleton: boolean): void;
    public get_use_external_skeleton(): boolean;
    public set_external_skeleton(externalSkeleton: NodePath | GDString | string): void;
    public get_external_skeleton(): NodePath;


}

