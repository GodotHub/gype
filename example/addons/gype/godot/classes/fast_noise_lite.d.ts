
import type { Noise } from '@godot/classes/noise';


export declare class FastNoiseLite extends Noise {

    
    /**     * The raw type is 'int'     */
    public noise_type: number;    
    /**     * The raw type is 'int'     */
    public seed: number;    
    /**     * The raw type is 'float'     */
    public frequency: number;    
    /**     * The raw type is 'Vector3'     */
    public offset: Vector3;    
    /**     * The raw type is 'int'     */
    public fractal_type: number;    
    /**     * The raw type is 'int'     */
    public fractal_octaves: number;    
    /**     * The raw type is 'float'     */
    public fractal_lacunarity: number;    
    /**     * The raw type is 'float'     */
    public fractal_gain: number;    
    /**     * The raw type is 'float'     */
    public fractal_weighted_strength: number;    
    /**     * The raw type is 'float'     */
    public fractal_ping_pong_strength: number;    
    /**     * The raw type is 'int'     */
    public cellular_distance_function: number;    
    /**     * The raw type is 'float'     */
    public cellular_jitter: number;    
    /**     * The raw type is 'int'     */
    public cellular_return_type: number;    
    /**     * The raw type is 'bool'     */
    public domain_warp_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public domain_warp_type: number;    
    /**     * The raw type is 'float'     */
    public domain_warp_amplitude: number;    
    /**     * The raw type is 'float'     */
    public domain_warp_frequency: number;    
    /**     * The raw type is 'int'     */
    public domain_warp_fractal_type: number;    
    /**     * The raw type is 'int'     */
    public domain_warp_fractal_octaves: number;    
    /**     * The raw type is 'float'     */
    public domain_warp_fractal_lacunarity: number;    
    /**     * The raw type is 'float'     */
    public domain_warp_fractal_gain: number;
    public set_noise_type(_type: number): void;
    public get_noise_type(): number;
    public set_seed(seed: number): void;
    public get_seed(): number;
    public set_frequency(freq: number): void;
    public get_frequency(): number;
    public set_offset(offset: Vector3): void;
    public get_offset(): Vector3;
    public set_fractal_type(_type: number): void;
    public get_fractal_type(): number;
    public set_fractal_octaves(octaveCount: number): void;
    public get_fractal_octaves(): number;
    public set_fractal_lacunarity(lacunarity: number): void;
    public get_fractal_lacunarity(): number;
    public set_fractal_gain(gain: number): void;
    public get_fractal_gain(): number;
    public set_fractal_weighted_strength(weightedStrength: number): void;
    public get_fractal_weighted_strength(): number;
    public set_fractal_ping_pong_strength(pingPongStrength: number): void;
    public get_fractal_ping_pong_strength(): number;
    public set_cellular_distance_function(func: number): void;
    public get_cellular_distance_function(): number;
    public set_cellular_jitter(jitter: number): void;
    public get_cellular_jitter(): number;
    public set_cellular_return_type(ret: number): void;
    public get_cellular_return_type(): number;
    public set_domain_warp_enabled(domainWarenabled: boolean): void;
    public is_domain_warp_enabled(): boolean;
    public set_domain_warp_type(domainWartype: number): void;
    public get_domain_warp_type(): number;
    public set_domain_warp_amplitude(domainWaramplitude: number): void;
    public get_domain_warp_amplitude(): number;
    public set_domain_warp_frequency(domainWarfrequency: number): void;
    public get_domain_warp_frequency(): number;
    public set_domain_warp_fractal_type(domainWarfractalType: number): void;
    public get_domain_warp_fractal_type(): number;
    public set_domain_warp_fractal_octaves(domainWaroctaveCount: number): void;
    public get_domain_warp_fractal_octaves(): number;
    public set_domain_warp_fractal_lacunarity(domainWarlacunarity: number): void;
    public get_domain_warp_fractal_lacunarity(): number;
    public set_domain_warp_fractal_gain(domainWargain: number): void;
    public get_domain_warp_fractal_gain(): number;


    public static readonly NoiseType: {
        TYPE_VALUE: 5;
        TYPE_VALUE_CUBIC: 4;
        TYPE_PERLIN: 3;
        TYPE_CELLULAR: 2;
        TYPE_SIMPLEX: 0;
        TYPE_SIMPLEX_SMOOTH: 1;
    };
    public static readonly FractalType: {
        FRACTAL_NONE: 0;
        FRACTAL_FBM: 1;
        FRACTAL_RIDGED: 2;
        FRACTAL_PING_PONG: 3;
    };
    public static readonly CellularDistanceFunction: {
        DISTANCE_EUCLIDEAN: 0;
        DISTANCE_EUCLIDEAN_SQUARED: 1;
        DISTANCE_MANHATTAN: 2;
        DISTANCE_HYBRID: 3;
    };
    public static readonly CellularReturnType: {
        RETURN_CELL_VALUE: 0;
        RETURN_DISTANCE: 1;
        RETURN_DISTANCE2: 2;
        RETURN_DISTANCE2_ADD: 3;
        RETURN_DISTANCE2_SUB: 4;
        RETURN_DISTANCE2_MUL: 5;
        RETURN_DISTANCE2_DIV: 6;
    };
    public static readonly DomainWarpType: {
        DOMAIN_WARP_SIMPLEX: 0;
        DOMAIN_WARP_SIMPLEX_REDUCED: 1;
        DOMAIN_WARP_BASIC_GRID: 2;
    };
    public static readonly DomainWarpFractalType: {
        DOMAIN_WARP_FRACTAL_NONE: 0;
        DOMAIN_WARP_FRACTAL_PROGRESSIVE: 1;
        DOMAIN_WARP_FRACTAL_INDEPENDENT: 2;
    };
}

