
import type { Vector2 } from '@godot/builtins/vector2';
import type { VisualShaderNodeConstant } from '@godot/classes/visual_shader_node_constant';


export declare class VisualShaderNodeVec2Constant extends VisualShaderNodeConstant {

    
    /**     * The raw type is 'Vector2'     */
    public constant: Vector2;
    public set_constant(constant: Vector2): void;
    public get_constant(): Vector2;


}

