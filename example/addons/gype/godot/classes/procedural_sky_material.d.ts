
import type { Material } from '@godot/classes/material';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class ProceduralSkyMaterial extends Material {

    
    /**     * The raw type is 'Color'     */
    public sky_top_color: Color;    
    /**     * The raw type is 'Color'     */
    public sky_horizon_color: Color;    
    /**     * The raw type is 'float'     */
    public sky_curve: number;    
    /**     * The raw type is 'float'     */
    public sky_energy_multiplier: number;    
    /**     * The raw type is 'Texture2D'     */
    public sky_cover: Texture2D;    
    /**     * The raw type is 'Color'     */
    public sky_cover_modulate: Color;    
    /**     * The raw type is 'Color'     */
    public ground_bottom_color: Color;    
    /**     * The raw type is 'Color'     */
    public ground_horizon_color: Color;    
    /**     * The raw type is 'float'     */
    public ground_curve: number;    
    /**     * The raw type is 'float'     */
    public ground_energy_multiplier: number;    
    /**     * The raw type is 'float'     */
    public sun_angle_max: number;    
    /**     * The raw type is 'float'     */
    public sun_curve: number;    
    /**     * The raw type is 'bool'     */
    public use_debanding: boolean;    
    /**     * The raw type is 'float'     */
    public energy_multiplier: number;
    public set_sky_top_color(color: Color): void;
    public get_sky_top_color(): Color;
    public set_sky_horizon_color(color: Color): void;
    public get_sky_horizon_color(): Color;
    public set_sky_curve(curve: number): void;
    public get_sky_curve(): number;
    public set_sky_energy_multiplier(multiplier: number): void;
    public get_sky_energy_multiplier(): number;
    public set_sky_cover(skyCover: Texture2D): void;
    public get_sky_cover(): Texture2D;
    public set_sky_cover_modulate(color: Color): void;
    public get_sky_cover_modulate(): Color;
    public set_ground_bottom_color(color: Color): void;
    public get_ground_bottom_color(): Color;
    public set_ground_horizon_color(color: Color): void;
    public get_ground_horizon_color(): Color;
    public set_ground_curve(curve: number): void;
    public get_ground_curve(): number;
    public set_ground_energy_multiplier(energy: number): void;
    public get_ground_energy_multiplier(): number;
    public set_sun_angle_max(degrees: number): void;
    public get_sun_angle_max(): number;
    public set_sun_curve(curve: number): void;
    public get_sun_curve(): number;
    public set_use_debanding(useDebanding: boolean): void;
    public get_use_debanding(): boolean;
    public set_energy_multiplier(multiplier: number): void;
    public get_energy_multiplier(): number;


}

