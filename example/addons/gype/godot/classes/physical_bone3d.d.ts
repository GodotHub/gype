
import type { PhysicsBody3D } from '@godot/classes/physics_body3d';
import type { PhysicsDirectBodyState3D } from '@godot/classes/physics_direct_body_state3d';
import type { Transform3D } from '@godot/builtins/transform3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class PhysicalBone3D extends PhysicsBody3D {

    
    /**     * The raw type is 'int'     */
    public joint_type: number;    
    /**     * The raw type is 'Transform3D'     */
    public joint_offset: Transform3D;    
    /**     * The raw type is 'Vector3'     */
    public joint_rotation: Vector3;    
    /**     * The raw type is 'Transform3D'     */
    public body_offset: Transform3D;    
    /**     * The raw type is 'float'     */
    public mass: number;    
    /**     * The raw type is 'float'     */
    public friction: number;    
    /**     * The raw type is 'float'     */
    public bounce: number;    
    /**     * The raw type is 'float'     */
    public gravity_scale: number;    
    /**     * The raw type is 'bool'     */
    public custom_integrator: boolean;    
    /**     * The raw type is 'int'     */
    public linear_damp_mode: number;    
    /**     * The raw type is 'float'     */
    public linear_damp: number;    
    /**     * The raw type is 'int'     */
    public angular_damp_mode: number;    
    /**     * The raw type is 'float'     */
    public angular_damp: number;    
    /**     * The raw type is 'Vector3'     */
    public linear_velocity: Vector3;    
    /**     * The raw type is 'Vector3'     */
    public angular_velocity: Vector3;    
    /**     * The raw type is 'bool'     */
    public can_sleep: boolean;
    public _integrate_forces(state: PhysicsDirectBodyState3D): void;
    public apply_central_impulse(impulse: Vector3): void;
    public apply_impulse(impulse: Vector3, position: Vector3 = Vector3(0, 0, 0)): void;
    public set_joint_type(jointType: number): void;
    public get_joint_type(): number;
    public set_joint_offset(offset: Transform3D): void;
    public get_joint_offset(): Transform3D;
    public set_joint_rotation(euler: Vector3): void;
    public get_joint_rotation(): Vector3;
    public set_body_offset(offset: Transform3D): void;
    public get_body_offset(): Transform3D;
    public get_simulate_physics(): boolean;
    public is_simulating_physics(): boolean;
    public get_bone_id(): number;
    public set_mass(mass: number): void;
    public get_mass(): number;
    public set_friction(friction: number): void;
    public get_friction(): number;
    public set_bounce(bounce: number): void;
    public get_bounce(): number;
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
    public set_linear_velocity(linearVelocity: Vector3): void;
    public get_linear_velocity(): Vector3;
    public set_angular_velocity(angularVelocity: Vector3): void;
    public get_angular_velocity(): Vector3;
    public set_use_custom_integrator(enable: boolean): void;
    public is_using_custom_integrator(): boolean;
    public set_can_sleep(ableToSleep: boolean): void;
    public is_able_to_sleep(): boolean;


    public static readonly DampMode: {
        DAMP_MODE_COMBINE: 0;
        DAMP_MODE_REPLACE: 1;
    };
    public static readonly JointType: {
        JOINT_TYPE_NONE: 0;
        JOINT_TYPE_PIN: 1;
        JOINT_TYPE_CONE: 2;
        JOINT_TYPE_HINGE: 3;
        JOINT_TYPE_SLIDER: 4;
        JOINT_TYPE_6DOF: 5;
    };
}

