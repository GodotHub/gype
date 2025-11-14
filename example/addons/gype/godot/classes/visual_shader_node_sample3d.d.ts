
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeSample3D extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public source: number;
    public set_source(value: number): void;
    public get_source(): number;


    public static readonly Source: {
        SOURCE_TEXTURE: 0;
        SOURCE_PORT: 1;
        SOURCE_MAX: 2;
    };
}

