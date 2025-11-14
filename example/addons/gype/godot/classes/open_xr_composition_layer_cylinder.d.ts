
import type { OpenXRCompositionLayer } from '@godot/classes/open_xr_composition_layer';


export declare class OpenXRCompositionLayerCylinder extends OpenXRCompositionLayer {

    
    /**     * The raw type is 'float'     */
    public radius: number;    
    /**     * The raw type is 'float'     */
    public aspect_ratio: number;    
    /**     * The raw type is 'float'     */
    public central_angle: number;    
    /**     * The raw type is 'int'     */
    public fallback_segments: number;
    public set_radius(radius: number): void;
    public get_radius(): number;
    public set_aspect_ratio(aspectRatio: number): void;
    public get_aspect_ratio(): number;
    public set_central_angle(angle: number): void;
    public get_central_angle(): number;
    public set_fallback_segments(segments: number): void;
    public get_fallback_segments(): number;


}

