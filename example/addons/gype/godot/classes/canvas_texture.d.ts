
import type { Texture2D } from '@godot/classes/texture2d';


export declare class CanvasTexture extends Texture2D {

    
    /**     * The raw type is 'Texture2D'     */
    public diffuse_texture: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public normal_texture: Texture2D;    
    /**     * The raw type is 'Texture2D'     */
    public specular_texture: Texture2D;    
    /**     * The raw type is 'Color'     */
    public specular_color: Color;    
    /**     * The raw type is 'float'     */
    public specular_shininess: number;    
    /**     * The raw type is 'int'     */
    public texture_filter: number;    
    /**     * The raw type is 'int'     */
    public texture_repeat: number;
    public set_diffuse_texture(texture: Texture2D): void;
    public get_diffuse_texture(): Texture2D;
    public set_normal_texture(texture: Texture2D): void;
    public get_normal_texture(): Texture2D;
    public set_specular_texture(texture: Texture2D): void;
    public get_specular_texture(): Texture2D;
    public set_specular_color(color: Color): void;
    public get_specular_color(): Color;
    public set_specular_shininess(shininess: number): void;
    public get_specular_shininess(): number;
    public set_texture_filter(filter: number): void;
    public get_texture_filter(): number;
    public set_texture_repeat(repeat: number): void;
    public get_texture_repeat(): number;


}

