
import type { Gradient } from '@godot/classes/gradient';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class GradientTexture1D extends Texture2D {

    
    /**     * The raw type is 'Gradient'     */
    public gradient: Gradient;    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'bool'     */
    public use_hdr: boolean;
    public set_gradient(gradient: Gradient): void;
    public get_gradient(): Gradient;
    public set_width(width: number): void;
    public set_use_hdr(enabled: boolean): void;
    public is_using_hdr(): boolean;


}

