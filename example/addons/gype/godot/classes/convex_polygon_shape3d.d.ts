
import type { Shape3D } from '@godot/classes/shape3d';


export declare class ConvexPolygonShape3D extends Shape3D {

    
    /**     * The raw type is 'Array'     */
    public points: PackedVector3Array;
    public set_points(points: PackedVector3Array): void;
    public get_points(): PackedVector3Array;


}

