
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDString } from '@godot/builtins/gd_string';
import type { RID } from '@godot/builtins/rid';
import type { Texture2D } from '@godot/classes/texture2d';
import type { Vector2i } from '@godot/builtins/vector2i';


export declare class DPITexture extends Texture2D {

    
    /**     * The raw type is 'float'     */
    public base_scale: number;    
    /**     * The raw type is 'float'     */
    public saturation: number;    
    /**     * The raw type is 'typeddictionary::Color;Color'     */
    public color_map: Dictionary;
    public static create_from_string(source: GDString | StringName | string, scale: number = 1.0, saturation: number = 1.0, colorMap: Dictionary = {}): DPITexture;
    public set_source(source: GDString | StringName | string): void;
    public get_source(): GDString;
    public set_base_scale(baseScale: number): void;
    public get_base_scale(): number;
    public set_saturation(saturation: number): void;
    public get_saturation(): number;
    public set_color_map(colorMap: Dictionary): void;
    public get_color_map(): Dictionary;
    public set_size_override(size: Vector2i): void;
    public get_scaled_rid(): RID;


}

