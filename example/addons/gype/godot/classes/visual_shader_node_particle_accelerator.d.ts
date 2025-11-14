
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeParticleAccelerator extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public mode: number;
    public set_mode(mode: number): void;
    public get_mode(): number;


    public static readonly Mode: {
        MODE_LINEAR: 0;
        MODE_RADIAL: 1;
        MODE_TANGENTIAL: 2;
        MODE_MAX: 3;
    };
}

