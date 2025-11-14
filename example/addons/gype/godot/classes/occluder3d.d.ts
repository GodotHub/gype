
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';
import type { Resource } from '@godot/classes/resource';


export declare class Occluder3D extends Resource {


    public get_vertices(): PackedVector3Array;
    public get_indices(): PackedInt32Array;


}

