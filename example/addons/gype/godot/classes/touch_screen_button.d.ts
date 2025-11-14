
import type { BitMap } from '@godot/classes/bit_map';
import type { GDString } from '@godot/builtins/gd_string';
import type { Node2D } from '@godot/classes/node2d';
import type { Shape2D } from '@godot/classes/shape2d';
import type { Signal } from '@godot/builtins/signal';
import type { StringName } from '@godot/builtins/string_name';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class TouchScreenButton extends Node2D {

    
    /**     * The raw type is 'Texture2D'     */
    public texture_normal: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public texture_pressed: Texture2D;    
    /**     * The raw type is 'BitMap'     */
    public bitmask: BitMap;    
    /**     * The raw type is 'Shape2D'     */
    public shape: Shape2D;    
    /**     * The raw type is 'bool'     */
    public shape_centered: boolean;    
    /**     * The raw type is 'bool'     */
    public shape_visible: boolean;    
    /**     * The raw type is 'bool'     */
    public passby_press: boolean;    
    /**     * The raw type is 'StringName'     */
    public action: GDString;    
    /**     * The raw type is 'int'     */
    public visibility_mode: number;
    public set_texture_normal(texture: Texture2D): void;
    public get_texture_normal(): Texture2D;
    public set_texture_pressed(texture: Texture2D): void;
    public get_texture_pressed(): Texture2D;
    public set_bitmask(bitmask: BitMap): void;
    public get_bitmask(): BitMap;
    public set_shape(shape: Shape2D): void;
    public get_shape(): Shape2D;
    public set_shape_centered(bool: boolean): void;
    public is_shape_centered(): boolean;
    public set_shape_visible(bool: boolean): void;
    public is_shape_visible(): boolean;
    public set_action(action: GDString | StringName | string): void;
    public get_action(): GDString;
    public set_visibility_mode(mode: number): void;
    public get_visibility_mode(): number;
    public set_passby_press(enabled: boolean): void;
    public is_passby_press_enabled(): boolean;
    public is_pressed(): boolean;

    
    public readonly pressed: Signal<() => void>;
    public readonly released: Signal<() => void>;

    public static readonly VisibilityMode: {
        VISIBILITY_ALWAYS: 0;
        VISIBILITY_TOUCHSCREEN_ONLY: 1;
    };
}

