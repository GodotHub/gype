
import type { Dictionary } from '@godot/builtins/dictionary';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class TriangleMesh extends RefCounted {


    public create_from_faces(faces: PackedVector3Array): boolean;
    public get_faces(): PackedVector3Array;
    public intersect_segment(begin: Vector3, end: Vector3): Dictionary;
    public intersect_ray(begin: Vector3, dir: Vector3): Dictionary;


}

