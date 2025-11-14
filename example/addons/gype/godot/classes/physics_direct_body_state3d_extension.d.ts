
import type { Basis } from '@godot/builtins/basis';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PhysicsDirectBodyState3D } from '@godot/classes/physics_direct_body_state3d';
import type { PhysicsDirectSpaceState3D } from '@godot/classes/physics_direct_space_state3d';
import type { RID } from '@godot/builtins/rid';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicsDirectBodyState3DExtension extends PhysicsDirectBodyState3D {


    public _get_total_gravity(): Vector3;
    public _get_total_linear_damp(): number;
    public _get_total_angular_damp(): number;
    public _get_center_of_mass(): Vector3;
    public _get_center_of_mass_local(): Vector3;
    public _get_principal_inertia_axes(): Basis;
    public _get_inverse_mass(): number;
    public _get_inverse_inertia(): Vector3;
    public _get_inverse_inertia_tensor(): Basis;
    public _set_linear_velocity(velocity: Vector3): void;
    public _get_linear_velocity(): Vector3;
    public _set_angular_velocity(velocity: Vector3): void;
    public _get_angular_velocity(): Vector3;
    public _set_transform(transform: Transform3D): void;
    public _get_transform(): Transform3D;
    public _get_velocity_at_local_position(localPosition: Vector3): Vector3;
    public _apply_central_impulse(impulse: Vector3): void;
    public _apply_impulse(impulse: Vector3, position: Vector3): void;
    public _apply_torque_impulse(impulse: Vector3): void;
    public _apply_central_force(force: Vector3): void;
    public _apply_force(force: Vector3, position: Vector3): void;
    public _apply_torque(torque: Vector3): void;
    public _add_constant_central_force(force: Vector3): void;
    public _add_constant_force(force: Vector3, position: Vector3): void;
    public _add_constant_torque(torque: Vector3): void;
    public _set_constant_force(force: Vector3): void;
    public _get_constant_force(): Vector3;
    public _set_constant_torque(torque: Vector3): void;
    public _get_constant_torque(): Vector3;
    public _set_sleep_state(enabled: boolean): void;
    public _is_sleeping(): boolean;
    public _set_collision_layer(layer: number): void;
    public _get_collision_layer(): number;
    public _set_collision_mask(mask: number): void;
    public _get_collision_mask(): number;
    public _get_contact_count(): number;
    public _get_contact_local_position(contactIdx: number): Vector3;
    public _get_contact_local_normal(contactIdx: number): Vector3;
    public _get_contact_impulse(contactIdx: number): Vector3;
    public _get_contact_local_shape(contactIdx: number): number;
    public _get_contact_local_velocity_at_position(contactIdx: number): Vector3;
    public _get_contact_collider(contactIdx: number): RID;
    public _get_contact_collider_position(contactIdx: number): Vector3;
    public _get_contact_collider_id(contactIdx: number): number;
    public _get_contact_collider_object(contactIdx: number): GodotObject;
    public _get_contact_collider_shape(contactIdx: number): number;
    public _get_contact_collider_velocity_at_position(contactIdx: number): Vector3;
    public _get_step(): number;
    public _integrate_forces(): void;
    public _get_space_state(): PhysicsDirectSpaceState3D;


}

