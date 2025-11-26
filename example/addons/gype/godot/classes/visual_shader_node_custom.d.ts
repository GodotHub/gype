
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeCustom extends VisualShaderNode {

    
    /**     * The raw type is 'bool'     */
    public initialized: boolean;    
    /**     * The raw type is 'String'     */
    public properties: GDString;
    public _get_name(): GDString;
    public _get_description(): GDString;
    public _get_category(): GDString;
    public _get_return_icon_type(): number;
    public _get_input_port_count(): number;
    public _get_input_port_type(port: number): number;
    public _get_input_port_name(port: number): GDString;
    public _get_input_port_default_value(port: number): any;
    public _get_default_input_port(_type: number): number;
    public _get_output_port_count(): number;
    public _get_output_port_type(port: number): number;
    public _get_output_port_name(port: number): GDString;
    public _get_property_count(): number;
    public _get_property_name(index: number): GDString;
    public _get_property_default_index(index: number): number;
    public _get_property_options(index: number): PackedStringArray;
    public _get_code(inputVars: Array<any>, outputVars: Array<any>, mode: number, _type: number): GDString;
    public _get_func_code(mode: number, _type: number): GDString;
    public _get_global_code(mode: number): GDString;
    public _is_highend(): boolean;
    public _is_available(mode: number, _type: number): boolean;
    public get_option_index(option: number): number;


}

