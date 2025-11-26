
import type { Node3D } from '@godot/classes/node3d';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class SpringArm3D extends Node3D {

    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'Shape3D'     */
    public shape: Shape3D;    
    /**     * The raw type is 'float'     */
    public spring_length: number;    
    /**     * The raw type is 'float'     */
    public margin: number;
    public get_hit_length(): number;
    public set_length(length: number): void;
    public get_length(): number;
    public set_shape(shape: Shape3D): void;
    public get_shape(): Shape3D;
    public add_excluded_object(RID: RID): void;
    public remove_excluded_object(RID: RID): boolean;
    public clear_excluded_objects(): void;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public set_margin(margin: number): void;
    public get_margin(): number;


}

