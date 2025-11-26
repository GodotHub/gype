
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';
import type { Shape3D } from '@godot/classes/shape3d';


export declare class PhysicsShapeQueryParameters3D extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'typedarray::RID'     */
    public exclude: Array<any>;    
    /**     * The raw type is 'float'     */
    public margin: number;    
    /**     * The raw type is 'Vector3'     */
    public motion: Vector3;    
    /**     * The raw type is 'Shape3D'     */
    public shape: Resource;    
    /**     * The raw type is 'RID'     */
    public shape_rid: RID;    
    /**     * The raw type is 'Transform3D'     */
    public transform: Transform3D;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;
    public set_shape(shape: Resource): void;
    public get_shape(): Resource;
    public set_shape_rid(shape: RID): void;
    public get_shape_rid(): RID;
    public set_transform(transform: Transform3D): void;
    public get_transform(): Transform3D;
    public set_motion(motion: Vector3): void;
    public get_motion(): Vector3;
    public set_margin(margin: number): void;
    public get_margin(): number;
    public set_collision_mask(collisionMask: number): void;
    public get_collision_mask(): number;
    public set_exclude(exclude: Array<any>): void;
    public get_exclude(): Array<any>;
    public set_collide_with_bodies(enable: boolean): void;
    public is_collide_with_bodies_enabled(): boolean;
    public set_collide_with_areas(enable: boolean): void;
    public is_collide_with_areas_enabled(): boolean;


}

