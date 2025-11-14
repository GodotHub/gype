
import type { Shape2D } from '@godot/classes/shape2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class SegmentShape2D extends Shape2D {

    
    /**     * The raw type is 'Vector2'     */
    public a: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public b: Vector2;
    public set_a(a: Vector2): void;
    public get_a(): Vector2;
    public set_b(b: Vector2): void;
    public get_b(): Vector2;


}

