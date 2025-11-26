
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class RDPipelineColorBlendState extends RefCounted {

    
    /**     * The raw type is 'bool'     */
    public enable_logic_op: boolean;    
    /**     * The raw type is 'int'     */
    public logic_op: number;    
    /**     * The raw type is 'Color'     */
    public blend_constant: Color;    
    /**     * The raw type is 'typedarray::RDPipelineColorBlendStateAttachment'     */
    public attachments: Array<any>;
    public set_enable_logic_op(member: boolean): void;
    public get_enable_logic_op(): boolean;
    public set_logic_op(member: number): void;
    public get_logic_op(): number;
    public set_blend_constant(member: Color): void;
    public get_blend_constant(): Color;
    public set_attachments(attachments: Array<any>): void;
    public get_attachments(): Array<any>;


}

