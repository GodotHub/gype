
import type { Node2D } from '@godot/classes/node2d';


export declare class CanvasGroup extends Node2D {

    
    /**     * The raw type is 'float'     */
    public fit_margin: number;    
    /**     * The raw type is 'float'     */
    public clear_margin: number;    
    /**     * The raw type is 'bool'     */
    public use_mipmaps: boolean;
    public set_fit_margin(fitMargin: number): void;
    public get_fit_margin(): number;
    public set_clear_margin(clearMargin: number): void;
    public get_clear_margin(): number;
    public set_use_mipmaps(useMipmaps: boolean): void;
    public is_using_mipmaps(): boolean;


}

