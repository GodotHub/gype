
import type { Light3D } from '@godot/classes/light3d';


export declare class DirectionalLight3D extends Light3D {

    
    /**     * The raw type is 'int'     */
    public directional_shadow_mode: number;    
    /**     * The raw type is 'float'     */
    public directional_shadow_split_1: number;    
    /**     * The raw type is 'float'     */
    public directional_shadow_split_2: number;    
    /**     * The raw type is 'float'     */
    public directional_shadow_split_3: number;    
    /**     * The raw type is 'bool'     */
    public directional_shadow_blend_splits: boolean;    
    /**     * The raw type is 'float'     */
    public directional_shadow_fade_start: number;    
    /**     * The raw type is 'float'     */
    public directional_shadow_max_distance: number;    
    /**     * The raw type is 'float'     */
    public directional_shadow_pancake_size: number;    
    /**     * The raw type is 'int'     */
    public sky_mode: number;
    public set_shadow_mode(mode: number): void;
    public get_shadow_mode(): number;
    public set_blend_splits(enabled: boolean): void;
    public is_blend_splits_enabled(): boolean;
    public set_sky_mode(mode: number): void;
    public get_sky_mode(): number;


    public static readonly ShadowMode: {
        SHADOW_ORTHOGONAL: 0;
        SHADOW_PARALLEL_2_SPLITS: 1;
        SHADOW_PARALLEL_4_SPLITS: 2;
    };
    public static readonly SkyMode: {
        SKY_MODE_LIGHT_AND_SKY: 0;
        SKY_MODE_LIGHT_ONLY: 1;
        SKY_MODE_SKY_ONLY: 2;
    };
}

