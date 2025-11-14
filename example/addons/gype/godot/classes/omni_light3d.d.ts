
import type { Light3D } from '@godot/classes/light3d';


export declare class OmniLight3D extends Light3D {

    
    /**     * The raw type is 'float'     */
    public omni_range: number;    
    /**     * The raw type is 'float'     */
    public omni_attenuation: number;    
    /**     * The raw type is 'int'     */
    public omni_shadow_mode: number;
    public set_shadow_mode(mode: number): void;
    public get_shadow_mode(): number;


    public static readonly ShadowMode: {
        SHADOW_DUAL_PARABOLOID: 0;
        SHADOW_CUBE: 1;
    };
}

