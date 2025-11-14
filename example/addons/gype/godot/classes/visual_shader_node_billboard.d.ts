
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeBillboard extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public billboard_type: number;    
    /**     * The raw type is 'bool'     */
    public keep_scale: boolean;
    public set_billboard_type(billboardType: number): void;
    public get_billboard_type(): number;
    public set_keep_scale_enabled(enabled: boolean): void;
    public is_keep_scale_enabled(): boolean;


    public static readonly BillboardType: {
        BILLBOARD_TYPE_DISABLED: 0;
        BILLBOARD_TYPE_ENABLED: 1;
        BILLBOARD_TYPE_FIXED_Y: 2;
        BILLBOARD_TYPE_PARTICLES: 3;
        BILLBOARD_TYPE_MAX: 4;
    };
}

