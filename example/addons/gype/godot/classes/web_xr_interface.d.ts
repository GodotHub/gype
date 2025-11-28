
import type { XRControllerTracker } from '@godot/classes/xr_controller_tracker';
import type { XRInterface } from '@godot/classes/xr_interface';


export declare class WebXRInterface extends XRInterface {

    
    /**     * The raw type is 'String'     */
    public session_mode: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public required_features: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public optional_features: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public requested_reference_space_types: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public reference_space_type: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public enabled_features: GDString | StringName | string;    
    /**     * The raw type is 'String'     */
    public visibility_state: GDString | StringName | string;
    public is_session_supported(sessionMode: GDString | StringName | string): void;
    public set_session_mode(sessionMode: GDString | StringName | string): void;
    public get_session_mode(): GDString;
    public set_required_features(requiredFeatures: GDString | StringName | string): void;
    public get_required_features(): GDString;
    public set_optional_features(optionalFeatures: GDString | StringName | string): void;
    public get_optional_features(): GDString;
    public get_reference_space_type(): GDString;
    public get_enabled_features(): GDString;
    public set_requested_reference_space_types(requestedReferenceSpaceTypes: GDString | StringName | string): void;
    public get_requested_reference_space_types(): GDString;
    public is_input_source_active(inputSourceId: number): boolean;
    public get_input_source_tracker(inputSourceId: number): XRControllerTracker;
    public get_input_source_target_ray_mode(inputSourceId: number): number;
    public get_visibility_state(): GDString;
    public get_display_refresh_rate(): number;
    public set_display_refresh_rate(refreshRate: number): void;
    public get_available_display_refresh_rates(): GDArray;

    
    public readonly session_supported: Signal;
    public readonly session_started: Signal;
    public readonly session_ended: Signal;
    public readonly session_failed: Signal;
    public readonly selectstart: Signal;
    public readonly select: Signal;
    public readonly selectend: Signal;
    public readonly squeezestart: Signal;
    public readonly squeeze: Signal;
    public readonly squeezeend: Signal;
    public readonly visibility_state_changed: Signal;
    public readonly reference_space_reset: Signal;
    public readonly display_refresh_rate_changed: Signal;

    public static readonly TargetRayMode: {
        TARGET_RAY_MODE_UNKNOWN: 0;
        TARGET_RAY_MODE_GAZE: 1;
        TARGET_RAY_MODE_TRACKED_POINTER: 2;
        TARGET_RAY_MODE_SCREEN: 3;
    };
}

