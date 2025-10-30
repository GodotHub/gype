
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Vector2i {
    constructor();
    constructor(_from: Vector2i);
    constructor(_from: Vector2);
    constructor(x: number, y: number);

    public x: number;
    public y: number;

    public aspect(): number;
    public max_axis_index(): number;
    public min_axis_index(): number;
    public distance_to(to: Vector2i): number;
    public distance_squared_to(to: Vector2i): number;
    public length(): number;
    public length_squared(): number;
    public sign(): Vector2i;
    public abs(): Vector2i;
    public clamp(min: Vector2i, max: Vector2i): Vector2i;
    public clampi(min: number, max: number): Vector2i;
    public snapped(step: Vector2i): Vector2i;
    public snappedi(step: number): Vector2i;
    public min(_with: Vector2i): Vector2i;
    public mini(_with: number): Vector2i;
    public max(_with: Vector2i): Vector2i;
    public maxi(_with: number): Vector2i;

    public static readonly Axis: {
        AXIS_X: 0;
        AXIS_Y: 1;
    };
}