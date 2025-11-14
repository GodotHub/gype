
import type { Node3D } from '@godot/classes/node3d';
import type { Signal } from '@godot/builtins/signal';
import type { Skeleton3D } from '@godot/classes/skeleton3d';


export declare class SkeletonModifier3D extends Node3D {

    
    /**     * The raw type is 'bool'     */
    public active: boolean;    
    /**     * The raw type is 'float'     */
    public influence: number;
    public _process_modification_with_delta(delta: number): void;
    public _process_modification(): void;
    public _skeleton_changed(oldSkeleton: Skeleton3D, newSkeleton: Skeleton3D): void;
    public _validate_bone_names(): void;
    public get_skeleton(): Skeleton3D;
    public set_active(active: boolean): void;
    public is_active(): boolean;
    public set_influence(influence: number): void;
    public get_influence(): number;

    
    public readonly modification_processed: Signal<() => void>;

    public static readonly BoneAxis: {
        BONE_AXIS_PLUS_X: 0;
        BONE_AXIS_MINUS_X: 1;
        BONE_AXIS_PLUS_Y: 2;
        BONE_AXIS_MINUS_Y: 3;
        BONE_AXIS_PLUS_Z: 4;
        BONE_AXIS_MINUS_Z: 5;
    };
}

