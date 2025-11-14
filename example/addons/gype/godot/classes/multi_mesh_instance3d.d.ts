
import type { GeometryInstance3D } from '@godot/classes/geometry_instance3d';
import type { MultiMesh } from '@godot/classes/multi_mesh';


export declare class MultiMeshInstance3D extends GeometryInstance3D {

    
    /**     * The raw type is 'MultiMesh'     */
    public multimesh: MultiMesh;
    public set_multimesh(multimesh: MultiMesh): void;
    public get_multimesh(): MultiMesh;


}

