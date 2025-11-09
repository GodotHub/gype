
/**
 * Godot's built-in Callable type.
 *
 * As a data structure, it can be represented by a plain object.
 * @example
 * let my_vector: Callable = { x: 1, y: 0 };
 *
 * To create a new instance, use the global constructor.
 * @example
 * const my_vector = new Callable(1, 0);
 */
export interface Callable {

    create(variant: any, method: GDString | StringName | string): Callable;
    callv(arguments: GDArray): any;
    isNull(): boolean;
    isCustom(): boolean;
    isStandard(): boolean;
    isValid(): boolean;
    getObject(): GodotObject;
    getObjectId(): number;
    getMethod(): StringName;
    getArgumentCount(): number;
    getBoundArgumentsCount(): number;
    getBoundArguments(): GDArray;
    getUnboundArgumentsCount(): number;
    hash(): number;
    bindv(arguments: GDArray): Callable;
    unbind(argcount: number): Callable;
    call(...args: any[]): any;
    callDeferred(...args: any[]): void;
    rpc(...args: any[]): void;
    rpcId(peerId: number, ...args: any[]): void;
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