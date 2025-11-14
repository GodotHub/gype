
import type { Color } from '@godot/builtins/color';
import type { Texture2D } from '@godot/classes/texture2d';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class Light3D extends VisualInstance3D {

    
    /**     * The raw type is 'float'     */
    public light_intensity_lumens: number;    
    /**     * The raw type is 'float'     */
    public light_intensity_lux: number;    
    /**     * The raw type is 'float'     */
    public light_temperature: number;    
    /**     * The raw type is 'Color'     */
    public light_color: Color;    
    /**     * The raw type is 'float'     */
    public light_energy: number;    
    /**     * The raw type is 'float'     */
    public light_indirect_energy: number;    
    /**     * The raw type is 'float'     */
    public light_volumetric_fog_energy: number;    
    /**     * The raw type is 'Texture2D,-AnimatedTexture,-AtlasTexture,-CameraTexture,-CanvasTexture,-MeshTexture,-Texture2DRD,-ViewportTexture'     */
    public light_projector: Texture2D;    
    /**     * The raw type is 'float'     */
    public light_size: number;    
    /**     * The raw type is 'float'     */
    public light_angular_distance: number;    
    /**     * The raw type is 'bool'     */
    public light_negative: boolean;    
    /**     * The raw type is 'float'     */
    public light_specular: number;    
    /**     * The raw type is 'int'     */
    public light_bake_mode: number;    
    /**     * The raw type is 'int'     */
    public light_cull_mask: number;    
    /**     * The raw type is 'bool'     */
    public shadow_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public shadow_bias: number;    
    /**     * The raw type is 'float'     */
    public shadow_normal_bias: number;    
    /**     * The raw type is 'bool'     */
    public shadow_reverse_cull_face: boolean;    
    /**     * The raw type is 'float'     */
    public shadow_transmittance_bias: number;    
    /**     * The raw type is 'float'     */
    public shadow_opacity: number;    
    /**     * The raw type is 'float'     */
    public shadow_blur: number;    
    /**     * The raw type is 'int'     */
    public shadow_caster_mask: number;    
    /**     * The raw type is 'bool'     */
    public distance_fade_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public distance_fade_begin: number;    
    /**     * The raw type is 'float'     */
    public distance_fade_shadow: number;    
    /**     * The raw type is 'float'     */
    public distance_fade_length: number;    
    /**     * The raw type is 'bool'     */
    public editor_only: boolean;
    public set_editor_only(editorOnly: boolean): void;
    public is_editor_only(): boolean;
    public set_param(param: number, value: number): void;
    public get_param(param: number): number;
    public set_shadow(enabled: boolean): void;
    public has_shadow(): boolean;
    public set_negative(enabled: boolean): void;
    public is_negative(): boolean;
    public set_cull_mask(cullMask: number): void;
    public get_cull_mask(): number;
    public set_enable_distance_fade(enable: boolean): void;
    public is_distance_fade_enabled(): boolean;
    public set_distance_fade_begin(distance: number): void;
    public get_distance_fade_begin(): number;
    public set_distance_fade_shadow(distance: number): void;
    public get_distance_fade_shadow(): number;
    public set_distance_fade_length(distance: number): void;
    public get_distance_fade_length(): number;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_shadow_reverse_cull_face(enable: boolean): void;
    public get_shadow_reverse_cull_face(): boolean;
    public set_shadow_caster_mask(casterMask: number): void;
    public get_shadow_caster_mask(): number;
    public set_bake_mode(bakeMode: number): void;
    public get_bake_mode(): number;
    public set_projector(projector: Texture2D): void;
    public get_projector(): Texture2D;
    public set_temperature(temperature: number): void;
    public get_temperature(): number;
    public get_correlated_color(): Color;


    public static readonly Param: {
        PARAM_ENERGY: 0;
        PARAM_INDIRECT_ENERGY: 1;
        PARAM_VOLUMETRIC_FOG_ENERGY: 2;
        PARAM_SPECULAR: 3;
        PARAM_RANGE: 4;
        PARAM_SIZE: 5;
        PARAM_ATTENUATION: 6;
        PARAM_SPOT_ANGLE: 7;
        PARAM_SPOT_ATTENUATION: 8;
        PARAM_SHADOW_MAX_DISTANCE: 9;
        PARAM_SHADOW_SPLIT_1_OFFSET: 10;
        PARAM_SHADOW_SPLIT_2_OFFSET: 11;
        PARAM_SHADOW_SPLIT_3_OFFSET: 12;
        PARAM_SHADOW_FADE_START: 13;
        PARAM_SHADOW_NORMAL_BIAS: 14;
        PARAM_SHADOW_BIAS: 15;
        PARAM_SHADOW_PANCAKE_SIZE: 16;
        PARAM_SHADOW_OPACITY: 17;
        PARAM_SHADOW_BLUR: 18;
        PARAM_TRANSMITTANCE_BIAS: 19;
        PARAM_INTENSITY: 20;
        PARAM_MAX: 21;
    };
    public static readonly BakeMode: {
        BAKE_DISABLED: 0;
        BAKE_STATIC: 1;
        BAKE_DYNAMIC: 2;
    };
}

