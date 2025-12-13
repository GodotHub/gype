
import type { Node2D } from '@godot/classes/node2d';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class Sprite2D extends Node2D {

    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'bool'     */
    public centered: boolean;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'bool'     */
    public flip_h: boolean;    
    /**     * The raw type is 'bool'     */
    public flip_v: boolean;    
    /**     * The raw type is 'int'     */
    public hframes: number;    
    /**     * The raw type is 'int'     */
    public vframes: number;    
    /**     * The raw type is 'int'     */
    public frame: number;    
    /**     * The raw type is 'Vector2i'     */
    public frame_coords: Vector2i;    
    /**     * The raw type is 'bool'     */
    public region_enabled: boolean;    
    /**     * The raw type is 'Rect2'     */
    public region_rect: Rect2;    
    /**     * The raw type is 'bool'     */
    public region_filter_clip_enabled: boolean;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_centered(centered: boolean): void;
    public is_centered(): boolean;
    public set_offset(offset: Vector2): void;
    public get_offset(): Vector2;
    public set_flip_h(flih: boolean): void;
    public is_flipped_h(): boolean;
    public set_flip_v(fliv: boolean): void;
    public is_flipped_v(): boolean;
    public set_region_enabled(enabled: boolean): void;
    public is_region_enabled(): boolean;
    public is_pixel_opaque(pos: Vector2): boolean;
    public set_region_rect(rect: Rect2): void;
    public get_region_rect(): Rect2;
    public set_region_filter_clip_enabled(enabled: boolean): void;
    public is_region_filter_clip_enabled(): boolean;
    public set_frame(frame: number): void;
    public get_frame(): number;
    public set_frame_coords(coords: Vector2i): void;
    public get_frame_coords(): Vector2i;
    public set_vframes(vframes: number): void;
    public get_vframes(): number;
    public set_hframes(hframes: number): void;
    public get_hframes(): number;
    public get_rect(): Rect2;

    
    public readonly frame_changed: Signal<() => void>;
    public readonly texture_changed: Signal<() => void>;

}

