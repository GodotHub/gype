
import type { ArrayMesh } from '@godot/classes/array_mesh';
import type { Resource } from '@godot/classes/resource';


export declare class Shape3D extends Resource {

    
    /**     * The raw type is 'float'     */
    public custom_solver_bias: number;    
    /**     * The raw type is 'float'     */
    public margin: number;
    public set_custom_solver_bias(bias: number): void;
    public get_custom_solver_bias(): number;
    public set_margin(margin: number): void;
    public get_margin(): number;
    public get_debug_mesh(): ArrayMesh;


}

