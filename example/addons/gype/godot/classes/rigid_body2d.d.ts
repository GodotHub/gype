
import { PhysicsDirectBodyState2D } from "@godot/classes/physics_direct_body_state2d";
import { Node2D } from "@godot/classes/node2d";
import { PhysicsBody2D } from "@godot/classes/physics_body2d";
import { PhysicsMaterial } from "@godot/classes/physics_material";

export declare class RigidBody2D extends PhysicsBody2D{
  public _integrate_forces(_state: PhysicsDirectBodyState2D): void;
  public set_mass(_mass: number): void;
  public get_mass(): number;
  public get_inertia(): number;
  public set_inertia(_inertia: number): void;
  public set_center_of_mass_mode(_mode: number): void;
  public get_center_of_mass_mode(): number;
  public set_center_of_mass(_center_of_mass: Vector2): void;
  public get_center_of_mass(): Vector2;
  public set_physics_material_override(_physics_material_override: PhysicsMaterial): void;
  public get_physics_material_override(): PhysicsMaterial;
  public set_gravity_scale(_gravity_scale: number): void;
  public get_gravity_scale(): number;
  public set_linear_damp_mode(_linear_damp_mode: number): void;
  public get_linear_damp_mode(): number;
  public set_angular_damp_mode(_angular_damp_mode: number): void;
  public get_angular_damp_mode(): number;
  public set_linear_damp(_linear_damp: number): void;
  public get_linear_damp(): number;
  public set_angular_damp(_angular_damp: number): void;
  public get_angular_damp(): number;
  public set_linear_velocity(_linear_velocity: Vector2): void;
  public get_linear_velocity(): Vector2;
  public set_angular_velocity(_angular_velocity: number): void;
  public get_angular_velocity(): number;
  public set_max_contacts_reported(_amount: number): void;
  public get_max_contacts_reported(): number;
  public get_contact_count(): number;
  public set_use_custom_integrator(_enable: boolean): void;
  public is_using_custom_integrator(): boolean;
  public set_contact_monitor(_enabled: boolean): void;
  public is_contact_monitor_enabled(): boolean;
  public set_continuous_collision_detection_mode(_mode: number): void;
  public get_continuous_collision_detection_mode(): number;
  public set_axis_velocity(_axis_velocity: Vector2): void;
  public apply_central_impulse(_impulse: Vector2): void;
  public apply_impulse(_impulse: Vector2, _position: Vector2): void;
  public apply_torque_impulse(_torque: number): void;
  public apply_central_force(_force: Vector2): void;
  public apply_force(_force: Vector2, _position: Vector2): void;
  public apply_torque(_torque: number): void;
  public add_constant_central_force(_force: Vector2): void;
  public add_constant_force(_force: Vector2, _position: Vector2): void;
  public add_constant_torque(_torque: number): void;
  public set_constant_force(_force: Vector2): void;
  public get_constant_force(): Vector2;
  public set_constant_torque(_torque: number): void;
  public get_constant_torque(): number;
  public set_sleeping(_sleeping: boolean): void;
  public is_sleeping(): boolean;
  public set_can_sleep(_able_to_sleep: boolean): void;
  public is_able_to_sleep(): boolean;
  public set_lock_rotation_enabled(_lock_rotation: boolean): void;
  public is_lock_rotation_enabled(): boolean;
  public set_freeze_enabled(_freeze_mode: boolean): void;
  public is_freeze_enabled(): boolean;
  public set_freeze_mode(_freeze_mode: number): void;
  public get_freeze_mode(): number;
  public get_colliding_bodies(): GDArray;
  public get mass(): number {
    get_mass();
  }
  public set mass(value): void {
    set_mass(value);
  }
  public get physics_material_override(): PhysicsMaterial {
    get_physics_material_override();
  }
  public set physics_material_override(value): void {
    set_physics_material_override(value);
  }
  public get gravity_scale(): number {
    get_gravity_scale();
  }
  public set gravity_scale(value): void {
    set_gravity_scale(value);
  }
  public get center_of_mass_mode(): number {
    get_center_of_mass_mode();
  }
  public set center_of_mass_mode(value): void {
    set_center_of_mass_mode(value);
  }
  public get center_of_mass(): Vector2 {
    get_center_of_mass();
  }
  public set center_of_mass(value): void {
    set_center_of_mass(value);
  }
  public get inertia(): number {
    get_inertia();
  }
  public set inertia(value): void {
    set_inertia(value);
  }
  public get sleeping(): boolean {
    is_sleeping();
  }
  public set sleeping(value): void {
    set_sleeping(value);
  }
  public get can_sleep(): boolean {
    is_able_to_sleep();
  }
  public set can_sleep(value): void {
    set_can_sleep(value);
  }
  public get lock_rotation(): boolean {
    is_lock_rotation_enabled();
  }
  public set lock_rotation(value): void {
    set_lock_rotation_enabled(value);
  }
  public get freeze(): boolean {
    is_freeze_enabled();
  }
  public set freeze(value): void {
    set_freeze_enabled(value);
  }
  public get freeze_mode(): number {
    get_freeze_mode();
  }
  public set freeze_mode(value): void {
    set_freeze_mode(value);
  }
  public get custom_integrator(): boolean {
    is_using_custom_integrator();
  }
  public set custom_integrator(value): void {
    set_use_custom_integrator(value);
  }
  public get continuous_cd(): number {
    get_continuous_collision_detection_mode();
  }
  public set continuous_cd(value): void {
    set_continuous_collision_detection_mode(value);
  }
  public get contact_monitor(): boolean {
    is_contact_monitor_enabled();
  }
  public set contact_monitor(value): void {
    set_contact_monitor(value);
  }
  public get max_contacts_reported(): number {
    get_max_contacts_reported();
  }
  public set max_contacts_reported(value): void {
    set_max_contacts_reported(value);
  }
  public get linear_velocity(): Vector2 {
    get_linear_velocity();
  }
  public set linear_velocity(value): void {
    set_linear_velocity(value);
  }
  public get linear_damp_mode(): number {
    get_linear_damp_mode();
  }
  public set linear_damp_mode(value): void {
    set_linear_damp_mode(value);
  }
  public get linear_damp(): number {
    get_linear_damp();
  }
  public set linear_damp(value): void {
    set_linear_damp(value);
  }
  public get angular_velocity(): number {
    get_angular_velocity();
  }
  public set angular_velocity(value): void {
    set_angular_velocity(value);
  }
  public get angular_damp_mode(): number {
    get_angular_damp_mode();
  }
  public set angular_damp_mode(value): void {
    set_angular_damp_mode(value);
  }
  public get angular_damp(): number {
    get_angular_damp();
  }
  public set angular_damp(value): void {
    set_angular_damp(value);
  }
  public get constant_force(): Vector2 {
    get_constant_force();
  }
  public set constant_force(value): void {
    set_constant_force(value);
  }
  public get constant_torque(): number {
    get_constant_torque();
  }
  public set constant_torque(value): void {
    set_constant_torque(value);
  }
  static FreezeMode = {
    FREEZE_MODE_STATIC = 0,
    FREEZE_MODE_KINEMATIC = 1,
  }
  static CenterOfMassMode = {
    CENTER_OF_MASS_MODE_AUTO = 0,
    CENTER_OF_MASS_MODE_CUSTOM = 1,
  }
  static DampMode = {
    DAMP_MODE_COMBINE = 0,
    DAMP_MODE_REPLACE = 1,
  }
  static CCDMode = {
    CCD_MODE_DISABLED = 0,
    CCD_MODE_CAST_RAY = 1,
    CCD_MODE_CAST_SHAPE = 2,
  }
}