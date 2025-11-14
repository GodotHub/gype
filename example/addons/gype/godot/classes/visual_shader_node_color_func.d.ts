
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeColorFunc extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public function: number;
    public set_function(func: number): void;
    public get_function(): number;


    public static readonly Function: {
        FUNC_GRAYSCALE: 0;
        FUNC_HSV2RGB: 1;
        FUNC_RGB2HSV: 2;
        FUNC_SEPIA: 3;
        FUNC_LINEAR_TO_SRGB: 4;
        FUNC_SRGB_TO_LINEAR: 5;
        FUNC_MAX: 6;
    };
}

