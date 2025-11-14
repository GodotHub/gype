
import type { Transform3D } from '@godot/builtins/transform3d';
import type { VisualShaderNodeParameter } from '@godot/classes/visual_shader_node_parameter';


export declare class VisualShaderNodeTransformParameter extends VisualShaderNodeParameter {

    
    /**     * The raw type is 'bool'     */
    public default_value_enabled: boolean;    
    /**     * The raw type is 'Transform3D'     */
    public default_value: Transform3D;
    public set_default_value_enabled(enabled: boolean): void;
    public is_default_value_enabled(): boolean;
    public set_default_value(value: Transform3D): void;
    public get_default_value(): Transform3D;


}

