
import type { Dictionary } from '@godot/builtins/dictionary';
import type { GDArray } from '@godot/builtins/gd_array';
import type { PackedColorArray } from '@godot/builtins/packed_color_array';


export declare class Color {
    constructor();
    constructor(_from: Color);
    constructor(_from: Color, alpha: number);
    constructor(r: number, g: number, b: number);
    constructor(r: number, g: number, b: number, a: number);
    constructor(code: GDString | StringName | string);
    constructor(code: GDString | StringName | string, alpha: number);

    public r: number;
    public g: number;
    public b: number;
    public a: number;
    public r8: number;
    public g8: number;
    public b8: number;
    public a8: number;
    public h: number;
    public s: number;
    public v: number;
    public ok_hsl_h: number;
    public ok_hsl_s: number;
    public ok_hsl_l: number;

    public to_argb32(): number;
    public to_abgr32(): number;
    public to_rgba32(): number;
    public to_argb64(): number;
    public to_abgr64(): number;
    public to_rgba64(): number;
    public to_html(with_alpha: boolean): GDString;
    public clamp(min: Color, max: Color): Color;
    public inverted(): Color;
    public lerp(to: Color, weight: number): Color;
    public lightened(amount: number): Color;
    public darkened(amount: number): Color;
    public blend(over: Color): Color;
    public get_luminance(): number;
    public srgb_to_linear(): Color;
    public linear_to_srgb(): Color;
    public is_equal_approx(to: Color): boolean;
    public static hex(hex: number): Color;
    public static hex64(hex: number): Color;
    public static html(rgba: GDString | StringName | string): Color;
    public static html_is_valid(color: GDString | StringName | string): boolean;
    public static from_string(str: GDString | StringName | string, _default: Color): Color;
    public static from_hsv(h: number, s: number, v: number, alpha: number): Color;
    public static from_ok_hsl(h: number, s: number, l: number, alpha: number): Color;
    public static from_rgbe9995(rgbe: number): Color;
    public static from_rgba8(r8: number, g8: number, b8: number, a8: number): Color;

    public equals(right: any): boolean;
    public not_equals(right: any): boolean;
    public negate(): Color;
    public positive(): Color;
    public op_not(): boolean;
    public multiply(right: number): Color;
    public divide(right: number): Color;
    public multiply(right: number): Color;
    public divide(right: number): Color;
    public equals(right: Color): boolean;
    public not_equals(right: Color): boolean;
    public add(right: Color): Color;
    public subtract(right: Color): Color;
    public multiply(right: Color): Color;
    public divide(right: Color): Color;
    public in_op(right: Dictionary): boolean;
    public in_op(right: GDArray): boolean;
    public in_op(right: PackedColorArray): boolean;

}