
import type { Node } from '@godot/classes/node';
import type { PhysicsBody2D } from '@godot/classes/physics_body2d';
import type { PhysicsDirectBodyState2D } from '@godot/classes/physics_direct_body_state2d';
import type { PhysicsMaterial } from '@godot/classes/physics_material';


export declare class RigidBody2D extends PhysicsBody2D {

    
    /**     * The raw type is 'float'     */
    public mass: number;    
    /**     * The raw type is 'PhysicsMaterial'     */
    public physics_material_override: PhysicsMaterial;    
    /**     * The raw type is 'float'     */
    public gravity_scale: number;    
    /**     * The raw type is 'int'     */
    public center_of_mass_mode: number;    
    /**     * The raw type is 'Vector2'     */
    public center_of_mass: Vector2;    
    /**     * The raw type is 'float'     */
    public inertia: number;    
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
    /**     * The raw type is 'int'     */
    public continuous_cd: number;    
    /**     * The raw type is 'bool'     */
    public contact_monitor: boolean;    
    /**     * The raw type is 'int'     */
    public max_contacts_reported: number;    
    /**     * The raw type is 'Vector2'     */
    public linear_velocity: Vector2;    
    /**     * The raw type is 'int'     */
    public linear_damp_mode: number;    
    /**     * The raw type is 'float'     */
    public linear_damp: number;    
    /**     * The raw type is 'float'     */
    public angular_velocity: number;    
    /**     * The raw type is 'int'     */
    public angular_damp_mode: number;    
    /**     * The raw type is 'float'     */
    public angular_damp: number;    
    /**     * The raw type is 'Vector2'     */
    public constant_force: Vector2;    
    /**     * The raw type is 'float'     */
    public constant_torque: number;
    public _integrate_forces(state: PhysicsDirectBodyState2D): void;
    public set_mass(mass: number): void;
    public get_mass(): number;
    public get_inertia(): number;
    public set_inertia(inertia: number): void;
    public set_center_of_mass_mode(mode: number): void;
    public get_center_of_mass_mode(): number;
    public set_center_of_mass(centerOfMass: Vector2): void;
    public get_center_of_mass(): Vector2;
    public set_physics_material_override(physicsMaterialOverride: PhysicsMaterial): void;
    public get_physics_material_override(): PhysicsMaterial;
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
    public set_linear_velocity(linearVelocity: Vector2): void;
    public get_linear_velocity(): Vector2;
    public set_angular_velocity(angularVelocity: number): void;
    public get_angular_velocity(): number;
    public set_max_contacts_reported(amount: number): void;
    public get_max_contacts_reported(): number;
    public get_contact_count(): number;
    public set_use_custom_integrator(enable: boolean): void;
    public is_using_custom_integrator(): boolean;
    public set_contact_monitor(enabled: boolean): void;
    public is_contact_monitor_enabled(): boolean;
    public set_continuous_collision_detection_mode(mode: number): void;
    public get_continuous_collision_detection_mode(): number;
    public set_axis_velocity(axisVelocity: Vector2): void;
    public apply_central_impulse(impulse: Vector2 = Vector2(0, 0)): void;
    public apply_impulse(impulse: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public apply_torque_impulse(torque: number): void;
    public apply_central_force(force: Vector2): void;
    public apply_force(force: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public apply_torque(torque: number): void;
    public add_constant_central_force(force: Vector2): void;
    public add_constant_force(force: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public add_constant_torque(torque: number): void;
    public set_constant_force(force: Vector2): void;
    public get_constant_force(): Vector2;
    public set_constant_torque(torque: number): void;
    public get_constant_torque(): number;
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
    public static readonly CCDMode: {
        CCD_MODE_DISABLED: 0;
        CCD_MODE_CAST_RAY: 1;
        CCD_MODE_CAST_SHAPE: 2;
    };
}

