#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/environment.hpp>

using namespace godot;

void register_classes_Environment() {
    qjs::Context::Module &_module = _General;
    _module.class_<Environment>("Environment")
           .constructor<>()
           .property<Environment::get_background, Environment::set_background>("background_mode")
           .property<Environment::get_bg_color, Environment::set_bg_color>("background_color")
           .property<Environment::get_bg_energy_multiplier, Environment::set_bg_energy_multiplier>("background_energy_multiplier")
           .property<Environment::get_bg_intensity, Environment::set_bg_intensity>("background_intensity")
           .property<Environment::get_canvas_max_layer, Environment::set_canvas_max_layer>("background_canvas_max_layer")
           .property<Environment::get_camera_feed_id, Environment::set_camera_feed_id>("background_camera_feed_id")
           .property<Environment::get_sky, Environment::set_sky>("sky")
           .property<Environment::get_sky_custom_fov, Environment::set_sky_custom_fov>("sky_custom_fov")
           .property<Environment::get_sky_rotation, Environment::set_sky_rotation>("sky_rotation")
           .property<Environment::get_ambient_source, Environment::set_ambient_source>("ambient_light_source")
           .property<Environment::get_ambient_light_color, Environment::set_ambient_light_color>("ambient_light_color")
           .property<Environment::get_ambient_light_sky_contribution, Environment::set_ambient_light_sky_contribution>("ambient_light_sky_contribution")
           .property<Environment::get_ambient_light_energy, Environment::set_ambient_light_energy>("ambient_light_energy")
           .property<Environment::get_reflection_source, Environment::set_reflection_source>("reflected_light_source")
           .property<Environment::get_tonemapper, Environment::set_tonemapper>("tonemap_mode")
           .property<Environment::get_tonemap_exposure, Environment::set_tonemap_exposure>("tonemap_exposure")
           .property<Environment::get_tonemap_white, Environment::set_tonemap_white>("tonemap_white")
           .property<Environment::is_ssr_enabled, Environment::set_ssr_enabled>("ssr_enabled")
           .property<Environment::get_ssr_max_steps, Environment::set_ssr_max_steps>("ssr_max_steps")
           .property<Environment::get_ssr_fade_in, Environment::set_ssr_fade_in>("ssr_fade_in")
           .property<Environment::get_ssr_fade_out, Environment::set_ssr_fade_out>("ssr_fade_out")
           .property<Environment::get_ssr_depth_tolerance, Environment::set_ssr_depth_tolerance>("ssr_depth_tolerance")
           .property<Environment::is_ssao_enabled, Environment::set_ssao_enabled>("ssao_enabled")
           .property<Environment::get_ssao_radius, Environment::set_ssao_radius>("ssao_radius")
           .property<Environment::get_ssao_intensity, Environment::set_ssao_intensity>("ssao_intensity")
           .property<Environment::get_ssao_power, Environment::set_ssao_power>("ssao_power")
           .property<Environment::get_ssao_detail, Environment::set_ssao_detail>("ssao_detail")
           .property<Environment::get_ssao_horizon, Environment::set_ssao_horizon>("ssao_horizon")
           .property<Environment::get_ssao_sharpness, Environment::set_ssao_sharpness>("ssao_sharpness")
           .property<Environment::get_ssao_direct_light_affect, Environment::set_ssao_direct_light_affect>("ssao_light_affect")
           .property<Environment::get_ssao_ao_channel_affect, Environment::set_ssao_ao_channel_affect>("ssao_ao_channel_affect")
           .property<Environment::is_ssil_enabled, Environment::set_ssil_enabled>("ssil_enabled")
           .property<Environment::get_ssil_radius, Environment::set_ssil_radius>("ssil_radius")
           .property<Environment::get_ssil_intensity, Environment::set_ssil_intensity>("ssil_intensity")
           .property<Environment::get_ssil_sharpness, Environment::set_ssil_sharpness>("ssil_sharpness")
           .property<Environment::get_ssil_normal_rejection, Environment::set_ssil_normal_rejection>("ssil_normal_rejection")
           .property<Environment::is_sdfgi_enabled, Environment::set_sdfgi_enabled>("sdfgi_enabled")
           .property<Environment::is_sdfgi_using_occlusion, Environment::set_sdfgi_use_occlusion>("sdfgi_use_occlusion")
           .property<Environment::is_sdfgi_reading_sky_light, Environment::set_sdfgi_read_sky_light>("sdfgi_read_sky_light")
           .property<Environment::get_sdfgi_bounce_feedback, Environment::set_sdfgi_bounce_feedback>("sdfgi_bounce_feedback")
           .property<Environment::get_sdfgi_cascades, Environment::set_sdfgi_cascades>("sdfgi_cascades")
           .property<Environment::get_sdfgi_min_cell_size, Environment::set_sdfgi_min_cell_size>("sdfgi_min_cell_size")
           .property<Environment::get_sdfgi_cascade0_distance, Environment::set_sdfgi_cascade0_distance>("sdfgi_cascade0_distance")
           .property<Environment::get_sdfgi_max_distance, Environment::set_sdfgi_max_distance>("sdfgi_max_distance")
           .property<Environment::get_sdfgi_y_scale, Environment::set_sdfgi_y_scale>("sdfgi_y_scale")
           .property<Environment::get_sdfgi_energy, Environment::set_sdfgi_energy>("sdfgi_energy")
           .property<Environment::get_sdfgi_normal_bias, Environment::set_sdfgi_normal_bias>("sdfgi_normal_bias")
           .property<Environment::get_sdfgi_probe_bias, Environment::set_sdfgi_probe_bias>("sdfgi_probe_bias")
           .property<Environment::is_glow_enabled, Environment::set_glow_enabled>("glow_enabled")
           .property<Environment::is_glow_normalized, Environment::set_glow_normalized>("glow_normalized")
           .property<Environment::get_glow_intensity, Environment::set_glow_intensity>("glow_intensity")
           .property<Environment::get_glow_strength, Environment::set_glow_strength>("glow_strength")
           .property<Environment::get_glow_mix, Environment::set_glow_mix>("glow_mix")
           .property<Environment::get_glow_bloom, Environment::set_glow_bloom>("glow_bloom")
           .property<Environment::get_glow_blend_mode, Environment::set_glow_blend_mode>("glow_blend_mode")
           .property<Environment::get_glow_hdr_bleed_threshold, Environment::set_glow_hdr_bleed_threshold>("glow_hdr_threshold")
           .property<Environment::get_glow_hdr_bleed_scale, Environment::set_glow_hdr_bleed_scale>("glow_hdr_scale")
           .property<Environment::get_glow_hdr_luminance_cap, Environment::set_glow_hdr_luminance_cap>("glow_hdr_luminance_cap")
           .property<Environment::get_glow_map_strength, Environment::set_glow_map_strength>("glow_map_strength")
           .property<Environment::get_glow_map, Environment::set_glow_map>("glow_map")
           .property<Environment::is_fog_enabled, Environment::set_fog_enabled>("fog_enabled")
           .property<Environment::get_fog_light_color, Environment::set_fog_light_color>("fog_light_color")
           .property<Environment::get_fog_light_energy, Environment::set_fog_light_energy>("fog_light_energy")
           .property<Environment::get_fog_sun_scatter, Environment::set_fog_sun_scatter>("fog_sun_scatter")
           .property<Environment::get_fog_density, Environment::set_fog_density>("fog_density")
           .property<Environment::get_fog_aerial_perspective, Environment::set_fog_aerial_perspective>("fog_aerial_perspective")
           .property<Environment::get_fog_sky_affect, Environment::set_fog_sky_affect>("fog_sky_affect")
           .property<Environment::get_fog_height, Environment::set_fog_height>("fog_height")
           .property<Environment::get_fog_height_density, Environment::set_fog_height_density>("fog_height_density")
           .property<Environment::is_volumetric_fog_enabled, Environment::set_volumetric_fog_enabled>("volumetric_fog_enabled")
           .property<Environment::get_volumetric_fog_density, Environment::set_volumetric_fog_density>("volumetric_fog_density")
           .property<Environment::get_volumetric_fog_albedo, Environment::set_volumetric_fog_albedo>("volumetric_fog_albedo")
           .property<Environment::get_volumetric_fog_emission, Environment::set_volumetric_fog_emission>("volumetric_fog_emission")
           .property<Environment::get_volumetric_fog_emission_energy, Environment::set_volumetric_fog_emission_energy>("volumetric_fog_emission_energy")
           .property<Environment::get_volumetric_fog_gi_inject, Environment::set_volumetric_fog_gi_inject>("volumetric_fog_gi_inject")
           .property<Environment::get_volumetric_fog_anisotropy, Environment::set_volumetric_fog_anisotropy>("volumetric_fog_anisotropy")
           .property<Environment::get_volumetric_fog_length, Environment::set_volumetric_fog_length>("volumetric_fog_length")
           .property<Environment::get_volumetric_fog_detail_spread, Environment::set_volumetric_fog_detail_spread>("volumetric_fog_detail_spread")
           .property<Environment::get_volumetric_fog_ambient_inject, Environment::set_volumetric_fog_ambient_inject>("volumetric_fog_ambient_inject")
           .property<Environment::get_volumetric_fog_sky_affect, Environment::set_volumetric_fog_sky_affect>("volumetric_fog_sky_affect")
           .property<Environment::is_volumetric_fog_temporal_reprojection_enabled, Environment::set_volumetric_fog_temporal_reprojection_enabled>("volumetric_fog_temporal_reprojection_enabled")
           .property<Environment::get_volumetric_fog_temporal_reprojection_amount, Environment::set_volumetric_fog_temporal_reprojection_amount>("volumetric_fog_temporal_reprojection_amount")
           .property<Environment::is_adjustment_enabled, Environment::set_adjustment_enabled>("adjustment_enabled")
           .property<Environment::get_adjustment_brightness, Environment::set_adjustment_brightness>("adjustment_brightness")
           .property<Environment::get_adjustment_contrast, Environment::set_adjustment_contrast>("adjustment_contrast")
           .property<Environment::get_adjustment_saturation, Environment::set_adjustment_saturation>("adjustment_saturation")
           .property<Environment::get_adjustment_color_correction, Environment::set_adjustment_color_correction>("adjustment_color_correction")
		    .fun<static_cast<void(Environment::*)(int32_t,double)>(&Environment::set_glow_level)>("set_glow_level")
		    .fun<static_cast<double(Environment::*)(int32_t)const>(&Environment::get_glow_level)>("get_glow_level")
;}