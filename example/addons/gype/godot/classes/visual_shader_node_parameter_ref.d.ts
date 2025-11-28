
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeParameterRef extends VisualShaderNode {

    
    /**     * The raw type is 'StringName'     */
    public parameter_name: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public param_type: number;
    public set_parameter_name(name: GDString | StringName | string): void;
    public get_parameter_name(): GDString;


}

