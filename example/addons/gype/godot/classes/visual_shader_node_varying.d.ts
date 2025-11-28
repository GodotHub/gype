
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeVarying extends VisualShaderNode {

    
    /**     * The raw type is 'StringName'     */
    public varying_name: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public varying_type: number;
    public set_varying_name(name: GDString | StringName | string): void;
    public get_varying_name(): GDString;
    public set_varying_type(_type: number): void;
    public get_varying_type(): number;


}

