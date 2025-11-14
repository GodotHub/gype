
import type { Node2D } from '@godot/classes/node2d';
import type { Rect2 } from '@godot/builtins/rect2';
import type { Signal } from '@godot/builtins/signal';


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

    
    public readonly screen_entered: Signal<() => void>;
    public readonly screen_exited: Signal<() => void>;

}

