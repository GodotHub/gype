
import type { Occluder3D } from '@godot/classes/occluder3d';
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class OccluderInstance3D extends VisualInstance3D {

    
    /**     * The raw type is 'Occluder3D'     */
    public occluder: Occluder3D;    
    /**     * The raw type is 'int'     */
    public bake_mask: number;    
    /**     * The raw type is 'float'     */
    public bake_simplification_distance: number;
    public set_bake_mask(mask: number): void;
    public get_bake_mask(): number;
    public set_bake_mask_value(layerNumber: number, value: boolean): void;
    public get_bake_mask_value(layerNumber: number): boolean;
    public set_bake_simplification_distance(simplificationDistance: number): void;
    public get_bake_simplification_distance(): number;
    public set_occluder(occluder: Occluder3D): void;
    public get_occluder(): Occluder3D;


}

