
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class TriangleMesh extends RefCounted {


    public create_from_faces(faces: PackedVector3Array): boolean;
    public get_faces(): PackedVector3Array;
    public intersect_segment(begin: Vector3, end: Vector3): Dictionary;
    public intersect_ray(begin: Vector3, dir: Vector3): Dictionary;


}

