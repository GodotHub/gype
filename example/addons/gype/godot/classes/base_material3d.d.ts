
import type { Color } from '@godot/builtins/color';
import type { Material } from '@godot/classes/material';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class BaseMaterial3D extends Material {

    
    /**     * The raw type is 'int'     */
    public transparency: number;    
    /**     * The raw type is 'float'     */
    public alpha_scissor_threshold: number;    
    /**     * The raw type is 'float'     */
    public alpha_hash_scale: number;    
    /**     * The raw type is 'int'     */
    public alpha_antialiasing_mode: number;    
    /**     * The raw type is 'float'     */
    public alpha_antialiasing_edge: number;    
    /**     * The raw type is 'int'     */
    public blend_mode: number;    
    /**     * The raw type is 'int'     */
    public cull_mode: number;    
    /**     * The raw type is 'int'     */
    public depth_draw_mode: number;    
    /**     * The raw type is 'bool'     */
    public no_depth_test: boolean;    
    /**     * The raw type is 'int'     */
    public depth_test: number;    
    /**     * The raw type is 'int'     */
    public shading_mode: number;    
    /**     * The raw type is 'int'     */
    public diffuse_mode: number;    
    /**     * The raw type is 'int'     */
    public specular_mode: number;    
    /**     * The raw type is 'bool'     */
    public disable_ambient_light: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_fog: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_specular_occlusion: boolean;    
    /**     * The raw type is 'bool'     */
    public vertex_color_use_as_albedo: boolean;    
    /**     * The raw type is 'bool'     */
    public vertex_color_is_srgb: boolean;    
    /**     * The raw type is 'Color'     */
    public albedo_color: Color;    
    /**     * The raw type is 'Texture2D'     */
    public albedo_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public albedo_texture_force_srgb: boolean;    
    /**     * The raw type is 'bool'     */
    public albedo_texture_msdf: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public orm_texture: Texture2D;    
    /**     * The raw type is 'float'     */
    public metallic: number;    
    /**     * The raw type is 'float'     */
    public metallic_specular: number;    
    /**     * The raw type is 'Texture2D'     */
    public metallic_texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public metallic_texture_channel: number;    
    /**     * The raw type is 'float'     */
    public roughness: number;    
    /**     * The raw type is 'Texture2D'     */
    public roughness_texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public roughness_texture_channel: number;    
    /**     * The raw type is 'bool'     */
    public emission_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public emission: Color;    
    /**     * The raw type is 'float'     */
    public emission_energy_multiplier: number;    
    /**     * The raw type is 'float'     */
    public emission_intensity: number;    
    /**     * The raw type is 'int'     */
    public emission_operator: number;    
    /**     * The raw type is 'bool'     */
    public emission_on_uv2: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public emission_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public normal_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public normal_scale: number;    
    /**     * The raw type is 'Texture2D'     */
    public normal_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public bent_normal_enabled: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public bent_normal_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public rim_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public rim: number;    
    /**     * The raw type is 'float'     */
    public rim_tint: number;    
    /**     * The raw type is 'Texture2D'     */
    public rim_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public clearcoat_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public clearcoat: number;    
    /**     * The raw type is 'float'     */
    public clearcoat_roughness: number;    
    /**     * The raw type is 'Texture2D'     */
    public clearcoat_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public anisotropy_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public anisotropy: number;    
    /**     * The raw type is 'Texture2D'     */
    public anisotropy_flowmap: Texture2D;    
    /**     * The raw type is 'bool'     */
    public ao_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public ao_light_affect: number;    
    /**     * The raw type is 'Texture2D'     */
    public ao_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public ao_on_uv2: boolean;    
    /**     * The raw type is 'int'     */
    public ao_texture_channel: number;    
    /**     * The raw type is 'bool'     */
    public heightmap_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public heightmap_scale: number;    
    /**     * The raw type is 'bool'     */
    public heightmap_deep_parallax: boolean;    
    /**     * The raw type is 'int'     */
    public heightmap_min_layers: number;    
    /**     * The raw type is 'int'     */
    public heightmap_max_layers: number;    
    /**     * The raw type is 'bool'     */
    public heightmap_flip_tangent: boolean;    
    /**     * The raw type is 'bool'     */
    public heightmap_flip_binormal: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public heightmap_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public heightmap_flip_texture: boolean;    
    /**     * The raw type is 'bool'     */
    public subsurf_scatter_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public subsurf_scatter_strength: number;    
    /**     * The raw type is 'bool'     */
    public subsurf_scatter_skin_mode: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public subsurf_scatter_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public subsurf_scatter_transmittance_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public subsurf_scatter_transmittance_color: Color;    
    /**     * The raw type is 'Texture2D'     */
    public subsurf_scatter_transmittance_texture: Texture2D;    
    /**     * The raw type is 'float'     */
    public subsurf_scatter_transmittance_depth: number;    
    /**     * The raw type is 'float'     */
    public subsurf_scatter_transmittance_boost: number;    
    /**     * The raw type is 'bool'     */
    public backlight_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public backlight: Color;    
    /**     * The raw type is 'Texture2D'     */
    public backlight_texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public refraction_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public refraction_scale: number;    
    /**     * The raw type is 'Texture2D'     */
    public refraction_texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public refraction_texture_channel: number;    
    /**     * The raw type is 'bool'     */
    public detail_enabled: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public detail_mask: Texture2D;    
    /**     * The raw type is 'int'     */
    public detail_blend_mode: number;    
    /**     * The raw type is 'int'     */
    public detail_uv_layer: number;    
    /**     * The raw type is 'Texture2D'     */
    public detail_albedo: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public detail_normal: Texture2D;    
    /**     * The raw type is 'Vector3'     */
    public uv1_scale: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public uv1_offset: Vector3;    
    /**     * The raw type is 'bool'     */
    public uv1_triplanar: boolean;    
    /**     * The raw type is 'float'     */
    public uv1_triplanar_sharpness: number;    
    /**     * The raw type is 'bool'     */
    public uv1_world_triplanar: boolean;    
    /**     * The raw type is 'Vector3'     */
    public uv2_scale: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public uv2_offset: Vector3;    
    /**     * The raw type is 'bool'     */
    public uv2_triplanar: boolean;    
    /**     * The raw type is 'float'     */
    public uv2_triplanar_sharpness: number;    
    /**     * The raw type is 'bool'     */
    public uv2_world_triplanar: boolean;    
    /**     * The raw type is 'int'     */
    public texture_filter: number;    
    /**     * The raw type is 'bool'     */
    public texture_repeat: boolean;    
    /**     * The raw type is 'bool'     */
    public disable_receive_shadows: boolean;    
    /**     * The raw type is 'bool'     */
    public shadow_to_opacity: boolean;    
    /**     * The raw type is 'int'     */
    public billboard_mode: number;    
    /**     * The raw type is 'bool'     */
    public billboard_keep_scale: boolean;    
    /**     * The raw type is 'int'     */
    public particles_anim_h_frames: number;    
    /**     * The raw type is 'int'     */
    public particles_anim_v_frames: number;    
    /**     * The raw type is 'bool'     */
    public particles_anim_loop: boolean;    
    /**     * The raw type is 'bool'     */
    public grow: boolean;    
    /**     * The raw type is 'float'     */
    public grow_amount: number;    
    /**     * The raw type is 'bool'     */
    public fixed_size: boolean;    
    /**     * The raw type is 'bool'     */
    public use_point_size: boolean;    
    /**     * The raw type is 'float'     */
    public point_size: number;    
    /**     * The raw type is 'bool'     */
    public use_particle_trails: boolean;    
    /**     * The raw type is 'bool'     */
    public use_z_clip_scale: boolean;    
    /**     * The raw type is 'float'     */
    public z_clip_scale: number;    
    /**     * The raw type is 'bool'     */
    public use_fov_override: boolean;    
    /**     * The raw type is 'float'     */
    public fov_override: number;    
    /**     * The raw type is 'bool'     */
    public proximity_fade_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public proximity_fade_distance: number;    
    /**     * The raw type is 'float'     */
    public msdf_pixel_range: number;    
    /**     * The raw type is 'float'     */
    public msdf_outline_size: number;    
    /**     * The raw type is 'int'     */
    public distance_fade_mode: number;    
    /**     * The raw type is 'float'     */
    public distance_fade_min_distance: number;    
    /**     * The raw type is 'float'     */
    public distance_fade_max_distance: number;    
    /**     * The raw type is 'int'     */
    public stencil_mode: number;    
    /**     * The raw type is 'int'     */
    public stencil_flags: number;    
    /**     * The raw type is 'int'     */
    public stencil_compare: number;    
    /**     * The raw type is 'int'     */
    public stencil_reference: number;    
    /**     * The raw type is 'Color'     */
    public stencil_color: Color;    
    /**     * The raw type is 'float'     */
    public stencil_outline_thickness: number;
    public set_albedo(albedo: Color): void;
    public get_albedo(): Color;
    public set_transparency(transparency: number): void;
    public get_transparency(): number;
    public set_alpha_antialiasing(alphaAa: number): void;
    public get_alpha_antialiasing(): number;
    public set_alpha_antialiasing_edge(edge: number): void;
    public get_alpha_antialiasing_edge(): number;
    public set_shading_mode(shadingMode: number): void;
    public get_shading_mode(): number;
    public set_specular(specular: number): void;
    public get_specular(): number;
    public set_metallic(metallic: number): void;
    public get_metallic(): number;
    public set_roughness(roughness: number): void;
    public get_roughness(): number;
    public set_emission(emission: Color): void;
    public get_emission(): Color;
    public set_emission_energy_multiplier(emissionEnergyMultiplier: number): void;
    public get_emission_energy_multiplier(): number;
    public set_emission_intensity(emissionEnergyMultiplier: number): void;
    public get_emission_intensity(): number;
    public set_normal_scale(normalScale: number): void;
    public get_normal_scale(): number;
    public set_rim(rim: number): void;
    public get_rim(): number;
    public set_rim_tint(rimTint: number): void;
    public get_rim_tint(): number;
    public set_clearcoat(clearcoat: number): void;
    public get_clearcoat(): number;
    public set_clearcoat_roughness(clearcoatRoughness: number): void;
    public get_clearcoat_roughness(): number;
    public set_anisotropy(anisotropy: number): void;
    public get_anisotropy(): number;
    public set_heightmap_scale(heightmascale: number): void;
    public get_heightmap_scale(): number;
    public set_subsurface_scattering_strength(strength: number): void;
    public get_subsurface_scattering_strength(): number;
    public set_transmittance_color(color: Color): void;
    public get_transmittance_color(): Color;
    public set_transmittance_depth(depth: number): void;
    public get_transmittance_depth(): number;
    public set_transmittance_boost(boost: number): void;
    public get_transmittance_boost(): number;
    public set_backlight(backlight: Color): void;
    public get_backlight(): Color;
    public set_refraction(refraction: number): void;
    public get_refraction(): number;
    public set_point_size(pointSize: number): void;
    public get_point_size(): number;
    public set_detail_uv(detailUv: number): void;
    public get_detail_uv(): number;
    public set_blend_mode(blendMode: number): void;
    public get_blend_mode(): number;
    public set_depth_draw_mode(depthDrawMode: number): void;
    public get_depth_draw_mode(): number;
    public set_depth_test(depthTest: number): void;
    public get_depth_test(): number;
    public set_cull_mode(cullMode: number): void;
    public get_cull_mode(): number;
    public set_diffuse_mode(diffuseMode: number): void;
    public get_diffuse_mode(): number;
    public set_specular_mode(specularMode: number): void;
    public get_specular_mode(): number;
    public set_flag(flag: number, enable: boolean): void;
    public get_flag(flag: number): boolean;
    public set_texture_filter(mode: number): void;
    public get_texture_filter(): number;
    public set_feature(feature: number, enable: boolean): void;
    public get_feature(feature: number): boolean;
    public set_texture(param: number, texture: Texture2D): void;
    public get_texture(param: number): Texture2D;
    public set_detail_blend_mode(detailBlendMode: number): void;
    public get_detail_blend_mode(): number;
    public set_uv1_scale(scale: Vector3): void;
    public get_uv1_scale(): Vector3;
    public set_uv1_offset(offset: Vector3): void;
    public get_uv1_offset(): Vector3;
    public set_uv1_triplanar_blend_sharpness(sharpness: number): void;
    public get_uv1_triplanar_blend_sharpness(): number;
    public set_uv2_scale(scale: Vector3): void;
    public get_uv2_scale(): Vector3;
    public set_uv2_offset(offset: Vector3): void;
    public get_uv2_offset(): Vector3;
    public set_uv2_triplanar_blend_sharpness(sharpness: number): void;
    public get_uv2_triplanar_blend_sharpness(): number;
    public set_billboard_mode(mode: number): void;
    public get_billboard_mode(): number;
    public set_particles_anim_h_frames(frames: number): void;
    public get_particles_anim_h_frames(): number;
    public set_particles_anim_v_frames(frames: number): void;
    public get_particles_anim_v_frames(): number;
    public set_particles_anim_loop(loop: boolean): void;
    public get_particles_anim_loop(): boolean;
    public set_heightmap_deep_parallax(enable: boolean): void;
    public is_heightmap_deep_parallax_enabled(): boolean;
    public set_heightmap_deep_parallax_min_layers(layer: number): void;
    public get_heightmap_deep_parallax_min_layers(): number;
    public set_heightmap_deep_parallax_max_layers(layer: number): void;
    public get_heightmap_deep_parallax_max_layers(): number;
    public set_heightmap_deep_parallax_flip_tangent(flip: boolean): void;
    public get_heightmap_deep_parallax_flip_tangent(): boolean;
    public set_heightmap_deep_parallax_flip_binormal(flip: boolean): void;
    public get_heightmap_deep_parallax_flip_binormal(): boolean;
    public set_grow(amount: number): void;
    public get_grow(): number;
    public set_emission_operator(operator: number): void;
    public get_emission_operator(): number;
    public set_ao_light_affect(amount: number): void;
    public get_ao_light_affect(): number;
    public set_alpha_scissor_threshold(threshold: number): void;
    public get_alpha_scissor_threshold(): number;
    public set_alpha_hash_scale(threshold: number): void;
    public get_alpha_hash_scale(): number;
    public set_grow_enabled(enable: boolean): void;
    public is_grow_enabled(): boolean;
    public set_metallic_texture_channel(channel: number): void;
    public get_metallic_texture_channel(): number;
    public set_roughness_texture_channel(channel: number): void;
    public get_roughness_texture_channel(): number;
    public set_ao_texture_channel(channel: number): void;
    public get_ao_texture_channel(): number;
    public set_refraction_texture_channel(channel: number): void;
    public get_refraction_texture_channel(): number;
    public set_proximity_fade_enabled(enabled: boolean): void;
    public is_proximity_fade_enabled(): boolean;
    public set_proximity_fade_distance(distance: number): void;
    public get_proximity_fade_distance(): number;
    public set_msdf_pixel_range(range: number): void;
    public get_msdf_pixel_range(): number;
    public set_msdf_outline_size(size: number): void;
    public get_msdf_outline_size(): number;
    public set_distance_fade(mode: number): void;
    public get_distance_fade(): number;
    public set_distance_fade_max_distance(distance: number): void;
    public get_distance_fade_max_distance(): number;
    public set_distance_fade_min_distance(distance: number): void;
    public get_distance_fade_min_distance(): number;
    public set_z_clip_scale(scale: number): void;
    public get_z_clip_scale(): number;
    public set_fov_override(scale: number): void;
    public get_fov_override(): number;
    public set_stencil_mode(stencilMode: number): void;
    public get_stencil_mode(): number;
    public set_stencil_flags(stencilFlags: number): void;
    public get_stencil_flags(): number;
    public set_stencil_compare(stencilCompare: number): void;
    public get_stencil_compare(): number;
    public set_stencil_reference(stencilReference: number): void;
    public get_stencil_reference(): number;
    public set_stencil_effect_color(stencilColor: Color): void;
    public get_stencil_effect_color(): Color;
    public set_stencil_effect_outline_thickness(stencilOutlineThickness: number): void;
    public get_stencil_effect_outline_thickness(): number;


    public static readonly TextureParam: {
        TEXTURE_ALBEDO: 0;
        TEXTURE_METALLIC: 1;
        TEXTURE_ROUGHNESS: 2;
        TEXTURE_EMISSION: 3;
        TEXTURE_NORMAL: 4;
        TEXTURE_BENT_NORMAL: 18;
        TEXTURE_RIM: 5;
        TEXTURE_CLEARCOAT: 6;
        TEXTURE_FLOWMAP: 7;
        TEXTURE_AMBIENT_OCCLUSION: 8;
        TEXTURE_HEIGHTMAP: 9;
        TEXTURE_SUBSURFACE_SCATTERING: 10;
        TEXTURE_SUBSURFACE_TRANSMITTANCE: 11;
        TEXTURE_BACKLIGHT: 12;
        TEXTURE_REFRACTION: 13;
        TEXTURE_DETAIL_MASK: 14;
        TEXTURE_DETAIL_ALBEDO: 15;
        TEXTURE_DETAIL_NORMAL: 16;
        TEXTURE_ORM: 17;
        TEXTURE_MAX: 19;
    };
    public static readonly TextureFilter: {
        TEXTURE_FILTER_NEAREST: 0;
        TEXTURE_FILTER_LINEAR: 1;
        TEXTURE_FILTER_NEAREST_WITH_MIPMAPS: 2;
        TEXTURE_FILTER_LINEAR_WITH_MIPMAPS: 3;
        TEXTURE_FILTER_NEAREST_WITH_MIPMAPS_ANISOTROPIC: 4;
        TEXTURE_FILTER_LINEAR_WITH_MIPMAPS_ANISOTROPIC: 5;
        TEXTURE_FILTER_MAX: 6;
    };
    public static readonly DetailUV: {
        DETAIL_UV_1: 0;
        DETAIL_UV_2: 1;
    };
    public static readonly Transparency: {
        TRANSPARENCY_DISABLED: 0;
        TRANSPARENCY_ALPHA: 1;
        TRANSPARENCY_ALPHA_SCISSOR: 2;
        TRANSPARENCY_ALPHA_HASH: 3;
        TRANSPARENCY_ALPHA_DEPTH_PRE_PASS: 4;
        TRANSPARENCY_MAX: 5;
    };
    public static readonly ShadingMode: {
        SHADING_MODE_UNSHADED: 0;
        SHADING_MODE_PER_PIXEL: 1;
        SHADING_MODE_PER_VERTEX: 2;
        SHADING_MODE_MAX: 3;
    };
    public static readonly Feature: {
        FEATURE_EMISSION: 0;
        FEATURE_NORMAL_MAPPING: 1;
        FEATURE_RIM: 2;
        FEATURE_CLEARCOAT: 3;
        FEATURE_ANISOTROPY: 4;
        FEATURE_AMBIENT_OCCLUSION: 5;
        FEATURE_HEIGHT_MAPPING: 6;
        FEATURE_SUBSURFACE_SCATTERING: 7;
        FEATURE_SUBSURFACE_TRANSMITTANCE: 8;
        FEATURE_BACKLIGHT: 9;
        FEATURE_REFRACTION: 10;
        FEATURE_DETAIL: 11;
        FEATURE_BENT_NORMAL_MAPPING: 12;
        FEATURE_MAX: 13;
    };
    public static readonly BlendMode: {
        BLEND_MODE_MIX: 0;
        BLEND_MODE_ADD: 1;
        BLEND_MODE_SUB: 2;
        BLEND_MODE_MUL: 3;
        BLEND_MODE_PREMULT_ALPHA: 4;
    };
    public static readonly AlphaAntiAliasing: {
        ALPHA_ANTIALIASING_OFF: 0;
        ALPHA_ANTIALIASING_ALPHA_TO_COVERAGE: 1;
        ALPHA_ANTIALIASING_ALPHA_TO_COVERAGE_AND_TO_ONE: 2;
    };
    public static readonly DepthDrawMode: {
        DEPTH_DRAW_OPAQUE_ONLY: 0;
        DEPTH_DRAW_ALWAYS: 1;
        DEPTH_DRAW_DISABLED: 2;
    };
    public static readonly DepthTest: {
        DEPTH_TEST_DEFAULT: 0;
        DEPTH_TEST_INVERTED: 1;
    };
    public static readonly CullMode: {
        CULL_BACK: 0;
        CULL_FRONT: 1;
        CULL_DISABLED: 2;
    };
    public static readonly Flags: {
        FLAG_DISABLE_DEPTH_TEST: 0;
        FLAG_ALBEDO_FROM_VERTEX_COLOR: 1;
        FLAG_SRGB_VERTEX_COLOR: 2;
        FLAG_USE_POINT_SIZE: 3;
        FLAG_FIXED_SIZE: 4;
        FLAG_BILLBOARD_KEEP_SCALE: 5;
        FLAG_UV1_USE_TRIPLANAR: 6;
        FLAG_UV2_USE_TRIPLANAR: 7;
        FLAG_UV1_USE_WORLD_TRIPLANAR: 8;
        FLAG_UV2_USE_WORLD_TRIPLANAR: 9;
        FLAG_AO_ON_UV2: 10;
        FLAG_EMISSION_ON_UV2: 11;
        FLAG_ALBEDO_TEXTURE_FORCE_SRGB: 12;
        FLAG_DONT_RECEIVE_SHADOWS: 13;
        FLAG_DISABLE_AMBIENT_LIGHT: 14;
        FLAG_USE_SHADOW_TO_OPACITY: 15;
        FLAG_USE_TEXTURE_REPEAT: 16;
        FLAG_INVERT_HEIGHTMAP: 17;
        FLAG_SUBSURFACE_MODE_SKIN: 18;
        FLAG_PARTICLE_TRAILS_MODE: 19;
        FLAG_ALBEDO_TEXTURE_MSDF: 20;
        FLAG_DISABLE_FOG: 21;
        FLAG_DISABLE_SPECULAR_OCCLUSION: 22;
        FLAG_USE_Z_CLIP_SCALE: 23;
        FLAG_USE_FOV_OVERRIDE: 24;
        FLAG_MAX: 25;
    };
    public static readonly DiffuseMode: {
        DIFFUSE_BURLEY: 0;
        DIFFUSE_LAMBERT: 1;
        DIFFUSE_LAMBERT_WRAP: 2;
        DIFFUSE_TOON: 3;
    };
    public static readonly SpecularMode: {
        SPECULAR_SCHLICK_GGX: 0;
        SPECULAR_TOON: 1;
        SPECULAR_DISABLED: 2;
    };
    public static readonly BillboardMode: {
        BILLBOARD_DISABLED: 0;
        BILLBOARD_ENABLED: 1;
        BILLBOARD_FIXED_Y: 2;
        BILLBOARD_PARTICLES: 3;
    };
    public static readonly TextureChannel: {
        TEXTURE_CHANNEL_RED: 0;
        TEXTURE_CHANNEL_GREEN: 1;
        TEXTURE_CHANNEL_BLUE: 2;
        TEXTURE_CHANNEL_ALPHA: 3;
        TEXTURE_CHANNEL_GRAYSCALE: 4;
    };
    public static readonly EmissionOperator: {
        EMISSION_OP_ADD: 0;
        EMISSION_OP_MULTIPLY: 1;
    };
    public static readonly DistanceFadeMode: {
        DISTANCE_FADE_DISABLED: 0;
        DISTANCE_FADE_PIXEL_ALPHA: 1;
        DISTANCE_FADE_PIXEL_DITHER: 2;
        DISTANCE_FADE_OBJECT_DITHER: 3;
    };
    public static readonly StencilMode: {
        STENCIL_MODE_DISABLED: 0;
        STENCIL_MODE_OUTLINE: 1;
        STENCIL_MODE_XRAY: 2;
        STENCIL_MODE_CUSTOM: 3;
    };
    public static readonly StencilFlags: {
        STENCIL_FLAG_READ: 1;
        STENCIL_FLAG_WRITE: 2;
        STENCIL_FLAG_WRITE_DEPTH_FAIL: 4;
    };
    public static readonly StencilCompare: {
        STENCIL_COMPARE_ALWAYS: 0;
        STENCIL_COMPARE_LESS: 1;
        STENCIL_COMPARE_EQUAL: 2;
        STENCIL_COMPARE_LESS_OR_EQUAL: 3;
        STENCIL_COMPARE_GREATER: 4;
        STENCIL_COMPARE_NOT_EQUAL: 5;
        STENCIL_COMPARE_GREATER_OR_EQUAL: 6;
    };
}

