
import type { Resource } from '@godot/classes/resource';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class SpriteFrames extends Resource {

    
    /**     * The raw type is 'Array'     */
    public animations: GDArray;
    public add_animation(anim: GDString | StringName | string): void;
    public has_animation(anim: GDString | StringName | string): boolean;
    public duplicate_animation(animFrom: GDString | StringName | string, animTo: GDString | StringName | string): void;
    public remove_animation(anim: GDString | StringName | string): void;
    public rename_animation(anim: GDString | StringName | string, newname: GDString | StringName | string): void;
    public get_animation_names(): PackedStringArray;
    public set_animation_speed(anim: GDString | StringName | string, fps: number): void;
    public get_animation_speed(anim: GDString | StringName | string): number;
    public set_animation_loop(anim: GDString | StringName | string, loop: boolean): void;
    public get_animation_loop(anim: GDString | StringName | string): boolean;
    public add_frame(anim: GDString | StringName | string, texture: Texture2D, duration: number = 1.0, atPosition: number = -1): void;
    public set_frame(anim: GDString | StringName | string, idx: number, texture: Texture2D, duration: number = 1.0): void;
    public remove_frame(anim: GDString | StringName | string, idx: number): void;
    public get_frame_count(anim: GDString | StringName | string): number;
    public get_frame_texture(anim: GDString | StringName | string, idx: number): Texture2D;
    public get_frame_duration(anim: GDString | StringName | string, idx: number): number;
    public clear(anim: GDString | StringName | string): void;
    public clear_all(): void;


}

