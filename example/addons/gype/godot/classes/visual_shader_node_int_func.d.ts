
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeIntFunc extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public function: number;
    public set_function(func: number): void;
    public get_function(): number;


    public static readonly Function: {
        FUNC_ABS: 0;
        FUNC_NEGATE: 1;
        FUNC_SIGN: 2;
        FUNC_BITWISE_NOT: 3;
        FUNC_MAX: 4;
    };
}

