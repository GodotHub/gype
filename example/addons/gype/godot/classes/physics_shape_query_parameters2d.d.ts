
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Resource } from '@godot/classes/resource';
import type { Shape2D } from '@godot/classes/shape2d';


export declare class PhysicsShapeQueryParameters2D extends RefCounted {

    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'typedarray::RID'     */
    public exclude: Array<any>;    
    /**     * The raw type is 'float'     */
    public margin: number;    
    /**     * The raw type is 'Vector2'     */
    public motion: Vector2;    
    /**     * The raw type is 'Shape2D'     */
    public shape: Resource;    
    /**     * The raw type is 'RID'     */
    public shape_rid: RID;    
    /**     * The raw type is 'Transform2D'     */
    public transform: Transform2D;    
    /**     * The raw type is 'bool'     */
    public collide_with_bodies: boolean;    
    /**     * The raw type is 'bool'     */
    public collide_with_areas: boolean;
    public set_shape(shape: Resource): void;
    public get_shape(): Resource;
    public set_shape_rid(shape: RID): void;
    public get_shape_rid(): RID;
    public set_transform(transform: Transform2D): void;
    public get_transform(): Transform2D;
    public set_motion(motion: Vector2): void;
    public get_motion(): Vector2;
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

