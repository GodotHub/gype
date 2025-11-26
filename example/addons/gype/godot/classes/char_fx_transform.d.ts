
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class CharFXTransform extends RefCounted {

    
    /**     * The raw type is 'Transform2D'     */
    public transform: Transform2D;    
    /**     * The raw type is 'Vector2i'     */
    public range: Vector2i;    
    /**     * The raw type is 'float'     */
    public elapsed_time: number;    
    /**     * The raw type is 'bool'     */
    public visible: boolean;    
    /**     * The raw type is 'bool'     */
    public outline: boolean;    
    /**     * The raw type is 'Vector2'     */
    public offset: Vector2;    
    /**     * The raw type is 'Color'     */
    public color: Color;    
    /**     * The raw type is 'Dictionary'     */
    public env: Dictionary;    
    /**     * The raw type is 'int'     */
    public glyph_index: number;    
    /**     * The raw type is 'int'     */
    public glyph_count: number;    
    /**     * The raw type is 'int'     */
    public glyph_flags: number;    
    /**     * The raw type is 'int'     */
    public relative_index: number;    
    /**     * The raw type is 'RID'     */
    public font: RID;
    public get_transform(): Transform2D;
    public set_transform(transform: Transform2D): void;
    public get_range(): Vector2i;
    public set_range(range: Vector2i): void;
    public get_elapsed_time(): number;
    public set_elapsed_time(time: number): void;
    public is_visible(): boolean;
    public set_visibility(visibility: boolean): void;
    public is_outline(): boolean;
    public set_outline(outline: boolean): void;
    public get_offset(): Vector2;
    public set_offset(offset: Vector2): void;
    public get_color(): Color;
    public set_color(color: Color): void;
    public get_environment(): Dictionary;
    public set_environment(environment: Dictionary): void;
    public get_glyph_index(): number;
    public set_glyph_index(glyphIndex: number): void;
    public get_relative_index(): number;
    public set_relative_index(relativeIndex: number): void;
    public get_glyph_count(): number;
    public set_glyph_count(glyphCount: number): void;
    public get_glyph_flags(): number;
    public set_glyph_flags(glyphFlags: number): void;
    public get_font(): RID;
    public set_font(font: RID): void;


}

