
import type { GodotObject } from '@godot/classes/godot_object';
import type { PhysicsDirectSpaceState2D } from '@godot/classes/physics_direct_space_state2d';


export declare class PhysicsDirectBodyState2D extends GodotObject {

    
    /**     * The raw type is 'float'     */
    public step: number;    
    /**     * The raw type is 'float'     */
    public inverse_mass: number;    
    /**     * The raw type is 'float'     */
    public inverse_inertia: number;    
    /**     * The raw type is 'float'     */
    public total_angular_damp: number;    
    /**     * The raw type is 'float'     */
    public total_linear_damp: number;    
    /**     * The raw type is 'Vector2'     */
    public total_gravity: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public center_of_mass: Vector2;    
    /**     * The raw type is 'Vector2'     */
    public center_of_mass_local: Vector2;    
    /**     * The raw type is 'float'     */
    public angular_velocity: number;    
    /**     * The raw type is 'Vector2'     */
    public linear_velocity: Vector2;    
    /**     * The raw type is 'bool'     */
    public sleeping: boolean;    
    /**     * The raw type is 'int'     */
    public collision_layer: number;    
    /**     * The raw type is 'int'     */
    public collision_mask: number;    
    /**     * The raw type is 'Transform2D'     */
    public transform: Transform2D;
    public get_total_gravity(): Vector2;
    public get_total_linear_damp(): number;
    public get_total_angular_damp(): number;
    public get_center_of_mass(): Vector2;
    public get_center_of_mass_local(): Vector2;
    public get_inverse_mass(): number;
    public get_inverse_inertia(): number;
    public set_linear_velocity(velocity: Vector2): void;
    public get_linear_velocity(): Vector2;
    public set_angular_velocity(velocity: number): void;
    public get_angular_velocity(): number;
    public set_transform(transform: Transform2D): void;
    public get_transform(): Transform2D;
    public get_velocity_at_local_position(localPosition: Vector2): Vector2;
    public apply_central_impulse(impulse: Vector2): void;
    public apply_torque_impulse(impulse: number): void;
    public apply_impulse(impulse: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public apply_central_force(force: Vector2 = Vector2(0, 0)): void;
    public apply_force(force: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public apply_torque(torque: number): void;
    public add_constant_central_force(force: Vector2 = Vector2(0, 0)): void;
    public add_constant_force(force: Vector2, position: Vector2 = Vector2(0, 0)): void;
    public add_constant_torque(torque: number): void;
    public set_constant_force(force: Vector2): void;
    public get_constant_force(): Vector2;
    public set_constant_torque(torque: number): void;
    public get_constant_torque(): number;
    public set_sleep_state(enabled: boolean): void;
    public is_sleeping(): boolean;
    public set_collision_layer(layer: number): void;
    public get_collision_layer(): number;
    public set_collision_mask(mask: number): void;
    public get_collision_mask(): number;
    public get_contact_count(): number;
    public get_contact_local_position(contactIdx: number): Vector2;
    public get_contact_local_normal(contactIdx: number): Vector2;
    public get_contact_local_shape(contactIdx: number): number;
    public get_contact_local_velocity_at_position(contactIdx: number): Vector2;
    public get_contact_collider(contactIdx: number): RID;
    public get_contact_collider_position(contactIdx: number): Vector2;
    public get_contact_collider_id(contactIdx: number): number;
    public get_contact_collider_object(contactIdx: number): GodotObject;
    public get_contact_collider_shape(contactIdx: number): number;
    public get_contact_collider_velocity_at_position(contactIdx: number): Vector2;
    public get_contact_impulse(contactIdx: number): Vector2;
    public get_step(): number;
    public integrate_forces(): void;
    public get_space_state(): PhysicsDirectSpaceState2D;


}

