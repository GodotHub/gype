

declare global {
    declare class Callable {
        constructor();
        constructor(_from: Callable);
        constructor(object: GodotObject, method: Function);


        public static create(variant: any, method: GDString | StringName | string): Callable;
        public callv(arguments: GDArray): any;
        public is_null(): boolean;
        public is_custom(): boolean;
        public is_standard(): boolean;
        public is_valid(): boolean;
        public get_object(): GodotObject;
        public get_object_id(): number;
        public get_method(): StringName;
        public get_argument_count(): number;
        public get_bound_arguments_count(): number;
        public get_bound_arguments(): GDArray;
        public get_unbound_arguments_count(): number;
        public hash(): number;
        public bindv(arguments: GDArray): Callable;
        public unbind(argcount: number): Callable;
        public call(...args: any[]): any;
        public call_deferred(...args: any[]): void;
        public rpc(...args: any[]): void;
        public rpc_id(peerId: number, ...args: any[]): void;
        public bind(...args: any[]): Callable;

    }
}

export {};