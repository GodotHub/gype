
import type { BoneConstraint3D } from '@godot/classes/bone_constraint3d';


export declare class CopyTransformModifier3D extends BoneConstraint3D {

    
    /**     * The raw type is 'int'     */
    public setting_count: number;
    public set_copy_flags(index: number, copyFlags: number): void;
    public get_copy_flags(index: number): number;
    public set_axis_flags(index: number, axisFlags: number): void;
    public get_axis_flags(index: number): number;
    public set_invert_flags(index: number, axisFlags: number): void;
    public get_invert_flags(index: number): number;
    public set_copy_position(index: number, enabled: boolean): void;
    public is_position_copying(index: number): boolean;
    public set_copy_rotation(index: number, enabled: boolean): void;
    public is_rotation_copying(index: number): boolean;
    public set_copy_scale(index: number, enabled: boolean): void;
    public is_scale_copying(index: number): boolean;
    public set_axis_x_enabled(index: number, enabled: boolean): void;
    public is_axis_x_enabled(index: number): boolean;
    public set_axis_y_enabled(index: number, enabled: boolean): void;
    public is_axis_y_enabled(index: number): boolean;
    public set_axis_z_enabled(index: number, enabled: boolean): void;
    public is_axis_z_enabled(index: number): boolean;
    public set_axis_x_inverted(index: number, enabled: boolean): void;
    public is_axis_x_inverted(index: number): boolean;
    public set_axis_y_inverted(index: number, enabled: boolean): void;
    public is_axis_y_inverted(index: number): boolean;
    public set_axis_z_inverted(index: number, enabled: boolean): void;
    public is_axis_z_inverted(index: number): boolean;
    public set_relative(index: number, enabled: boolean): void;
    public is_relative(index: number): boolean;
    public set_additive(index: number, enabled: boolean): void;
    public is_additive(index: number): boolean;


    public static readonly TransformFlag: {
        TRANSFORM_FLAG_POSITION: 1;
        TRANSFORM_FLAG_ROTATION: 2;
        TRANSFORM_FLAG_SCALE: 4;
        TRANSFORM_FLAG_ALL: 7;
    };
    public static readonly AxisFlag: {
        AXIS_FLAG_X: 1;
        AXIS_FLAG_Y: 2;
        AXIS_FLAG_Z: 4;
        AXIS_FLAG_ALL: 7;
    };
}

