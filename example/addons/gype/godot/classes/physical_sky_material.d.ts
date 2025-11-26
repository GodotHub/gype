
import type { Material } from '@godot/classes/material';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class PhysicalSkyMaterial extends Material {

    
    /**     * The raw type is 'float'     */
    public rayleigh_coefficient: number;    
    /**     * The raw type is 'Color'     */
    public rayleigh_color: Color;    
    /**     * The raw type is 'float'     */
    public mie_coefficient: number;    
    /**     * The raw type is 'float'     */
    public mie_eccentricity: number;    
    /**     * The raw type is 'Color'     */
    public mie_color: Color;    
    /**     * The raw type is 'float'     */
    public turbidity: number;    
    /**     * The raw type is 'float'     */
    public sun_disk_scale: number;    
    /**     * The raw type is 'Color'     */
    public ground_color: Color;    
    /**     * The raw type is 'float'     */
    public energy_multiplier: number;    
    /**     * The raw type is 'bool'     */
    public use_debanding: boolean;    
    /**     * The raw type is 'Texture2D'     */
    public night_sky: Texture2D;
    public set_rayleigh_coefficient(rayleigh: number): void;
    public get_rayleigh_coefficient(): number;
    public set_rayleigh_color(color: Color): void;
    public get_rayleigh_color(): Color;
    public set_mie_coefficient(mie: number): void;
    public get_mie_coefficient(): number;
    public set_mie_eccentricity(eccentricity: number): void;
    public get_mie_eccentricity(): number;
    public set_mie_color(color: Color): void;
    public get_mie_color(): Color;
    public set_turbidity(turbidity: number): void;
    public get_turbidity(): number;
    public set_sun_disk_scale(scale: number): void;
    public get_sun_disk_scale(): number;
    public set_ground_color(color: Color): void;
    public get_ground_color(): Color;
    public set_energy_multiplier(multiplier: number): void;
    public get_energy_multiplier(): number;
    public set_use_debanding(useDebanding: boolean): void;
    public get_use_debanding(): boolean;
    public set_night_sky(nightSky: Texture2D): void;
    public get_night_sky(): Texture2D;


}

