
import type { GDString } from '@godot/builtins/gd_string';
import type { Signal } from '@godot/builtins/signal';
import type { SpriteBase3D } from '@godot/classes/sprite_base3d';
import type { SpriteFrames } from '@godot/classes/sprite_frames';
import type { StringName } from '@godot/builtins/string_name';


export declare class AnimatedSprite3D extends SpriteBase3D {

    
    /**     * The raw type is 'SpriteFrames'     */
    public sprite_frames: SpriteFrames;    
    /**     * The raw type is 'StringName'     */
    public animation: StringName;    
    /**     * The raw type is 'StringName'     */
    public autoplay: GDString;    
    /**     * The raw type is 'int'     */
    public frame: number;    
    /**     * The raw type is 'float'     */
    public frame_progress: number;    
    /**     * The raw type is 'float'     */
    public speed_scale: number;
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
    public set_frame(frame: number): void;
    public get_frame(): number;
    public set_frame_progress(progress: number): void;
    public get_frame_progress(): number;
    public set_frame_and_progress(frame: number, progress: number): void;
    public set_speed_scale(speedScale: number): void;
    public get_speed_scale(): number;
    public get_playing_speed(): number;

    
    public readonly sprite_frames_changed: Signal<() => void>;
    public readonly animation_changed: Signal<() => void>;
    public readonly frame_changed: Signal<() => void>;
    public readonly animation_looped: Signal<() => void>;
    public readonly animation_finished: Signal<() => void>;

}

