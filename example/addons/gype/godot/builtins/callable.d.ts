declare global {
    export class Callable {
        constructor(): Callable;
        constructor(_from: Callable | Function): Callable;
        constructor(object: GodotObject, method: GDString | StringName | string): Callable;
        constructor(object: GodotObject, method: Function): Callable;    

        create(variant: any, method: GDString | StringName | string): Callable;
        callv(arguments: GDArray | Array): any;
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
        bindv(arguments: GDArray | Array): Callable;
        unbind(argcount: number): Callable;
        call(...args: any[]): any;
        call_deferred(...args: any[]): void;
        rpc(...args: any[]): void;
        rpc_id(peerId: number, ...args: any[]): void;
        bind(...args: any[]): Callable;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Callable): boolean
        // not_equals(Callable): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    }
}

export {};