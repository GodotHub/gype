
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

    
    public readonly session_supported: Signal<(sessionMode: GDString | StringName | string, supported: boolean) => void>;
    public readonly session_started: Signal<() => void>;
    public readonly session_ended: Signal<() => void>;
    public readonly session_failed: Signal<(message: GDString | StringName | string) => void>;
    public readonly selectstart: Signal<(inputSourceId: number) => void>;
    public readonly select: Signal<(inputSourceId: number) => void>;
    public readonly selectend: Signal<(inputSourceId: number) => void>;
    public readonly squeezestart: Signal<(inputSourceId: number) => void>;
    public readonly squeeze: Signal<(inputSourceId: number) => void>;
    public readonly squeezeend: Signal<(inputSourceId: number) => void>;
    public readonly visibility_state_changed: Signal<() => void>;
    public readonly reference_space_reset: Signal<() => void>;
    public readonly display_refresh_rate_changed: Signal<() => void>;

    public static readonly TargetRayMode: {
        TARGET_RAY_MODE_UNKNOWN: 0;
        TARGET_RAY_MODE_GAZE: 1;
        TARGET_RAY_MODE_TRACKED_POINTER: 2;
        TARGET_RAY_MODE_SCREEN: 3;
    };
}

