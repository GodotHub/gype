
import type { Color } from '@godot/builtins/color';
import type { Node2D } from '@godot/classes/node2d';


export declare class Light2D extends Node2D {

    
    /**     * The raw type is 'bool'     */
    public enabled: boolean;    
    /**     * The raw type is 'bool'     */
    public editor_only: boolean;    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'float'     */
    public energy: number;    
    /**     * The raw type is 'int'     */
    public blend_mode: number;    
    /**     * The raw type is 'int'     */
    public range_z_min: number;    
    /**     * The raw type is 'int'     */
    public range_z_max: number;    
    /**     * The raw type is 'int'     */
    public range_layer_min: number;    
    /**     * The raw type is 'int'     */
    public range_layer_max: number;    
    /**     * The raw type is 'int'     */
    public range_item_cull_mask: number;    
    /**     * The raw type is 'bool'     */
    public shadow_enabled: boolean;    
    /**     * The raw type is 'Color'     */
    public shadow_color: Color;    
    /**     * The raw type is 'int'     */
    public shadow_filter: number;    
    /**     * The raw type is 'float'     */
    public shadow_filter_smooth: number;    
    /**     * The raw type is 'int'     */
    public shadow_item_cull_mask: number;
    public set_enabled(enabled: boolean): void;
    public is_enabled(): boolean;
    public set_editor_only(editorOnly: boolean): void;
    public is_editor_only(): boolean;
    public set_color(color: Color): void;
    public get_color(): Color;
    public set_energy(energy: number): void;
    public get_energy(): number;
    public set_z_range_min(z: number): void;
    public get_z_range_min(): number;
    public set_z_range_max(z: number): void;
    public get_z_range_max(): number;
    public set_layer_range_min(layer: number): void;
    public get_layer_range_min(): number;
    public set_layer_range_max(layer: number): void;
    public get_layer_range_max(): number;
    public set_item_cull_mask(itemCullMask: number): void;
    public get_item_cull_mask(): number;
    public set_item_shadow_cull_mask(itemShadowCullMask: number): void;
    public get_item_shadow_cull_mask(): number;
    public set_shadow_enabled(enabled: boolean): void;
    public is_shadow_enabled(): boolean;
    public set_shadow_smooth(smooth: number): void;
    public get_shadow_smooth(): number;
    public set_shadow_filter(filter: number): void;
    public get_shadow_filter(): number;
    public set_shadow_color(shadowColor: Color): void;
    public get_shadow_color(): Color;
    public set_blend_mode(mode: number): void;
    public get_blend_mode(): number;
    public set_height(height: number): void;
    public get_height(): number;


    public static readonly ShadowFilter: {
        SHADOW_FILTER_NONE: 0;
        SHADOW_FILTER_PCF5: 1;
        SHADOW_FILTER_PCF13: 2;
    };
    public static readonly BlendMode: {
        BLEND_MODE_ADD: 0;
        BLEND_MODE_SUB: 1;
        BLEND_MODE_MIX: 2;
    };
}

