
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class PhysicsRayQueryParameters3D extends RefCounted {

    
    /**     * The raw type is 'Vector3'     */
    public from: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public to: Vector3;    
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
    /**     * The raw type is 'bool'     */
    public hit_back_faces: boolean;
    public static create(_from: Vector3, to: Vector3, collisionMask: number = 4294967295, exclude: Array<any> = Array[RID]([])): PhysicsRayQueryParameters3D;
    public set_from(_from: Vector3): void;
    public get_from(): Vector3;
    public set_to(to: Vector3): void;
    public get_to(): Vector3;
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
    public set_hit_back_faces(enable: boolean): void;
    public is_hit_back_faces_enabled(): boolean;


}

