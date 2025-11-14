
import type { AudioListener2D } from '@godot/classes/audio_listener2d';
import type { AudioListener3D } from '@godot/classes/audio_listener3d';
import type { Camera2D } from '@godot/classes/camera2d';
import type { Camera3D } from '@godot/classes/camera3d';
import type { Control } from '@godot/classes/control';
import type { GDString } from '@godot/builtins/gd_string';
import type { InputEvent } from '@godot/classes/input_event';
import type { Node } from '@godot/classes/node';
import type { RID } from '@godot/builtins/rid';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Signal } from '@godot/builtins/signal';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';
import type { ViewportTexture } from '@godot/classes/viewport_texture';
import type { World2D } from '@godot/classes/world2d';
import type { World3D } from '@godot/classes/world3d';


export declare class Viewport extends Node {

    
    /**     * The raw type is 'bool'     */
    public disable_3d: boolean;    
    /**     * The raw type is 'bool'     */
    public use_xr: boolean;    
    /**     * The raw type is 'bool'     */
    public own_world_3d: boolean;    
    /**     * The raw type is 'World3D'     */
    public world_3d: World3D;    
    /**     * The raw type is 'World2D'     */
    public world_2d: World2D;    
    /**     * The raw type is 'bool'     */
    public transparent_bg: boolean;    
    /**     * The raw type is 'bool'     */
    public handle_input_locally: boolean;    
    /**     * The raw type is 'bool'     */
    public snap_2d_transforms_to_pixel: boolean;    
    /**     * The raw type is 'bool'     */
    public snap_2d_vertices_to_pixel: boolean;    
    /**     * The raw type is 'int'     */
    public msaa_2d: number;    
    /**     * The raw type is 'int'     */
    public msaa_3d: number;    
    /**     * The raw type is 'int'     */
    public screen_space_aa: number;    
    /**     * The raw type is 'bool'     */
    public use_taa: boolean;    
    /**     * The raw type is 'bool'     */
    public use_debanding: boolean;    
    /**     * The raw type is 'bool'     */
    public use_occlusion_culling: boolean;    
    /**     * The raw type is 'float'     */
    public mesh_lod_threshold: number;    
    /**     * The raw type is 'int'     */
    public debug_draw: number;    
    /**     * The raw type is 'bool'     */
    public use_hdr_2d: boolean;    
    /**     * The raw type is 'int'     */
    public scaling_3d_mode: number;    
    /**     * The raw type is 'float'     */
    public scaling_3d_scale: number;    
    /**     * The raw type is 'float'     */
    public texture_mipmap_bias: number;    
    /**     * The raw type is 'int'     */
    public anisotropic_filtering_level: number;    
    /**     * The raw type is 'float'     */
    public fsr_sharpness: number;    
    /**     * The raw type is 'int'     */
    public vrs_mode: number;    
    /**     * The raw type is 'int'     */
    public vrs_update_mode: number;    
    /**     * The raw type is 'Texture2D'     */
    public vrs_texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public canvas_item_default_texture_filter: number;    
    /**     * The raw type is 'int'     */
    public canvas_item_default_texture_repeat: number;    
    /**     * The raw type is 'bool'     */
    public audio_listener_enable_2d: boolean;    
    /**     * The raw type is 'bool'     */
    public audio_listener_enable_3d: boolean;    
    /**     * The raw type is 'bool'     */
    public physics_object_picking: boolean;    
    /**     * The raw type is 'bool'     */
    public physics_object_picking_sort: boolean;    
    /**     * The raw type is 'bool'     */
    public physics_object_picking_first_only: boolean;    
    /**     * The raw type is 'bool'     */
    public gui_disable_input: boolean;    
    /**     * The raw type is 'bool'     */
    public gui_snap_controls_to_pixels: boolean;    
    /**     * The raw type is 'bool'     */
    public gui_embed_subwindows: boolean;    
    /**     * The raw type is 'int'     */
    public sdf_oversize: number;    
    /**     * The raw type is 'int'     */
    public sdf_scale: number;    
    /**     * The raw type is 'int'     */
    public positional_shadow_atlas_size: number;    
    /**     * The raw type is 'bool'     */
    public positional_shadow_atlas_16_bits: boolean;    
    /**     * The raw type is 'int'     */
    public positional_shadow_atlas_quad_0: number;    
    /**     * The raw type is 'int'     */
    public positional_shadow_atlas_quad_1: number;    
    /**     * The raw type is 'int'     */
    public positional_shadow_atlas_quad_2: number;    
    /**     * The raw type is 'int'     */
    public positional_shadow_atlas_quad_3: number;    
    /**     * The raw type is 'Transform2D'     */
    public canvas_transform: Transform2D;    
    /**     * The raw type is 'Transform2D'     */
    public global_canvas_transform: Transform2D;    
    /**     * The raw type is 'int'     */
    public canvas_cull_mask: number;    
    /**     * The raw type is 'bool'     */
    public oversampling: boolean;    
    /**     * The raw type is 'float'     */
    public oversampling_override: number;
    public set_world_2d(world2D: World2D): void;
    public get_world_2d(): World2D;
    public find_world_2d(): World2D;
    public set_canvas_transform(xform: Transform2D): void;
    public get_canvas_transform(): Transform2D;
    public set_global_canvas_transform(xform: Transform2D): void;
    public get_global_canvas_transform(): Transform2D;
    public get_stretch_transform(): Transform2D;
    public get_final_transform(): Transform2D;
    public get_screen_transform(): Transform2D;
    public get_visible_rect(): Rect2;
    public set_transparent_background(enable: boolean): void;
    public has_transparent_background(): boolean;
    public set_use_hdr_2d(enable: boolean): void;
    public is_using_hdr_2d(): boolean;
    public set_msaa_2d(msaa: number): void;
    public get_msaa_2d(): number;
    public set_msaa_3d(msaa: number): void;
    public get_msaa_3d(): number;
    public set_screen_space_aa(screenSpaceAa: number): void;
    public get_screen_space_aa(): number;
    public set_use_taa(enable: boolean): void;
    public is_using_taa(): boolean;
    public set_use_debanding(enable: boolean): void;
    public is_using_debanding(): boolean;
    public set_use_occlusion_culling(enable: boolean): void;
    public is_using_occlusion_culling(): boolean;
    public set_debug_draw(debugDraw: number): void;
    public get_debug_draw(): number;
    public set_use_oversampling(enable: boolean): void;
    public is_using_oversampling(): boolean;
    public set_oversampling_override(oversampling: number): void;
    public get_oversampling_override(): number;
    public get_oversampling(): number;
    public get_render_info(_type: number, info: number): number;
    public get_texture(): ViewportTexture;
    public set_physics_object_picking(enable: boolean): void;
    public get_physics_object_picking(): boolean;
    public set_physics_object_picking_sort(enable: boolean): void;
    public get_physics_object_picking_sort(): boolean;
    public set_physics_object_picking_first_only(enable: boolean): void;
    public get_physics_object_picking_first_only(): boolean;
    public get_viewport_rid(): RID;
    public push_text_input(text: GDString | StringName | string): void;
    public push_input(event: InputEvent, inLocalCoords: boolean = false): void;
    public push_unhandled_input(event: InputEvent, inLocalCoords: boolean = false): void;
    public notify_mouse_entered(): void;
    public notify_mouse_exited(): void;
    public get_mouse_position(): Vector2;
    public warp_mouse(position: Vector2): void;
    public update_mouse_cursor_state(): void;
    public gui_cancel_drag(): void;
    public gui_get_drag_data(): any;
    public gui_get_drag_description(): GDString;
    public gui_set_drag_description(description: GDString | StringName | string): void;
    public gui_is_dragging(): boolean;
    public gui_is_drag_successful(): boolean;
    public gui_release_focus(): void;
    public gui_get_focus_owner(): Control;
    public gui_get_hovered_control(): Control;
    public set_disable_input(disable: boolean): void;
    public is_input_disabled(): boolean;
    public set_positional_shadow_atlas_size(size: number): void;
    public get_positional_shadow_atlas_size(): number;
    public set_positional_shadow_atlas_16_bits(enable: boolean): void;
    public get_positional_shadow_atlas_16_bits(): boolean;
    public set_snap_controls_to_pixels(enabled: boolean): void;
    public is_snap_controls_to_pixels_enabled(): boolean;
    public set_snap_2d_transforms_to_pixel(enabled: boolean): void;
    public is_snap_2d_transforms_to_pixel_enabled(): boolean;
    public set_snap_2d_vertices_to_pixel(enabled: boolean): void;
    public is_snap_2d_vertices_to_pixel_enabled(): boolean;
    public set_positional_shadow_atlas_quadrant_subdiv(quadrant: number, subdiv: number): void;
    public get_positional_shadow_atlas_quadrant_subdiv(quadrant: number): number;
    public set_input_as_handled(): void;
    public is_input_handled(): boolean;
    public set_handle_input_locally(enable: boolean): void;
    public is_handling_input_locally(): boolean;
    public set_default_canvas_item_texture_filter(mode: number): void;
    public get_default_canvas_item_texture_filter(): number;
    public set_embedding_subwindows(enable: boolean): void;
    public is_embedding_subwindows(): boolean;
    public get_embedded_subwindows(): Array<any>;
    public set_canvas_cull_mask(mask: number): void;
    public get_canvas_cull_mask(): number;
    public set_canvas_cull_mask_bit(layer: number, enable: boolean): void;
    public get_canvas_cull_mask_bit(layer: number): boolean;
    public set_default_canvas_item_texture_repeat(mode: number): void;
    public get_default_canvas_item_texture_repeat(): number;
    public set_sdf_oversize(oversize: number): void;
    public get_sdf_oversize(): number;
    public set_sdf_scale(scale: number): void;
    public get_sdf_scale(): number;
    public set_mesh_lod_threshold(pixels: number): void;
    public get_mesh_lod_threshold(): number;
    public set_as_audio_listener_2d(enable: boolean): void;
    public is_audio_listener_2d(): boolean;
    public get_audio_listener_2d(): AudioListener2D;
    public get_camera_2d(): Camera2D;
    public set_world_3d(world3D: World3D): void;
    public get_world_3d(): World3D;
    public find_world_3d(): World3D;
    public set_use_own_world_3d(enable: boolean): void;
    public is_using_own_world_3d(): boolean;
    public get_audio_listener_3d(): AudioListener3D;
    public get_camera_3d(): Camera3D;
    public set_as_audio_listener_3d(enable: boolean): void;
    public is_audio_listener_3d(): boolean;
    public set_disable_3d(disable: boolean): void;
    public is_3d_disabled(): boolean;
    public set_use_xr(use: boolean): void;
    public is_using_xr(): boolean;
    public set_scaling_3d_mode(scaling3DMode: number): void;
    public get_scaling_3d_mode(): number;
    public set_scaling_3d_scale(scale: number): void;
    public get_scaling_3d_scale(): number;
    public set_fsr_sharpness(fsrSharpness: number): void;
    public get_fsr_sharpness(): number;
    public set_texture_mipmap_bias(textureMipmabias: number): void;
    public get_texture_mipmap_bias(): number;
    public set_anisotropic_filtering_level(anisotropicFilteringLevel: number): void;
    public get_anisotropic_filtering_level(): number;
    public set_vrs_mode(mode: number): void;
    public get_vrs_mode(): number;
    public set_vrs_update_mode(mode: number): void;
    public get_vrs_update_mode(): number;
    public set_vrs_texture(texture: Texture2D): void;
    public get_vrs_texture(): Texture2D;

    
    public readonly size_changed: Signal<() => void>;
    public readonly gui_focus_changed: Signal<(node: Control) => void>;

