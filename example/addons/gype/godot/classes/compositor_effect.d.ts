
import type { RenderData } from '@godot/classes/render_data';
import type { Resource } from '@godot/classes/resource';


export declare class CompositorEffect extends Resource {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'int'     */
    public effect_callback_type: number;    
    /**     * The raw type is 'bool'     */
    public access_resolved_color: boolean;    
    /**     * The raw type is 'bool'     */
    public access_resolved_depth: boolean;    
    /**     * The raw type is 'bool'     */
    public needs_motion_vectors: boolean;    
    /**     * The raw type is 'bool'     */
    public needs_normal_roughness: boolean;    
    /**     * The raw type is 'bool'     */
    public needs_separate_specular: boolean;
    public _render_callback(effectCallbackType: number, renderData: RenderData): void;
    public set_enabled(enabled: boolean): void;
    public get_enabled(): boolean;
    public set_effect_callback_type(effectCallbackType: number): void;
    public get_effect_callback_type(): number;
    public set_access_resolved_color(enable: boolean): void;
    public get_access_resolved_color(): boolean;
    public set_access_resolved_depth(enable: boolean): void;
    public get_access_resolved_depth(): boolean;
    public set_needs_motion_vectors(enable: boolean): void;
    public get_needs_motion_vectors(): boolean;
    public set_needs_normal_roughness(enable: boolean): void;
    public get_needs_normal_roughness(): boolean;
    public set_needs_separate_specular(enable: boolean): void;
    public get_needs_separate_specular(): boolean;


    public static readonly EffectCallbackType: {
        EFFECT_CALLBACK_TYPE_PRE_OPAQUE: 0;
        EFFECT_CALLBACK_TYPE_POST_OPAQUE: 1;
        EFFECT_CALLBACK_TYPE_POST_SKY: 2;
        EFFECT_CALLBACK_TYPE_PRE_TRANSPARENT: 3;
        EFFECT_CALLBACK_TYPE_POST_TRANSPARENT: 4;
        EFFECT_CALLBACK_TYPE_MAX: 5;
    };
}

