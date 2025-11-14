
import type { VisualShaderNodeParameter } from '@godot/classes/visual_shader_node_parameter';


export declare class VisualShaderNodeTextureParameter extends VisualShaderNodeParameter {

    
    /**     * The raw type is 'int'     */
    public texture_type: number;    
    /**     * The raw type is 'int'     */
    public color_default: number;    
    /**     * The raw type is 'int'     */
    public texture_filter: number;    
    /**     * The raw type is 'int'     */
    public texture_repeat: number;    
    /**     * The raw type is 'int'     */
    public texture_source: number;
    public set_texture_type(_type: number): void;
    public get_texture_type(): number;
    public set_color_default(color: number): void;
    public get_color_default(): number;
    public set_texture_filter(filter: number): void;
    public get_texture_filter(): number;
    public set_texture_repeat(repeat: number): void;
    public get_texture_repeat(): number;
    public set_texture_source(source: number): void;
    public get_texture_source(): number;


    public static readonly TextureType: {
        TYPE_DATA: 0;
        TYPE_COLOR: 1;
        TYPE_NORMAL_MAP: 2;
        TYPE_ANISOTROPY: 3;
        TYPE_MAX: 4;
    };
    public static readonly ColorDefault: {
        COLOR_DEFAULT_WHITE: 0;
        COLOR_DEFAULT_BLACK: 1;
        COLOR_DEFAULT_TRANSPARENT: 2;
        COLOR_DEFAULT_MAX: 3;
    };
    public static readonly TextureFilter: {
        FILTER_DEFAULT: 0;
        FILTER_NEAREST: 1;
        FILTER_LINEAR: 2;
        FILTER_NEAREST_MIPMAP: 3;
        FILTER_LINEAR_MIPMAP: 4;
        FILTER_NEAREST_MIPMAP_ANISOTROPIC: 5;
        FILTER_LINEAR_MIPMAP_ANISOTROPIC: 6;
        FILTER_MAX: 7;
    };
    public static readonly TextureRepeat: {
        REPEAT_DEFAULT: 0;
        REPEAT_ENABLED: 1;
        REPEAT_DISABLED: 2;
        REPEAT_MAX: 3;
    };
    public static readonly TextureSource: {
        SOURCE_NONE: 0;
        SOURCE_SCREEN: 1;
        SOURCE_DEPTH: 2;
        SOURCE_NORMAL_ROUGHNESS: 3;
        SOURCE_MAX: 4;
    };
}