    public static readonly PositionalShadowAtlasQuadrantSubdiv: {
        SHADOW_ATLAS_QUADRANT_SUBDIV_DISABLED: 0;
        SHADOW_ATLAS_QUADRANT_SUBDIV_1: 1;
        SHADOW_ATLAS_QUADRANT_SUBDIV_4: 2;
        SHADOW_ATLAS_QUADRANT_SUBDIV_16: 3;
        SHADOW_ATLAS_QUADRANT_SUBDIV_64: 4;
        SHADOW_ATLAS_QUADRANT_SUBDIV_256: 5;
        SHADOW_ATLAS_QUADRANT_SUBDIV_1024: 6;
        SHADOW_ATLAS_QUADRANT_SUBDIV_MAX: 7;
    };
    public static readonly Scaling3DMode: {
        SCALING_3D_MODE_BILINEAR: 0;
        SCALING_3D_MODE_FSR: 1;
        SCALING_3D_MODE_FSR2: 2;
        SCALING_3D_MODE_METALFX_SPATIAL: 3;
        SCALING_3D_MODE_METALFX_TEMPORAL: 4;
        SCALING_3D_MODE_MAX: 5;
    };
    public static readonly MSAA: {
        MSAA_DISABLED: 0;
        MSAA_2X: 1;
        MSAA_4X: 2;
        MSAA_8X: 3;
        MSAA_MAX: 4;
    };
    public static readonly AnisotropicFiltering: {
        ANISOTROPY_DISABLED: 0;
        ANISOTROPY_2X: 1;
        ANISOTROPY_4X: 2;
        ANISOTROPY_8X: 3;
        ANISOTROPY_16X: 4;
        ANISOTROPY_MAX: 5;
    };
    public static readonly ScreenSpaceAA: {
        SCREEN_SPACE_AA_DISABLED: 0;
        SCREEN_SPACE_AA_FXAA: 1;
        SCREEN_SPACE_AA_SMAA: 2;
        SCREEN_SPACE_AA_MAX: 3;
    };
    public static readonly RenderInfo: {
        RENDER_INFO_OBJECTS_IN_FRAME: 0;
        RENDER_INFO_PRIMITIVES_IN_FRAME: 1;
        RENDER_INFO_DRAW_CALLS_IN_FRAME: 2;
        RENDER_INFO_MAX: 3;
    };
    public static readonly RenderInfoType: {
        RENDER_INFO_TYPE_VISIBLE: 0;
        RENDER_INFO_TYPE_SHADOW: 1;
        RENDER_INFO_TYPE_CANVAS: 2;
        RENDER_INFO_TYPE_MAX: 3;
    };
    public static readonly DebugDraw: {
        DEBUG_DRAW_DISABLED: 0;
        DEBUG_DRAW_UNSHADED: 1;
        DEBUG_DRAW_LIGHTING: 2;
        DEBUG_DRAW_OVERDRAW: 3;
        DEBUG_DRAW_WIREFRAME: 4;
        DEBUG_DRAW_NORMAL_BUFFER: 5;
        DEBUG_DRAW_VOXEL_GI_ALBEDO: 6;
        DEBUG_DRAW_VOXEL_GI_LIGHTING: 7;
        DEBUG_DRAW_VOXEL_GI_EMISSION: 8;
        DEBUG_DRAW_SHADOW_ATLAS: 9;
        DEBUG_DRAW_DIRECTIONAL_SHADOW_ATLAS: 10;
        DEBUG_DRAW_SCENE_LUMINANCE: 11;
        DEBUG_DRAW_SSAO: 12;
        DEBUG_DRAW_SSIL: 13;
        DEBUG_DRAW_PSSM_SPLITS: 14;
        DEBUG_DRAW_DECAL_ATLAS: 15;
        DEBUG_DRAW_SDFGI: 16;
        DEBUG_DRAW_SDFGI_PROBES: 17;
        DEBUG_DRAW_GI_BUFFER: 18;
        DEBUG_DRAW_DISABLE_LOD: 19;
        DEBUG_DRAW_CLUSTER_OMNI_LIGHTS: 20;
        DEBUG_DRAW_CLUSTER_SPOT_LIGHTS: 21;
        DEBUG_DRAW_CLUSTER_DECALS: 22;
        DEBUG_DRAW_CLUSTER_REFLECTION_PROBES: 23;
        DEBUG_DRAW_OCCLUDERS: 24;
        DEBUG_DRAW_MOTION_VECTORS: 25;
        DEBUG_DRAW_INTERNAL_BUFFER: 26;
    };
    public static readonly DefaultCanvasItemTextureFilter: {
        DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_NEAREST: 0;
        DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_LINEAR: 1;
        DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_LINEAR_WITH_MIPMAPS: 2;
        DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_NEAREST_WITH_MIPMAPS: 3;
        DEFAULT_CANVAS_ITEM_TEXTURE_FILTER_MAX: 4;
    };
    public static readonly DefaultCanvasItemTextureRepeat: {
        DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_DISABLED: 0;
        DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_ENABLED: 1;
        DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_MIRROR: 2;
        DEFAULT_CANVAS_ITEM_TEXTURE_REPEAT_MAX: 3;
    };
    public static readonly SDFOversize: {
        SDF_OVERSIZE_100_PERCENT: 0;
        SDF_OVERSIZE_120_PERCENT: 1;
        SDF_OVERSIZE_150_PERCENT: 2;
        SDF_OVERSIZE_200_PERCENT: 3;
        SDF_OVERSIZE_MAX: 4;
    };
    public static readonly SDFScale: {
        SDF_SCALE_100_PERCENT: 0;
        SDF_SCALE_50_PERCENT: 1;
        SDF_SCALE_25_PERCENT: 2;
        SDF_SCALE_MAX: 3;
    };
    public static readonly VRSMode: {
        VRS_DISABLED: 0;
        VRS_TEXTURE: 1;
        VRS_XR: 2;
        VRS_MAX: 3;
    };
    public static readonly VRSUpdateMode: {
        VRS_UPDATE_DISABLED: 0;
        VRS_UPDATE_ONCE: 1;
        VRS_UPDATE_ALWAYS: 2;
        VRS_UPDATE_MAX: 3;
    };
}

