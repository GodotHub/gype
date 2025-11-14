
import type { GPUParticlesAttractor3D } from '@godot/classes/gpu_particles_attractor3d';
import type { Texture3D } from '@godot/classes/texture3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class GPUParticlesAttractorVectorField3D extends GPUParticlesAttractor3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'Texture3D'     */
    public texture: Texture3D;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_texture(texture: Texture3D): void;
    public get_texture(): Texture3D;


}

