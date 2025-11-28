
import type { Skeleton3D } from '@godot/classes/skeleton3d';
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';


export declare class SkeletonIK3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'StringName'     */
    public root_bone: GDString | StringName | string;    
    /**     * The raw type is 'StringName'     */
    public tip_bone: GDString | StringName | string;    
    /**     * The raw type is 'Transform3D'     */
    public target: Transform3D;    
    /**     * The raw type is 'bool'     */
    public override_tip_basis: boolean;    
    /**     * The raw type is 'bool'     */
    public use_magnet: boolean;    
    /**     * The raw type is 'Vector3'     */
    public magnet: Vector3;    
    /**     * The raw type is 'NodePath'     */
    public target_node: NodePath;    
    /**     * The raw type is 'float'     */
    public min_distance: number;    
    /**     * The raw type is 'int'     */
    public max_iterations: number;    
    /**     * The raw type is 'float'     */
    public interpolation: number;
    public set_root_bone(rootBone: GDString | StringName | string): void;
    public get_root_bone(): StringName;
    public set_tip_bone(tibone: GDString | StringName | string): void;
    public get_tip_bone(): StringName;
    public set_target_transform(target: Transform3D): void;
    public get_target_transform(): Transform3D;
    public set_target_node(node: NodePath | GDString | string): void;
    public get_target_node(): NodePath;
    public set_override_tip_basis(override: boolean): void;
    public is_override_tip_basis(): boolean;
    public set_use_magnet(use: boolean): void;
    public is_using_magnet(): boolean;
    public set_magnet_position(localPosition: Vector3): void;
    public get_magnet_position(): Vector3;
    public get_parent_skeleton(): Skeleton3D;
    public is_running(): boolean;
    public set_min_distance(minDistance: number): void;
    public get_min_distance(): number;
    public set_max_iterations(iterations: number): void;
    public get_max_iterations(): number;
    public start(oneTime: boolean = false): void;
    public stop(): void;
    public set_interpolation(interpolation: number): void;
    public get_interpolation(): number;


}

