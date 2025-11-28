
import type { SkeletonModifier3D } from '@godot/classes/skeleton_modifier3d';


export declare class XRBodyModifier3D extends SkeletonModifier3D {

    
    /**     * The raw type is 'String'     */
    public body_tracker: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public body_update: number;    
    /**     * The raw type is 'int'     */
    public bone_update: number;
    public set_body_tracker(trackerName: GDString | StringName | string): void;
    public get_body_tracker(): StringName;
    public set_body_update(bodyUpdate: number): void;
    public get_body_update(): number;
    public set_bone_update(boneUpdate: number): void;
    public get_bone_update(): number;


    public static readonly BodyUpdate: {
        BODY_UPDATE_UPPER_BODY: 1;
        BODY_UPDATE_LOWER_BODY: 2;
        BODY_UPDATE_HANDS: 4;
    };
    public static readonly BoneUpdate: {
        BONE_UPDATE_FULL: 0;
        BONE_UPDATE_ROTATION_ONLY: 1;
        BONE_UPDATE_MAX: 2;
    };
}

