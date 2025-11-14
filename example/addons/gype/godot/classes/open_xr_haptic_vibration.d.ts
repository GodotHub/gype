
import type { OpenXRHapticBase } from '@godot/classes/open_xr_haptic_base';


export declare class OpenXRHapticVibration extends OpenXRHapticBase {

    
    /**     * The raw type is 'int'     */
    public duration: number;    
    /**     * The raw type is 'float'     */
    public frequency: number;    
    /**     * The raw type is 'float'     */
    public amplitude: number;
    public set_duration(duration: number): void;
    public get_duration(): number;
    public set_frequency(frequency: number): void;
    public get_frequency(): number;
    public set_amplitude(amplitude: number): void;
    public get_amplitude(): number;


}

