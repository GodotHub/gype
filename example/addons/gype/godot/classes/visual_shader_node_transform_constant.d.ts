
import type { Transform3D } from '@godot/builtins/transform3d';
import type { VisualShaderNodeConstant } from '@godot/classes/visual_shader_node_constant';


export declare class VisualShaderNodeTransformConstant extends VisualShaderNodeConstant {

    
    /**     * The raw type is 'Transform3D'     */
    public constant: Transform3D;
    public set_constant(constant: Transform3D): void;
    public get_constant(): Transform3D;


}

