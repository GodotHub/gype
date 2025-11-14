
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Projection } from '@godot/builtins/projection';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class XRInterface extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public interface_is_primary: boolean;    
    /**     * The raw type is 'int'     */
    public xr_play_area_mode: number;    
    /**     * The raw type is 'int'     */
    public environment_blend_mode: number;    
    /**     * The raw type is 'bool'     */
    public ar_is_anchor_detection_enabled: boolean;
    public get_name(): StringName;
    public get_capabilities(): number;
    public is_primary(): boolean;
    public set_primary(primary: boolean): void;
    public is_initialized(): boolean;
    public initialize(): boolean;
    public uninitialize(): void;
    public get_system_info(): Dictionary;
    public get_tracking_status(): number;
    public get_render_target_size(): Vector2;
    public get_view_count(): number;
    public trigger_haptic_pulse(actionName: GDString | StringName | string, trackerName: GDString | StringName | string, frequency: number, amplitude: number, durationSec: number, delaySec: number): void;
    public supports_play_area_mode(mode: number): boolean;
    public get_play_area_mode(): number;
    public set_play_area_mode(mode: number): boolean;
    public get_play_area(): PackedVector3Array;
    public get_anchor_detection_is_enabled(): boolean;
    public set_anchor_detection_is_enabled(enable: boolean): void;
    public get_camera_feed_id(): number;
    public is_passthrough_supported(): boolean;
    public is_passthrough_enabled(): boolean;
    public start_passthrough(): boolean;
    public stop_passthrough(): void;
    public get_transform_for_view(view: number, camTransform: Transform3D): Transform3D;
    public get_projection_for_view(view: number, aspect: number, near: number, far: number): Projection;
    public get_supported_environment_blend_modes(): GDArray;
    public set_environment_blend_mode(mode: number): boolean;
    public get_environment_blend_mode(): number;

    
    public readonly play_area_changed: Signal<(mode: number) => void>;

    public static readonly Capabilities: {
        XR_NONE: 0;
        XR_MONO: 1;
        XR_STEREO: 2;
        XR_QUAD: 4;
        XR_VR: 8;
        XR_AR: 16;
        XR_EXTERNAL: 32;
    };
    public static readonly TrackingStatus: {
        XR_NORMAL_TRACKING: 0;
        XR_EXCESSIVE_MOTION: 1;
        XR_INSUFFICIENT_FEATURES: 2;
        XR_UNKNOWN_TRACKING: 3;
        XR_NOT_TRACKING: 4;
    };
    public static readonly PlayAreaMode: {
        XR_PLAY_AREA_UNKNOWN: 0;
        XR_PLAY_AREA_3DOF: 1;
        XR_PLAY_AREA_SITTING: 2;
        XR_PLAY_AREA_ROOMSCALE: 3;
        XR_PLAY_AREA_STAGE: 4;
        XR_PLAY_AREA_CUSTOM: 2147483647;
    };
    public static readonly EnvironmentBlendMode: {
        XR_ENV_BLEND_MODE_OPAQUE: 0;
        XR_ENV_BLEND_MODE_ADDITIVE: 1;
        XR_ENV_BLEND_MODE_ALPHA_BLEND: 2;
    };
    public static readonly VRSTextureFormat: {
        XR_VRS_TEXTURE_FORMAT_UNIFIED: 0;
        XR_VRS_TEXTURE_FORMAT_FRAGMENT_SHADING_RATE: 1;
        XR_VRS_TEXTURE_FORMAT_FRAGMENT_DENSITY_MAP: 2;
    };
}

