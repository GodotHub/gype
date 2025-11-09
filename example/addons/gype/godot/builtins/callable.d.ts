declare global {
    export interface Callable {

        create(variant: any, method: GDString | StringName | string): Callable;
        callv(arguments: GDArray): any;
        is_null(): boolean;
        is_custom(): boolean;
        is_standard(): boolean;
        is_valid(): boolean;
        get_object(): GodotObject;
        get_object_id(): number;
        get_method(): StringName;
        get_argument_count(): number;
        get_bound_arguments_count(): number;
        get_bound_arguments(): GDArray;
        get_unbound_arguments_count(): number;
        hash(): number;
        bindv(arguments: GDArray): Callable;
        unbind(argcount: number): Callable;
        call(...args: any[]): any;
        call_deferred(...args: any[]): void;
        rpc(...args: any[]): void;
        rpc_id(peerId: number, ...args: any[]): void;
        bind(...args: any[]): Callable;
    }

    /**
    * A global constructor and namespace for the Callable type.
    *
    * Use `new Callable(...)` to create a new instance.
    * Access static members like `Callable.ZERO`.
    */
    export declare const Callable: {
        new(): Callable;
        new(_from: Callable): Callable;
        new(object: GodotObject, method: GDString | StringName | string): Callable;
        new(object: GodotObject, method: Function): Callable;


        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Callable): boolean
        // not_equals(Callable): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    };
}

export {};