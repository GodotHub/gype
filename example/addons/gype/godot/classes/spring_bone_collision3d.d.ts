
import type { Node3D } from '@godot/classes/node3d';
import type { Skeleton3D } from '@godot/classes/skeleton3d';


export declare class SpringBoneCollision3D extends Node3D {

    
    /**     * The raw type is 'StringName'     */
    public bone_name: GDString;    
    /**     * The raw type is 'int'     */
    public bone: number;    
    /**     * The raw type is 'Vector3'     */
    public position_offset: Vector3;    
    /**     * The raw type is 'Quaternion'     */
    public rotation_offset: Quaternion;
    public get_skeleton(): Skeleton3D;
    public set_bone_name(boneName: GDString | StringName | string): void;
    public get_bone_name(): GDString;
    public set_bone(bone: number): void;
    public get_bone(): number;
    public set_position_offset(offset: Vector3): void;
    public get_position_offset(): Vector3;
    public set_rotation_offset(offset: Quaternion): void;
    public get_rotation_offset(): Quaternion;


}

