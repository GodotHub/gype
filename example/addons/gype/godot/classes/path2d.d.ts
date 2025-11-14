
import type { Curve2D } from '@godot/classes/curve2d';
import type { Node2D } from '@godot/classes/node2d';


export declare class Path2D extends Node2D {

    
    /**     * The raw type is 'Curve2D'     */
    public curve: Curve2D;
    public set_curve(curve: Curve2D): void;
    public get_curve(): Curve2D;


}

