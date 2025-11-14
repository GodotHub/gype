
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDTextureFormat extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public format: number;    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public height: number;    
    /**     * The raw type is 'int'     */
    public depth: number;    
    /**     * The raw type is 'int'     */
    public array_layers: number;    
    /**     * The raw type is 'int'     */
    public mipmaps: number;    
    /**     * The raw type is 'int'     */
    public texture_type: number;    
    /**     * The raw type is 'int'     */
    public samples: number;    
    /**     * The raw type is 'int'     */
    public usage_bits: number;    
    /**     * The raw type is 'bool'     */
    public is_resolve_buffer: boolean;    
    /**     * The raw type is 'bool'     */
    public is_discardable: boolean;
    public set_format(member: number): void;
    public get_format(): number;
    public set_width(member: number): void;
    public get_width(): number;
    public set_height(member: number): void;
    public get_height(): number;
    public set_depth(member: number): void;
    public get_depth(): number;
    public set_array_layers(member: number): void;
    public get_array_layers(): number;
    public set_mipmaps(member: number): void;
    public get_mipmaps(): number;
    public set_texture_type(member: number): void;
    public get_texture_type(): number;
    public set_samples(member: number): void;
    public get_samples(): number;
    public set_usage_bits(member: number): void;
    public get_usage_bits(): number;
    public set_is_resolve_buffer(member: boolean): void;
    public get_is_resolve_buffer(): boolean;
    public set_is_discardable(member: boolean): void;
    public get_is_discardable(): boolean;
    public add_shareable_format(format: number): void;
    public remove_shareable_format(format: number): void;


}

