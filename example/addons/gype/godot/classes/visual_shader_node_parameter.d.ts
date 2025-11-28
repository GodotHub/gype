
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeParameter extends VisualShaderNode {

    
    /**     * The raw type is 'StringName'     */
    public parameter_name: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public qualifier: number;
    public set_parameter_name(name: GDString | StringName | string): void;
    public get_parameter_name(): GDString;
    public set_qualifier(qualifier: number): void;
    public get_qualifier(): number;


    public static readonly Qualifier: {
        QUAL_NONE: 0;
        QUAL_GLOBAL: 1;
        QUAL_INSTANCE: 2;
        QUAL_MAX: 3;
    };
}

