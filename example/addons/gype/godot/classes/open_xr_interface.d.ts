
import type { XRInterface } from '@godot/classes/xr_interface';


export declare class OpenXRInterface extends XRInterface {

    
    /**     * The raw type is 'float'     */
    public display_refresh_rate: number;    
    /**     * The raw type is 'float'     */
    public render_target_size_multiplier: number;    
    /**     * The raw type is 'int'     */
    public foveation_level: number;    
    /**     * The raw type is 'bool'     */
    public foveation_dynamic: boolean;    
    /**     * The raw type is 'float'     */
    public vrs_min_radius: number;    
    /**     * The raw type is 'float'     */
    public vrs_strength: number;
    public get_session_state(): number;
    public get_display_refresh_rate(): number;
    public set_display_refresh_rate(refreshRate: number): void;
    public get_render_target_size_multiplier(): number;
    public set_render_target_size_multiplier(multiplier: number): void;
    public is_foveation_supported(): boolean;
    public get_foveation_level(): number;
    public set_foveation_level(foveationLevel: number): void;
    public get_foveation_dynamic(): boolean;
    public set_foveation_dynamic(foveationDynamic: boolean): void;
    public is_action_set_active(name: GDString | StringName | string): boolean;
    public set_action_set_active(name: GDString | StringName | string, active: boolean): void;
    public get_action_sets(): GDArray;
    public get_available_display_refresh_rates(): GDArray;
    public set_motion_range(hand: number, motionRange: number): void;
    public get_motion_range(hand: number): number;
    public get_hand_tracking_source(hand: number): number;
    public get_hand_joint_flags(hand: number, joint: number): number;
    public get_hand_joint_rotation(hand: number, joint: number): Quaternion;
    public get_hand_joint_position(hand: number, joint: number): Vector3;
    public get_hand_joint_radius(hand: number, joint: number): number;
    public get_hand_joint_linear_velocity(hand: number, joint: number): Vector3;
    public get_hand_joint_angular_velocity(hand: number, joint: number): Vector3;
    public is_hand_tracking_supported(): boolean;
    public is_hand_interaction_supported(): boolean;
    public is_eye_gaze_interaction_supported(): boolean;
    public get_vrs_min_radius(): number;
    public set_vrs_min_radius(radius: number): void;
    public get_vrs_strength(): number;
    public set_vrs_strength(strength: number): void;
    public set_cpu_level(level: number): void;
    public set_gpu_level(level: number): void;

    
    public readonly session_begun: Signal;
    public readonly session_stopping: Signal;
    public readonly session_synchronized: Signal;
    public readonly session_focussed: Signal;
    public readonly session_visible: Signal;
    public readonly session_loss_pending: Signal;
    public readonly instance_exiting: Signal;
    public readonly pose_recentered: Signal;
    public readonly refresh_rate_changed: Signal;
    public readonly cpu_level_changed: Signal;
    public readonly gpu_level_changed: Signal;

    public static readonly SessionState: {
        SESSION_STATE_UNKNOWN: 0;
        SESSION_STATE_IDLE: 1;
        SESSION_STATE_READY: 2;
        SESSION_STATE_SYNCHRONIZED: 3;
        SESSION_STATE_VISIBLE: 4;
        SESSION_STATE_FOCUSED: 5;
        SESSION_STATE_STOPPING: 6;
        SESSION_STATE_LOSS_PENDING: 7;
        SESSION_STATE_EXITING: 8;
    };
    public static readonly Hand: {
        HAND_LEFT: 0;
        HAND_RIGHT: 1;
        HAND_MAX: 2;
    };
    public static readonly HandMotionRange: {
        HAND_MOTION_RANGE_UNOBSTRUCTED: 0;
        HAND_MOTION_RANGE_CONFORM_TO_CONTROLLER: 1;
        HAND_MOTION_RANGE_MAX: 2;
    };
    public static readonly HandTrackedSource: {
        HAND_TRACKED_SOURCE_UNKNOWN: 0;
        HAND_TRACKED_SOURCE_UNOBSTRUCTED: 1;
        HAND_TRACKED_SOURCE_CONTROLLER: 2;
        HAND_TRACKED_SOURCE_MAX: 3;
    };
    public static readonly HandJoints: {
        HAND_JOINT_PALM: 0;
        HAND_JOINT_WRIST: 1;
        HAND_JOINT_THUMB_METACARPAL: 2;
        HAND_JOINT_THUMB_PROXIMAL: 3;
        HAND_JOINT_THUMB_DISTAL: 4;
        HAND_JOINT_THUMB_TIP: 5;
        HAND_JOINT_INDEX_METACARPAL: 6;
        HAND_JOINT_INDEX_PROXIMAL: 7;
        HAND_JOINT_INDEX_INTERMEDIATE: 8;
        HAND_JOINT_INDEX_DISTAL: 9;
        HAND_JOINT_INDEX_TIP: 10;
        HAND_JOINT_MIDDLE_METACARPAL: 11;
        HAND_JOINT_MIDDLE_PROXIMAL: 12;
        HAND_JOINT_MIDDLE_INTERMEDIATE: 13;
        HAND_JOINT_MIDDLE_DISTAL: 14;
        HAND_JOINT_MIDDLE_TIP: 15;
        HAND_JOINT_RING_METACARPAL: 16;
        HAND_JOINT_RING_PROXIMAL: 17;
        HAND_JOINT_RING_INTERMEDIATE: 18;
        HAND_JOINT_RING_DISTAL: 19;
        HAND_JOINT_RING_TIP: 20;
        HAND_JOINT_LITTLE_METACARPAL: 21;
        HAND_JOINT_LITTLE_PROXIMAL: 22;
        HAND_JOINT_LITTLE_INTERMEDIATE: 23;
        HAND_JOINT_LITTLE_DISTAL: 24;
        HAND_JOINT_LITTLE_TIP: 25;
        HAND_JOINT_MAX: 26;
    };
    public static readonly PerfSettingsLevel: {
        PERF_SETTINGS_LEVEL_POWER_SAVINGS: 0;
        PERF_SETTINGS_LEVEL_SUSTAINED_LOW: 1;
        PERF_SETTINGS_LEVEL_SUSTAINED_HIGH: 2;
        PERF_SETTINGS_LEVEL_BOOST: 3;
    };
    public static readonly PerfSettingsSubDomain: {
        PERF_SETTINGS_SUB_DOMAIN_COMPOSITING: 0;
        PERF_SETTINGS_SUB_DOMAIN_RENDERING: 1;
        PERF_SETTINGS_SUB_DOMAIN_THERMAL: 2;
    };
    public static readonly PerfSettingsNotificationLevel: {
        PERF_SETTINGS_NOTIF_LEVEL_NORMAL: 0;
        PERF_SETTINGS_NOTIF_LEVEL_WARNING: 1;
        PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED: 2;
    };
    public static readonly HandJointFlags: {
        HAND_JOINT_NONE: 0;
        HAND_JOINT_ORIENTATION_VALID: 1;
        HAND_JOINT_ORIENTATION_TRACKED: 2;
        HAND_JOINT_POSITION_VALID: 4;
        HAND_JOINT_POSITION_TRACKED: 8;
        HAND_JOINT_LINEAR_VELOCITY_VALID: 16;
        HAND_JOINT_ANGULAR_VELOCITY_VALID: 32;
    };
}

