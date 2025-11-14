
import type { Vector4 } from '@godot/builtins/vector4';
import type { VisualShaderNodeParameter } from '@godot/classes/visual_shader_node_parameter';


export declare class VisualShaderNodeVec4Parameter extends VisualShaderNodeParameter {

    
    /**     * The raw type is 'bool'     */
    public default_value_enabled: boolean;    
    /**     * The raw type is 'Vector4'     */
    public default_value: Vector4;
    public set_default_value_enabled(enabled: boolean): void;
    public is_default_value_enabled(): boolean;
    public set_default_value(value: Vector4): void;
    public get_default_value(): Vector4;


}

