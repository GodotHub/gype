
import type { GDString } from '@godot/builtins/gd_string';
import type { NodePath } from '@godot/builtins/node_path';
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class LookAtModifier3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'NodePath'     */
    public target_node: NodePath;    
    /**     * The raw type is 'String'     */
    public bone_name: GDString;    
    /**     * The raw type is 'int'     */
    public bone: number;    
    /**     * The raw type is 'int'     */
    public forward_axis: number;    
    /**     * The raw type is 'int'     */
    public primary_rotation_axis: number;    
    /**     * The raw type is 'bool'     */
    public use_secondary_rotation: boolean;    
    /**     * The raw type is 'int'     */
    public origin_from: number;    
    /**     * The raw type is 'String'     */
    public origin_bone_name: GDString;    
    /**     * The raw type is 'int'     */
    public origin_bone: number;    
    /**     * The raw type is 'NodePath'     */
    public origin_external_node: NodePath;    
    /**     * The raw type is 'Vector3'     */
    public origin_offset: Vector3;    
    /**     * The raw type is 'float'     */
    public origin_safe_margin: number;    
    /**     * The raw type is 'float'     */
    public duration: number;    
    /**     * The raw type is 'int'     */
    public transition_type: number;    
    /**     * The raw type is 'int'     */
    public ease_type: number;    
    /**     * The raw type is 'bool'     */
    public use_angle_limitation: boolean;    
    /**     * The raw type is 'bool'     */
    public symmetry_limitation: boolean;    
    /**     * The raw type is 'float'     */
    public primary_limit_angle: number;    
    /**     * The raw type is 'float'     */
    public primary_damp_threshold: number;    
    /**     * The raw type is 'float'     */
    public primary_positive_limit_angle: number;    
    /**     * The raw type is 'float'     */
    public primary_positive_damp_threshold: number;    
    /**     * The raw type is 'float'     */
    public primary_negative_limit_angle: number;    
    /**     * The raw type is 'float'     */
    public primary_negative_damp_threshold: number;    
    /**     * The raw type is 'float'     */
    public secondary_limit_angle: number;    
    /**     * The raw type is 'float'     */
    public secondary_damp_threshold: number;    
    /**     * The raw type is 'float'     */
    public secondary_positive_limit_angle: number;    
    /**     * The raw type is 'float'     */
    public secondary_positive_damp_threshold: number;    
    /**     * The raw type is 'float'     */
    public secondary_negative_limit_angle: number;    
    /**     * The raw type is 'float'     */
    public secondary_negative_damp_threshold: number;
    public set_target_node(targetNode: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_bone_name(boneName: GDString | StringName | string): void;
    public get_bone_name(): GDString;
    public set_bone(bone: number): void;
    public get_bone(): number;
    public set_forward_axis(forwardAxis: number): void;
    public get_forward_axis(): number;
    public set_primary_rotation_axis(axis: number): void;
    public get_primary_rotation_axis(): number;
    public set_use_secondary_rotation(enabled: boolean): void;
    public is_using_secondary_rotation(): boolean;
    public set_origin_safe_margin(margin: number): void;
    public get_origin_safe_margin(): number;
    public set_origin_from(originFrom: number): void;
    public get_origin_from(): number;
    public set_origin_bone_name(boneName: GDString | StringName | string): void;
    public get_origin_bone_name(): GDString;
    public set_origin_bone(bone: number): void;
    public get_origin_bone(): number;
    public set_origin_external_node(externalNode: NodePath | GDString | string): void;
    public get_origin_external_node(): NodePath;
    public set_origin_offset(offset: Vector3): void;
    public get_origin_offset(): Vector3;
    public set_duration(duration: number): void;
    public get_duration(): number;
    public set_transition_type(transitionType: number): void;
    public get_transition_type(): number;
    public set_ease_type(easeType: number): void;
    public get_ease_type(): number;
    public set_use_angle_limitation(enabled: boolean): void;
    public is_using_angle_limitation(): boolean;
    public set_symmetry_limitation(enabled: boolean): void;
    public is_limitation_symmetry(): boolean;
    public set_primary_limit_angle(angle: number): void;
    public get_primary_limit_angle(): number;
    public set_primary_damp_threshold(power: number): void;
    public get_primary_damp_threshold(): number;
    public set_primary_positive_limit_angle(angle: number): void;
    public get_primary_positive_limit_angle(): number;
    public set_primary_positive_damp_threshold(power: number): void;
    public get_primary_positive_damp_threshold(): number;
    public set_primary_negative_limit_angle(angle: number): void;
    public get_primary_negative_limit_angle(): number;
    public set_primary_negative_damp_threshold(power: number): void;
    public get_primary_negative_damp_threshold(): number;
    public set_secondary_limit_angle(angle: number): void;
    public get_secondary_limit_angle(): number;
    public set_secondary_damp_threshold(power: number): void;
    public get_secondary_damp_threshold(): number;
    public set_secondary_positive_limit_angle(angle: number): void;
    public get_secondary_positive_limit_angle(): number;
    public set_secondary_positive_damp_threshold(power: number): void;
    public get_secondary_positive_damp_threshold(): number;
    public set_secondary_negative_limit_angle(angle: number): void;
    public get_secondary_negative_limit_angle(): number;
    public set_secondary_negative_damp_threshold(power: number): void;
    public get_secondary_negative_damp_threshold(): number;
    public get_interpolation_remaining(): number;
    public is_interpolating(): boolean;
    public is_target_within_limitation(): boolean;


    public static readonly OriginFrom: {
        ORIGIN_FROM_SELF: 0;
        ORIGIN_FROM_SPECIFIC_BONE: 1;
        ORIGIN_FROM_EXTERNAL_NODE: 2;
    };
}

