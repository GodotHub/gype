
import type { GDArray } from '@godot/builtins/gd_array';
import type { RefCounted } from '@godot/classes/ref_counted';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicsTestMotionParameters3D extends RefCounted {

    
    /**     * The raw type is 'Transform3D'     */
    public from: Transform3D;    
    /**     * The raw type is 'Vector3'     */
    public motion: Vector3;    
    /**     * The raw type is 'float'     */
    public margin: number;    
    /**     * The raw type is 'int'     */
    public max_collisions: number;    
    /**     * The raw type is 'bool'     */
    public collide_separation_ray: boolean;    
    /**     * The raw type is 'typedarray::RID'     */
    public exclude_bodies: Array<any>;    
    /**     * The raw type is 'Array'     */
    public exclude_objects: Array<any>;    
    /**     * The raw type is 'bool'     */
    public recovery_as_collision: boolean;
    public get_from(): Transform3D;
    public set_from(_from: Transform3D): void;
    public get_motion(): Vector3;
    public set_motion(motion: Vector3): void;
    public get_margin(): number;
    public set_margin(margin: number): void;
    public get_max_collisions(): number;
    public set_max_collisions(maxCollisions: number): void;
    public is_collide_separation_ray_enabled(): boolean;
    public set_collide_separation_ray_enabled(enabled: boolean): void;
    public get_exclude_bodies(): Array<any>;
    public set_exclude_bodies(excludeList: Array<any>): void;
    public get_exclude_objects(): Array<any>;
    public set_exclude_objects(excludeList: Array<any>): void;
    public is_recovery_as_collision_enabled(): boolean;
    public set_recovery_as_collision_enabled(enabled: boolean): void;


}

