
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeTransformVecMult extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public operator: number;
    public set_operator(op: number): void;
    public get_operator(): number;


    public static readonly Operator: {
        OP_AxB: 0;
        OP_BxA: 1;
        OP_3x3_AxB: 2;
        OP_3x3_BxA: 3;
        OP_MAX: 4;
    };
}

