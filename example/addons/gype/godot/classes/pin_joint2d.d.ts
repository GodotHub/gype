
import type { Joint2D } from '@godot/classes/joint2d';


export declare class PinJoint2D extends Joint2D {

    
    /**     * The raw type is 'float'     */
    public softness: number;    
    /**     * The raw type is 'bool'     */
    public angular_limit_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public angular_limit_lower: number;    
    /**     * The raw type is 'float'     */
    public angular_limit_upper: number;    
    /**     * The raw type is 'bool'     */
    public motor_enabled: boolean;    
    /**     * The raw type is 'float'     */
    public motor_target_velocity: number;
    public set_softness(softness: number): void;
    public get_softness(): number;
    public set_angular_limit_lower(angularLimitLower: number): void;
    public get_angular_limit_lower(): number;
    public set_angular_limit_upper(angularLimitUpper: number): void;
    public get_angular_limit_upper(): number;
    public set_motor_target_velocity(motorTargetVelocity: number): void;
    public get_motor_target_velocity(): number;
    public set_motor_enabled(enabled: boolean): void;
    public is_motor_enabled(): boolean;
    public set_angular_limit_enabled(enabled: boolean): void;
    public is_angular_limit_enabled(): boolean;


}

