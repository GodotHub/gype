
import type { Gradient } from '@godot/classes/gradient';
import type { Noise } from '@godot/classes/noise';
import type { Texture3D } from '@godot/classes/texture3d';


export declare class NoiseTexture3D extends Texture3D {

    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public height: number;    
    /**     * The raw type is 'int'     */
    public depth: number;    
    /**     * The raw type is 'Noise'     */
    public noise: Noise;    
    /**     * The raw type is 'Gradient'     */
    public color_ramp: Gradient;    
    /**     * The raw type is 'bool'     */
    public seamless: boolean;    
    /**     * The raw type is 'bool'     */
    public invert: boolean;    
    /**     * The raw type is 'bool'     */
    public normalize: boolean;    
    /**     * The raw type is 'float'     */
    public seamless_blend_skirt: number;
    public set_width(width: number): void;
    public set_height(height: number): void;
    public set_depth(depth: number): void;
    public set_noise(noise: Noise): void;
    public get_noise(): Noise;
    public set_color_ramp(gradient: Gradient): void;
    public get_color_ramp(): Gradient;
    public set_seamless(seamless: boolean): void;
    public get_seamless(): boolean;
    public set_invert(invert: boolean): void;
    public get_invert(): boolean;
    public set_normalize(normalize: boolean): void;
    public is_normalized(): boolean;
    public set_seamless_blend_skirt(seamlessBlendSkirt: number): void;
    public get_seamless_blend_skirt(): number;


}

