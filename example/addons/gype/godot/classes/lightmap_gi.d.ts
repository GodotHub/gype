
import type { CameraAttributes } from '@godot/classes/camera_attributes';
import type { CameraAttributesPractical } from '@godot/classes/camera_attributes_practical';
import type { LightmapGIData } from '@godot/classes/lightmap_gi_data';
import type { Sky } from '@godot/classes/sky';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class LightmapGI extends VisualInstance3D {

    
    /**     * The raw type is 'int'     */
    public quality: number;    
    /**     * The raw type is 'bool'     */
    public supersampling: boolean;    
    /**     * The raw type is 'float'     */
    public supersampling_factor: number;    
    /**     * The raw type is 'int'     */
    public bounces: number;    
    /**     * The raw type is 'float'     */
    public bounce_indirect_energy: number;    
    /**     * The raw type is 'bool'     */
    public directional: boolean;    
    /**     * The raw type is 'int'     */
    public shadowmask_mode: number;    
    /**     * The raw type is 'bool'     */
    public use_texture_for_bounces: boolean;    
    /**     * The raw type is 'bool'     */
    public interior: boolean;    
    /**     * The raw type is 'bool'     */
    public use_denoiser: boolean;    
    /**     * The raw type is 'float'     */
    public denoiser_strength: number;    
    /**     * The raw type is 'int'     */
    public denoiser_range: number;    
    /**     * The raw type is 'float'     */
    public bias: number;    
    /**     * The raw type is 'float'     */
    public texel_scale: number;    
    /**     * The raw type is 'int'     */
    public max_texture_size: number;    
    /**     * The raw type is 'int'     */
    public environment_mode: number;    
    /**     * The raw type is 'Sky'     */
    public environment_custom_sky: Sky;    
    /**     * The raw type is 'Color'     */
    public environment_custom_color: Color;    
    /**     * The raw type is 'float'     */
    public environment_custom_energy: number;    
    /**     * The raw type is 'CameraAttributesPractical,CameraAttributesPhysical'     */
    public camera_attributes: CameraAttributes;    
    /**     * The raw type is 'int'     */
    public generate_probes_subdiv: number;    
    /**     * The raw type is 'LightmapGIData'     */
    public light_data: LightmapGIData;
    public set_light_data(data: LightmapGIData): void;
    public get_light_data(): LightmapGIData;
    public set_bake_quality(bakeQuality: number): void;
    public get_bake_quality(): number;
    public set_bounces(bounces: number): void;
    public get_bounces(): number;
    public set_bounce_indirect_energy(bounceIndirectEnergy: number): void;
    public get_bounce_indirect_energy(): number;
    public set_generate_probes(subdivision: number): void;
    public get_generate_probes(): number;
    public set_bias(bias: number): void;
    public get_bias(): number;
    public set_environment_mode(mode: number): void;
    public get_environment_mode(): number;
    public set_environment_custom_sky(sky: Sky): void;
    public get_environment_custom_sky(): Sky;
    public set_environment_custom_color(color: Color): void;
    public get_environment_custom_color(): Color;
    public set_environment_custom_energy(energy: number): void;
    public get_environment_custom_energy(): number;
    public set_texel_scale(texelScale: number): void;
    public get_texel_scale(): number;
    public set_max_texture_size(maxTextureSize: number): void;
    public get_max_texture_size(): number;
    public set_supersampling_enabled(enable: boolean): void;
    public is_supersampling_enabled(): boolean;
    public set_supersampling_factor(factor: number): void;
    public get_supersampling_factor(): number;
    public set_use_denoiser(useDenoiser: boolean): void;
    public is_using_denoiser(): boolean;
    public set_denoiser_strength(denoiserStrength: number): void;
    public get_denoiser_strength(): number;
    public set_denoiser_range(denoiserRange: number): void;
    public get_denoiser_range(): number;
    public set_interior(enable: boolean): void;
    public is_interior(): boolean;
    public set_directional(directional: boolean): void;
    public is_directional(): boolean;
    public set_shadowmask_mode(mode: number): void;
    public get_shadowmask_mode(): number;
    public set_use_texture_for_bounces(useTextureForBounces: boolean): void;
    public is_using_texture_for_bounces(): boolean;
    public set_camera_attributes(cameraAttributes: CameraAttributes): void;
    public get_camera_attributes(): CameraAttributes;


    public static readonly BakeQuality: {
        BAKE_QUALITY_LOW: 0;
        BAKE_QUALITY_MEDIUM: 1;
        BAKE_QUALITY_HIGH: 2;
        BAKE_QUALITY_ULTRA: 3;
    };
    public static readonly GenerateProbes: {
        GENERATE_PROBES_DISABLED: 0;
        GENERATE_PROBES_SUBDIV_4: 1;
        GENERATE_PROBES_SUBDIV_8: 2;
        GENERATE_PROBES_SUBDIV_16: 3;
        GENERATE_PROBES_SUBDIV_32: 4;
    };
    public static readonly BakeError: {
        BAKE_ERROR_OK: 0;
        BAKE_ERROR_NO_SCENE_ROOT: 1;
        BAKE_ERROR_FOREIGN_DATA: 2;
        BAKE_ERROR_NO_LIGHTMAPPER: 3;
        BAKE_ERROR_NO_SAVE_PATH: 4;
        BAKE_ERROR_NO_MESHES: 5;
        BAKE_ERROR_MESHES_INVALID: 6;
        BAKE_ERROR_CANT_CREATE_IMAGE: 7;
        BAKE_ERROR_USER_ABORTED: 8;
        BAKE_ERROR_TEXTURE_SIZE_TOO_SMALL: 9;
        BAKE_ERROR_LIGHTMAP_TOO_SMALL: 10;
        BAKE_ERROR_ATLAS_TOO_SMALL: 11;
    };
    public static readonly EnvironmentMode: {
        ENVIRONMENT_MODE_DISABLED: 0;
        ENVIRONMENT_MODE_SCENE: 1;
        ENVIRONMENT_MODE_CUSTOM_SKY: 2;
        ENVIRONMENT_MODE_CUSTOM_COLOR: 3;
    };
}

