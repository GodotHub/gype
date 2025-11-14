
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';
import type { SkeletonProfile } from '@godot/classes/skeleton_profile';


export declare class RetargetModifier3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'SkeletonProfile'     */
    public profile: SkeletonProfile;    
    /**     * The raw type is 'bool'     */
    public use_global_pose: boolean;    
    /**     * The raw type is 'int'     */
    public enable: number;
    public set_profile(profile: SkeletonProfile): void;
    public get_profile(): SkeletonProfile;
    public set_use_global_pose(useGlobalPose: boolean): void;
    public is_using_global_pose(): boolean;
    public set_enable_flags(enableFlags: number): void;
    public get_enable_flags(): number;
    public set_position_enabled(enabled: boolean): void;
    public is_position_enabled(): boolean;
    public set_rotation_enabled(enabled: boolean): void;
    public is_rotation_enabled(): boolean;
    public set_scale_enabled(enabled: boolean): void;
    public is_scale_enabled(): boolean;


    public static readonly TransformFlag: {
        TRANSFORM_FLAG_POSITION: 1;
        TRANSFORM_FLAG_ROTATION: 2;
        TRANSFORM_FLAG_SCALE: 4;
        TRANSFORM_FLAG_ALL: 7;
    };
}

