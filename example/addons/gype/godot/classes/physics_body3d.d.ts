
import type { CollisionObject3D } from '@godot/classes/collision_object3d';
import type { KinematicCollision3D } from '@godot/classes/kinematic_collision3d';
import type { Node } from '@godot/classes/node';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicsBody3D extends CollisionObject3D {

    
    /**     * The raw type is 'bool'     */
    public axis_lock_linear_x: boolean;    
    /**     * The raw type is 'bool'     */
    public axis_lock_linear_y: boolean;    
    /**     * The raw type is 'bool'     */
    public axis_lock_linear_z: boolean;    
    /**     * The raw type is 'bool'     */
    public axis_lock_angular_x: boolean;    
    /**     * The raw type is 'bool'     */
    public axis_lock_angular_y: boolean;    
    /**     * The raw type is 'bool'     */
    public axis_lock_angular_z: boolean;
    public move_and_collide(motion: Vector3, testOnly: boolean = false, safeMargin: number = 0.001, recoveryAsCollision: boolean = false, maxCollisions: number = 1): KinematicCollision3D;
    public test_move(_from: Transform3D, motion: Vector3, collision: KinematicCollision3D = null, safeMargin: number = 0.001, recoveryAsCollision: boolean = false, maxCollisions: number = 1): boolean;
    public get_gravity(): Vector3;
    public set_axis_lock(axis: number, lock: boolean): void;
    public get_axis_lock(axis: number): boolean;
    public get_collision_exceptions(): Array<any>;
    public add_collision_exception_with(body: Node): void;
    public remove_collision_exception_with(body: Node): void;


}

