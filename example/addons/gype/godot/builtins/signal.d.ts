declare global {
    export class Signal<T extends (...args: any[]) => void> {
        constructor(): Signal;
        constructor(_from: Signal): Signal;
        constructor(object: GodotObject, signal: GDString | StringName | string): Signal;
    

        is_null(): boolean;
        get_object(): GodotObject;
        get_object_id(): number;
        get_name(): StringName;
        connect(callable: Callable | Function, flags: number = 0): number;
        disconnect(callable: Callable | Function): void;
        is_connected(callable: Callable | Function): boolean;
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