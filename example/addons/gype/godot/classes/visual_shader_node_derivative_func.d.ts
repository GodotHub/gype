
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeDerivativeFunc extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public op_type: number;    
    /**     * The raw type is 'int'     */
    public function: number;    
    /**     * The raw type is 'int'     */
    public precision: number;
    public set_op_type(_type: number): void;
    public get_op_type(): number;
    public set_function(func: number): void;
    public get_function(): number;
    public set_precision(precision: number): void;
    public get_precision(): number;


    public static readonly OpType: {
        OP_TYPE_SCALAR: 0;
        OP_TYPE_VECTOR_2D: 1;
        OP_TYPE_VECTOR_3D: 2;
        OP_TYPE_VECTOR_4D: 3;
        OP_TYPE_MAX: 4;
    };
    public static readonly Function: {
        FUNC_SUM: 0;
        FUNC_X: 1;
        FUNC_Y: 2;
        FUNC_MAX: 3;
    };
    public static readonly Precision: {
        PRECISION_NONE: 0;
        PRECISION_COARSE: 1;
        PRECISION_FINE: 2;
        PRECISION_MAX: 3;
    };
}

