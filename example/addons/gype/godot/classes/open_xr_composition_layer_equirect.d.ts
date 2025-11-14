
import type { OpenXRCompositionLayer } from '@godot/classes/open_xr_composition_layer';


export declare class OpenXRCompositionLayerEquirect extends OpenXRCompositionLayer {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public central_horizontal_angle: number;    
    /**     * The raw type is 'float'     */
    public upper_vertical_angle: number;    
    /**     * The raw type is 'float'     */
    public lower_vertical_angle: number;    
    /**     * The raw type is 'int'     */
    public fallback_segments: number;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_central_horizontal_angle(angle: number): void;
    public get_central_horizontal_angle(): number;
    public set_upper_vertical_angle(angle: number): void;
    public get_upper_vertical_angle(): number;
    public set_lower_vertical_angle(angle: number): void;
    public get_lower_vertical_angle(): number;
    public set_fallback_segments(segments: number): void;
    public get_fallback_segments(): number;


}

