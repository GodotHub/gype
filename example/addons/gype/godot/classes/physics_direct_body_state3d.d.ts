
import type { Basis } from '@godot/builtins/basis';
import type { GodotObject } from '@godot/classes/godot_object';
import type { PhysicsDirectSpaceState3D } from '@godot/classes/physics_direct_space_state3d';
import type { RID } from '@godot/builtins/rid';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicsDirectBodyState3D extends GodotObject {

    
    /**     * The raw type is 'float'     */
    public step: number;    
    /**     * The raw type is 'float'     */
    public inverse_mass: number;    
    /**     * The raw type is 'float'     */
    public total_angular_damp: number;    
    /**     * The raw type is 'float'     */
    public total_linear_damp: number;    
    /**     * The raw type is 'Vector3'     */
    public inverse_inertia: Vector3;    
    /**     * The raw type is 'Basis'     */
    public inverse_inertia_tensor: Basis;    
    /**     * The raw type is 'Vector3'     */
    public total_gravity: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public center_of_mass: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public center_of_mass_local: Vector3;    
    /**     * The raw type is 'Basis'     */
    public principal_inertia_axes: Basis;    
    /**     * The raw type is 'Vector3'     */
    public angular_velocity: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public linear_velocity: Vector3;    
    /**     * The raw type is 'bool'     */
    public sleeping: boolean;    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'Transform3D'     */
    public transform: Transform3D;
    public get_total_gravity(): Vector3;
    public get_total_linear_damp(): number;
    public get_total_angular_damp(): number;
    public get_center_of_mass(): Vector3;
    public get_center_of_mass_local(): Vector3;
    public get_principal_inertia_axes(): Basis;
    public get_inverse_mass(): number;
    public get_inverse_inertia(): Vector3;
    public get_inverse_inertia_tensor(): Basis;
    public set_linear_velocity(velocity: Vector3): void;
    public get_linear_velocity(): Vector3;
    public set_angular_velocity(velocity: Vector3): void;
    public get_angular_velocity(): Vector3;
    public set_transform(transform: Transform3D): void;
    public get_transform(): Transform3D;
    public get_velocity_at_local_position(localPosition: Vector3): Vector3;
    public apply_central_impulse(impulse: Vector3 = Vector3(0, 0, 0)): void;
    public apply_impulse(impulse: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public apply_torque_impulse(impulse: Vector3): void;
    public apply_central_force(force: Vector3 = Vector3(0, 0, 0)): void;
    public apply_force(force: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public apply_torque(torque: Vector3): void;
    public add_constant_central_force(force: Vector3 = Vector3(0, 0, 0)): void;
    public add_constant_force(force: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public add_constant_torque(torque: Vector3): void;
    public set_constant_force(force: Vector3): void;
    public get_constant_force(): Vector3;
    public set_constant_torque(torque: Vector3): void;
    public get_constant_torque(): Vector3;
    public set_sleep_state(enabled: boolean): void;
    public is_sleeping(): boolean;
    public set_collision_layer(layer: number): void;
    public get_collision_layer(): number;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public get_contact_count(): number;
    public get_contact_local_position(contactIdx: number): Vector3;
    public get_contact_local_normal(contactIdx: number): Vector3;
    public get_contact_impulse(contactIdx: number): Vector3;
    public get_contact_local_shape(contactIdx: number): number;
    public get_contact_local_velocity_at_position(contactIdx: number): Vector3;
    public get_contact_collider(contactIdx: number): RID;
    public get_contact_collider_position(contactIdx: number): Vector3;
    public get_contact_collider_id(contactIdx: number): number;
    public get_contact_collider_object(contactIdx: number): GodotObject;
    public get_contact_collider_shape(contactIdx: number): number;
    public get_contact_collider_velocity_at_position(contactIdx: number): Vector3;
    public get_step(): number;
    public integrate_forces(): void;
    public get_space_state(): PhysicsDirectSpaceState3D;


}

