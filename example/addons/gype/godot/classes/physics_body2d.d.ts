
import type { CollisionObject2D } from '@godot/classes/collision_object2d';
import type { KinematicCollision2D } from '@godot/classes/kinematic_collision2d';
import type { Node } from '@godot/classes/node';


export declare class PhysicsBody2D extends CollisionObject2D {


    public move_and_collide(motion: Vector2, testOnly: boolean = false, safeMargin: number = 0.08, recoveryAsCollision: boolean = false): KinematicCollision2D;
    public test_move(_from: Transform2D, motion: Vector2, collision: KinematicCollision2D = null, safeMargin: number = 0.08, recoveryAsCollision: boolean = false): boolean;
    public get_gravity(): Vector2;
    public get_collision_exceptions(): Array<any>;
    public add_collision_exception_with(body: Node): void;
    public remove_collision_exception_with(body: Node): void;


}

