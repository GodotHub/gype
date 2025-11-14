
import type { Occluder3D } from '@godot/classes/occluder3d';
import type { PackedInt32Array } from '@godot/builtins/packed_int32_array';
import type { PackedVector3Array } from '@godot/builtins/packed_vector3_array';


export declare class ArrayOccluder3D extends Occluder3D {

    
    /**     * The raw type is 'PackedVector3Array'     */
    public vertices: PackedVector3Array;    
    /**     * The raw type is 'PackedInt32Array'     */
    public indices: PackedInt32Array;
    public set_arrays(vertices: PackedVector3Array, indices: PackedInt32Array): void;
    public set_vertices(vertices: PackedVector3Array): void;
    public set_indices(indices: PackedInt32Array): void;


}

