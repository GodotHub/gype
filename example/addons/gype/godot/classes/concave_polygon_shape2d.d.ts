
import type { Shape2D } from '@godot/classes/shape2d';


export declare class ConcavePolygonShape2D extends Shape2D {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public segments: PackedVector2Array;
    public set_segments(segments: PackedVector2Array): void;
    public get_segments(): PackedVector2Array;


}

