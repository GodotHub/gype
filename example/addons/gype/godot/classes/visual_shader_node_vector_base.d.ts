
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeVectorBase extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public op_type: number;
    public set_op_type(_type: number): void;
    public get_op_type(): number;


    public static readonly OpType: {
        OP_TYPE_VECTOR_2D: 0;
        OP_TYPE_VECTOR_3D: 1;
        OP_TYPE_VECTOR_4D: 2;
        OP_TYPE_MAX: 3;
    };
}

