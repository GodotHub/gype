
import type { GDString } from '@godot/builtins/gd_string';
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';
import type { StringName } from '@godot/builtins/string_name';


export declare class XRHandModifier3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'String'     */
    public hand_tracker: StringName;    
    /**     * The raw type is 'int'     */
    public bone_update: number;
    public set_hand_tracker(trackerName: GDString | StringName | string): void;
    public get_hand_tracker(): StringName;
    public set_bone_update(boneUpdate: number): void;
    public get_bone_update(): number;


    public static readonly BoneUpdate: {
        BONE_UPDATE_FULL: 0;
        BONE_UPDATE_ROTATION_ONLY: 1;
        BONE_UPDATE_MAX: 2;
    };
}

