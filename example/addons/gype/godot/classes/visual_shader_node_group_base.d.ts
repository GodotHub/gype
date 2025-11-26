
import type { VisualShaderNodeResizableBase } from '@godot/classes/visual_shader_node_resizable_base';


export declare class VisualShaderNodeGroupBase extends VisualShaderNodeResizableBase {


    public set_inputs(inputs: GDString | StringName | string): void;
    public get_inputs(): GDString;
    public set_outputs(outputs: GDString | StringName | string): void;
    public get_outputs(): GDString;
    public is_valid_port_name(name: GDString | StringName | string): boolean;
    public add_input_port(id: number, _type: number, name: GDString | StringName | string): void;
    public remove_input_port(id: number): void;
    public get_input_port_count(): number;
    public has_input_port(id: number): boolean;
    public clear_input_ports(): void;
    public add_output_port(id: number, _type: number, name: GDString | StringName | string): void;
    public remove_output_port(id: number): void;
    public get_output_port_count(): number;
    public has_output_port(id: number): boolean;
    public clear_output_ports(): void;
    public set_input_port_name(id: number, name: GDString | StringName | string): void;
    public set_input_port_type(id: number, _type: number): void;
    public set_output_port_name(id: number, name: GDString | StringName | string): void;
    public set_output_port_type(id: number, _type: number): void;
    public get_free_input_port_id(): number;
    public get_free_output_port_id(): number;


}

