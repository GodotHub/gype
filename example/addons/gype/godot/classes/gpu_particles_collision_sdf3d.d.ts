
import type { GPUParticlesCollision3D } from '@godot/classes/gpu_particles_collision3d';
import type { Texture3D } from '@godot/classes/texture3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class GPUParticlesCollisionSDF3D extends GPUParticlesCollision3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'int'     */
    public resolution: number;    
    /**     * The raw type is 'float'     */
    public thickness: number;    
    /**     * The raw type is 'int'     */
    public bake_mask: number;    
    /**     * The raw type is 'Texture3D'     */
    public texture: Texture3D;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_resolution(resolution: number): void;
    public get_resolution(): number;
    public set_texture(texture: Texture3D): void;
    public get_texture(): Texture3D;
    public set_thickness(thickness: number): void;
    public get_thickness(): number;
    public set_bake_mask(mask: number): void;
    public get_bake_mask(): number;
    public set_bake_mask_value(layerNumber: number, value: boolean): void;
    public get_bake_mask_value(layerNumber: number): boolean;


    public static readonly Resolution: {
        RESOLUTION_16: 0;
        RESOLUTION_32: 1;
        RESOLUTION_64: 2;
        RESOLUTION_128: 3;
        RESOLUTION_256: 4;
        RESOLUTION_512: 5;
        RESOLUTION_MAX: 6;
    };
}

