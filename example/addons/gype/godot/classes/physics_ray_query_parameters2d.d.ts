
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class PhysicsRayQueryParameters2D extends RefCounted {

    
    /**     * The raw type is 'Vector2'     */
    public from: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public to: Vector2;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'typedarray::RID'     */
    public exclude: Array<any>;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;    
    /**     * The raw type is 'bool'     */
    public hit_from_inside: boolean;
    public static create(_from: Vector2, to: Vector2, collisionMask: number = 4294967295, exclude: Array<any> = Array[RID]([])): PhysicsRayQueryParameters2D;
    public set_from(_from: Vector2): void;
    public get_from(): Vector2;
    public set_to(to: Vector2): void;
    public get_to(): Vector2;
    public set_collision_mask(collisionMask: number): void;
    public get_collision_mask(): number;
    public set_exclude(exclude: Array<any>): void;
    public get_exclude(): Array<any>;
    public set_collide_with_bodies(enable: boolean): void;
    public is_collide_with_bodies_enabled(): boolean;
    public set_collide_with_areas(enable: boolean): void;
    public is_collide_with_areas_enabled(): boolean;
    public set_hit_from_inside(enable: boolean): void;
    public is_hit_from_inside_enabled(): boolean;


}

