
import type { BoneConstraint3D } from '@godot/classes/bone_constraint3d';


export declare class AimModifier3D extends BoneConstraint3D {

    
    /**     * The raw type is 'int'     */
    public setting_count: number;
    public set_forward_axis(index: number, axis: number): void;
    public get_forward_axis(index: number): number;
    public set_use_euler(index: number, enabled: boolean): void;
    public is_using_euler(index: number): boolean;
    public set_primary_rotation_axis(index: number, axis: number): void;
    public get_primary_rotation_axis(index: number): number;
    public set_use_secondary_rotation(index: number, enabled: boolean): void;
    public is_using_secondary_rotation(index: number): boolean;


}

