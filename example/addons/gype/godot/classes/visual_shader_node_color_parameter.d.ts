
import type { Color } from '@godot/builtins/color';
import type { VisualShaderNodeParameter } from '@godot/classes/visual_shader_node_parameter';


export declare class VisualShaderNodeColorParameter extends VisualShaderNodeParameter {

    
    /**     * The raw type is 'bool'     */
    public default_value_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public default_value: Color;
    public set_default_value_enabled(enabled: boolean): void;
    public is_default_value_enabled(): boolean;
    public set_default_value(value: Color): void;
    public get_default_value(): Color;


}

