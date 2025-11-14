
import type { Color } from '@godot/builtins/color';
import type { Material } from '@godot/classes/material';
import type { Texture3D } from '@godot/classes/texture3d';


export declare class FogMaterial extends Material {

    
    /**     * The raw type is 'float'     */
    public density: number;    
    /**     * The raw type is 'Color'     */
    public albedo: Color;    
    /**     * The raw type is 'Color'     */
    public emission: Color;    
    /**     * The raw type is 'float'     */
    public height_falloff: number;    
    /**     * The raw type is 'float'     */
    public edge_fade: number;    
    /**     * The raw type is 'Texture3D'     */
    public density_texture: Texture3D;
    public set_density(density: number): void;
    public get_density(): number;
    public set_albedo(albedo: Color): void;
    public get_albedo(): Color;
    public set_emission(emission: Color): void;
    public get_emission(): Color;
    public set_height_falloff(heightFalloff: number): void;
    public get_height_falloff(): number;
    public set_edge_fade(edgeFade: number): void;
    public get_edge_fade(): number;
    public set_density_texture(densityTexture: Texture3D): void;
    public get_density_texture(): Texture3D;


}

