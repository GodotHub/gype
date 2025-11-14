
import type { Node2D } from '@godot/classes/node2d';


export declare class PathFollow2D extends Node2D {

    
    /**     * The raw type is 'float'     */
    public progress: number;    
    /**     * The raw type is 'float'     */
    public progress_ratio: number;    
    /**     * The raw type is 'float'     */
    public h_offset: number;    
    /**     * The raw type is 'float'     */
    public v_offset: number;    
    /**     * The raw type is 'bool'     */
    public rotates: boolean;    
    /**     * The raw type is 'bool'     */
    public cubic_interp: boolean;    
    /**     * The raw type is 'bool'     */
    public loop: boolean;
    public set_progress(progress: number): void;
    public get_progress(): number;
    public set_h_offset(hOffset: number): void;
    public get_h_offset(): number;
    public set_v_offset(vOffset: number): void;
    public get_v_offset(): number;
    public set_progress_ratio(ratio: number): void;
    public get_progress_ratio(): number;
    public set_rotates(enabled: boolean): void;
    public is_rotating(): boolean;
    public set_cubic_interpolation(enabled: boolean): void;
    public get_cubic_interpolation(): boolean;
    public set_loop(loop: boolean): void;
    public has_loop(): boolean;


}

