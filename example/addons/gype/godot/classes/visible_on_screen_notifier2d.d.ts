
import type { Node2D } from '@godot/classes/node2d';


export declare class VisibleOnScreenNotifier2D extends Node2D {

    
    /**     * The raw type is 'Rect2'     */
    public rect: Rect2;    
    /**     * The raw type is 'bool'     */
    public show_rect: boolean;
    public set_rect(rect: Rect2): void;
    public get_rect(): Rect2;
    public set_show_rect(showRect: boolean): void;
    public is_showing_rect(): boolean;
    public is_on_screen(): boolean;

    
    public readonly screen_entered: Signal;
    public readonly screen_exited: Signal;

}

