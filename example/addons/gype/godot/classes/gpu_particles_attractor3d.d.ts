
import type { VisualInstance3D } from '@godot/classes/visual_instance3d';


export declare class GPUParticlesAttractor3D extends VisualInstance3D {

    
    /**     * The raw type is 'float'     */
    public strength: number;    
    /**     * The raw type is 'float'     */
    public attenuation: number;    
    /**     * The raw type is 'float'     */
    public directionality: number;    
    /**     * The raw type is 'int'     */
    public cull_mask: number;
    public set_cull_mask(mask: number): void;
    public get_cull_mask(): number;
    public set_strength(strength: number): void;
    public get_strength(): number;
    public set_attenuation(attenuation: number): void;
    public get_attenuation(): number;
    public set_directionality(amount: number): void;
    public get_directionality(): number;


}

