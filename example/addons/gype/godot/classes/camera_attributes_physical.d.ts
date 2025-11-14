
import type { CameraAttributes } from '@godot/classes/camera_attributes';


export declare class CameraAttributesPhysical extends CameraAttributes {

    
    /**     * The raw type is 'float'     */
    public frustum_focus_distance: number;    
    /**     * The raw type is 'float'     */
    public frustum_focal_length: number;    
    /**     * The raw type is 'float'     */
    public frustum_near: number;    
    /**     * The raw type is 'float'     */
    public frustum_far: number;    
    /**     * The raw type is 'float'     */
    public exposure_aperture: number;    
    /**     * The raw type is 'float'     */
    public exposure_shutter_speed: number;    
    /**     * The raw type is 'float'     */
    public auto_exposure_min_exposure_value: number;    
    /**     * The raw type is 'float'     */
    public auto_exposure_max_exposure_value: number;
    public set_aperture(aperture: number): void;
    public get_aperture(): number;
    public set_shutter_speed(shutterSpeed: number): void;
    public get_shutter_speed(): number;
    public set_focal_length(focalLength: number): void;
    public get_focal_length(): number;
    public set_focus_distance(focusDistance: number): void;
    public get_focus_distance(): number;
    public set_near(near: number): void;
    public get_near(): number;
    public set_far(far: number): void;
    public get_far(): number;
    public get_fov(): number;
    public set_auto_exposure_max_exposure_value(exposureValueMax: number): void;
    public get_auto_exposure_max_exposure_value(): number;
    public set_auto_exposure_min_exposure_value(exposureValueMin: number): void;
    public get_auto_exposure_min_exposure_value(): number;


}

