
import type { GodotObject } from '@godot/classes/godot_object';
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class PhysicsTestMotionResult2D extends RefCounted {


    public get_travel(): Vector2;
    public get_remainder(): Vector2;
    public get_collision_point(): Vector2;
    public get_collision_normal(): Vector2;
    public get_collider_velocity(): Vector2;
    public get_collider_id(): number;
    public get_collider_rid(): RID;
    public get_collider(): GodotObject;
    public get_collider_shape(): number;
    public get_collision_local_shape(): number;
    public get_collision_depth(): number;
    public get_collision_safe_fraction(): number;
    public get_collision_unsafe_fraction(): number;


}

