
import type { Curve3D } from '@godot/classes/curve3d';
import type { Node3D } from '@godot/classes/node3d';


export declare class Path3D extends Node3D {

    
    /**     * The raw type is 'Curve3D'     */
    public curve: Curve3D;    
    /**     * The raw type is 'Color'     */
    public debug_custom_color: Color;
    public set_curve(curve: Curve3D): void;
    public get_curve(): Curve3D;
    public set_debug_custom_color(debugCustomColor: Color): void;
    public get_debug_custom_color(): Color;

    
    public readonly curve_changed: Signal<() => void>;
    public readonly debug_color_changed: Signal<() => void>;

}

