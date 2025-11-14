
import type { Texture2DArray } from '@godot/classes/texture2d_array';
import type { TextureLayered } from '@godot/classes/texture_layered';
import type { VisualShaderNodeSample3D } from '@godot/classes/visual_shader_node_sample3d';


export declare class VisualShaderNodeTexture2DArray extends VisualShaderNodeSample3D {

    
    /**     * The raw type is 'Texture2DArray,CompressedTexture2DArray,PlaceholderTexture2DArray,Texture2DArrayRD'     */
    public texture_array: TextureLayered;
    public set_texture_array(value: TextureLayered): void;
    public get_texture_array(): TextureLayered;


}

