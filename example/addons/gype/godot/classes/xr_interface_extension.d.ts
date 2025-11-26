
import type { XRInterface } from '@godot/classes/xr_interface';


export declare class XRInterfaceExtension extends XRInterface {


    public _get_name(): StringName;
    public _get_capabilities(): number;
    public _is_initialized(): boolean;
    public _initialize(): boolean;
    public _uninitialize(): void;
    public _get_system_info(): Dictionary;
    public _supports_play_area_mode(mode: number): boolean;
    public _get_play_area_mode(): number;
    public _set_play_area_mode(mode: number): boolean;
    public _get_play_area(): PackedVector3Array;
    public _get_render_target_size(): Vector2;
    public _get_view_count(): number;
    public _get_camera_transform(): Transform3D;
    public _get_transform_for_view(view: number, camTransform: Transform3D): Transform3D;
    public _get_projection_for_view(view: number, aspect: number, zNear: number, zFar: number): PackedFloat64Array;
    public _get_vrs_texture(): RID;
    public _get_vrs_texture_format(): number;
    public _process(): void;
    public _pre_render(): void;
    public _pre_draw_viewport(renderTarget: RID): boolean;
    public _post_draw_viewport(renderTarget: RID, screenRect: Rect2): void;
    public _end_frame(): void;
    public _get_suggested_tracker_names(): PackedStringArray;
    public _get_suggested_pose_names(trackerName: GDString | StringName | string): PackedStringArray;
    public _get_tracking_status(): number;
    public _trigger_haptic_pulse(actionName: GDString | StringName | string, trackerName: GDString | StringName | string, frequency: number, amplitude: number, durationSec: number, delaySec: number): void;
    public _get_anchor_detection_is_enabled(): boolean;
    public _set_anchor_detection_is_enabled(enabled: boolean): void;
    public _get_camera_feed_id(): number;
    public _get_color_texture(): RID;
    public _get_depth_texture(): RID;
    public _get_velocity_texture(): RID;
    public get_color_texture(): RID;
    public get_depth_texture(): RID;
    public get_velocity_texture(): RID;
    public add_blit(renderTarget: RID, srcRect: Rect2, dstRect: Rect2i, useLayer: boolean, layer: number, applyLensDistortion: boolean, eyeCenter: Vector2, k1: number, k2: number, upscale: number, aspectRatio: number): void;
    public get_render_target_texture(renderTarget: RID): RID;


}

