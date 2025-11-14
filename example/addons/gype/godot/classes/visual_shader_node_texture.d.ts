
import type { Texture2D } from '@godot/classes/texture2d';
import type { VisualShaderNode } from '@godot/classes/visual_shader_node';


export declare class VisualShaderNodeTexture extends VisualShaderNode {

    
    /**     * The raw type is 'int'     */
    public source: number;    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public texture_type: number;
    public set_source(value: number): void;
    public get_source(): number;
    public set_texture(value: Texture2D): void;
    public get_texture(): Texture2D;
    public set_texture_type(value: number): void;
    public get_texture_type(): number;


    public static readonly Source: {
        SOURCE_TEXTURE: 0;
        SOURCE_SCREEN: 1;
        SOURCE_2D_TEXTURE: 2;
        SOURCE_2D_NORMAL: 3;
        SOURCE_DEPTH: 4;
        SOURCE_PORT: 5;
        SOURCE_3D_NORMAL: 6;
        SOURCE_ROUGHNESS: 7;
        SOURCE_MAX: 8;
    };
    public static readonly TextureType: {
        TYPE_DATA: 0;
        TYPE_COLOR: 1;
        TYPE_NORMAL_MAP: 2;
        TYPE_MAX: 3;
    };
}

