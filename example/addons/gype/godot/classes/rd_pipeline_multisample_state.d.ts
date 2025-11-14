
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDPipelineMultisampleState extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public sample_count: number;    
    /**     * The raw type is 'bool'     */
    public enable_sample_shading: boolean;    
    /**     * The raw type is 'float'     */
    public min_sample_shading: number;    
    /**     * The raw type is 'bool'     */
    public enable_alpha_to_coverage: boolean;    
    /**     * The raw type is 'bool'     */
    public enable_alpha_to_one: boolean;    
    /**     * The raw type is 'typedarray::int'     */
    public sample_masks: Array<any>;
    public set_sample_count(member: number): void;
    public get_sample_count(): number;
    public set_enable_sample_shading(member: boolean): void;
    public get_enable_sample_shading(): boolean;
    public set_min_sample_shading(member: number): void;
    public get_min_sample_shading(): number;
    public set_enable_alpha_to_coverage(member: boolean): void;
    public get_enable_alpha_to_coverage(): boolean;
    public set_enable_alpha_to_one(member: boolean): void;
    public get_enable_alpha_to_one(): boolean;
    public set_sample_masks(masks: Array<any>): void;
    public get_sample_masks(): Array<any>;


}

