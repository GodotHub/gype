
import type { Vector3 } from '@godot/builtins/vector3';
import type { VisualShaderNodeConstant } from '@godot/classes/visual_shader_node_constant';


export declare class VisualShaderNodeVec3Constant extends VisualShaderNodeConstant {

    
    /**     * The raw type is 'Vector3'     */
    public constant: Vector3;
    public set_constant(constant: Vector3): void;
    public get_constant(): Vector3;


}

