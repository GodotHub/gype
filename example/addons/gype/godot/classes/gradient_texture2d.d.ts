
import type { Gradient } from '@godot/classes/gradient';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class GradientTexture2D extends Texture2D {

    
    /**     * The raw type is 'Gradient'     */
    public gradient: Gradient;    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'int'     */
    public height: number;    
    /**     * The raw type is 'bool'     */
    public use_hdr: boolean;    
    /**     * The raw type is 'int'     */
    public fill: number;    
    /**     * The raw type is 'Vector2'     */
    public fill_from: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public fill_to: Vector2;    
    /**     * The raw type is 'int'     */
    public repeat: number;
    public set_gradient(gradient: Gradient): void;
    public get_gradient(): Gradient;
    public set_width(width: number): void;
    public set_height(height: number): void;
    public set_use_hdr(enabled: boolean): void;
    public is_using_hdr(): boolean;
    public set_fill(fill: number): void;
    public get_fill(): number;
    public set_fill_from(fillFrom: Vector2): void;
    public get_fill_from(): Vector2;
    public set_fill_to(fillTo: Vector2): void;
    public get_fill_to(): Vector2;
    public set_repeat(repeat: number): void;
    public get_repeat(): number;


    public static readonly Fill: {
        FILL_LINEAR: 0;
        FILL_RADIAL: 1;
        FILL_SQUARE: 2;
    };
    public static readonly Repeat: {
        REPEAT_NONE: 0;
        REPEAT: 1;
        REPEAT_MIRROR: 2;
    };
}

