
import type { VisualShaderNodeGroupBase } from '@godot/classes/visual_shader_node_group_base';


export declare class VisualShaderNodeExpression extends VisualShaderNodeGroupBase {

    
    /**     * The raw type is 'String'     */
    public expression: GDString | StringName | string;
    public set_expression(expression: GDString | StringName | string): void;
    public get_expression(): GDString;


}

