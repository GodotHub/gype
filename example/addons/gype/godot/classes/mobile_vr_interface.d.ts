
import type { Rect2 } from '@godot/builtins/rect2';
import type { XRInterface } from '@godot/classes/xr_interface';


export declare class MobileVRInterface extends XRInterface {

    
    /**     * The raw type is 'float'     */
    public eye_height: number;    
    /**     * The raw type is 'float'     */
    public iod: number;    
    /**     * The raw type is 'float'     */
    public display_width: number;    
    /**     * The raw type is 'float'     */
    public display_to_lens: number;    
    /**     * The raw type is 'Rect2'     */
    public offset_rect: Rect2;    
    /**     * The raw type is 'float'     */
    public oversample: number;    
    /**     * The raw type is 'float'     */
    public k1: number;    
    /**     * The raw type is 'float'     */
    public k2: number;    
    /**     * The raw type is 'float'     */
    public vrs_min_radius: number;    
    /**     * The raw type is 'float'     */
    public vrs_strength: number;
    public set_eye_height(eyeHeight: number): void;
    public get_eye_height(): number;
    public set_iod(iod: number): void;
    public get_iod(): number;
    public set_display_width(displayWidth: number): void;
    public get_display_width(): number;
    public set_display_to_lens(displayToLens: number): void;
    public get_display_to_lens(): number;
    public set_offset_rect(offsetRect: Rect2): void;
    public get_offset_rect(): Rect2;
    public set_oversample(oversample: number): void;
    public get_oversample(): number;
    public set_k1(k: number): void;
    public get_k1(): number;
    public set_k2(k: number): void;
    public get_k2(): number;
    public get_vrs_min_radius(): number;
    public set_vrs_min_radius(radius: number): void;
    public get_vrs_strength(): number;
    public set_vrs_strength(strength: number): void;


}

