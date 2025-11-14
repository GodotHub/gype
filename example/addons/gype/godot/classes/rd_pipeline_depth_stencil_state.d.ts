
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDPipelineDepthStencilState extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public enable_depth_test: boolean;    
    /**     * The raw type is 'bool'     */
    public enable_depth_write: boolean;    
    /**     * The raw type is 'int'     */
    public depth_compare_operator: number;    
    /**     * The raw type is 'bool'     */
    public enable_depth_range: boolean;    
    /**     * The raw type is 'float'     */
    public depth_range_min: number;    
    /**     * The raw type is 'float'     */
    public depth_range_max: number;    
    /**     * The raw type is 'bool'     */
    public enable_stencil: boolean;    
    /**     * The raw type is 'int'     */
    public front_op_fail: number;    
    /**     * The raw type is 'int'     */
    public front_op_pass: number;    
    /**     * The raw type is 'int'     */
    public front_op_depth_fail: number;    
    /**     * The raw type is 'int'     */
    public front_op_compare: number;    
    /**     * The raw type is 'int'     */
    public front_op_compare_mask: number;    
    /**     * The raw type is 'int'     */
    public front_op_write_mask: number;    
    /**     * The raw type is 'int'     */
    public front_op_reference: number;    
    /**     * The raw type is 'int'     */
    public back_op_fail: number;    
    /**     * The raw type is 'int'     */
    public back_op_pass: number;    
    /**     * The raw type is 'int'     */
    public back_op_depth_fail: number;    
    /**     * The raw type is 'int'     */
    public back_op_compare: number;    
    /**     * The raw type is 'int'     */
    public back_op_compare_mask: number;    
    /**     * The raw type is 'int'     */
    public back_op_write_mask: number;    
    /**     * The raw type is 'int'     */
    public back_op_reference: number;
    public set_enable_depth_test(member: boolean): void;
    public get_enable_depth_test(): boolean;
    public set_enable_depth_write(member: boolean): void;
    public get_enable_depth_write(): boolean;
    public set_depth_compare_operator(member: number): void;
    public get_depth_compare_operator(): number;
    public set_enable_depth_range(member: boolean): void;
    public get_enable_depth_range(): boolean;
    public set_depth_range_min(member: number): void;
    public get_depth_range_min(): number;
    public set_depth_range_max(member: number): void;
    public get_depth_range_max(): number;
    public set_enable_stencil(member: boolean): void;
    public get_enable_stencil(): boolean;
    public set_front_op_fail(member: number): void;
    public get_front_op_fail(): number;
    public set_front_op_pass(member: number): void;
    public get_front_op_pass(): number;
    public set_front_op_depth_fail(member: number): void;
    public get_front_op_depth_fail(): number;
    public set_front_op_compare(member: number): void;
    public get_front_op_compare(): number;
    public set_front_op_compare_mask(member: number): void;
    public get_front_op_compare_mask(): number;
    public set_front_op_write_mask(member: number): void;
    public get_front_op_write_mask(): number;
    public set_front_op_reference(member: number): void;
    public get_front_op_reference(): number;
    public set_back_op_fail(member: number): void;
    public get_back_op_fail(): number;
    public set_back_op_pass(member: number): void;
    public get_back_op_pass(): number;
    public set_back_op_depth_fail(member: number): void;
    public get_back_op_depth_fail(): number;
    public set_back_op_compare(member: number): void;
    public get_back_op_compare(): number;
    public set_back_op_compare_mask(member: number): void;
    public get_back_op_compare_mask(): number;
    public set_back_op_write_mask(member: number): void;
    public get_back_op_write_mask(): number;
    public set_back_op_reference(member: number): void;
    public get_back_op_reference(): number;


}

