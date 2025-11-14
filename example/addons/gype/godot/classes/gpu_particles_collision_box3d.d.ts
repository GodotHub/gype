
import type { GPUParticlesCollision3D } from '@godot/classes/gpu_particles_collision3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class GPUParticlesCollisionBox3D extends GPUParticlesCollision3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;


}

