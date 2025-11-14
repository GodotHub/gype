import { GodotObject } from "@godot/classes/godot_object";

declare global {
    export class Signal {
        constructor(): Signal;
        constructor(_from: Signal): Signal;
        constructor(object: GodotObject, signal: GDString | StringName | string): Signal;
    

        is_null(): boolean;
        get_object(): GodotObject;
        get_object_id(): number;
        get_name(): StringName;
        connect(callable: Callable | ((...args: any) => void), flags: number = 0): number;
        disconnect(callable: Callable | ((...args: any) => void)): void;
        is_connected(callable: Callable | ((...args: any) => void)): boolean;
        get_connections(): GDArray;
        has_connections(): boolean;
        emit(...args: any[]): void;
        
        /*
        // equals(any): boolean
        // not_equals(any): boolean
        // op_not(any): boolean
        // equals(Signal): boolean
        // not_equals(Signal): boolean
        // in_op(Dictionary): boolean
        // in_op(GDArray): boolean
        */
    }
}

export {};