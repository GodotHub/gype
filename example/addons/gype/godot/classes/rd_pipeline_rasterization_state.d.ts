
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDPipelineRasterizationState extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public enable_depth_clamp: boolean;    
    /**     * The raw type is 'bool'     */
    public discard_primitives: boolean;    
    /**     * The raw type is 'bool'     */
    public wireframe: boolean;    
    /**     * The raw type is 'int'     */
    public cull_mode: number;    
    /**     * The raw type is 'int'     */
    public front_face: number;    
    /**     * The raw type is 'bool'     */
    public depth_bias_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public depth_bias_constant_factor: number;    
    /**     * The raw type is 'float'     */
    public depth_bias_clamp: number;    
    /**     * The raw type is 'float'     */
    public depth_bias_slope_factor: number;    
    /**     * The raw type is 'float'     */
    public line_width: number;    
    /**     * The raw type is 'int'     */
    public patch_control_points: number;
    public set_enable_depth_clamp(member: boolean): void;
    public get_enable_depth_clamp(): boolean;
    public set_discard_primitives(member: boolean): void;
    public get_discard_primitives(): boolean;
    public set_wireframe(member: boolean): void;
    public get_wireframe(): boolean;
    public set_cull_mode(member: number): void;
    public get_cull_mode(): number;
    public set_front_face(member: number): void;
    public get_front_face(): number;
    public set_depth_bias_enabled(member: boolean): void;
    public get_depth_bias_enabled(): boolean;
    public set_depth_bias_constant_factor(member: number): void;
    public get_depth_bias_constant_factor(): number;
    public set_depth_bias_clamp(member: number): void;
    public get_depth_bias_clamp(): number;
    public set_depth_bias_slope_factor(member: number): void;
    public get_depth_bias_slope_factor(): number;
    public set_line_width(member: number): void;
    public get_line_width(): number;
    public set_patch_control_points(member: number): void;
    public get_patch_control_points(): number;


}

