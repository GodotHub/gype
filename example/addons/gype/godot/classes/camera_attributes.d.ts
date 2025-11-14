
import type { Resource } from '@godot/classes/resource';


export declare class CameraAttributes extends Resource {

    
    /**     * The raw type is 'float'     */
    public exposure_sensitivity: number;    
    /**     * The raw type is 'float'     */
    public exposure_multiplier: number;    
    /**     * The raw type is 'bool'     */
    public auto_exposure_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public auto_exposure_scale: number;    
    /**     * The raw type is 'float'     */
    public auto_exposure_speed: number;
    public set_exposure_multiplier(multiplier: number): void;
    public get_exposure_multiplier(): number;
    public set_exposure_sensitivity(sensitivity: number): void;
    public get_exposure_sensitivity(): number;
    public set_auto_exposure_enabled(enabled: boolean): void;
    public is_auto_exposure_enabled(): boolean;
    public set_auto_exposure_speed(exposureSpeed: number): void;
    public get_auto_exposure_speed(): number;
    public set_auto_exposure_scale(exposureGrey: number): void;
    public get_auto_exposure_scale(): number;


}

