
import type { BoneConstraint3D } from '@godot/classes/bone_constraint3d';


export declare class ConvertTransformModifier3D extends BoneConstraint3D {

    
    /**     * The raw type is 'int'     */
    public setting_count: number;
    public set_apply_transform_mode(index: number, transformMode: number): void;
    public get_apply_transform_mode(index: number): number;
    public set_apply_axis(index: number, axis: number): void;
    public get_apply_axis(index: number): number;
    public set_apply_range_min(index: number, rangeMin: number): void;
    public get_apply_range_min(index: number): number;
    public set_apply_range_max(index: number, rangeMax: number): void;
    public get_apply_range_max(index: number): number;
    public set_reference_transform_mode(index: number, transformMode: number): void;
    public get_reference_transform_mode(index: number): number;
    public set_reference_axis(index: number, axis: number): void;
    public get_reference_axis(index: number): number;
    public set_reference_range_min(index: number, rangeMin: number): void;
    public get_reference_range_min(index: number): number;
    public set_reference_range_max(index: number, rangeMax: number): void;
    public get_reference_range_max(index: number): number;
    public set_relative(index: number, enabled: boolean): void;
    public is_relative(index: number): boolean;
    public set_additive(index: number, enabled: boolean): void;
    public is_additive(index: number): boolean;


    public static readonly TransformMode: {
        TRANSFORM_MODE_POSITION: 0;
        TRANSFORM_MODE_ROTATION: 1;
        TRANSFORM_MODE_SCALE: 2;
    };
}

