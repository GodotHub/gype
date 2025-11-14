
import type { Joint3D } from '@godot/classes/joint3d';


export declare class ConeTwistJoint3D extends Joint3D {

    
    /**     * The raw type is 'float'     */
    public swing_span: number;    
    /**     * The raw type is 'float'     */
    public twist_span: number;    
    /**     * The raw type is 'float'     */
    public bias: number;    
    /**     * The raw type is 'float'     */
    public softness: number;    
    /**     * The raw type is 'float'     */
    public relaxation: number;
    public set_param(param: number, value: number): void;
    public get_param(param: number): number;


    public static readonly Param: {
        PARAM_SWING_SPAN: 0;
        PARAM_TWIST_SPAN: 1;
        PARAM_BIAS: 2;
        PARAM_SOFTNESS: 3;
        PARAM_RELAXATION: 4;
        PARAM_MAX: 5;
    };
}

