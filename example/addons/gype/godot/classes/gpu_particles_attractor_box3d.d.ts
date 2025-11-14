
import type { GPUParticlesAttractor3D } from '@godot/classes/gpu_particles_attractor3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class GPUParticlesAttractorBox3D extends GPUParticlesAttractor3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;


}

