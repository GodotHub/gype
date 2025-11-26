
import type { RefCounted } from '@godot/classes/ref_counted';


export declare class OpenXRFutureResult extends RefCounted {


    public get_status(): number;
    public get_future(): number;
    public cancel_future(): void;
    public set_result_value(resultValue: any): void;
    public get_result_value(): any;

    
    public readonly completed: Signal;

    public static readonly ResultStatus: {
        RESULT_RUNNING: 0;
        RESULT_FINISHED: 1;
        RESULT_CANCELLED: 2;
    };
}

