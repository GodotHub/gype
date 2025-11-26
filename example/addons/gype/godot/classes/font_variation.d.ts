
import type { Font } from '@godot/classes/font';


export declare class FontVariation extends Font {

    
    /**     * The raw type is 'Font'     */
    public base_font: Font;    
    /**     * The raw type is 'Dictionary'     */
    public variation_opentype: Dictionary;    
    /**     * The raw type is 'int'     */
    public variation_face_index: number;    
    /**     * The raw type is 'float'     */
    public variation_embolden: number;    
    /**     * The raw type is 'Transform2D'     */
    public variation_transform: Transform2D;    
    /**     * The raw type is 'Dictionary'     */
    public opentype_features: Dictionary;    
    /**     * The raw type is 'int'     */
    public spacing_glyph: number;    
    /**     * The raw type is 'int'     */
    public spacing_space: number;    
    /**     * The raw type is 'int'     */
    public spacing_top: number;    
    /**     * The raw type is 'int'     */
    public spacing_bottom: number;    
    /**     * The raw type is 'float'     */
    public baseline_offset: number;
    public set_base_font(font: Font): void;
    public get_base_font(): Font;
    public set_variation_opentype(coords: Dictionary): void;
    public get_variation_opentype(): Dictionary;
    public set_variation_embolden(strength: number): void;
    public get_variation_embolden(): number;
    public set_variation_face_index(faceIndex: number): void;
    public get_variation_face_index(): number;
    public set_variation_transform(transform: Transform2D): void;
    public get_variation_transform(): Transform2D;
    public set_opentype_features(features: Dictionary): void;
    public set_spacing(spacing: number, value: number): void;
    public set_baseline_offset(baselineOffset: number): void;
    public get_baseline_offset(): number;


}

