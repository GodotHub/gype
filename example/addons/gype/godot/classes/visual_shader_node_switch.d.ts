
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeSwitch extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public op_type: number;
    public set_op_type(_type: number): void;
    public get_op_type(): number;


    public static readonly OpType: {
        OP_TYPE_FLOAT: 0;
        OP_TYPE_INT: 1;
        OP_TYPE_UINT: 2;
        OP_TYPE_VECTOR_2D: 3;
        OP_TYPE_VECTOR_3D: 4;
        OP_TYPE_VECTOR_4D: 5;
        OP_TYPE_BOOLEAN: 6;
        OP_TYPE_TRANSFORM: 7;
        OP_TYPE_MAX: 8;
    };
}

