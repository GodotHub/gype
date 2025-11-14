
import type { Light2D } from '@godot/classes/light2d';


export declare class DirectionalLight2D extends Light2D {

    
    /**     * The raw type is 'float'     */
    public height: number;    
    /**     * The raw type is 'float'     */
    public max_distance: number;
    public set_max_distance(pixels: number): void;
    public get_max_distance(): number;


}

