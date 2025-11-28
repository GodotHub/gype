
import type { VisualShaderNodeFrame } from '@godot/classes/visual_shader_node_frame';


export declare class VisualShaderNodeComment extends VisualShaderNodeFrame {

    
    /**     * The raw type is 'String'     */
    public description: GDString | StringName | string;
    public set_description(description: GDString | StringName | string): void;
    public get_description(): GDString;


}

