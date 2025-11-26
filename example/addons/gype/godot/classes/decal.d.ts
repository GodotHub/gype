
import type { Texture2D } from '@godot/classes/texture2d';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class Decal extends VisualInstance3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'Texture2D,-AnimatedTexture,-AtlasTexture,-CameraTexture,-CanvasTexture,-MeshTexture,-Texture2DRD,-ViewportTexture'     */
    public texture_albedo: Texture2D;    
    /**     * The raw type is 'Texture2D,-AnimatedTexture,-AtlasTexture,-CameraTexture,-CanvasTexture,-MeshTexture,-Texture2DRD,-ViewportTexture'     */
    public texture_normal: Texture2D;    
    /**     * The raw type is 'Texture2D,-AnimatedTexture,-AtlasTexture,-CameraTexture,-CanvasTexture,-MeshTexture,-Texture2DRD,-ViewportTexture'     */
    public texture_orm: Texture2D;    
    /**     * The raw type is 'Texture2D,-AnimatedTexture,-AtlasTexture,-CameraTexture,-CanvasTexture,-MeshTexture,-Texture2DRD,-ViewportTexture'     */
    public texture_emission: Texture2D;    
    /**     * The raw type is 'float'     */
    public emission_energy: number;    
    /**     * The raw type is 'Color'     */
    public modulate: Color;    
    /**     * The raw type is 'float'     */
    public albedo_mix: number;    
    /**     * The raw type is 'float'     */
    public normal_fade: number;    
    /**     * The raw type is 'float'     */
    public upper_fade: number;    
    /**     * The raw type is 'float'     */
    public lower_fade: number;    
    /**     * The raw type is 'bool'     */
    public distance_fade_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public distance_fade_begin: number;    
    /**     * The raw type is 'float'     */
    public distance_fade_length: number;    
    /**     * The raw type is 'int'     */
    public cull_mask: number;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_texture(_type: number, texture: Texture2D): void;
    public get_texture(_type: number): Texture2D;
    public set_emission_energy(energy: number): void;
    public get_emission_energy(): number;
    public set_albedo_mix(energy: number): void;
    public get_albedo_mix(): number;
    public set_modulate(color: Color): void;
    public get_modulate(): Color;
    public set_upper_fade(fade: number): void;
    public get_upper_fade(): number;
    public set_lower_fade(fade: number): void;
    public get_lower_fade(): number;
    public set_normal_fade(fade: number): void;
    public get_normal_fade(): number;
    public set_enable_distance_fade(enable: boolean): void;
    public is_distance_fade_enabled(): boolean;
    public set_distance_fade_begin(distance: number): void;
    public get_distance_fade_begin(): number;
    public set_distance_fade_length(distance: number): void;
    public get_distance_fade_length(): number;
    public set_cull_mask(mask: number): void;
    public get_cull_mask(): number;


    public static readonly DecalTexture: {
        TEXTURE_ALBEDO: 0;
        TEXTURE_NORMAL: 1;
        TEXTURE_ORM: 2;
        TEXTURE_EMISSION: 3;
        TEXTURE_MAX: 4;
    };
}

