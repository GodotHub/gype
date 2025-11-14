
import type { RID } from '@godot/builtins/rid';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class RenderSceneBuffersConfiguration extends RefCounted {

    
    /**     * The raw type is 'RID'     */
    public render_target: RID;    
    /**     * The raw type is 'Vector2i'     */
    public internal_size: Vector2i;    
    /**     * The raw type is 'Vector2i'     */
    public target_size: Vector2i;    
    /**     * The raw type is 'int'     */
    public view_count: number;    
    /**     * The raw type is 'int'     */
    public scaling_3d_mode: number;    
    /**     * The raw type is 'int'     */
    public msaa_3d: number;    
    /**     * The raw type is 'int'     */
    public screen_space_aa: number;    
    /**     * The raw type is 'bool'     */
    public fsr_sharpness: number;    
    /**     * The raw type is 'bool'     */
    public texture_mipmap_bias: number;    
    /**     * The raw type is 'int'     */
    public anisotropic_filtering_level: number;
    public get_render_target(): RID;
    public set_render_target(renderTarget: RID): void;
    public get_internal_size(): Vector2i;
    public set_internal_size(internalSize: Vector2i): void;
    public get_target_size(): Vector2i;
    public set_target_size(targetSize: Vector2i): void;
    public get_view_count(): number;
    public set_view_count(viewCount: number): void;
    public get_scaling_3d_mode(): number;
    public set_scaling_3d_mode(scaling3DMode: number): void;
    public get_msaa_3d(): number;
    public set_msaa_3d(msaa3D: number): void;
    public get_screen_space_aa(): number;
    public set_screen_space_aa(screenSpaceAa: number): void;
    public get_fsr_sharpness(): number;
    public set_fsr_sharpness(fsrSharpness: number): void;
    public get_texture_mipmap_bias(): number;
    public set_texture_mipmap_bias(textureMipmabias: number): void;
    public get_anisotropic_filtering_level(): number;
    public set_anisotropic_filtering_level(anisotropicFilteringLevel: number): void;


}

