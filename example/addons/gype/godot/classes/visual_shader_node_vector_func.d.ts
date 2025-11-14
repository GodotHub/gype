
import type { VisualShaderNodeVectorBase } from '@godot/classes/visual_shader_node_vector_base';


export declare class VisualShaderNodeVectorFunc extends VisualShaderNodeVectorBase {

    
    /**     * The raw type is 'int'     */
    public function: number;
    public set_function(func: number): void;
    public get_function(): number;


    public static readonly Function: {
        FUNC_NORMALIZE: 0;
        FUNC_SATURATE: 1;
        FUNC_NEGATE: 2;
        FUNC_RECIPROCAL: 3;
        FUNC_ABS: 4;
        FUNC_ACOS: 5;
        FUNC_ACOSH: 6;
        FUNC_ASIN: 7;
        FUNC_ASINH: 8;
        FUNC_ATAN: 9;
        FUNC_ATANH: 10;
        FUNC_CEIL: 11;
        FUNC_COS: 12;
        FUNC_COSH: 13;
        FUNC_DEGREES: 14;
        FUNC_EXP: 15;
        FUNC_EXP2: 16;
        FUNC_FLOOR: 17;
        FUNC_FRACT: 18;
        FUNC_INVERSE_SQRT: 19;
        FUNC_LOG: 20;
        FUNC_LOG2: 21;
        FUNC_RADIANS: 22;
        FUNC_ROUND: 23;
        FUNC_ROUNDEVEN: 24;
        FUNC_SIGN: 25;
        FUNC_SIN: 26;
        FUNC_SINH: 27;
        FUNC_SQRT: 28;
        FUNC_TAN: 29;
        FUNC_TANH: 30;
        FUNC_TRUNC: 31;
        FUNC_ONEMINUS: 32;
        FUNC_MAX: 33;
    };
}

