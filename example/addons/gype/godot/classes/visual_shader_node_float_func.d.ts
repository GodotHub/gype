
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeFloatFunc extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public function: number;
    public set_function(func: number): void;
    public get_function(): number;


    public static readonly Function: {
        FUNC_SIN: 0;
        FUNC_COS: 1;
        FUNC_TAN: 2;
        FUNC_ASIN: 3;
        FUNC_ACOS: 4;
        FUNC_ATAN: 5;
        FUNC_SINH: 6;
        FUNC_COSH: 7;
        FUNC_TANH: 8;
        FUNC_LOG: 9;
        FUNC_EXP: 10;
        FUNC_SQRT: 11;
        FUNC_ABS: 12;
        FUNC_SIGN: 13;
        FUNC_FLOOR: 14;
        FUNC_ROUND: 15;
        FUNC_CEIL: 16;
        FUNC_FRACT: 17;
        FUNC_SATURATE: 18;
        FUNC_NEGATE: 19;
        FUNC_ACOSH: 20;
        FUNC_ASINH: 21;
        FUNC_ATANH: 22;
        FUNC_DEGREES: 23;
        FUNC_EXP2: 24;
        FUNC_INVERSE_SQRT: 25;
        FUNC_LOG2: 26;
        FUNC_RADIANS: 27;
        FUNC_RECIPROCAL: 28;
        FUNC_ROUNDEVEN: 29;
        FUNC_TRUNC: 30;
        FUNC_ONEMINUS: 31;
        FUNC_MAX: 32;
    };
}

