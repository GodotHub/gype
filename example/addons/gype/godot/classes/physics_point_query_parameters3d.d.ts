
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicsPointQueryParameters3D extends RefCounted {

    
    /**     * The raw type is 'Vector3'     */
    public position: Vector3;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'typedarray::RID'     */
    public exclude: Array<any>;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;
    public set_position(position: Vector3): void;
    public get_position(): Vector3;
    public set_collision_mask(collisionMask: number): void;
    public get_collision_mask(): number;
    public set_exclude(exclude: Array<any>): void;
    public get_exclude(): Array<any>;
    public set_collide_with_bodies(enable: boolean): void;
    public is_collide_with_bodies_enabled(): boolean;
    public set_collide_with_areas(enable: boolean): void;
    public is_collide_with_areas_enabled(): boolean;


}

