
import type { Node } from '@godot/classes/node';
import type { PhysicsBody3D } from '@godot/classes/physics_body3d';
import type { PhysicsDirectBodyState3D } from '@godot/classes/physics_direct_body_state3d';
import type { PhysicsMaterial } from '@godot/classes/physics_material';


export declare class RigidBody3D extends PhysicsBody3D {

    
    /**     * The raw type is 'float'     */
    public mass: number;    
    /**     * The raw type is 'PhysicsMaterial'     */
    public physics_material_override: PhysicsMaterial;    
    /**     * The raw type is 'float'     */
    public gravity_scale: number;    
    /**     * The raw type is 'int'     */
    public center_of_mass_mode: number;    
    /**     * The raw type is 'Vector3'     */
    public center_of_mass: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public inertia: Vector3;    
    /**     * The raw type is 'bool'     */
    public sleeping: boolean;    
    /**     * The raw type is 'bool'     */
    public can_sleep: boolean;    
    /**     * The raw type is 'bool'     */
    public lock_rotation: boolean;    
    /**     * The raw type is 'bool'     */
    public freeze: boolean;    
    /**     * The raw type is 'int'     */
    public freeze_mode: number;    
    /**     * The raw type is 'bool'     */
    public custom_integrator: boolean;    
    /**     * The raw type is 'bool'     */
    public continuous_cd: boolean;    
    /**     * The raw type is 'bool'     */
    public contact_monitor: boolean;    
    /**     * The raw type is 'int'     */
    public max_contacts_reported: number;    
    /**     * The raw type is 'Vector3'     */
    public linear_velocity: Vector3;    
    /**     * The raw type is 'int'     */
    public linear_damp_mode: number;    
    /**     * The raw type is 'float'     */
    public linear_damp: number;    
    /**     * The raw type is 'Vector3'     */
    public angular_velocity: Vector3;    
    /**     * The raw type is 'int'     */
    public angular_damp_mode: number;    
    /**     * The raw type is 'float'     */
    public angular_damp: number;    
    /**     * The raw type is 'Vector3'     */
    public constant_force: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public constant_torque: Vector3;
    public _integrate_forces(state: PhysicsDirectBodyState3D): void;
    public set_mass(mass: number): void;
    public get_mass(): number;
    public set_inertia(inertia: Vector3): void;
    public get_inertia(): Vector3;
    public set_center_of_mass_mode(mode: number): void;
    public get_center_of_mass_mode(): number;
    public set_center_of_mass(centerOfMass: Vector3): void;
    public get_center_of_mass(): Vector3;
    public set_physics_material_override(physicsMaterialOverride: PhysicsMaterial): void;
    public get_physics_material_override(): PhysicsMaterial;
    public set_linear_velocity(linearVelocity: Vector3): void;
    public get_linear_velocity(): Vector3;
    public set_angular_velocity(angularVelocity: Vector3): void;
    public get_angular_velocity(): Vector3;
    public get_inverse_inertia_tensor(): Basis;
    public set_gravity_scale(gravityScale: number): void;
    public get_gravity_scale(): number;
    public set_linear_damp_mode(linearDammode: number): void;
    public get_linear_damp_mode(): number;
    public set_angular_damp_mode(angularDammode: number): void;
    public get_angular_damp_mode(): number;
    public set_linear_damp(linearDamp: number): void;
    public get_linear_damp(): number;
    public set_angular_damp(angularDamp: number): void;
    public get_angular_damp(): number;
    public set_max_contacts_reported(amount: number): void;
    public get_max_contacts_reported(): number;
    public get_contact_count(): number;
    public set_use_custom_integrator(enable: boolean): void;
    public is_using_custom_integrator(): boolean;
    public set_contact_monitor(enabled: boolean): void;
    public is_contact_monitor_enabled(): boolean;
    public set_use_continuous_collision_detection(enable: boolean): void;
    public is_using_continuous_collision_detection(): boolean;
    public set_axis_velocity(axisVelocity: Vector3): void;
    public apply_central_impulse(impulse: Vector3): void;
    public apply_impulse(impulse: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public apply_torque_impulse(impulse: Vector3): void;
    public apply_central_force(force: Vector3): void;
    public apply_force(force: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public apply_torque(torque: Vector3): void;
    public add_constant_central_force(force: Vector3): void;
    public add_constant_force(force: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public add_constant_torque(torque: Vector3): void;
    public set_constant_force(force: Vector3): void;
    public get_constant_force(): Vector3;
    public set_constant_torque(torque: Vector3): void;
    public get_constant_torque(): Vector3;
    public set_sleeping(sleeping: boolean): void;
    public is_sleeping(): boolean;
    public set_can_sleep(ableToSleep: boolean): void;
    public is_able_to_sleep(): boolean;
    public set_lock_rotation_enabled(lockRotation: boolean): void;
    public is_lock_rotation_enabled(): boolean;
    public set_freeze_enabled(freezeMode: boolean): void;
    public is_freeze_enabled(): boolean;
    public set_freeze_mode(freezeMode: number): void;
    public get_freeze_mode(): number;
    public get_colliding_bodies(): Array<any>;

    
    public readonly body_shape_entered: Signal;
    public readonly body_shape_exited: Signal;
    public readonly body_entered: Signal;
    public readonly body_exited: Signal;
    public readonly sleeping_state_changed: Signal;

    public static readonly FreezeMode: {
        FREEZE_MODE_STATIC: 0;
        FREEZE_MODE_KINEMATIC: 1;
    };
    public static readonly CenterOfMassMode: {
        CENTER_OF_MASS_MODE_AUTO: 0;
        CENTER_OF_MASS_MODE_CUSTOM: 1;
    };
    public static readonly DampMode: {
        DAMP_MODE_COMBINE: 0;
        DAMP_MODE_REPLACE: 1;
    };
}

