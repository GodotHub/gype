
import type { Curve } from '@godot/classes/curve';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class CurveTexture extends Texture2D {

    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public texture_mode: number;    
    /**     * The raw type is 'Curve'     */
    public curve: Curve;
    public set_width(width: number): void;
    public set_curve(curve: Curve): void;
    public get_curve(): Curve;
    public set_texture_mode(textureMode: number): void;
    public get_texture_mode(): number;


    public static readonly TextureMode: {
        TEXTURE_MODE_RGB: 0;
        TEXTURE_MODE_RED: 1;
    };
}

