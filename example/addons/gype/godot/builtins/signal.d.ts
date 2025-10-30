
import type { Callable } from '@godot/builtins/callable';
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { GDString } from '@godot/classes/gd_string';
import type { StringName } from '@godot/builtins/string_name';


export declare class Signal {
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

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public equals(right: Signal): boolean;
    public not_equals(right: Signal): boolean;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;

}