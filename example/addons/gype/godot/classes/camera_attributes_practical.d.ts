
import type { CameraAttributes } from '@godot/classes/camera_attributes';


export declare class CameraAttributesPractical extends CameraAttributes {

    
    /**     * The raw type is 'bool'     */
    public dof_blur_far_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public dof_blur_far_distance: number;    
    /**     * The raw type is 'float'     */
    public dof_blur_far_transition: number;    
    /**     * The raw type is 'bool'     */
    public dof_blur_near_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public dof_blur_near_distance: number;    
    /**     * The raw type is 'float'     */
    public dof_blur_near_transition: number;    
    /**     * The raw type is 'float'     */
    public dof_blur_amount: number;    
    /**     * The raw type is 'float'     */
    public auto_exposure_min_sensitivity: number;    
    /**     * The raw type is 'float'     */
    public auto_exposure_max_sensitivity: number;
    public set_dof_blur_far_enabled(enabled: boolean): void;
    public is_dof_blur_far_enabled(): boolean;
    public set_dof_blur_far_distance(distance: number): void;
    public get_dof_blur_far_distance(): number;
    public set_dof_blur_far_transition(distance: number): void;
    public get_dof_blur_far_transition(): number;
    public set_dof_blur_near_enabled(enabled: boolean): void;
    public is_dof_blur_near_enabled(): boolean;
    public set_dof_blur_near_distance(distance: number): void;
    public get_dof_blur_near_distance(): number;
    public set_dof_blur_near_transition(distance: number): void;
    public get_dof_blur_near_transition(): number;
    public set_dof_blur_amount(amount: number): void;
    public get_dof_blur_amount(): number;
    public set_auto_exposure_max_sensitivity(maxSensitivity: number): void;
    public get_auto_exposure_max_sensitivity(): number;
    public set_auto_exposure_min_sensitivity(minSensitivity: number): void;
    public get_auto_exposure_min_sensitivity(): number;


}

