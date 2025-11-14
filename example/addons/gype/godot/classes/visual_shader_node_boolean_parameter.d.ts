
import type { VisualShaderNodeParameter } from '@godot/classes/visual_shader_node_parameter';


export declare class VisualShaderNodeBooleanParameter extends VisualShaderNodeParameter {

    
    /**     * The raw type is 'bool'     */
    public default_value_enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public default_value: boolean;
    public set_default_value_enabled(enabled: boolean): void;
    public is_default_value_enabled(): boolean;
    public set_default_value(value: boolean): void;
    public get_default_value(): boolean;


}

