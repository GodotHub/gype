
import type { Material } from '@godot/classes/material';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class PanoramaSkyMaterial extends Material {

    
    /**     * The raw type is 'Texture2D'     */
    public panorama: Texture2D;    
    /**     * The raw type is 'bool'     */
    public filter: boolean;    
    /**     * The raw type is 'float'     */
    public energy_multiplier: number;
    public set_panorama(texture: Texture2D): void;
    public get_panorama(): Texture2D;
    public set_filtering_enabled(enabled: boolean): void;
    public is_filtering_enabled(): boolean;
    public set_energy_multiplier(multiplier: number): void;
    public get_energy_multiplier(): number;


}

