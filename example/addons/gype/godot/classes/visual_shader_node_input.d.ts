
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeInput extends VisualShaderNode {

    
    /**     * The raw type is 'StringName'     */
    public input_name: GDString | StringName | string;
    public set_input_name(name: GDString | StringName | string): void;
    public get_input_name(): GDString;
    public get_input_real_name(): GDString;

    
    public readonly input_type_changed: Signal<() => void>;

}

