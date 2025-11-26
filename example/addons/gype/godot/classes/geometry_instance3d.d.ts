
import type { BaseMaterial3D } from '@godot/classes/base_material3d';
import type { Material } from '@godot/classes/material';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class GeometryInstance3D extends VisualInstance3D {

    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material_override: Material;    
    /**     * The raw type is 'BaseMaterial3D,ShaderMaterial'     */
    public material_overlay: Material;    
    /**     * The raw type is 'float'     */
    public transparency: number;    
    /**     * The raw type is 'int'     */
    public cast_shadow: number;    
    /**     * The raw type is 'float'     */
    public extra_cull_margin: number;    
    /**     * The raw type is 'AABB'     */
    public custom_aabb: AABB;    
    /**     * The raw type is 'float'     */
    public lod_bias: number;    
    /**     * The raw type is 'bool'     */
    public ignore_occlusion_culling: boolean;    
    /**     * The raw type is 'int'     */
    public gi_mode: number;    
    /**     * The raw type is 'float'     */
    public gi_lightmap_texel_scale: number;    
    /**     * The raw type is 'int'     */
    public gi_lightmap_scale: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_begin: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_begin_margin: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_end: number;    
    /**     * The raw type is 'float'     */
    public visibility_range_end_margin: number;    
    /**     * The raw type is 'int'     */
    public visibility_range_fade_mode: number;
    public set_material_override(material: Material): void;
    public get_material_override(): Material;
    public set_material_overlay(material: Material): void;
    public get_material_overlay(): Material;
    public set_cast_shadows_setting(shadowCastingSetting: number): void;
    public get_cast_shadows_setting(): number;
    public set_lod_bias(bias: number): void;
    public get_lod_bias(): number;
    public set_transparency(transparency: number): void;
    public get_transparency(): number;
    public set_visibility_range_end_margin(distance: number): void;
    public get_visibility_range_end_margin(): number;
    public set_visibility_range_end(distance: number): void;
    public get_visibility_range_end(): number;
    public set_visibility_range_begin_margin(distance: number): void;
    public get_visibility_range_begin_margin(): number;
    public set_visibility_range_begin(distance: number): void;
    public get_visibility_range_begin(): number;
    public set_visibility_range_fade_mode(mode: number): void;
    public get_visibility_range_fade_mode(): number;
    public set_instance_shader_parameter(name: GDString | StringName | string, value: any): void;
    public get_instance_shader_parameter(name: GDString | StringName | string): any;
    public set_extra_cull_margin(margin: number): void;
    public get_extra_cull_margin(): number;
    public set_lightmap_texel_scale(scale: number): void;
    public get_lightmap_texel_scale(): number;
    public set_lightmap_scale(scale: number): void;
    public get_lightmap_scale(): number;
    public set_gi_mode(mode: number): void;
    public get_gi_mode(): number;
    public set_ignore_occlusion_culling(ignoreCulling: boolean): void;
    public is_ignoring_occlusion_culling(): boolean;
    public set_custom_aabb(aabb: AABB): void;
    public get_custom_aabb(): AABB;


    public static readonly ShadowCastingSetting: {
        SHADOW_CASTING_SETTING_OFF: 0;
        SHADOW_CASTING_SETTING_ON: 1;
        SHADOW_CASTING_SETTING_DOUBLE_SIDED: 2;
        SHADOW_CASTING_SETTING_SHADOWS_ONLY: 3;
    };
    public static readonly GIMode: {
        GI_MODE_DISABLED: 0;
        GI_MODE_STATIC: 1;
        GI_MODE_DYNAMIC: 2;
    };
    public static readonly LightmapScale: {
        LIGHTMAP_SCALE_1X: 0;
        LIGHTMAP_SCALE_2X: 1;
        LIGHTMAP_SCALE_4X: 2;
        LIGHTMAP_SCALE_8X: 3;
        LIGHTMAP_SCALE_MAX: 4;
    };
    public static readonly VisibilityRangeFadeMode: {
        VISIBILITY_RANGE_FADE_DISABLED: 0;
        VISIBILITY_RANGE_FADE_SELF: 1;
        VISIBILITY_RANGE_FADE_DEPENDENCIES: 2;
    };
}

