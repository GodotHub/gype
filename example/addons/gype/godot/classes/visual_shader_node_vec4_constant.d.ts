
import type { Quaternion } from '@godot/builtins/quaternion';
import type { Vector4 } from '@godot/builtins/vector4';
import type { VisualShaderNodeConstant } from '@godot/classes/visual_shader_node_constant';


export declare class VisualShaderNodeVec4Constant extends VisualShaderNodeConstant {

    
    /**     * The raw type is 'Quaternion'     */
    public constant: Quaternion;    
    /**     * The raw type is 'Vector4'     */
    public constant_v4: Vector4;
    public set_constant(constant: Quaternion): void;
    public get_constant(): Quaternion;


}

