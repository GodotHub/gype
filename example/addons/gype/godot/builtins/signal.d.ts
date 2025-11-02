

declare global {
    declare class Signal {
        constructor();
        constructor(_from: Signal);
        constructor(object: GodotObject, signal: GDString | StringName | string);


        public is_null(): boolean;
        public get_object(): GodotObject;
        public get_object_id(): number;
        public get_name(): StringName;
        public connect(callable: Callable, flags: number): number;
        public disconnect(callable: Callable): void;
        public is_connected(callable: Callable): boolean;
        public get_connections(): GDArray;
        public has_connections(): boolean;
        public emit(...args: any[]): void;

    }
}

export {};