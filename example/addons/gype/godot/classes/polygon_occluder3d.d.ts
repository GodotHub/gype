
import type { Occluder3D } from '@godot/classes/occluder3d';
import type { PackedVector2Array } from '@godot/builtins/packed_vector2_array';


export declare class PolygonOccluder3D extends Occluder3D {

    
    /**     * The raw type is 'PackedVector2Array'     */
    public polygon: PackedVector2Array;
    public set_polygon(polygon: PackedVector2Array): void;
    public get_polygon(): PackedVector2Array;


}

