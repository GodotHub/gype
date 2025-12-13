
import type { SpriteBase3D } from '@godot/classes/sprite_base3d';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class Sprite3D extends SpriteBase3D {

    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
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
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_region_enabled(enabled: boolean): void;
    public is_region_enabled(): boolean;
    public set_region_rect(rect: Rect2): void;
    public get_region_rect(): Rect2;
    public set_frame(frame: number): void;
    public get_frame(): number;
    public set_frame_coords(coords: Vector2i): void;
    public get_frame_coords(): Vector2i;
    public set_vframes(vframes: number): void;
    public get_vframes(): number;
    public set_hframes(hframes: number): void;
    public get_hframes(): number;

    
    public readonly frame_changed: Signal<() => void>;
    public readonly texture_changed: Signal<() => void>;

}

