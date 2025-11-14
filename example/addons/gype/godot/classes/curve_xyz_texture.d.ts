
import type { Curve } from '@godot/classes/curve';
import type { Texture2D } from '@godot/classes/texture2d';


export declare class CurveXYZTexture extends Texture2D {

    
    /**     * The raw type is 'int'     */
    public width: number;    
    /**     * The raw type is 'Curve'     */
    public curve_x: Curve;    
    /**     * The raw type is 'Curve'     */
    public curve_y: Curve;    
    /**     * The raw type is 'Curve'     */
    public curve_z: Curve;
    public set_width(width: number): void;
    public set_curve_x(curve: Curve): void;
    public get_curve_x(): Curve;
    public set_curve_y(curve: Curve): void;
    public get_curve_y(): Curve;
    public set_curve_z(curve: Curve): void;
    public get_curve_z(): Curve;


}

