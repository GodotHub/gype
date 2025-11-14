
import type { GDString } from '@godot/builtins/gd_string';
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';


export declare class BoneConstraint3D extends SkeletonModifier3D {


    public set_amount(index: number, amount: number): void;
    public get_amount(index: number): number;
    public set_apply_bone_name(index: number, boneName: GDString | StringName | string): void;
    public get_apply_bone_name(index: number): GDString;
    public set_apply_bone(index: number, bone: number): void;
    public get_apply_bone(index: number): number;
    public set_reference_bone_name(index: number, boneName: GDString | StringName | string): void;
    public get_reference_bone_name(index: number): GDString;
    public set_reference_bone(index: number, bone: number): void;
    public get_reference_bone(index: number): number;
    public set_setting_count(count: number): void;
    public get_setting_count(): number;
    public clear_setting(): void;


}

