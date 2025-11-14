
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeTransformFunc extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public function: number;
    public set_function(func: number): void;
    public get_function(): number;


    public static readonly Function: {
        FUNC_INVERSE: 0;
        FUNC_TRANSPOSE: 1;
        FUNC_MAX: 2;
    };
}

