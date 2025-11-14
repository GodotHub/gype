
import type { Joint3D } from '@godot/classes/joint3d';


export declare class Generic6DOFJoint3D extends Joint3D {


    public set_param_x(param: number, value: number): void;
    public get_param_x(param: number): number;
    public set_param_y(param: number, value: number): void;
    public get_param_y(param: number): number;
    public set_param_z(param: number, value: number): void;
    public get_param_z(param: number): number;
    public set_flag_x(flag: number, value: boolean): void;
    public get_flag_x(flag: number): boolean;
    public set_flag_y(flag: number, value: boolean): void;
    public get_flag_y(flag: number): boolean;
    public set_flag_z(flag: number, value: boolean): void;
    public get_flag_z(flag: number): boolean;


    public static readonly Param: {
        PARAM_LINEAR_LOWER_LIMIT: 0;
        PARAM_LINEAR_UPPER_LIMIT: 1;
        PARAM_LINEAR_LIMIT_SOFTNESS: 2;
        PARAM_LINEAR_RESTITUTION: 3;
        PARAM_LINEAR_DAMPING: 4;
        PARAM_LINEAR_MOTOR_TARGET_VELOCITY: 5;
        PARAM_LINEAR_MOTOR_FORCE_LIMIT: 6;
        PARAM_LINEAR_SPRING_STIFFNESS: 7;
        PARAM_LINEAR_SPRING_DAMPING: 8;
        PARAM_LINEAR_SPRING_EQUILIBRIUM_POINT: 9;
        PARAM_ANGULAR_LOWER_LIMIT: 10;
        PARAM_ANGULAR_UPPER_LIMIT: 11;
        PARAM_ANGULAR_LIMIT_SOFTNESS: 12;
        PARAM_ANGULAR_DAMPING: 13;
        PARAM_ANGULAR_RESTITUTION: 14;
        PARAM_ANGULAR_FORCE_LIMIT: 15;
        PARAM_ANGULAR_ERP: 16;
        PARAM_ANGULAR_MOTOR_TARGET_VELOCITY: 17;
        PARAM_ANGULAR_MOTOR_FORCE_LIMIT: 18;
        PARAM_ANGULAR_SPRING_STIFFNESS: 19;
        PARAM_ANGULAR_SPRING_DAMPING: 20;
        PARAM_ANGULAR_SPRING_EQUILIBRIUM_POINT: 21;
        PARAM_MAX: 22;
    };
    public static readonly Flag: {
        FLAG_ENABLE_LINEAR_LIMIT: 0;
        FLAG_ENABLE_ANGULAR_LIMIT: 1;
        FLAG_ENABLE_LINEAR_SPRING: 3;
        FLAG_ENABLE_ANGULAR_SPRING: 2;
        FLAG_ENABLE_MOTOR: 4;
        FLAG_ENABLE_LINEAR_MOTOR: 5;
        FLAG_MAX: 6;
    };
}

