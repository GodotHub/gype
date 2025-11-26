
import type { Node3D } from '@godot/classes/node3d';


export declare class PathFollow3D extends Node3D {

    
    /**     * The raw type is 'float'     */
    public progress: number;    
    /**     * The raw type is 'float'     */
    public progress_ratio: number;    
    /**     * The raw type is 'float'     */
    public h_offset: number;    
    /**     * The raw type is 'float'     */
    public v_offset: number;    
    /**     * The raw type is 'int'     */
    public rotation_mode: number;    
    /**     * The raw type is 'bool'     */
    public use_model_front: boolean;    
    /**     * The raw type is 'bool'     */
    public cubic_interp: boolean;    
    /**     * The raw type is 'bool'     */
    public loop: boolean;    
    /**     * The raw type is 'bool'     */
    public tilt_enabled: boolean;
    public set_progress(progress: number): void;
    public get_progress(): number;
    public set_h_offset(hOffset: number): void;
    public get_h_offset(): number;
    public set_v_offset(vOffset: number): void;
    public get_v_offset(): number;
    public set_progress_ratio(ratio: number): void;
    public get_progress_ratio(): number;
    public set_rotation_mode(rotationMode: number): void;
    public get_rotation_mode(): number;
    public set_cubic_interpolation(enabled: boolean): void;
    public get_cubic_interpolation(): boolean;
    public set_use_model_front(enabled: boolean): void;
    public is_using_model_front(): boolean;
    public set_loop(loop: boolean): void;
    public has_loop(): boolean;
    public set_tilt_enabled(enabled: boolean): void;
    public is_tilt_enabled(): boolean;
    public static correct_posture(transform: Transform3D, rotationMode: number): Transform3D;


    public static readonly RotationMode: {
        ROTATION_NONE: 0;
        ROTATION_Y: 1;
        ROTATION_XY: 2;
        ROTATION_XYZ: 3;
        ROTATION_ORIENTED: 4;
    };
}

