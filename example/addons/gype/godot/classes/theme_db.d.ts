
import type { Font } from '@godot/classes/font';
import type { GodotObject } from '@godot/classes/godot_object';
import type { StyleBox } from '@godot/classes/style_box';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Theme } from '@godot/classes/theme';


export declare class _ThemeDB extends GodotObject {

    
    /**     * The raw type is 'float'     */
    public fallback_base_scale: number;    
    /**     * The raw type is 'Font'     */
    public fallback_font: Font;    
    /**     * The raw type is 'int'     */
    public fallback_font_size: number;    
    /**     * The raw type is 'Texture2D'     */
    public fallback_icon: Texture2D;    
    /**     * The raw type is 'StyleBox'     */
    public fallback_stylebox: StyleBox;
    public get_default_theme(): Theme;
    public get_project_theme(): Theme;
    public set_fallback_base_scale(baseScale: number): void;
    public get_fallback_base_scale(): number;
    public set_fallback_font(font: Font): void;
    public get_fallback_font(): Font;
    public set_fallback_font_size(fontSize: number): void;
    public get_fallback_font_size(): number;
    public set_fallback_icon(icon: Texture2D): void;
    public get_fallback_icon(): Texture2D;
    public set_fallback_stylebox(stylebox: StyleBox): void;
    public get_fallback_stylebox(): StyleBox;

    
    public readonly fallback_changed: Signal<() => void>;

}

declare global {
    const ThemeDB: _ThemeDB
}
