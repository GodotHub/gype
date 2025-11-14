
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/builtins/gd_string';
import type { OpenXRExtensionWrapper } from '@godot/classes/open_xr_extension_wrapper';
import type { PackedInt64Array } from '@godot/builtins/packed_int64_array';
import type { RID } from '@godot/builtins/rid';
import type { Rect2i } from '@godot/builtins/rect2i';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class OpenXRAPIExtension extends RefCounted {


    public get_instance(): number;
    public get_system_id(): number;
    public get_session(): number;
    public transform_from_pose(pose: any): Transform3D;
    public xr_result(result: number, format: GDString | StringName | string, args: GDArray): boolean;
    public static openxr_is_enabled(checkRunInEditor: boolean): boolean;
    public get_instance_proc_addr(name: GDString | StringName | string): number;
    public get_error_string(result: number): GDString;
    public get_swapchain_format_name(swapchainFormat: number): GDString;
    public set_object_name(objectType: number, objectHandle: number, objectName: GDString | StringName | string): void;
    public begin_debug_label_region(labelName: GDString | StringName | string): void;
    public end_debug_label_region(): void;
    public insert_debug_label(labelName: GDString | StringName | string): void;
    public is_initialized(): boolean;
    public is_running(): boolean;
    public set_custom_play_space(space: any): void;
    public get_play_space(): number;
    public get_predicted_display_time(): number;
    public get_next_frame_time(): number;
    public can_render(): boolean;
    public find_action(name: GDString | StringName | string, actionSet: RID): RID;
    public action_get_handle(action: RID): number;
    public get_hand_tracker(handIndex: number): number;
    public register_composition_layer_provider(extension: OpenXRExtensionWrapper): void;
    public unregister_composition_layer_provider(extension: OpenXRExtensionWrapper): void;
    public register_projection_views_extension(extension: OpenXRExtensionWrapper): void;
    public unregister_projection_views_extension(extension: OpenXRExtensionWrapper): void;
    public register_frame_info_extension(extension: OpenXRExtensionWrapper): void;
    public unregister_frame_info_extension(extension: OpenXRExtensionWrapper): void;
    public get_render_state_z_near(): number;
    public get_render_state_z_far(): number;
    public set_velocity_texture(renderTarget: RID): void;
    public set_velocity_depth_texture(renderTarget: RID): void;
    public set_velocity_target_size(targetSize: Vector2i): void;
    public get_supported_swapchain_formats(): PackedInt64Array;
    public openxr_swapchain_create(createFlags: number, usageFlags: number, swapchainFormat: number, width: number, height: number, sampleCount: number, arraySize: number): number;
    public openxr_swapchain_free(swapchain: number): void;
    public openxr_swapchain_get_swapchain(swapchain: number): number;
    public openxr_swapchain_acquire(swapchain: number): void;
    public openxr_swapchain_get_image(swapchain: number): RID;
    public openxr_swapchain_release(swapchain: number): void;
    public get_projection_layer(): number;
    public set_render_region(renderRegion: Rect2i): void;
    public set_emulate_environment_blend_mode_alpha_blend(enabled: boolean): void;
    public is_environment_blend_mode_alpha_supported(): number;


    public static readonly OpenXRAlphaBlendModeSupport: {
        OPENXR_ALPHA_BLEND_MODE_SUPPORT_NONE: 0;
        OPENXR_ALPHA_BLEND_MODE_SUPPORT_REAL: 1;
        OPENXR_ALPHA_BLEND_MODE_SUPPORT_EMULATING: 2;
    };
}

