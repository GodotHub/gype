
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeTransformOp extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public operator: number;
    public set_operator(op: number): void;
    public get_operator(): number;


    public static readonly Operator: {
        OP_AxB: 0;
        OP_BxA: 1;
        OP_AxB_COMP: 2;
        OP_BxA_COMP: 3;
        OP_ADD: 4;
        OP_A_MINUS_B: 5;
        OP_B_MINUS_A: 6;
        OP_A_DIV_B: 7;
        OP_B_DIV_A: 8;
        OP_MAX: 9;
    };
}

