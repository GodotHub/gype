
import type { Camera3D } from '@godot/classes/camera3d';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { Resource } from '@godot/classes/resource';


export declare class GLTFCamera extends Resource {

    
    /**     * The raw type is 'bool'     */
    public perspective: boolean;    
    /**     * The raw type is 'float'     */
    public fov: number;    
    /**     * The raw type is 'float'     */
    public size_mag: number;    
    /**     * The raw type is 'float'     */
    public depth_far: number;    
    /**     * The raw type is 'float'     */
    public depth_near: number;
    public static from_node(cameraNode: Camera3D): GLTFCamera;
    public to_node(): Camera3D;
    public static from_dictionary(dictionary: Dictionary): GLTFCamera;
    public to_dictionary(): Dictionary;
    public get_perspective(): boolean;
    public set_perspective(perspective: boolean): void;
    public get_fov(): number;
    public set_fov(fov: number): void;
    public get_size_mag(): number;
    public set_size_mag(sizeMag: number): void;
    public get_depth_far(): number;
    public set_depth_far(zdepthFar: number): void;
    public get_depth_near(): number;
    public set_depth_near(zdepthNear: number): void;


}

