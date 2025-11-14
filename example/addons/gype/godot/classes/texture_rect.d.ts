
import type { Control } from '@godot/classes/control';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class TextureRect extends Control {

    
    /**     * The raw type is 'Texture2D'     */
    public texture: Texture2D;    
    /**     * The raw type is 'int'     */
    public expand_mode: number;    
    /**     * The raw type is 'int'     */
    public stretch_mode: number;    
    /**     * The raw type is 'bool'     */
    public flip_h: boolean;    
    /**     * The raw type is 'bool'     */
    public flip_v: boolean;
    public set_texture(texture: Texture2D): void;
    public get_texture(): Texture2D;
    public set_expand_mode(expandMode: number): void;
    public get_expand_mode(): number;
    public set_flip_h(enable: boolean): void;
    public is_flipped_h(): boolean;
    public set_flip_v(enable: boolean): void;
    public is_flipped_v(): boolean;
    public set_stretch_mode(stretchMode: number): void;
    public get_stretch_mode(): number;


    public static readonly ExpandMode: {
        EXPAND_KEEP_SIZE: 0;
        EXPAND_IGNORE_SIZE: 1;
        EXPAND_FIT_WIDTH: 2;
        EXPAND_FIT_WIDTH_PROPORTIONAL: 3;
        EXPAND_FIT_HEIGHT: 4;
        EXPAND_FIT_HEIGHT_PROPORTIONAL: 5;
    };
    public static readonly StretchMode: {
        STRETCH_SCALE: 0;
        STRETCH_TILE: 1;
        STRETCH_KEEP: 2;
        STRETCH_KEEP_CENTERED: 3;
        STRETCH_KEEP_ASPECT: 4;
        STRETCH_KEEP_ASPECT_CENTERED: 5;
        STRETCH_KEEP_ASPECT_COVERED: 6;
    };
}

