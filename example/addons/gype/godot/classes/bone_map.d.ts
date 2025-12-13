
import type { Resource } from '@godot/classes/resource';
import type { SkeletonProfile } from '@godot/classes/skeleton_profile';


export declare class BoneMap extends Resource {

    
    /**     * The raw type is 'SkeletonProfile'     */
    public profile: SkeletonProfile;
    public get_profile(): SkeletonProfile;
    public set_profile(profile: SkeletonProfile): void;
    public get_skeleton_bone_name(profileBoneName: GDString | StringName | string): StringName;
    public set_skeleton_bone_name(profileBoneName: GDString | StringName | string, skeletonBoneName: GDString | StringName | string): void;
    public find_profile_bone_name(skeletonBoneName: GDString | StringName | string): StringName;

    
    public readonly bone_map_updated: Signal<() => void>;
    public readonly profile_updated: Signal<() => void>;

}

