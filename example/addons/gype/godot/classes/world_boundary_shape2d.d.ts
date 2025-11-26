
import type { Shape2D } from '@godot/classes/shape2d';


export declare class WorldBoundaryShape2D extends Shape2D {

    
    /**     * The raw type is 'Vector2'     */
    public normal: Vector2;    
    /**     * The raw type is 'float'     */
    public distance: number;
    public set_normal(normal: Vector2): void;
    public get_normal(): Vector2;
    public set_distance(distance: number): void;
    public get_distance(): number;


}

