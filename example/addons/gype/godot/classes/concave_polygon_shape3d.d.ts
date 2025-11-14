
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class ConcavePolygonShape3D extends Shape3D {

    
    /**     * The raw type is 'PackedVector3Array'     */
    public data: PackedVector3Array;    
    /**     * The raw type is 'bool'     */
    public backface_collision: boolean;
    public set_faces(faces: PackedVector3Array): void;
    public get_faces(): PackedVector3Array;
    public set_backface_collision_enabled(enabled: boolean): void;
    public is_backface_collision_enabled(): boolean;


}

