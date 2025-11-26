
import type { Shape2D } from '@godot/classes/shape2d';


export declare class ConvexPolygonShape2D extends Shape2D {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public points: PackedVector2Array;
    public set_point_cloud(pointCloud: PackedVector2Array): void;
    public set_points(points: PackedVector2Array): void;
    public get_points(): PackedVector2Array;


}

