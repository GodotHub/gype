
import type { GDArray } from '@godot/builtins/gd_array';
import type { Resource } from '@godot/classes/resource';


export declare class VisualShaderNode extends Resource {

    
    /**     * The raw type is 'int'     */
    public output_port_for_preview: number;    
    /**     * The raw type is 'Array'     */
    public default_input_values: GDArray;    
    /**     * The raw type is 'Array'     */
    public expanded_output_ports: GDArray;    
    /**     * The raw type is 'int'     */
    public linked_parent_graph_frame: number;
    public get_default_input_port(_type: number): number;
    public set_output_port_for_preview(port: number): void;
    public get_output_port_for_preview(): number;
    public set_input_port_default_value(port: number, value: any, prevValue: any = null): void;
    public get_input_port_default_value(port: number): any;
    public remove_input_port_default_value(port: number): void;
    public clear_default_input_values(): void;
    public set_default_input_values(values: GDArray): void;
    public get_default_input_values(): GDArray;
    public set_frame(frame: number): void;
    public get_frame(): number;


    public static readonly PortType: {
        PORT_TYPE_SCALAR: 0;
        PORT_TYPE_SCALAR_INT: 1;
        PORT_TYPE_SCALAR_UINT: 2;
        PORT_TYPE_VECTOR_2D: 3;
        PORT_TYPE_VECTOR_3D: 4;
        PORT_TYPE_VECTOR_4D: 5;
        PORT_TYPE_BOOLEAN: 6;
        PORT_TYPE_TRANSFORM: 7;
        PORT_TYPE_SAMPLER: 8;
        PORT_TYPE_MAX: 9;
    };
}

