
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDSamplerState extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public mag_filter: number;    
    /**     * The raw type is 'int'     */
    public min_filter: number;    
    /**     * The raw type is 'int'     */
    public mip_filter: number;    
    /**     * The raw type is 'int'     */
    public repeat_u: number;    
    /**     * The raw type is 'int'     */
    public repeat_v: number;    
    /**     * The raw type is 'int'     */
    public repeat_w: number;    
    /**     * The raw type is 'float'     */
    public lod_bias: number;    
    /**     * The raw type is 'bool'     */
    public use_anisotropy: boolean;    
    /**     * The raw type is 'float'     */
    public anisotropy_max: number;    
    /**     * The raw type is 'bool'     */
    public enable_compare: boolean;    
    /**     * The raw type is 'int'     */
    public compare_op: number;    
    /**     * The raw type is 'float'     */
    public min_lod: number;    
    /**     * The raw type is 'float'     */
    public max_lod: number;    
    /**     * The raw type is 'int'     */
    public border_color: number;    
    /**     * The raw type is 'bool'     */
    public unnormalized_uvw: boolean;
    public set_mag_filter(member: number): void;
    public get_mag_filter(): number;
    public set_min_filter(member: number): void;
    public get_min_filter(): number;
    public set_mip_filter(member: number): void;
    public get_mip_filter(): number;
    public set_repeat_u(member: number): void;
    public get_repeat_u(): number;
    public set_repeat_v(member: number): void;
    public get_repeat_v(): number;
    public set_repeat_w(member: number): void;
    public get_repeat_w(): number;
    public set_lod_bias(member: number): void;
    public get_lod_bias(): number;
    public set_use_anisotropy(member: boolean): void;
    public get_use_anisotropy(): boolean;
    public set_anisotropy_max(member: number): void;
    public get_anisotropy_max(): number;
    public set_enable_compare(member: boolean): void;
    public get_enable_compare(): boolean;
    public set_compare_op(member: number): void;
    public get_compare_op(): number;
    public set_min_lod(member: number): void;
    public get_min_lod(): number;
    public set_max_lod(member: number): void;
    public get_max_lod(): number;
    public set_border_color(member: number): void;
    public get_border_color(): number;
    public set_unnormalized_uvw(member: boolean): void;
    public get_unnormalized_uvw(): boolean;


}

