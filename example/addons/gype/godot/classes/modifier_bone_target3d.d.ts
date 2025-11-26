
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';


export declare class ModifierBoneTarget3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'String'     */
    public bone_name: GDString;    
    /**     * The raw type is 'int'     */
    public bone: number;
    public set_bone_name(boneName: GDString | StringName | string): void;
    public get_bone_name(): GDString;
    public set_bone(bone: number): void;
    public get_bone(): number;


}

