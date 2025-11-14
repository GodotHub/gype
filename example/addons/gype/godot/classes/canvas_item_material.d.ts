
import type { Material } from '@godot/classes/material';


export declare class CanvasItemMaterial extends Material {

    
    /**     * The raw type is 'int'     */
    public blend_mode: number;    
    /**     * The raw type is 'int'     */
    public light_mode: number;    
    /**     * The raw type is 'bool'     */
    public particles_animation: boolean;    
    /**     * The raw type is 'int'     */
    public particles_anim_h_frames: number;    
    /**     * The raw type is 'int'     */
    public particles_anim_v_frames: number;    
    /**     * The raw type is 'bool'     */
    public particles_anim_loop: boolean;
    public set_blend_mode(blendMode: number): void;
    public get_blend_mode(): number;
    public set_light_mode(lightMode: number): void;
    public get_light_mode(): number;
    public set_particles_animation(particlesAnim: boolean): void;
    public get_particles_animation(): boolean;
    public set_particles_anim_h_frames(frames: number): void;
    public get_particles_anim_h_frames(): number;
    public set_particles_anim_v_frames(frames: number): void;
    public get_particles_anim_v_frames(): number;
    public set_particles_anim_loop(loop: boolean): void;
    public get_particles_anim_loop(): boolean;


    public static readonly BlendMode: {
        BLEND_MODE_MIX: 0;
        BLEND_MODE_ADD: 1;
        BLEND_MODE_SUB: 2;
        BLEND_MODE_MUL: 3;
        BLEND_MODE_PREMULT_ALPHA: 4;
    };
    public static readonly LightMode: {
        LIGHT_MODE_NORMAL: 0;
        LIGHT_MODE_UNSHADED: 1;
        LIGHT_MODE_LIGHT_ONLY: 2;
    };
}

