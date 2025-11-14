
import type { OpenXRActionBindingModifier } from '@godot/classes/open_xr_action_binding_modifier';
import type { OpenXRHapticBase } from '@godot/classes/open_xr_haptic_base';


export declare class OpenXRAnalogThresholdModifier extends OpenXRActionBindingModifier {

    
    /**     * The raw type is 'float'     */
    public on_threshold: number;    
    /**     * The raw type is 'float'     */
    public off_threshold: number;    
    /**     * The raw type is 'OpenXRHapticBase'     */
    public on_haptic: OpenXRHapticBase;    
    /**     * The raw type is 'OpenXRHapticBase'     */
    public off_haptic: OpenXRHapticBase;
    public set_on_threshold(onThreshold: number): void;
    public get_on_threshold(): number;
    public set_off_threshold(offThreshold: number): void;
    public get_off_threshold(): number;
    public set_on_haptic(haptic: OpenXRHapticBase): void;
    public get_on_haptic(): OpenXRHapticBase;
    public set_off_haptic(haptic: OpenXRHapticBase): void;
    public get_off_haptic(): OpenXRHapticBase;


}

