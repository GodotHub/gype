
import type { GDArray } from '@godot/builtins/gd_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class PhysicsTestMotionParameters2D extends RefCounted {

    
    /**     * The raw type is 'Transform2D'     */
    public from: Transform2D;    
    /**     * The raw type is 'Vector2'     */
    public motion: Vector2;    
    /**     * The raw type is 'float'     */
    public margin: number;    
    /**     * The raw type is 'bool'     */
    public collide_separation_ray: boolean;    
    /**     * The raw type is 'typedarray::RID'     */
    public exclude_bodies: Array<any>;    
    /**     * The raw type is 'Array'     */
    public exclude_objects: Array<any>;    
    /**     * The raw type is 'bool'     */
    public recovery_as_collision: boolean;
    public get_from(): Transform2D;
    public set_from(_from: Transform2D): void;
    public get_motion(): Vector2;
    public set_motion(motion: Vector2): void;
    public get_margin(): number;
    public set_margin(margin: number): void;
    public is_collide_separation_ray_enabled(): boolean;
    public set_collide_separation_ray_enabled(enabled: boolean): void;
    public get_exclude_bodies(): Array<any>;
    public set_exclude_bodies(excludeList: Array<any>): void;
    public get_exclude_objects(): Array<any>;
    public set_exclude_objects(excludeList: Array<any>): void;
    public is_recovery_as_collision_enabled(): boolean;
    public set_recovery_as_collision_enabled(enabled: boolean): void;


}

