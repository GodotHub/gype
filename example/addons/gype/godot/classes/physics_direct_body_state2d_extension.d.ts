
import type { GodotObject } from '@godot/classes/godot_object';
import type { PhysicsDirectBodyState2D } from '@godot/classes/physics_direct_body_state2d';
import type { PhysicsDirectSpaceState2D } from '@godot/classes/physics_direct_space_state2d';
import type { RID } from '@godot/builtins/rid';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class PhysicsDirectBodyState2DExtension extends PhysicsDirectBodyState2D {


    public _get_total_gravity(): Vector2;
    public _get_total_linear_damp(): number;
    public _get_total_angular_damp(): number;
    public _get_center_of_mass(): Vector2;
    public _get_center_of_mass_local(): Vector2;
    public _get_inverse_mass(): number;
    public _get_inverse_inertia(): number;
    public _set_linear_velocity(velocity: Vector2): void;
    public _get_linear_velocity(): Vector2;
    public _set_angular_velocity(velocity: number): void;
    public _get_angular_velocity(): number;
    public _set_transform(transform: Transform2D): void;
    public _get_transform(): Transform2D;
    public _get_velocity_at_local_position(localPosition: Vector2): Vector2;
    public _apply_central_impulse(impulse: Vector2): void;
    public _apply_impulse(impulse: Vector2, position: Vector2): void;
    public _apply_torque_impulse(impulse: number): void;
    public _apply_central_force(force: Vector2): void;
    public _apply_force(force: Vector2, position: Vector2): void;
    public _apply_torque(torque: number): void;
    public _add_constant_central_force(force: Vector2): void;
    public _add_constant_force(force: Vector2, position: Vector2): void;
    public _add_constant_torque(torque: number): void;
    public _set_constant_force(force: Vector2): void;
    public _get_constant_force(): Vector2;
    public _set_constant_torque(torque: number): void;
    public _get_constant_torque(): number;
    public _set_sleep_state(enabled: boolean): void;
    public _is_sleeping(): boolean;
    public _set_collision_layer(layer: number): void;
    public _get_collision_layer(): number;
    public _set_collision_mask(mask: number): void;
    public _get_collision_mask(): number;
    public _get_contact_count(): number;
    public _get_contact_local_position(contactIdx: number): Vector2;
    public _get_contact_local_normal(contactIdx: number): Vector2;
    public _get_contact_local_shape(contactIdx: number): number;
    public _get_contact_local_velocity_at_position(contactIdx: number): Vector2;
    public _get_contact_collider(contactIdx: number): RID;
    public _get_contact_collider_position(contactIdx: number): Vector2;
    public _get_contact_collider_id(contactIdx: number): number;
    public _get_contact_collider_object(contactIdx: number): GodotObject;
    public _get_contact_collider_shape(contactIdx: number): number;
    public _get_contact_collider_velocity_at_position(contactIdx: number): Vector2;
    public _get_contact_impulse(contactIdx: number): Vector2;
    public _get_step(): number;
    public _integrate_forces(): void;
    public _get_space_state(): PhysicsDirectSpaceState2D;


}

