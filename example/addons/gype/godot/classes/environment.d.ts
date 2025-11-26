
import type { Resource } from '@godot/classes/resource';
import type { Sky } from '@godot/classes/sky';
import type { Texture } from '@godot/classes/texture';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class Environment extends Resource {

    
    /**     * The raw type is 'int'     */
    public background_mode: number;    
    /**     * The raw type is 'Color'     */
    public background_color: Color;    
    /**     * The raw type is 'float'     */
    public background_energy_multiplier: number;    
    /**     * The raw type is 'float'     */
    public background_intensity: number;    
    /**     * The raw type is 'int'     */
    public background_canvas_max_layer: number;    
    /**     * The raw type is 'int'     */
    public background_camera_feed_id: number;    
    /**     * The raw type is 'Sky'     */
    public sky: Sky;    
    /**     * The raw type is 'float'     */
    public sky_custom_fov: number;    
    /**     * The raw type is 'Vector3'     */
    public sky_rotation: Vector3;    
    /**     * The raw type is 'int'     */
    public ambient_light_source: number;    
    /**     * The raw type is 'Color'     */
    public ambient_light_color: Color;    
    /**     * The raw type is 'float'     */
    public ambient_light_sky_contribution: number;    
    /**     * The raw type is 'float'     */
    public ambient_light_energy: number;    
    /**     * The raw type is 'int'     */
    public reflected_light_source: number;    
    /**     * The raw type is 'int'     */
    public tonemap_mode: number;    
    /**     * The raw type is 'float'     */
    public tonemap_exposure: number;    
    /**     * The raw type is 'float'     */
    public tonemap_white: number;    
    /**     * The raw type is 'bool'     */
    public ssr_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public ssr_max_steps: number;    
    /**     * The raw type is 'float'     */
    public ssr_fade_in: number;    
    /**     * The raw type is 'float'     */
    public ssr_fade_out: number;    
    /**     * The raw type is 'float'     */
    public ssr_depth_tolerance: number;    
    /**     * The raw type is 'bool'     */
    public ssao_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public ssao_radius: number;    
    /**     * The raw type is 'float'     */
    public ssao_intensity: number;    
    /**     * The raw type is 'float'     */
    public ssao_power: number;    
    /**     * The raw type is 'float'     */
    public ssao_detail: number;    
    /**     * The raw type is 'float'     */
    public ssao_horizon: number;    
    /**     * The raw type is 'float'     */
    public ssao_sharpness: number;    
    /**     * The raw type is 'float'     */
    public ssao_light_affect: number;    
    /**     * The raw type is 'float'     */
    public ssao_ao_channel_affect: number;    
    /**     * The raw type is 'bool'     */
    public ssil_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public ssil_radius: number;    
    /**     * The raw type is 'float'     */
    public ssil_intensity: number;    
    /**     * The raw type is 'float'     */
    public ssil_sharpness: number;    
    /**     * The raw type is 'float'     */
    public ssil_normal_rejection: number;    
    /**     * The raw type is 'bool'     */
    public sdfgi_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public sdfgi_use_occlusion: boolean;    
    /**     * The raw type is 'bool'     */
    public sdfgi_read_sky_light: boolean;    
    /**     * The raw type is 'float'     */
    public sdfgi_bounce_feedback: number;    
    /**     * The raw type is 'int'     */
    public sdfgi_cascades: number;    
    /**     * The raw type is 'float'     */
    public sdfgi_min_cell_size: number;    
    /**     * The raw type is 'float'     */
    public sdfgi_cascade0_distance: number;    
    /**     * The raw type is 'float'     */
    public sdfgi_max_distance: number;    
    /**     * The raw type is 'int'     */
    public sdfgi_y_scale: number;    
    /**     * The raw type is 'float'     */
    public sdfgi_energy: number;    
    /**     * The raw type is 'float'     */
    public sdfgi_normal_bias: number;    
    /**     * The raw type is 'float'     */
    public sdfgi_probe_bias: number;    
    /**     * The raw type is 'bool'     */
    public glow_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public glow_normalized: boolean;    
    /**     * The raw type is 'float'     */
    public glow_intensity: number;    
    /**     * The raw type is 'float'     */
    public glow_strength: number;    
    /**     * The raw type is 'float'     */
    public glow_mix: number;    
    /**     * The raw type is 'float'     */
    public glow_bloom: number;    
    /**     * The raw type is 'int'     */
    public glow_blend_mode: number;    
    /**     * The raw type is 'float'     */
    public glow_hdr_threshold: number;    
    /**     * The raw type is 'float'     */
    public glow_hdr_scale: number;    
    /**     * The raw type is 'float'     */
    public glow_hdr_luminance_cap: number;    
    /**     * The raw type is 'float'     */
    public glow_map_strength: number;    
    /**     * The raw type is 'Texture2D'     */
    public glow_map: Texture;    
    /**     * The raw type is 'bool'     */
    public fog_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public fog_mode: number;    
    /**     * The raw type is 'Color'     */
    public fog_light_color: Color;    
    /**     * The raw type is 'float'     */
    public fog_light_energy: number;    
    /**     * The raw type is 'float'     */
    public fog_sun_scatter: number;    
    /**     * The raw type is 'float'     */
    public fog_density: number;    
    /**     * The raw type is 'float'     */
    public fog_aerial_perspective: number;    
    /**     * The raw type is 'float'     */
    public fog_sky_affect: number;    
    /**     * The raw type is 'float'     */
    public fog_height: number;    
    /**     * The raw type is 'float'     */
    public fog_height_density: number;    
    /**     * The raw type is 'float'     */
    public fog_depth_curve: number;    
    /**     * The raw type is 'float'     */
    public fog_depth_begin: number;    
    /**     * The raw type is 'float'     */
    public fog_depth_end: number;    
    /**     * The raw type is 'bool'     */
    public volumetric_fog_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_density: number;    
    /**     * The raw type is 'Color'     */
    public volumetric_fog_albedo: Color;    
    /**     * The raw type is 'Color'     */
    public volumetric_fog_emission: Color;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_emission_energy: number;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_gi_inject: number;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_anisotropy: number;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_length: number;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_detail_spread: number;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_ambient_inject: number;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_sky_affect: number;    
    /**     * The raw type is 'bool'     */
    public volumetric_fog_temporal_reprojection_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public volumetric_fog_temporal_reprojection_amount: number;    
    /**     * The raw type is 'bool'     */
    public adjustment_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public adjustment_brightness: number;    
    /**     * The raw type is 'float'     */
    public adjustment_contrast: number;    
    /**     * The raw type is 'float'     */
    public adjustment_saturation: number;    
    /**     * The raw type is 'Texture2D,Texture3D'     */
    public adjustment_color_correction: Texture;
    public set_background(mode: number): void;
    public get_background(): number;
    public set_sky(sky: Sky): void;
    public get_sky(): Sky;
    public set_sky_custom_fov(scale: number): void;
    public get_sky_custom_fov(): number;
    public set_sky_rotation(eulerRadians: Vector3): void;
    public get_sky_rotation(): Vector3;
    public set_bg_color(color: Color): void;
    public get_bg_color(): Color;
    public set_bg_energy_multiplier(energy: number): void;
    public get_bg_energy_multiplier(): number;
    public set_bg_intensity(energy: number): void;
    public get_bg_intensity(): number;
    public set_canvas_max_layer(layer: number): void;
    public get_canvas_max_layer(): number;
    public set_camera_feed_id(id: number): void;
    public get_camera_feed_id(): number;
    public set_ambient_light_color(color: Color): void;
    public get_ambient_light_color(): Color;
    public set_ambient_source(source: number): void;
    public get_ambient_source(): number;
    public set_ambient_light_energy(energy: number): void;
    public get_ambient_light_energy(): number;
    public set_ambient_light_sky_contribution(ratio: number): void;
    public get_ambient_light_sky_contribution(): number;
    public set_reflection_source(source: number): void;
    public get_reflection_source(): number;
    public set_tonemapper(mode: number): void;
    public get_tonemapper(): number;
    public set_tonemap_exposure(exposure: number): void;
    public get_tonemap_exposure(): number;
    public set_tonemap_white(white: number): void;
    public get_tonemap_white(): number;
    public set_ssr_enabled(enabled: boolean): void;
    public is_ssr_enabled(): boolean;
    public set_ssr_max_steps(maxSteps: number): void;
    public get_ssr_max_steps(): number;
    public set_ssr_fade_in(fadeIn: number): void;
    public get_ssr_fade_in(): number;
    public set_ssr_fade_out(fadeOut: number): void;
    public get_ssr_fade_out(): number;
    public set_ssr_depth_tolerance(depthTolerance: number): void;
    public get_ssr_depth_tolerance(): number;
    public set_ssao_enabled(enabled: boolean): void;
    public is_ssao_enabled(): boolean;
    public set_ssao_radius(radius: number): void;
    public get_ssao_radius(): number;
    public set_ssao_intensity(intensity: number): void;
    public get_ssao_intensity(): number;
    public set_ssao_power(power: number): void;
    public get_ssao_power(): number;
    public set_ssao_detail(detail: number): void;
    public get_ssao_detail(): number;
    public set_ssao_horizon(horizon: number): void;
    public get_ssao_horizon(): number;
    public set_ssao_sharpness(sharpness: number): void;
    public get_ssao_sharpness(): number;
    public set_ssao_direct_light_affect(amount: number): void;
    public get_ssao_direct_light_affect(): number;
    public set_ssao_ao_channel_affect(amount: number): void;
    public get_ssao_ao_channel_affect(): number;
    public set_ssil_enabled(enabled: boolean): void;
    public is_ssil_enabled(): boolean;
    public set_ssil_radius(radius: number): void;
    public get_ssil_radius(): number;
    public set_ssil_intensity(intensity: number): void;
    public get_ssil_intensity(): number;
    public set_ssil_sharpness(sharpness: number): void;
    public get_ssil_sharpness(): number;
    public set_ssil_normal_rejection(normalRejection: number): void;
    public get_ssil_normal_rejection(): number;
    public set_sdfgi_enabled(enabled: boolean): void;
    public is_sdfgi_enabled(): boolean;
    public set_sdfgi_cascades(amount: number): void;
    public get_sdfgi_cascades(): number;
    public set_sdfgi_min_cell_size(size: number): void;
    public get_sdfgi_min_cell_size(): number;
    public set_sdfgi_max_distance(distance: number): void;
    public get_sdfgi_max_distance(): number;
    public set_sdfgi_cascade0_distance(distance: number): void;
    public get_sdfgi_cascade0_distance(): number;
    public set_sdfgi_y_scale(scale: number): void;
    public get_sdfgi_y_scale(): number;
    public set_sdfgi_use_occlusion(enable: boolean): void;
    public is_sdfgi_using_occlusion(): boolean;
    public set_sdfgi_bounce_feedback(amount: number): void;
    public get_sdfgi_bounce_feedback(): number;
    public set_sdfgi_read_sky_light(enable: boolean): void;
    public is_sdfgi_reading_sky_light(): boolean;
    public set_sdfgi_energy(amount: number): void;
    public get_sdfgi_energy(): number;
    public set_sdfgi_normal_bias(bias: number): void;
    public get_sdfgi_normal_bias(): number;
    public set_sdfgi_probe_bias(bias: number): void;
    public get_sdfgi_probe_bias(): number;
    public set_glow_enabled(enabled: boolean): void;
    public is_glow_enabled(): boolean;
    public set_glow_level(idx: number, intensity: number): void;
    public get_glow_level(idx: number): number;
    public set_glow_normalized(normalize: boolean): void;
    public is_glow_normalized(): boolean;
    public set_glow_intensity(intensity: number): void;
    public get_glow_intensity(): number;
    public set_glow_strength(strength: number): void;
    public get_glow_strength(): number;
    public set_glow_mix(mix: number): void;
    public get_glow_mix(): number;
    public set_glow_bloom(amount: number): void;
    public get_glow_bloom(): number;
    public set_glow_blend_mode(mode: number): void;
    public get_glow_blend_mode(): number;
    public set_glow_hdr_bleed_threshold(threshold: number): void;
    public get_glow_hdr_bleed_threshold(): number;
    public set_glow_hdr_bleed_scale(scale: number): void;
    public get_glow_hdr_bleed_scale(): number;
    public set_glow_hdr_luminance_cap(amount: number): void;
    public get_glow_hdr_luminance_cap(): number;
    public set_glow_map_strength(strength: number): void;
    public get_glow_map_strength(): number;
    public set_glow_map(mode: Texture): void;
    public get_glow_map(): Texture;
    public set_fog_enabled(enabled: boolean): void;
    public is_fog_enabled(): boolean;
    public set_fog_mode(mode: number): void;
    public get_fog_mode(): number;
    public set_fog_light_color(lightColor: Color): void;
    public get_fog_light_color(): Color;
    public set_fog_light_energy(lightEnergy: number): void;
    public get_fog_light_energy(): number;
    public set_fog_sun_scatter(sunScatter: number): void;
    public get_fog_sun_scatter(): number;
    public set_fog_density(density: number): void;
    public get_fog_density(): number;
    public set_fog_height(height: number): void;
    public get_fog_height(): number;
    public set_fog_height_density(heightDensity: number): void;
    public get_fog_height_density(): number;
    public set_fog_aerial_perspective(aerialPerspective: number): void;
    public get_fog_aerial_perspective(): number;
    public set_fog_sky_affect(skyAffect: number): void;
    public get_fog_sky_affect(): number;
    public set_fog_depth_curve(curve: number): void;
    public get_fog_depth_curve(): number;
    public set_fog_depth_begin(begin: number): void;
    public get_fog_depth_begin(): number;
    public set_fog_depth_end(end: number): void;
    public get_fog_depth_end(): number;
    public set_volumetric_fog_enabled(enabled: boolean): void;
    public is_volumetric_fog_enabled(): boolean;
    public set_volumetric_fog_emission(color: Color): void;
    public get_volumetric_fog_emission(): Color;
    public set_volumetric_fog_albedo(color: Color): void;
    public get_volumetric_fog_albedo(): Color;
    public set_volumetric_fog_density(density: number): void;
    public get_volumetric_fog_density(): number;
    public set_volumetric_fog_emission_energy(begin: number): void;
    public get_volumetric_fog_emission_energy(): number;
    public set_volumetric_fog_anisotropy(anisotropy: number): void;
    public get_volumetric_fog_anisotropy(): number;
    public set_volumetric_fog_length(length: number): void;
    public get_volumetric_fog_length(): number;
    public set_volumetric_fog_detail_spread(detailSpread: number): void;
    public get_volumetric_fog_detail_spread(): number;
    public set_volumetric_fog_gi_inject(giInject: number): void;
    public get_volumetric_fog_gi_inject(): number;
    public set_volumetric_fog_ambient_inject(enabled: number): void;
    public get_volumetric_fog_ambient_inject(): number;
    public set_volumetric_fog_sky_affect(skyAffect: number): void;
    public get_volumetric_fog_sky_affect(): number;
    public set_volumetric_fog_temporal_reprojection_enabled(enabled: boolean): void;
    public is_volumetric_fog_temporal_reprojection_enabled(): boolean;
    public set_volumetric_fog_temporal_reprojection_amount(temporalReprojectionAmount: number): void;
    public get_volumetric_fog_temporal_reprojection_amount(): number;
    public set_adjustment_enabled(enabled: boolean): void;
    public is_adjustment_enabled(): boolean;
    public set_adjustment_brightness(brightness: number): void;
    public get_adjustment_brightness(): number;
    public set_adjustment_contrast(contrast: number): void;
    public get_adjustment_contrast(): number;
    public set_adjustment_saturation(saturation: number): void;
    public get_adjustment_saturation(): number;
    public set_adjustment_color_correction(colorCorrection: Texture): void;
    public get_adjustment_color_correction(): Texture;


    public static readonly BGMode: {
        BG_CLEAR_COLOR: 0;
        BG_COLOR: 1;
        BG_SKY: 2;
        BG_CANVAS: 3;
        BG_KEEP: 4;
        BG_CAMERA_FEED: 5;
        BG_MAX: 6;
    };
    public static readonly AmbientSource: {
        AMBIENT_SOURCE_BG: 0;
        AMBIENT_SOURCE_DISABLED: 1;
        AMBIENT_SOURCE_COLOR: 2;
        AMBIENT_SOURCE_SKY: 3;
    };
    public static readonly ReflectionSource: {
        REFLECTION_SOURCE_BG: 0;
        REFLECTION_SOURCE_DISABLED: 1;
        REFLECTION_SOURCE_SKY: 2;
    };
    public static readonly ToneMapper: {
        TONE_MAPPER_LINEAR: 0;
        TONE_MAPPER_REINHARDT: 1;
        TONE_MAPPER_FILMIC: 2;
        TONE_MAPPER_ACES: 3;
        TONE_MAPPER_AGX: 4;
    };
    public static readonly GlowBlendMode: {
        GLOW_BLEND_MODE_ADDITIVE: 0;
        GLOW_BLEND_MODE_SCREEN: 1;
        GLOW_BLEND_MODE_SOFTLIGHT: 2;
        GLOW_BLEND_MODE_REPLACE: 3;
        GLOW_BLEND_MODE_MIX: 4;
    };
    public static readonly FogMode: {
        FOG_MODE_EXPONENTIAL: 0;
        FOG_MODE_DEPTH: 1;
    };
    public static readonly SDFGIYScale: {
        SDFGI_Y_SCALE_50_PERCENT: 0;
        SDFGI_Y_SCALE_75_PERCENT: 1;
        SDFGI_Y_SCALE_100_PERCENT: 2;
    };
}

