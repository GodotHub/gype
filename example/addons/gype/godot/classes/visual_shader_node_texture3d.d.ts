
import type { Texture3D } from '@godot/classes/texture3d';
import type { VisualShaderNodeSample3D } from '@godot/classes/visual_shader_node_sample3d';


export declare class VisualShaderNodeTexture3D extends VisualShaderNodeSample3D {

    
    /**     * The raw type is 'Texture3D'     */
    public texture: Texture3D;
    public set_texture(value: Texture3D): void;
    public get_texture(): Texture3D;


}

