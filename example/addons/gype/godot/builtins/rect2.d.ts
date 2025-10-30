
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { Rect2i } from '@godot/builtins/rect2i';
import type { Transform2D } from '@godot/builtins/transform2d';
import type { Vector2 } from '@godot/builtins/vector2';


export declare class Rect2 {
    constructor();
    constructor(_from: Rect2);
    constructor(_from: Rect2i);
    constructor(position: Vector2, size: Vector2);
    constructor(x: number, y: number, width: number, height: number);

    public position: Vector2;
    public size: Vector2;
    public end: Vector2;

    public get_center(): Vector2;
    public get_area(): number;
    public has_area(): boolean;
    public has_point(point: Vector2): boolean;
    public is_equal_approx(rect: Rect2): boolean;
    public is_finite(): boolean;
    public intersects(b: Rect2, include_borders: boolean): boolean;
    public encloses(b: Rect2): boolean;
    public intersection(b: Rect2): Rect2;
    public merge(b: Rect2): Rect2;
    public expand(to: Vector2): Rect2;
    public get_support(direction: Vector2): Vector2;
    public grow(amount: number): Rect2;
    public grow_side(side: number, amount: number): Rect2;
    public grow_individual(left: number, top: number, right: number, bottom: number): Rect2;
    public abs(): Rect2;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public op_not(): boolean;
    public equals(right: Rect2): boolean;
    public not_equals(right: Rect2): boolean;
    public multiply(right: Transform2D): Rect2;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;

}