
import type { Mesh } from '@godot/classes/mesh';
import type { VisualShaderNodeParticleEmitter } from '@godot/classes/visual_shader_node_particle_emitter';


export declare class VisualShaderNodeParticleMeshEmitter extends VisualShaderNodeParticleEmitter {

    
    /**     * The raw type is 'Mesh'     */
    public mesh: Mesh;    
    /**     * The raw type is 'bool'     */
    public use_all_surfaces: boolean;    
    /**     * The raw type is 'int'     */
    public surface_index: number;
    public set_mesh(mesh: Mesh): void;
    public get_mesh(): Mesh;
    public set_use_all_surfaces(enabled: boolean): void;
    public is_use_all_surfaces(): boolean;
    public set_surface_index(surfaceIndex: number): void;
    public get_surface_index(): number;


}

