declare global {
    export interface Signal {

        is_null(): boolean;
        get_object(): GodotObject;
        get_object_id(): number;
        get_name(): StringName;
        connect(callable: Callable, flags: number = 0): number;
        disconnect(callable: Callable): void;
        is_connected(callable: Callable): boolean;
        get_connections(): GDArray;
        has_connections(): boolean;
        emit(...args: any[]): void;
    }

    /**
    * A global constructor and namespace for the Signal type.
    *
    * Use `new Signal(...)` to create a new instance.
    * Access static members like `Signal.ZERO`.
    */
    export declare const Signal: {
        new(): Signal;
        new(_from: Signal): Signal;
        new(object: GodotObject, signal: GDString | StringName | string): Signal;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Signal): boolean
        // not_equals(Signal): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};