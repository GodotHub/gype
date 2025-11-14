
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeParticleEmit extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public flags: number;
    public set_flags(flags: number): void;
    public get_flags(): number;


    public static readonly EmitFlags: {
        EMIT_FLAG_POSITION: 1;
        EMIT_FLAG_ROT_SCALE: 2;
        EMIT_FLAG_VELOCITY: 4;
        EMIT_FLAG_COLOR: 8;
        EMIT_FLAG_CUSTOM: 16;
    };
}

