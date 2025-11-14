
import type { Joint3D } from '@godot/classes/joint3d';


export declare class HingeJoint3D extends Joint3D {


    public set_param(param: number, value: number): void;
    public get_param(param: number): number;
    public set_flag(flag: number, enabled: boolean): void;
    public get_flag(flag: number): boolean;


    public static readonly Param: {
        PARAM_BIAS: 0;
        PARAM_LIMIT_UPPER: 1;
        PARAM_LIMIT_LOWER: 2;
        PARAM_LIMIT_BIAS: 3;
        PARAM_LIMIT_SOFTNESS: 4;
        PARAM_LIMIT_RELAXATION: 5;
        PARAM_MOTOR_TARGET_VELOCITY: 6;
        PARAM_MOTOR_MAX_IMPULSE: 7;
        PARAM_MAX: 8;
    };
    public static readonly Flag: {
        FLAG_USE_LIMIT: 0;
        FLAG_ENABLE_MOTOR: 1;
        FLAG_MAX: 2;
    };
}

