
import type { Cubemap } from '@godot/classes/cubemap';
import type { TextureLayered } from '@godot/classes/texture_layered';
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeCubemap extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public source: number;    
    /**     * The raw type is 'Cubemap,CompressedCubemap,PlaceholderCubemap,TextureCubemapRD'     */
    public cube_map: TextureLayered;    
    /**     * The raw type is 'int'     */
    public texture_type: number;
    public set_source(value: number): void;
    public get_source(): number;
    public set_cube_map(value: TextureLayered): void;
    public get_cube_map(): TextureLayered;
    public set_texture_type(value: number): void;
    public get_texture_type(): number;


    public static readonly Source: {
        SOURCE_TEXTURE: 0;
        SOURCE_PORT: 1;
        SOURCE_MAX: 2;
    };
    public static readonly TextureType: {
        TYPE_DATA: 0;
        TYPE_COLOR: 1;
        TYPE_NORMAL_MAP: 2;
        TYPE_MAX: 3;
    };
}

