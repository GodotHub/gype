
import type { Node3D } from '@godot/classes/node3d';
import type { Vector3 } from '@godot/builtins/vector3';


export declare class VehicleWheel3D extends Node3D {

    
    /**     * The raw type is 'float'     */
    public engine_force: number;    
    /**     * The raw type is 'float'     */
    public brake: number;    
    /**     * The raw type is 'float'     */
    public steering: number;    
    /**     * The raw type is 'bool'     */
    public use_as_traction: boolean;    
    /**     * The raw type is 'bool'     */
    public use_as_steering: boolean;    
    /**     * The raw type is 'float'     */
    public wheel_roll_influence: number;    
    /**     * The raw type is 'float'     */
    public wheel_radius: number;    
    /**     * The raw type is 'float'     */
    public wheel_rest_length: number;    
    /**     * The raw type is 'float'     */
    public wheel_friction_slip: number;    
    /**     * The raw type is 'float'     */
    public suspension_travel: number;    
    /**     * The raw type is 'float'     */
    public suspension_stiffness: number;    
    /**     * The raw type is 'float'     */
    public suspension_max_force: number;    
    /**     * The raw type is 'float'     */
    public damping_compression: number;    
    /**     * The raw type is 'float'     */
    public damping_relaxation: number;
    public set_radius(length: number): void;
    public get_radius(): number;
    public set_suspension_rest_length(length: number): void;
    public get_suspension_rest_length(): number;
    public set_suspension_travel(length: number): void;
    public get_suspension_travel(): number;
    public set_suspension_stiffness(length: number): void;
    public get_suspension_stiffness(): number;
    public set_suspension_max_force(length: number): void;
    public get_suspension_max_force(): number;
    public set_damping_compression(length: number): void;
    public get_damping_compression(): number;
    public set_damping_relaxation(length: number): void;
    public get_damping_relaxation(): number;
    public set_use_as_traction(enable: boolean): void;
    public is_used_as_traction(): boolean;
    public set_use_as_steering(enable: boolean): void;
    public is_used_as_steering(): boolean;
    public set_friction_slip(length: number): void;
    public get_friction_slip(): number;
    public is_in_contact(): boolean;
    public get_contact_body(): Node3D;
    public get_contact_point(): Vector3;
    public get_contact_normal(): Vector3;
    public set_roll_influence(rollInfluence: number): void;
    public get_roll_influence(): number;
    public get_skidinfo(): number;
    public get_rpm(): number;
    public set_engine_force(engineForce: number): void;
    public get_engine_force(): number;
    public set_brake(brake: number): void;
    public get_brake(): number;
    public set_steering(steering: number): void;
    public get_steering(): number;


}

