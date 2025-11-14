
import type { AABB } from '@godot/builtins/aabb';
import type { Node3D } from '@godot/classes/node3d';
import type { RID } from '@godot/builtins/rid';


export declare class VisualInstance3D extends Node3D {

    
    /**     * The raw type is 'int'     */
    public layers: number;    
    /**     * The raw type is 'float'     */
    public sorting_offset: number;    
    /**     * The raw type is 'bool'     */
    public sorting_use_aabb_center: boolean;
    public _get_aabb(): AABB;
    public set_base(base: RID): void;
    public get_base(): RID;
    public get_instance(): RID;
    public set_layer_mask(mask: number): void;
    public get_layer_mask(): number;
    public set_layer_mask_value(layerNumber: number, value: boolean): void;
    public get_layer_mask_value(layerNumber: number): boolean;
    public set_sorting_offset(offset: number): void;
    public get_sorting_offset(): number;
    public set_sorting_use_aabb_center(enabled: boolean): void;
    public is_sorting_use_aabb_center(): boolean;
    public get_aabb(): AABB;


}

