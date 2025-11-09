
/**
 * Godot's built-in Signal type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Signal = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Signal(1, 0);
 */
export interface Signal {

    isNull(): boolean;
    getObject(): GodotObject;
    getObjectId(): number;
    getName(): StringName;
    connect(callable: Callable, flags: number = 0): number;
    disconnect(callable: Callable): void;
    isConnected(callable: Callable): boolean;
    getConnections(): GDArray;
    hasConnections(): boolean;
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