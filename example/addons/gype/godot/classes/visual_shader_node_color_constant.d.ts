
import type { Color } from '@godot/builtins/color';
import type { VisualShaderNodeConstant } from '@godot/classes/visual_shader_node_constant';


export declare class VisualShaderNodeColorConstant extends VisualShaderNodeConstant {

    
    /**     * The raw type is 'Color'     */
    public constant: Color;
    public set_constant(constant: Color): void;
    public get_constant(): Color;


}

