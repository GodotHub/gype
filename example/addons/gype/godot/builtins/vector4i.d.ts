
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Vector4 } from '@godot/builtins/vector4';


export declare class Vector4i {
    constructor();
    constructor(_from: Vector4i);
    constructor(_from: Vector4);
    constructor(x: number, y: number, z: number, w: number);

    public x: number;
    public y: number;
    public z: number;
    public w: number;

    public min_axis_index(): number;
    public max_axis_index(): number;
    public length(): number;
    public length_squared(): number;
    public sign(): Vector4i;
    public abs(): Vector4i;
    public clamp(min: Vector4i, max: Vector4i): Vector4i;
    public clampi(min: number, max: number): Vector4i;
    public snapped(step: Vector4i): Vector4i;
    public snappedi(step: number): Vector4i;
    public min(_with: Vector4i): Vector4i;
    public mini(_with: number): Vector4i;
    public max(_with: Vector4i): Vector4i;
    public maxi(_with: number): Vector4i;
    public distance_to(to: Vector4i): number;
    public distance_squared_to(to: Vector4i): number;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public negate(): Vector4i;
    public positive(): Vector4i;
    public op_not(): boolean;
    public multiply(right: number): Vector4i;
    public divide(right: number): Vector4i;
    public module(right: number): Vector4i;
    public multiply(right: number): Vector4;
    public divide(right: number): Vector4;
    public equals(right: Vector4i): boolean;
    public not_equals(right: Vector4i): boolean;
    public less(right: Vector4i): boolean;
    public less_equal(right: Vector4i): boolean;
    public greater(right: Vector4i): boolean;
    public greater_equal(right: Vector4i): boolean;
    public add(right: Vector4i): Vector4i;
    public subtract(right: Vector4i): Vector4i;
    public multiply(right: Vector4i): Vector4i;
    public divide(right: Vector4i): Vector4i;
    public module(right: Vector4i): Vector4i;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;

    public static readonly Axis: {
        AXIS_X: 0;
        AXIS_Y: 1;
        AXIS_Z: 2;
        AXIS_W: 3;
    };
}