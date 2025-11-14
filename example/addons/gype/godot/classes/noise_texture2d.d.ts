
import type { Gradient } from '@godot/classes/gradient';
import type { Noise } from '@godot/classes/noise';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class NoiseTexture2D extends Texture2D {

    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public height: number;    
    /**     * The raw type is 'bool'     */
    public generate_mipmaps: boolean;    
    /**     * The raw type is 'Noise'     */
    public noise: Noise;    
    /**     * The raw type is 'Gradient'     */
    public color_ramp: Gradient;    
    /**     * The raw type is 'bool'     */
    public seamless: boolean;    
    /**     * The raw type is 'bool'     */
    public invert: boolean;    
    /**     * The raw type is 'bool'     */
    public in_3d_space: boolean;    
    /**     * The raw type is 'bool'     */
    public as_normal_map: boolean;    
    /**     * The raw type is 'bool'     */
    public normalize: boolean;    
    /**     * The raw type is 'float'     */
    public seamless_blend_skirt: number;    
    /**     * The raw type is 'float'     */
    public bump_strength: number;
    public set_width(width: number): void;
    public set_height(height: number): void;
    public set_generate_mipmaps(invert: boolean): void;
    public is_generating_mipmaps(): boolean;
    public set_noise(noise: Noise): void;
    public get_noise(): Noise;
    public set_color_ramp(gradient: Gradient): void;
    public get_color_ramp(): Gradient;
    public set_seamless(seamless: boolean): void;
    public get_seamless(): boolean;
    public set_invert(invert: boolean): void;
    public get_invert(): boolean;
    public set_in_3d_space(enable: boolean): void;
    public is_in_3d_space(): boolean;
    public set_as_normal_map(asNormalMap: boolean): void;
    public is_normal_map(): boolean;
    public set_normalize(normalize: boolean): void;
    public is_normalized(): boolean;
    public set_seamless_blend_skirt(seamlessBlendSkirt: number): void;
    public get_seamless_blend_skirt(): number;
    public set_bump_strength(bumstrength: number): void;
    public get_bump_strength(): number;


}

