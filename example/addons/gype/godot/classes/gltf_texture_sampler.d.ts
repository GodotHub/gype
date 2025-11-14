
import type { Resource } from '@godot/classes/resource';


export declare class GLTFTextureSampler extends Resource {

    
    /**     * The raw type is 'int'     */
    public mag_filter: number;    
    /**     * The raw type is 'int'     */
    public min_filter: number;    
    /**     * The raw type is 'int'     */
    public wrap_s: number;    
    /**     * The raw type is 'int'     */
    public wrap_t: number;
    public get_mag_filter(): number;
    public set_mag_filter(filterMode: number): void;
    public get_min_filter(): number;
    public set_min_filter(filterMode: number): void;
    public get_wrap_s(): number;
    public set_wrap_s(wramode: number): void;
    public get_wrap_t(): number;
    public set_wrap_t(wramode: number): void;


}

