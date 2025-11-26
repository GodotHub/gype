
import type { OpenXRActionSet } from '@godot/classes/open_xr_action_set';
import type { OpenXRHapticBase } from '@godot/classes/open_xr_haptic_base';
import type { OpenXRIPBindingModifier } from '@godot/classes/open_xrip_binding_modifier';


export declare class OpenXRDpadBindingModifier extends OpenXRIPBindingModifier {

    
    /**     * The raw type is 'OpenXRActionSet'     */
    public action_set: OpenXRActionSet;    
    /**     * The raw type is 'String'     */
    public input_path: GDString;    
    /**     * The raw type is 'float'     */
    public threshold: number;    
    /**     * The raw type is 'float'     */
    public threshold_released: number;    
    /**     * The raw type is 'float'     */
    public center_region: number;    
    /**     * The raw type is 'float'     */
    public wedge_angle: number;    
    /**     * The raw type is 'bool'     */
    public is_sticky: boolean;    
    /**     * The raw type is 'OpenXRHapticBase'     */
    public on_haptic: OpenXRHapticBase;    
    /**     * The raw type is 'OpenXRHapticBase'     */
    public off_haptic: OpenXRHapticBase;
    public set_action_set(actionSet: OpenXRActionSet): void;
    public get_action_set(): OpenXRActionSet;
    public set_input_path(inputPath: GDString | StringName | string): void;
    public get_input_path(): GDString;
    public set_threshold(threshold: number): void;
    public get_threshold(): number;
    public set_threshold_released(thresholdReleased: number): void;
    public get_threshold_released(): number;
    public set_center_region(centerRegion: number): void;
    public get_center_region(): number;
    public set_wedge_angle(wedgeAngle: number): void;
    public get_wedge_angle(): number;
    public set_is_sticky(isSticky: boolean): void;
    public get_is_sticky(): boolean;
    public set_on_haptic(haptic: OpenXRHapticBase): void;
    public get_on_haptic(): OpenXRHapticBase;
    public set_off_haptic(haptic: OpenXRHapticBase): void;
    public get_off_haptic(): OpenXRHapticBase;


}

