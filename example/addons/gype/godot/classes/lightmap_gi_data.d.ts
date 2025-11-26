
import type { Resource } from '@godot/classes/resource';
import type { TextureLayered } from '@godot/classes/texture_layered';


export declare class LightmapGIData extends Resource {

    
    /**     * The raw type is 'typedarray::TextureLayered'     */
    public lightmap_textures: Array<any>;    
    /**     * The raw type is 'typedarray::TextureLayered'     */
    public shadowmask_textures: Array<any>;    
    /**     * The raw type is 'bool'     */
    public uses_spherical_harmonics: boolean;    
    /**     * The raw type is 'Array'     */
    public user_data: GDArray;    
    /**     * The raw type is 'Dictionary'     */
    public probe_data: Dictionary;    
    /**     * The raw type is 'TextureLayered'     */
    public light_texture: TextureLayered;    
    /**     * The raw type is 'Array'     */
    public light_textures: GDArray;
    public set_lightmap_textures(lightTextures: Array<any>): void;
    public get_lightmap_textures(): Array<any>;
    public set_shadowmask_textures(shadowmaskTextures: Array<any>): void;
    public get_shadowmask_textures(): Array<any>;
    public set_uses_spherical_harmonics(usesSphericalHarmonics: boolean): void;
    public is_using_spherical_harmonics(): boolean;
    public add_user(path: NodePath | GDString | string, uvScale: Rect2, sliceIndex: number, subInstance: number): void;
    public get_user_count(): number;
    public get_user_path(userIdx: number): NodePath;
    public clear_users(): void;
    public set_light_texture(lightTexture: TextureLayered): void;
    public get_light_texture(): TextureLayered;


    public static readonly ShadowmaskMode: {
        SHADOWMASK_MODE_NONE: 0;
        SHADOWMASK_MODE_REPLACE: 1;
        SHADOWMASK_MODE_OVERLAY: 2;
    };
}

