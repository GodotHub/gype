
import type { GodotObject } from '@godot/classes/godot_object';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class KinematicCollision3D extends RefCounted {


    public get_travel(): Vector3;
    public get_remainder(): Vector3;
    public get_depth(): number;
    public get_collision_count(): number;
    public get_position(collisionIndex: number = 0): Vector3;
    public get_normal(collisionIndex: number = 0): Vector3;
    public get_angle(collisionIndex: number = 0, udirection: Vector3 = Vector3(0, 1, 0)): number;
    public get_local_shape(collisionIndex: number = 0): GodotObject;
    public get_collider(collisionIndex: number = 0): GodotObject;
    public get_collider_id(collisionIndex: number = 0): number;
    public get_collider_rid(collisionIndex: number = 0): RID;
    public get_collider_shape(collisionIndex: number = 0): GodotObject;
    public get_collider_shape_index(collisionIndex: number = 0): number;
    public get_collider_velocity(collisionIndex: number = 0): Vector3;


}

