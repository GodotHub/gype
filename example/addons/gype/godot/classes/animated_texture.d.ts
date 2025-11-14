
import type { Texture2D } from '@godot/classes/texture2d';


export declare class AnimatedTexture extends Texture2D {

    
    /**     * The raw type is 'int'     */
    public frames: number;    
    /**     * The raw type is 'int'     */
    public current_frame: number;    
    /**     * The raw type is 'bool'     */
    public pause: boolean;    
    /**     * The raw type is 'bool'     */
    public one_shot: boolean;    
    /**     * The raw type is 'float'     */
    public speed_scale: number;
    public set_frames(frames: number): void;
    public get_frames(): number;
    public set_current_frame(frame: number): void;
    public get_current_frame(): number;
    public set_pause(pause: boolean): void;
    public get_pause(): boolean;
    public set_one_shot(oneShot: boolean): void;
    public get_one_shot(): boolean;
    public set_speed_scale(scale: number): void;
    public get_speed_scale(): number;
    public set_frame_texture(frame: number, texture: Texture2D): void;
    public get_frame_texture(frame: number): Texture2D;
    public set_frame_duration(frame: number, duration: number): void;
    public get_frame_duration(frame: number): number;


}

