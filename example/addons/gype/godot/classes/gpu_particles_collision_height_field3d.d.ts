
import type { GPUParticlesCollision3D } from '@godot/classes/gpu_particles_collision3d';


export declare class GPUParticlesCollisionHeightField3D extends GPUParticlesCollision3D {

    
    /**     * The raw type is 'Vector3'     */
    public size: Vector3;    
    /**     * The raw type is 'int'     */
    public resolution: number;    
    /**     * The raw type is 'int'     */
    public update_mode: number;    
    /**     * The raw type is 'bool'     */
    public follow_camera_enabled: boolean;    
    /**     * The raw type is 'int'     */
    public heightfield_mask: number;
    public set_size(size: Vector3): void;
    public get_size(): Vector3;
    public set_resolution(resolution: number): void;
    public get_resolution(): number;
    public set_update_mode(updateMode: number): void;
    public get_update_mode(): number;
    public set_heightfield_mask(heightfieldMask: number): void;
    public get_heightfield_mask(): number;
    public set_heightfield_mask_value(layerNumber: number, value: boolean): void;
    public get_heightfield_mask_value(layerNumber: number): boolean;
    public set_follow_camera_enabled(enabled: boolean): void;
    public is_follow_camera_enabled(): boolean;


    public static readonly Resolution: {
        RESOLUTION_256: 0;
        RESOLUTION_512: 1;
        RESOLUTION_1024: 2;
        RESOLUTION_2048: 3;
        RESOLUTION_4096: 4;
        RESOLUTION_8192: 5;
        RESOLUTION_MAX: 6;
    };
    public static readonly UpdateMode: {
        UPDATE_MODE_WHEN_MOVED: 0;
        UPDATE_MODE_ALWAYS: 1;
    };
}

