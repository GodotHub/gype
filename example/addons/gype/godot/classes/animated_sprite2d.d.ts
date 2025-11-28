
import type { Node2D } from '@godot/classes/node2d';
import type { SpriteFrames } from '@godot/classes/sprite_frames';


export declare class AnimatedSprite2D extends Node2D {

    
    /**     * The raw type is 'SpriteFrames'     */
    public sprite_frames: SpriteFrames;    
    /**     * The raw type is 'StringName'     */
    public animation: GDString | StringName | string;    
    /**     * The raw type is 'StringName'     */
    public autoplay: GDString | StringName | string;    
    /**     * The raw type is 'int'     */
    public frame: number;    
    /**     * The raw type is 'float'     */
    public frame_progress: number;    
    /**     * The raw type is 'float'     */
    public speed_scale: number;    
    /**     * The raw type is 'bool'     */
    public centered: boolean;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public flip_h: boolean;    
    /**     * The raw type is 'bool'     */
    public flip_v: boolean;
    public set_sprite_frames(spriteFrames: SpriteFrames): void;
    public get_sprite_frames(): SpriteFrames;
    public set_animation(name: GDString | StringName | string): void;
    public get_animation(): StringName;
    public set_autoplay(name: GDString | StringName | string): void;
    public get_autoplay(): GDString;
    public is_playing(): boolean;
    public play(name: GDString | StringName | string = "", customSpeed: number = 1.0, fromEnd: boolean = false): void;
    public play_backwards(name: GDString | StringName | string = ""): void;
    public pause(): void;
    public stop(): void;
    public set_centered(centered: boolean): void;
    public is_centered(): boolean;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_flip_h(flih: boolean): void;
    public is_flipped_h(): boolean;
    public set_flip_v(fliv: boolean): void;
    public is_flipped_v(): boolean;
    public set_frame(frame: number): void;
    public get_frame(): number;
    public set_frame_progress(progress: number): void;
    public get_frame_progress(): number;
    public set_frame_and_progress(frame: number, progress: number): void;
    public set_speed_scale(speedScale: number): void;
    public get_speed_scale(): number;
    public get_playing_speed(): number;

    
    public readonly sprite_frames_changed: Signal;
    public readonly animation_changed: Signal;
    public readonly frame_changed: Signal;
    public readonly animation_looped: Signal;
    public readonly animation_finished: Signal;

}

