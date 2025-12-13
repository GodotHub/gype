
import type { XRPose } from '@godot/classes/xr_pose';
import type { XRTracker } from '@godot/classes/xr_tracker';


export declare class XRPositionalTracker extends XRTracker {

    
    /**     * The raw type is 'String'     */
    public profile: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public hand: number;
    public get_tracker_profile(): GDString;
    public set_tracker_profile(profile: GDString | StringName | string): void;
    public get_tracker_hand(): number;
    public set_tracker_hand(hand: number): void;
    public has_pose(name: GDString | StringName | string): boolean;
    public get_pose(name: GDString | StringName | string): XRPose;
    public invalidate_pose(name: GDString | StringName | string): void;
    public set_pose(name: GDString | StringName | string, transform: Transform3D, linearVelocity: Vector3, angularVelocity: Vector3, trackingConfidence: number): void;
    public get_input(name: GDString | StringName | string): any;
    public set_input(name: GDString | StringName | string, value: any): void;

    
    public readonly pose_changed: Signal<(pose: XRPose) => void>;
    public readonly pose_lost_tracking: Signal<(pose: XRPose) => void>;
    public readonly button_pressed: Signal<(name: GDString | StringName | string) => void>;
    public readonly button_released: Signal<(name: GDString | StringName | string) => void>;
    public readonly input_float_changed: Signal<(name: GDString | StringName | string, value: number) => void>;
    public readonly input_vector2_changed: Signal<(name: GDString | StringName | string, vector: Vector2) => void>;
    public readonly profile_changed: Signal<(role: GDString | StringName | string) => void>;

    public static readonly TrackerHand: {
        TRACKER_HAND_UNKNOWN: 0;
        TRACKER_HAND_LEFT: 1;
        TRACKER_HAND_RIGHT: 2;
        TRACKER_HAND_MAX: 3;
    };
}

