
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDPipelineColorBlendStateAttachment extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public enable_blend: boolean;    
    /**     * The raw type is 'int'     */
    public src_color_blend_factor: number;    
    /**     * The raw type is 'int'     */
    public dst_color_blend_factor: number;    
    /**     * The raw type is 'int'     */
    public color_blend_op: number;    
    /**     * The raw type is 'int'     */
    public src_alpha_blend_factor: number;    
    /**     * The raw type is 'int'     */
    public dst_alpha_blend_factor: number;    
    /**     * The raw type is 'int'     */
    public alpha_blend_op: number;    
    /**     * The raw type is 'bool'     */
    public write_r: boolean;    
    /**     * The raw type is 'bool'     */
    public write_g: boolean;    
    /**     * The raw type is 'bool'     */
    public write_b: boolean;    
    /**     * The raw type is 'bool'     */
    public write_a: boolean;
    public set_as_mix(): void;
    public set_enable_blend(member: boolean): void;
    public get_enable_blend(): boolean;
    public set_src_color_blend_factor(member: number): void;
    public get_src_color_blend_factor(): number;
    public set_dst_color_blend_factor(member: number): void;
    public get_dst_color_blend_factor(): number;
    public set_color_blend_op(member: number): void;
    public get_color_blend_op(): number;
    public set_src_alpha_blend_factor(member: number): void;
    public get_src_alpha_blend_factor(): number;
    public set_dst_alpha_blend_factor(member: number): void;
    public get_dst_alpha_blend_factor(): number;
    public set_alpha_blend_op(member: number): void;
    public get_alpha_blend_op(): number;
    public set_write_r(member: boolean): void;
    public get_write_r(): boolean;
    public set_write_g(member: boolean): void;
    public get_write_g(): boolean;
    public set_write_b(member: boolean): void;
    public get_write_b(): boolean;
    public set_write_a(member: boolean): void;
    public get_write_a(): boolean;


}

